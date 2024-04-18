//ENE212-0095/2021
//IDAH AMONDI OMONDI 

#include <stdio.h>
#include <stdlib.h>

void removeData(FILE *file) {    
    freopen(NULL, "w", file);
}

void overwriteData(FILE *file) {
    fflush(stdin);
    printf("Enter new content to overwrite: ");
    char buffer[100];
    fgets(buffer, sizeof(buffer), stdin);
    fprintf(file, "%s", buffer);
}

void appendData(FILE *file) {
    fflush(stdin);
    printf("Enter additional content to append: ");
    char buffer[100];
    fgets(buffer, sizeof(buffer), stdin);
    fprintf(file, "%s", buffer);
}

int main() {
    FILE *inputFile, *outputFile;
    char buffer[100];
    inputFile = fopen("input.txt", "w");
    if (inputFile == NULL) {
        printf("Error creating input.txt\n");
        return 1;
    }
    printf("Enter initial content for input.txt: ");
    fgets(buffer, sizeof(buffer), stdin);
    fprintf(inputFile, "%s", buffer);
    fclose(inputFile);

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input.txt\n");
        return 1;
    }

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error creating output.txt\n");
        fclose(inputFile);
        return 1;
    }

    printf("Content copied from input.txt to output.txt:\n");
    while (fgets(buffer, sizeof(buffer), inputFile) != NULL) {
        printf("%s", buffer); 
        fprintf(outputFile, "%s", buffer); 
    }

    fclose(inputFile);
    fclose(outputFile);

    // Manipulation of input file
    int choice;
    printf("\nOptions for input.txt:\n");
    printf("1. Remove all data\n");
    printf("2. Overwrite data\n");
    printf("3. Append data\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    inputFile = fopen("input.txt", "a+"); //append mode
    if (inputFile == NULL) {
        printf("Error opening input.txt\n");
        return 1;
    }

    switch (choice) {
        case 1:
            removeData(inputFile);
            printf("Data removed from input.txt\n");
            break;
        case 2:
            overwriteData(inputFile);
            printf("Data overwritten in input.txt\n");
            break;
        case 3:
            appendData(inputFile);
            printf("Data appended to input.txt\n");
            break;
        default:
            printf("Invalid choice\n");
    }

    fclose(inputFile);

    return 0;
}