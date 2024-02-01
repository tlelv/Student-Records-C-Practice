#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void addRecord() {
    char name[100];
    char userAverage;
    int userID;
    char userMajor[100];

    Record *student = malloc(sizeof(Record));

    printf("\nEnter Name: ");
    scanf("%s", name);

    printf("\nEnter ID: ");
    scanf("%d", &userID);

    //BUG - Skips Average
    printf("\nEnter Average: ");
    scanf("%c", &userAverage);

    printf("\nEnter Major: ");
    scanf("%s", userMajor);

    strcpy (student->userName, name);
    student->userID = userID;
    student->userAverage = userAverage;
    strcpy (student->userMajor, userMajor);

    student->next = head;
    head = student;
};

void displayRecord() {
    Record *student = head;
    if (student == NULL) {
        printf("No records found");
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
    //free(Record);
    return 0;
}
