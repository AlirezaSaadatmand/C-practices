#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10

// Data structure for user information
typedef struct {
    char cardNumber[17];
    char pin[5];
    double balance;
} User;

// Global variables
User users[MAX_USERS];
int userCount = 0;

// Function declarations
int login(int *userIndex);
void checkBalance(int userIndex);
void withdrawMoney(int userIndex);
void depositMoney(int userIndex);
void changePin(int userIndex);
void saveDataToTextFile();
int loadDataFromTextFile();

// Main program
int main() {
    int choice, userIndex;

    // Load data from text file
    if (!loadDataFromTextFile()){
        return 0;
    }

    printf("Welcome to the ATM System!\n");

    if (!login(&userIndex)) {
        printf("Invalid card number or PIN. Exiting.\n");
        return 0;
    }

    do {
        printf("\nMain Menu:\n");
        printf("1. Check Balance\n");
        printf("2. Withdraw Money\n");
        printf("3. Deposit Money\n");
        printf("4. Change PIN\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                checkBalance(userIndex);
                break;
            case 2:
                withdrawMoney(userIndex);
                break;
            case 3:
                depositMoney(userIndex);
                break;
            case 4:
                changePin(userIndex);
                break;
            case 5:
                printf("Thank you for using the ATM. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
        printf("--------------------------------------");
    } while (choice != 5);

    // Save data to text file
    saveDataToTextFile();

    return 0;
}

// User login function
int login(int *userIndex) {
    char cardNumber[16], pin[5];

    printf("Enter card number: ");
    scanf("%s", cardNumber);
    printf("Enter PIN: ");
    scanf("%s", pin);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].cardNumber, cardNumber) == 0 && strcmp(users[i].pin, pin) == 0) {
            *userIndex = i;
            return 1;
        }
    }
    return 0;
}

// Check balance function
void checkBalance(int userIndex) {
    printf("Your current balance is: %.2f\n", users[userIndex].balance);
}

// Withdraw money function
void withdrawMoney(int userIndex) {
    double amount;
    printf("Enter the amount to withdraw: ");
    scanf("%lf", &amount);

    if (amount > users[userIndex].balance) {
        printf("Insufficient balance.\n");
    } else {
        users[userIndex].balance -= amount;
        printf("Withdrawal successful. New balance: %.2f\n", users[userIndex].balance);
    }
}

// Deposit money function
void depositMoney(int userIndex) {
    double amount;
    printf("Enter the amount to deposit: ");
    scanf("%lf", &amount);

    users[userIndex].balance += amount;
    printf("Deposit successful. New balance: %.2f\n", users[userIndex].balance);
}

// Change PIN function
void changePin(int userIndex) {
    char newPin[5];
    printf("Enter new PIN (4 digits): ");
    scanf("%s", newPin);

    if (strlen(newPin) == 4) {
        strcpy(users[userIndex].pin, newPin);
        printf("PIN changed successfully.\n");
    } else {
        printf("Invalid PIN format. Must be 4 digits.\n");
    }
}

// Save data to a text file
void saveDataToTextFile() {
    FILE *file = fopen("users.txt", "w");
    if (file) {
        for (int i = 0; i < userCount; i++) {
            fprintf(file, "%s %s %.2f\n", users[i].cardNumber, users[i].pin, users[i].balance);
        }
        fclose(file);
    } else {
        printf("Error saving data.\n");
    }
}

// Load data from a text file
int loadDataFromTextFile() {
    FILE *file = fopen("users.txt", "r");
    if (file) {
        userCount = 0;
        while (fscanf(file, "%s %s %lf", users[userCount].cardNumber, users[userCount].pin, &users[userCount].balance) == 3) {
            userCount++;
        }
        fclose(file);
        return 1;
    } else {
        printf("No data file found. Starting with default users.\n");
        return 0;
    }
}
