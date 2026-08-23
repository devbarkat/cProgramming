#include <stdio.h>

int main() {
    double balance = 500.00;
    int choice;
    double amount;
    int running = 1;

while (running) {
    printf("\n--- ATM MENU ---\n");
    printf("1. Check Balance\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Exit\n");
    printf("Choose an option: ");

if (scanf("%d", &choice) != 1) {
    printf("Error: Invalid input. Please enter a number.\n");
while (getchar() != '\n');
    continue;
    }

switch (choice) {
    case 1:
        printf("Current Balance: $%.2f\n", balance);
        break;

    case 2:
        printf("Enter amount to deposit: ");
        if (scanf("%lf", &amount) != 1) {
            printf("Error: Invalid input.\n");
            while (getchar() != '\n');
            break;
            }
        if (amount <= 0) {
            printf("Error: Deposit amount must be positive.\n");
        } else {
             balance += amount;
            printf("Success! New balance: $%.2f\n", balance);
            }
        break;

    case 3:
        printf("Enter amount to withdraw: ");
        if (scanf("%lf", &amount) != 1) {
            printf("Error: Invalid input.\n");
            while (getchar() != '\n');
            break;
            }
        if (amount <= 0) {
            printf("Error: Withdrawal amount must be positive.\n");
        } else if (amount > balance) {
            printf("Error: Insufficient funds.\n");
            } else {
            balance -= amount;
            printf("Success! New balance: $%.2f\n", balance);
            }
             break;

    case 4:
        printf("Thank you for using our ATM\n");
        running = 0;
        break;

    default:
    printf("Error: Invalid option. Please choose 1-4.\n");
        break;
        }
    }

    return 0;
}