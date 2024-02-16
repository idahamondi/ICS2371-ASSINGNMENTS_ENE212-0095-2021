// IDAH AMONDI OMONDI
// ENE212-0095/2021
#include <stdio.h>

// Function to check if a number is a palindrome
int isPalindrome(int n) {
    int original = n, reversed = 0, remainder;

    // Reverse the number
    while (n != 0) {
        remainder = n % 10;
        reversed = reversed * 10 + remainder;
        n /= 10;
    }

    // Check if the original number and reversed number are the same
    if (original == reversed)
        return 1; // It's a palindrome
    else
        return 0; // It's not a palindrome
}

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (isPalindrome(n))
        printf("%d is a palindrome.\n", n);
    else
        printf("%d is not a palindrome.\n", n);

    return 0;
}