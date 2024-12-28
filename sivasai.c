#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

// Define structure for student record
typedef struct {
    int rollNumber;
    char name[50];
    char course[50];
    float marks;
} Student;

// Function to add a new student record
void addStudentRecord(Student *students, int *size) {
    if (*size < MAX_STUDENTS) {
        printf("Enter roll number: ");
        scanf("%d", &students[*size].rollNumber);
        printf("Enter name: ");
        scanf("%s", students[*size].name);
        printf("Enter course: ");
        scanf("%s", students[*size].course);
        printf("Enter marks: ");
        scanf("%f", &students[*size].marks);
        (*size)++;
        printf("Student record added successfully!\n");
    } else {
        printf("Maximum number of students reached!\n");
    }
}

// Function to display all student records
void displayStudentRecords(Student *students, int size) {
    if (size == 0) {
        printf("No student records found!\n");
    } else {
        printf("Roll Number\tName\tCourse\tMarks\n");
        for (int i = 0; i < size; i++) {
            printf("%d\t\t%s\t%s\t%.2f\n", students[i].rollNumber, students[i].name, students[i].course, students[i].marks);
        }
    }
}

// Function to search for a specific student record
void searchStudentRecord(Student *students, int size) {
    int rollNumber;
    printf("Enter roll number to search: ");
    scanf("%d", &rollNumber);
    for (int i = 0; i < size; i++) {
        if (students[i].rollNumber == rollNumber) {
            printf("Student record found:\n");
            printf("Roll Number: %d\n", students[i].rollNumber);
            printf("Name: %s\n", students[i].name);
            printf("Course: %s\n", students[i].course);
            printf("Marks: %.2f\n", students[i].marks);
            return;
        }
    }
    printf("Student record not found!\n");
}

// Function to update an existing student record
void updateStudentRecord(Student *students, int size) {
    int rollNumber;
    printf("Enter roll number to update: ");
    scanf("%d", &rollNumber);
    for (int i = 0; i < size; i++) {
        if (students[i].rollNumber == rollNumber) {
            printf("Enter new name: ");
            scanf("%s", students[i].name);
            printf("Enter new course: ");
            scanf("%s", students[i].course);
            printf("Enter new marks: ");
            scanf("%f", &students[i].marks);
            printf("Student record updated successfully!\n");
            return;
        }
    }
    printf("Student record not found!\n");
}

// Function to delete a student record
void deleteStudentRecord(Student *students, int *size) {
    int rollNumber;
    printf("Enter roll number to delete: ");
    scanf("%d", &rollNumber);
    for (int i = 0; i < *size; i++) {
        if (students[i].rollNumber == rollNumber) {
            for (int j = i; j < *size - 1; j++) {
                students[j] = students[j + 1];
            }
            (*size)--;
            printf("Student record deleted successfully!\n");
            return;
        }
    }
    printf("Student record not found!\n");
}

int main() {
    Student students[MAX_STUDENTS];
    int size = 0;

    while (1) {
        printf("Student Record Management System\n");
        printf("1. Add Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Search Student Record\n");
        printf("4. Update Student Record\n");
        printf("5. Delete Student Record\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudentRecord(students, &size);
                break;
            case 2:
                displayStudentRecords(students, size);
                break;
            case 3:
                searchStudentRecord(students, size);
                break;
            case 4:
                updateStudentRecord(students, size);
                break;
            case 5:
                deleteStudentRecord(students, &size);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }