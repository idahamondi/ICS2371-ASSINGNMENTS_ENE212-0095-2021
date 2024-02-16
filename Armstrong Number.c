// IDAH AMONDI OMONDI
// ENE212-0095/2021

#include <stdio.h>
#include <math.h>

// Function to calculate the number of digits in a number
int countDigits(int n) {
    int count = 0;
    while (n != 0) {
        n /= 10;
        count++;
    }
    return count;
}
// To check whether the number is armstrong
int isArmstrong(int n) {
    int originalNumber, remainder, result = 0, digits;

    originalNumber = n;

   
    digits = countDigits(n);

    // Calculate the sum of each digit raised to the power of the number of digits
    while (originalNumber != 0) {
        remainder = originalNumber % 10;
        result += pow(remainder, digits);
        originalNumber /= 10;
    }

    // Check if the result is equal to the original number
    if (result == n)
        return 1; // It's an Armstrong number
    else
        return 0; // It's not an Armstrong number
}

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (isArmstrong(n))
        printf("%d is an Armstrong number.\n", n);
    else
        printf("%d is not an Armstrong number.\n", n);

    return 0;
}