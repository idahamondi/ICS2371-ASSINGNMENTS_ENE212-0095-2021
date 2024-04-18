//ENE212-0095/2021
//IDAH AMONDI OMONDI 

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int size = 10;
    int arr[size], temp[size];
    int insertVal, insertPos, removePos;

    // Initialize the array with random numbers
    printf("Original Array: ");
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; 
        printf("%d ", arr[i]);
        temp[i] = arr[i];
    }
    printf("\n");

    printf("Enter a value to insert: ");
    scanf("%d", &insertVal);
    printf("Enter the position to insert: ");
    scanf("%d", &insertPos);

    for (int i = size - 1; i >= insertPos; i--) {
        temp[i] = temp[i - 1];
    }
    temp[insertPos] = insertVal;

    printf("Array after insertion: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", temp[i]);
    }
    printf("\n");

    qsort(temp, size, sizeof(int), compare);

    printf("Array after sorting: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", temp[i]);
    }
    printf("\n");

    printf("Enter the position to remove an element: ");
    scanf("%d", &removePos);
    for (int i = removePos; i < size - 1; i++) {
        temp[i] = temp[i + 1];
    }
    temp[size - 1] = 0;

    printf("Array after removal: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", temp[i]);
    }
    printf("\n");

    return 0;
}