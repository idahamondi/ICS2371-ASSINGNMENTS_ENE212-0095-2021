// IDAH AMONDI OMONDI
// ENE212-0095/2021

#include <stdio.h>
#include <stdbool.h>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

float divide(int a, int b) {
    if (b != 0) {
        return (float)a / b;
    } else {
        printf("Error: Division by zero\n");
        return 0;
    }
}

void checkGreater(int a, int b) {
    if (a > b) {
        printf("%d is greater than %d\n", a, b);
    } else if (b > a) {
        printf("%d is greater than %d\n", b, a);
    } else {
        printf("Both numbers are equal\n");
    }
}

void checkOddEven(int num) {
    if (num % 2 == 0) {
        printf("%d is even\n", num);
    } else {
        printf("%d is odd\n", num);
    }
}

int main() {
    char operation;
    int a, b;
    char choice;

    while (true) {
        printf("Enter the first number: ");
        scanf("%d", &a);
        printf("Enter the second number: ");
        scanf("%d", &b);

        printf("Do you want to perform:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("Enter your choice (1/2/3/4): ");
        scanf(" %c", &operation);

        int result;
        switch (operation) {
            case '1':
                result = add(a, b);
                printf("Addition result is %d\n", result);
                break;
            case '2':
                result = subtract(a, b);
                printf("Subtraction result is %d\n", result);
                break;
            case '3':
                result = multiply(a, b);
                printf("Multiplication result is %d\n", result);
                break;
            case '4':
                printf("Division result is %.2f\n", divide(a, b));
                break;
            default:
                printf("Invalid operation choice!\n");
                continue;
        }

        checkGreater(a, b);
        checkOddEven(a);
        checkOddEven(b);

        printf("\nDo you want to continue? Enter 'yes' or 'no': ");
        scanf(" %c", &choice);

        if (choice == 'no') {
            break;
        } else if (choice != 'yes') {
            printf("Invalid choice! Exiting...\n");
            break;
        }
    }

    return 0;
}
