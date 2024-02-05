#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Record {
    char userName[100];
    int userID;
    char userAverage;
    char userMajor[100];
    struct Record *next;
} Record;

Record *head = NULL;

int displayMenu() {
    int myNum;
    printf("        Welcome to RU Record Management\n\n");
    printf("    Press\n");
    printf("    1 to create a new Student Record\n");
    printf("    2 to view all records\n");
    printf("    3 to exit\n\n");

    printf("Enter your Choice (ONLY DIGITS): \n");
    scanf("%d", &myNum);
    while (myNum < 1 || myNum > 3) {
        printf("That is not a valid choice\n Enter your Choice: \n");
        scanf("%d", &myNum);
    }
    return myNum;
}

int findRecord(Record node) {
    Record *student = head;
    int checkStatus = 0;

    while (student != NULL) {
        if (node.userID == student->userID) {
            checkStatus = 1;
        }
        student = student->next;
    }
    return checkStatus;
}

void addRecord() {
    char name[100];
    char userAverage;
    int userID;
    char userMajor[100];

    Record *student = malloc(sizeof(Record));

    printf("\nEnter Name: ");
    scanf(" %s", name);
    strcpy (student->userName, name);

    printf("Enter ID: ");
    scanf(" %d", &userID);
    student->userID = userID;
    if (findRecord(*student) == 1) {
        printf("Record already exists\n");
        printf("\n");
    }
    else {
        printf("Enter Average: ");
        scanf(" %c", &userAverage);
        student->userAverage = userAverage;

        printf("Enter Major: ");
        scanf(" %s", userMajor);
        strcpy (student->userMajor, userMajor);

        printf("\n");
        student->next = head;
        head = student;
    }
}

void displayRecord() {
    Record *student = head;
    printf("\n");
    if (student == NULL) {
        printf("\nNo records found\n");
    }
    while (student != NULL) {
        printf("%s, ", student->userName);
        printf("%d, ", student->userID);
        printf("%c, ", student->userAverage);
        printf("%s.\n", student->userMajor);
        student = student->next;
    }
    printf("\n");
}

int main() {
    int myNum;
    myNum = displayMenu();
    while (myNum != 3) {
        if (myNum == 1) {
            addRecord();
            myNum = displayMenu();
        }
        if (myNum == 2) {
            displayRecord();
            myNum = displayMenu();
        }
    }
    free(head);
    return 0;
}
