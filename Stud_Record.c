#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll_no;
    char name[50];
    struct Student* next;
};

struct Student* head = NULL;

// Function to create a new student node
struct Student* createStudent(int roll_no, const char* name) {
    struct Student* new_student = (struct Student*)malloc(sizeof(struct Student));
    new_student->roll_no = roll_no;
    strcpy(new_student->name, name);
    new_student->next = NULL;
    return new_student;
}

// Function to add a student at the end of the list
void addStudent(int roll_no, const char* name) {
    struct Student* new_student = createStudent(roll_no, name);
    if (head == NULL) {
        head = new_student;
    } else {
        struct Student* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_student;
    }
    printf("Student added: %d, %s\n", roll_no, name);
}

// Function to display all students
void displayStudents() {
    struct Student* temp = head;
    if (temp == NULL) {
        printf("No records found.\n");
        return;
    }
    printf("Student Records:\n");
    while (temp != NULL) {
        printf("Roll No: %d, Name: %s\n", temp->roll_no, temp->name);
        temp = temp->next;
    }
}

// Function to delete a student by roll number
void deleteStudent(int roll_no) {
    struct Student* temp = head;
    struct Student* prev = NULL;

    // If head node itself holds the roll_no to be deleted
    if (temp != NULL && temp->roll_no == roll_no) {
        head = temp->next; // Changed head
        free(temp); // Free old head
        printf("Student with roll no %d deleted.\n", roll_no);
        return;
    }

    // Search for the roll_no to be deleted
    while (temp != NULL && temp->roll_no != roll_no) {
        prev = temp;
        temp = temp->next;
    }

    // If roll_no was not present in the linked list
    if (temp == NULL) {
        printf("Student with roll no %d not found.\n", roll_no);
        return;
    }

    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp); // Free memory
    printf("Student with roll no %d deleted.\n", roll_no);
}

// Main function
int main() {
    int choice, roll_no;
    char name[50];

    while (1) {
        printf("\nStudent Record System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Delete Student\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Roll No: ");
                scanf("%d", &roll_no);
                printf("Enter Name: ");
                scanf("%s", name);
                addStudent(roll_no, name);
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                printf("Enter Roll No to delete: ");
                scanf("%d", &roll_no);
                deleteStudent(roll_no);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
