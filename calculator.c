#include <stdio.h>
#include <stdbool.h>
#include <string.h> 

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

int main() {
    char operation[10];
    int a, b;
    char choice[4]; 

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
        scanf("%s", operation);

        if (strcmp(operation, "1") == 0) {
            printf("Addition result is %d\n", add(a, b));
        } else if (strcmp(operation, "2") == 0) {
            printf("Subtraction result is %d\n", subtract(a, b));
        } else if (strcmp(operation, "3") == 0) {
            printf("Multiplication result is %d\n", multiply(a, b));
        } else if (strcmp(operation, "4") == 0) {
            printf("Division result is %.2f\n", divide(a, b));
        } else {
            printf("Invalid operation choice!\n");
            continue;
        }

        // Check which number is greater
        if (a > b) {
            printf("%d is greater than %d\n", a, b);
        } else if (b > a) {
            printf("%d is greater than %d\n", b, a);
        } else {
            printf("Both numbers are equal\n");
        }

        // Check if numbers are odd or even
        if (a % 2 == 0) {
            printf("%d is even\n", a);
        } else {
            printf("%d is odd\n", a);
        }
        if (b % 2 == 0) {
            printf("%d is even\n", b);
        } else {
            printf("%d is odd\n", b);
        }

        printf("\nDo you want to continue? Enter 'yes' or 'no': ");
        scanf("%s", choice);

        if (strcmp(choice, "no") == 0) {
            break;
        } else if (strcmp(choice, "yes") != 0) {
            printf("Invalid choice! Exiting...\n");
            break; 
        }
    }

    return 0;
}