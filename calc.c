//IDAH AMONDI
//ENE212-0095/2021

#include <stdio.h>
#include <stdbool.h>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int main() {
    char c;
    int a, b;
    char s[] = "sub";
    char e[] = "add";
    char y[] = "yes";
    char n[] = "no";
    char ch[10];

    while (true) {
        printf("Enter the first number: ");
        scanf("%d", &a);
        printf("Enter the second number: ");
        scanf("%d", &b);

        printf("Do you want to add or subtract? Enter '%s' to subtract and '%s' to add: ", s, e);
        scanf(" %c", &c);

        if (c == s[0]) {
            printf("Subtraction is %d\n", subtract(a, b));
        } else {
            printf("Addition is %d\n", add(a, b));
        }

        printf("\nDo you want to continue? Enter yes/no: ");
        scanf("%s", ch);

        if (ch[0] == n[0]) {
            break;
        }
    }

    return 0;
}
