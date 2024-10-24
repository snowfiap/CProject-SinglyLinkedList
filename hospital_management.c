#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Patient {
    int id;
    char name[50];
    int age;
    char disease[50];
    struct Patient* next;
};

struct Patient* head = NULL;

struct Patient* createPatient(int id, const char* name, int age, const char* disease) {
    struct Patient* new_patient = (struct Patient*)malloc(sizeof(struct Patient));
    new_patient->id = id;
    strcpy(new_patient->name, name);
    new_patient->age = age;
    strcpy(new_patient->disease, disease);
    new_patient->next = NULL;
    return new_patient;
}

void addPatient(int id, const char* name, int age, const char* disease) {
    struct Patient* new_patient = createPatient(id, name, age, disease);
    if (head == NULL) {
        head = new_patient;
    } else {
        struct Patient* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_patient;
    }
    printf("Patient added: ID: %d, Name: %s, Age: %d, Disease: %s\n", id, name, age, disease);
}

void displayPatients() {
    struct Patient* temp = head;
    if (temp == NULL) {
        printf("No patients found.\n");
        return;
    }
    printf("Patient List:\n");
    while (temp != NULL) {
        printf("ID: %d, Name: %s, Age: %d, Disease: %s\n", temp->id, temp->name, temp->age, temp->disease);
        temp = temp->next;
    }
}

void editPatient(int id) {
    struct Patient* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            char new_name[50];
            int new_age;
            char new_disease[50];
            printf("Editing patient ID: %d\n", temp->id);
            printf("Enter new Name: ");
            scanf("%s", new_name);
            printf("Enter new Age: ");
            scanf("%d", &new_age);
            printf("Enter new Disease: ");
            scanf("%s", new_disease);
            strcpy(temp->name, new_name);
            temp->age = new_age;
            strcpy(temp->disease, new_disease);
            printf("Patient updated.\n");
            return;
        }
        temp = temp->next;
    }
    printf("Patient with ID %d not found.\n", id);
}

void deletePatient(int id) {
    struct Patient* temp = head;
    struct Patient* prev = NULL;

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Patient with ID %d not found.\n", id);
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    printf("Patient with ID %d deleted.\n", id);
}

int main() {
    int choice, id, age;
    char name[50], disease[50];

    while (1) {
        printf("\nHospital Management System\n");
        printf("1. Add Patient\n");
        printf("2. Display Patients\n");
        printf("3. Edit Patient\n");
        printf("4. Delete Patient\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Age: ");
                scanf("%d", &age);
                printf("Enter Disease: ");
                scanf("%s", disease);
                addPatient(id, name, age, disease);
                break;
            case 2:
                displayPatients();
                break;
            case 3:
                printf("Enter ID of the patient to edit: ");
                scanf("%d", &id);
                editPatient(id);
                break;
            case 4:
                printf("Enter ID of the patient to delete: ");
                scanf("%d", &id);
                deletePatient(id);
                break;
            case 5:
                exit(0);
}
}
return 0;
}