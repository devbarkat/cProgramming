#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_ACCOUNTS 5
#define FILENAME "bank_accounts.dat"


struct BankAccount {
    char username[50];
    char password[50];
    float balance;
};


// Function Prototypes
void saveAccounts(struct BankAccount accounts[], int size);
void loadAccounts(struct BankAccount accounts[], int *size);
int findUser(struct BankAccount accounts[], int size, char username[]);
int login(struct BankAccount accounts[], int size, char username[], char password[]);
void deposit(struct BankAccount *account);
void withdraw(struct BankAccount *account);
void checkBalance(struct BankAccount *account);
void calculateInterest(struct BankAccount *account);


// Function to save all account data to a file
void saveAccounts(struct BankAccount accounts[], int size) {
    FILE *file = fopen(FILENAME, "wb"); // Open in write-binary mode
    if (file == NULL) {
        printf("Error: Could not open file %s for writing.\n", FILENAME);
        return;
    }
    // Write the number of accounts first
    fwrite(&size, sizeof(int), 1, file);
    // Write the account data
    fwrite(accounts, sizeof(struct BankAccount), size, file);
    fclose(file);
    printf("\nAll account data saved to %s.\n", FILENAME);
}


// Function to load account data from a file
void loadAccounts(struct BankAccount accounts[], int *size) {
    FILE *file = fopen(FILENAME, "rb"); // Open in read-binary mode
    if (file == NULL) {
        // If file doesn't exist, it's the first run, initialize with default data
        printf("No existing data file found. Initializing with default accounts.\n");
        *size = MAX_ACCOUNTS;
        struct BankAccount defaultAccounts[MAX_ACCOUNTS] = {
            {"abir", "1122", 1000.00},
            {"barkat", "1122", 2500.50},
            {"arafat", "1122", 750.25},
            {"kowshik", "1122", 3200.00},
            {"rokon", "1122", 1800.75}
        };
        memcpy(accounts, defaultAccounts, sizeof(defaultAccounts));
        saveAccounts(accounts, *size); // Save the initial data
        return;
    }

    // Read the number of accounts
    fread(size, sizeof(int), 1, file);
    if (*size > MAX_ACCOUNTS) {
        printf("Error: Data file contains more accounts than allowed by program limits.\n");
        *size = 0;
        fclose(file);
        return;
    }
    // Read the account data
    fread(accounts, sizeof(struct BankAccount), *size, file);
    fclose(file);
    printf("\nAccount data loaded from %s.\n", FILENAME);
}


int findUser(struct BankAccount accounts[], int size, char username[]) {
    for (int i = 0; i < size; i++) {
        if (strcmp(accounts[i].username, username) == 0) {
            return i;
        }
    }
    return -1;
}


int login(struct BankAccount accounts[], int size, char username[], char password[]) {
    int userIndex = findUser(accounts, size, username);
    
    if (userIndex != -1) {
        if (strcmp(accounts[userIndex].password, password) == 0) {
            return userIndex;
        }
    }
    return -1;
}


void deposit(struct BankAccount *account) {
    float amount;
    printf("\nEnter amount to deposit: $");
    // Added input validation for the float input
    if (scanf("%f", &amount) != 1) {
        printf("Invalid input! Please enter a numeric amount.\n");
        while (getchar() != '\n'); // Clear input buffer
        return;
    }
    
    if (amount > 0) {
        account->balance += amount;
        printf("Successfully deposited $%.2f\n", amount);
        printf("New balance: $%.2f\n", account->balance);
    } else {
        printf("Invalid amount! Amount must be positive.\n");
    }
}


void withdraw(struct BankAccount *account) {
    float amount;
    printf("\nEnter amount to withdraw: $");
    // Added input validation for the float input
    if (scanf("%f", &amount) != 1) {
        printf("Invalid input! Please enter a numeric amount.\n");
        while (getchar() != '\n'); // Clear input buffer
        return;
    }
    
    if (amount > 0) {
        if (amount <= account->balance) {
            account->balance -= amount;
            printf("Successfully withdrawn $%.2f\n", amount);
            printf("New balance: $%.2f\n", account->balance);
        } else {
            printf("Insufficient balance!\n");
            printf("Your current balance: $%.2f\n", account->balance);
        }
    } else {
        printf("Invalid amount! Amount must be positive.\n");
    }
}


void checkBalance(struct BankAccount *account) {
    printf("\n=== Account Details ===\n");
    printf("Username: %s\n", account->username);
    printf("Current Balance: $%.2f\n", account->balance);
    printf("======================\n");
}


void calculateInterest(struct BankAccount *account) {
    float rate = 5.0; // Annual interest rate of 5%
    int years;
    
    printf("\nEnter number of years for interest calculation: ");
    // Added input validation for the integer input
    if (scanf("%d", &years) != 1) {
        printf("Invalid input! Please enter an integer number of years.\n");
        while (getchar() != '\n'); // Clear input buffer
        return;
    }

    if (years > 0) {
        // Simple Interest Formula: Principal * Rate * Time / 100
        float interest = (account->balance * rate * years) / 100.0;
        float finalBalance = account->balance + interest;

        printf("\n=== Interest Calculation ===\n");
        printf("Principal Amount: $%.2f\n", account->balance);
        printf("Annual Rate: %.2f%%\n", rate);
        printf("Time Period: %d years\n", years);
        printf("Calculated Interest: $%.2f\n", interest);
        printf("Future Balance after %d years: $%.2f\n", years, finalBalance);
        printf("============================\n");
    } else {
        printf("Invalid number of years! Must be positive.\n");
    }
}


int main() {
    struct BankAccount accounts[MAX_ACCOUNTS];
    int numAccounts = 0;

    // Load account data at the start of the program
    loadAccounts(accounts, &numAccounts);
    
    char username[50];
    char password[50];
    int loggedInUser = -1;
    int choice;
    
    printf("========================================\n");
    printf("   Welcome to Simple Bank System\n");
    printf("========================================\n");
    
    // Login
    printf("\n--- Login ---\n");
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    
    loggedInUser = login(accounts, numAccounts, username, password);
    
    if (loggedInUser == -1) {
        printf("\nLogin failed! Invalid username or password.\n");
        return 0;
    }
    
    printf("\nLogin successful! Welcome, %s!\n", accounts[loggedInUser].username);
    
    // Main menu
    while (1) {
        printf("\n========================================\n");
        printf("           Main Menu\n");
        printf("========================================\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Calculate Interest\n");
        printf("5. Save and Logout\n"); // Changed option description
        printf("========================================\n");
        printf("Enter your choice: ");
        
        // Added input validation for the menu choice
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input! Please enter a number from the menu.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                checkBalance(&accounts[loggedInUser]);
                break;
            case 2:
                deposit(&accounts[loggedInUser]);
                break;
            case 3:
                withdraw(&accounts[loggedInUser]);
                break;
            case 4:
                calculateInterest(&accounts[loggedInUser]);
                break;
            case 5:
                // Save data before exiting
                saveAccounts(accounts, numAccounts);
                printf("\nThank you for using our bank. Goodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    
    return 0;
}