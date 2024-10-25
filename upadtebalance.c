#include <stdio.h>

typedef struct {
    float balance;
} BankAccount;

void deposit(BankAccount *account, float amount) {
    if (amount > 0) {
        account->balance += amount;
        printf("Deposited $%.2f. New balance: $%.2f\n", amount, account->balance);
    } else {
        printf("Invalid deposit amount.\n");
    }
}

void withdraw(BankAccount *account, float amount) {
    if (amount > 0 && amount <= account->balance) {
        account->balance -= amount;
        printf("Withdrew $%.2f. New balance: $%.2f\n", amount, account->balance);
    } else if (amount <= 0) {
        printf("Invalid withdrawal amount.\n");
    } else {
        printf("Insufficient funds.\n");
    }
}

void check_balance(BankAccount *account) {
    printf("Current balance: $%.2f\n", account->balance);
}

int main() {
    BankAccount account = {0}; // Initialize account with a balance of 0
    int choice;
    float amount;

    while (1) {
        printf("\nBank Account Menu:\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Check Balance\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter deposit amount: ");
                scanf("%f", &amount);
                deposit(&account, amount);
                break;
            case 2:
                printf("Enter withdrawal amount: ");
                scanf("%f", &amount);
                withdraw(&account, amount);
                break;
            case 3:
                check_balance(&account);
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
