//IDAH AMONDI OMONDI
//ENE212-0095/2021

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int main() {
    char operation[10]; 
    int a, b;
    char choice[3]; 

    while (true) {
        printf("Enter the first number: ");
        scanf("%d", &a);
        printf("Enter the second number: ");
        scanf("%d", &b);

        printf("Do you want to add or subtract? Enter 'add' or 'sub': ");
        scanf("%s", operation);

        if (strcmp(operation, "sub") == 0) { 
            printf("Subtraction result is %d\n", subtract(a, b));
        } else if (strcmp(operation, "add") == 0) { 
            printf("Addition result is %d\n", add(a, b));
        } else {
            printf("Invalid operation choice!\n");
            continue;
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
