//ENE212-0095/2021
//IDAH AMONDI OMONDI

#include <stdio.h>

#define NAME_SIZE 20
#define ID_SIZE 50
#define MAX_STUDENTS 5
#define MIN_COURSES 3
#define MAX_COURSES 8
#define COURSE_CODE_SIZE 5

struct StudentInfo {
    char first[NAME_SIZE];
    char last[NAME_SIZE];
    char id[ID_SIZE];
    int course_count;
    char courses[MAX_COURSES][COURSE_CODE_SIZE];
} students[MAX_STUDENTS];

void menu() {
    printf("\nSelect an option:\n");
    printf("1. Add a new student\n");
    printf("2. Edit existing student details\n");
    printf("3. Display all student details\n");
    printf("4. Exit\n");
}

void addStudent(int index) {
    int courses, attempts = 0;
    printf("Enter first name: ");
    scanf("%s", students[index].first);
    printf("Enter last name: ");
    scanf("%s", students[index].last);
    printf("Enter student ID: ");
    scanf("%s", students[index].id);
    printf("Enter the number of courses (minimum %d, maximum %d): ", MIN_COURSES, MAX_COURSES);
    scanf("%d", &courses);
    
    while(courses < MIN_COURSES || courses > MAX_COURSES) {
        attempts++;
        printf("Please enter a value between %d and %d: ", MIN_COURSES, MAX_COURSES);
        if(attempts == 3) {
            courses = MIN_COURSES;
            printf("Number of courses set to minimum.\n");
            break;
        }
        scanf("%d", &courses);
    }

    students[index].course_count = courses;
    for(int i = 0; i < courses; i++) {
        printf("Enter course %d code: ", i + 1);
        scanf("%s", students[index].courses[i]);
    }
    printf("-- Student details recorded! --\n");
}

void editStudent(int count) {
    int selection, option;
    printf("Available students: %d\n", count);
    printf("Enter the student number to edit: ");
    scanf("%d", &selection);

    while(!(selection > 0 && selection <= count)) {
        printf("Student not found!\n");
        scanf("%d", &selection);
    }
    selection--;

    printf("What do you want to edit?\n");
    printf("1. First Name\n");
    printf("2. Last Name\n");
    printf("3. Student ID\n");
    printf("4. Courses\n");
    scanf("%d", &option);

    switch(option) {
        case 1:
            printf("Enter new first name: ");
            scanf("%s", students[selection].first);
            break;
        case 2:
            printf("Enter new last name: ");
            scanf("%s", students[selection].last);
            break;
        case 3:
            printf("Enter new student ID: ");
            scanf("%s", students[selection].id);
            break;
        case 4:
            printf("Available courses:\n");
            for(int i = 0; i < students[selection].course_count; i++) {
                printf("%d. %s\n", i + 1, students[selection].courses[i]);
            }
            int courseNum;
            printf("Enter the course number to edit: ");
            scanf("%d", &courseNum);
            printf("Enter the new course code: ");
            scanf("%s", students[selection].courses[courseNum - 1]);
            break;
    }
}

void displayStudents(int count) {
    for(int i = 0; i < count; i++) {
        printf("----- Student %d Details -----\n", i + 1);
        printf("Name: %s %s\n", students[i].first, students[i].last);
        printf("ID: %s\n", students[i].id);
        printf("Courses:\n");
        for(int j = 0; j < students[i].course_count; j++) {
            printf("%d. %s\n", j + 1, students[i].courses[j]);
        }
        printf("-------------------------------\n");
    }
}

int main() {
    int choice = 3, studentCount = 0;

    printf("**** STUDENT DATABASE ****\n");
    printf("Enter details for the first student:\n");

    addStudent(studentCount);
    studentCount++;

    while(choice > 0 && choice <= 4) {
        menu();
        scanf("%d", &choice);
        if(choice > 0 && choice <= 4) {
            switch(choice) {
                case 1:
                    addStudent(studentCount);
                    studentCount++;
                    break;
                case 2:
                    editStudent(studentCount);
                    break;
                case 3:
                    displayStudents(studentCount);
                    break;
                case 4:
                    return 0;
            }
        }
        else {
            printf("Invalid option.\n");
        }
    }

    return 0;
}