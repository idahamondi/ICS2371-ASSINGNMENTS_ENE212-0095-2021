//IDAH AMONDI OMONDI 
//ENE212-0095/2021

#include <stdio.h>

#define ROWS_MATRIX_1 2
#define COLS_MATRIX_1 3
#define ROWS_MATRIX_2 3
#define COLS_MATRIX_2 2

int main() {
    int i, j, k;
    int matrix1[ROWS_MATRIX_1][COLS_MATRIX_1], matrix2[ROWS_MATRIX_2][COLS_MATRIX_2], result[ROWS_MATRIX_1][COLS_MATRIX_2];

    printf("Enter elements for First Matrix:\n");
    for (i = 0; i < ROWS_MATRIX_1; i++) {
        for (j = 0; j < COLS_MATRIX_1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter elements for Second Matrix:\n");
    for (i = 0; i < ROWS_MATRIX_2; i++) {
        for (j = 0; j < COLS_MATRIX_2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    printf("First Matrix:\n");
    for (i = 0; i < ROWS_MATRIX_1; i++) {
        for (j = 0; j < COLS_MATRIX_1; j++) {
            printf("%d\t", matrix1[i][j]);
        }
        printf("\n");
    }

    printf("Second Matrix:\n");
    for (i = 0; i < ROWS_MATRIX_2; i++) {
        for (j = 0; j < COLS_MATRIX_2; j++) {
            printf("%d\t", matrix2[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < ROWS_MATRIX_1; i++) {
        for (j = 0; j < COLS_MATRIX_2; j++) {
            result[i][j] = 0;
            for (k = 0; k < COLS_MATRIX_1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    printf("Resultant matrix after multiplication:\n");
    for (i = 0; i < ROWS_MATRIX_1; i++) {
        for (j = 0; j < COLS_MATRIX_2; j++) {
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
