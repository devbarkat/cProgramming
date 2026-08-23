#include <stdio.h>
#include <string.h>


struct BankAccount {
    char username[50];
    char password[50];
    float balance;
};


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
    scanf("%f", &amount);
    
    if (amount > 0) {
        account->balance += amount;
        printf("Successfully deposited $%.2f\n", amount);
        printf("New balance: $%.2f\n", account->balance);
    } else {
        printf("Invalid amount!\n");
    }
}

void withdraw(struct BankAccount *account) {
    float amount;
    printf("\nEnter amount to withdraw: $");
    scanf("%f", &amount);
    
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
        printf("Invalid amount!\n");
    }
}


void checkBalance(struct BankAccount *account) {
    printf("\n=== Account Details ===\n");
    printf("Username: %s\n", account->username);
    printf("Current Balance: $%.2f\n", account->balance);
    printf("======================\n");
}

// Function to calculate interest
void calculateInterest(struct BankAccount *account) {
    float rate = 5.0; // Annual interest rate of 5%
    int years;
    
    printf("\nEnter number of years for interest calculation: ");
    // Basic input validation would be good here
    scanf("%d", &years);

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
        printf("Invalid number of years!\n");
    }
}

int main() {
    struct BankAccount accounts[5] = {
        {"abir", "1122", 1000.00},
        {"barkat", "1122", 2500.50},
        {"arafat", "1122", 750.25},
        {"kowshik", "1122", 3200.00},
        {"rokon", "1122", 1800.75}
    };
    
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
    
    loggedInUser = login(accounts, 5, username, password);
    
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
        printf("4. Calculate Interest\n"); // Added option
        printf("5. Logout\n");           // Updated option
        printf("========================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
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
            case 4: // Case for new function
                calculateInterest(&accounts[loggedInUser]);
                break;
            case 5: // Case for logout
                printf("\nThank you for using our bank. Goodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    
    return 0;
}