/*
Name: Aayush Mishra
PRN: 1262253653
Batch: A3
Btech CSE (CLOUD)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int regNo;
    char name[50];
    struct node *next;
};

int len(struct node *H)
{
    int count = 0;
    struct node *curr = H->next;

    while (curr != NULL) {
        count++;
        curr = curr->next;
    }

    return count;
}

void create(struct node *H)
{
    struct node *temp = H;
    struct node *curr;
    char choice;

    do {
        curr = malloc(sizeof(struct node));

        if (curr == NULL) {
            printf("Memory allocation failed!\n");
            return;
        }

        printf("Enter Registration Number: ");
        if (scanf("%d", &curr->regNo) != 1) {
            free(curr);
            printf("Invalid input!\n");
            return;
        }

        printf("Enter Name: ");
        scanf(" %49[^\n]", curr->name);

        curr->next = NULL;
        temp->next = curr;
        temp = curr;

        printf("Do you want to add another student? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');
}

void display(struct node *H)
{
    struct node *curr = H->next;

    if (curr == NULL) {
        printf("\nList is empty\n");
        return;
    }

    printf("\n%-18s %-10s %-20s %-18s\n",
           "Node Address", "Reg No", "Name", "Next Address");
    printf("--------------------------------------------------------------------------\n");

    while (curr != NULL) {
        printf("%-18p %-10d %-20s %-18p\n",
               (void *)curr, curr->regNo, curr->name,
               (void *)curr->next);
        curr = curr->next;
    }
}

void sort(struct node *H)
{
    int l = len(H);

    if (l < 2) {
        printf("\nList sorted successfully!\n");
        return;
    }

    struct node *prev, *curr, *temp;

    for (int i = 1; i < l; i++) {
        prev = H;
        curr = H->next;

        for (int j = 0; j < l - i; j++) {
            temp = curr->next;

            if (curr->regNo > temp->regNo) {
                prev->next = temp;
                curr->next = temp->next;
                temp->next = curr;
                prev = temp;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
    }

    printf("\nList sorted successfully!\n");
}

void addStudent(struct node *H)
{
    struct node *curr = malloc(sizeof(struct node));
    struct node *temp;

    if (curr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter Registration Number: ");
    if (scanf("%d", &curr->regNo) != 1) {
        free(curr);
        printf("Invalid input!\n");
        return;
    }

    printf("Enter Name: ");
    scanf(" %49[^\n]", curr->name);

    curr->next = NULL;
    temp = H;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = curr;

    printf("Student added successfully!\n");
}

void removeStudent(struct node *H)
{
    int reg;
    struct node *prev = H;
    struct node *curr = H->next;

    printf("Enter Registration Number to remove: ");
    if (scanf("%d", &reg) != 1) {
        printf("Invalid input!\n");
        return;
    }

    while (curr != NULL && curr->regNo != reg) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Student not found!\n");
    } else {
        prev->next = curr->next;
        free(curr);
        printf("Student removed successfully!\n");
    }
}

void countStudents(struct node *H)
{
    printf("\nTotal Participants = %d\n", len(H));
}

void reverse(struct node *H)
{
    struct node *prev = NULL;
    struct node *curr = H->next;
    struct node *nextNode;

    while (curr != NULL) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    H->next = prev;
    printf("\nList reversed successfully!\n");
}

int main()
{
    struct node *head = malloc(sizeof(struct node));

    if (head == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    head->next = NULL;

    int choice;

    printf("Workshop Enrollment System\n");
    create(head);

    do {
        printf("\n\nWORKSHOP MENU\n");
        printf("1. Add a Student\n");
        printf("2. Remove a Student\n");
        printf("3. Display the List\n");
        printf("4. Count Total Participants\n");
        printf("5. Sort the List\n");
        printf("6. Reverse the List\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            break;
        }

        switch (choice) {
            case 1:
                addStudent(head);
                break;
            case 2:
                removeStudent(head);
                break;
            case 3:
                display(head);
                break;
            case 4:
                countStudents(head);
                break;
            case 5:
                sort(head);
                break;
            case 6:
                reverse(head);
                break;
            case 7:
                printf("Exiting Workshop Enrollment System.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 7);

    struct node *curr = head->next;

    while (curr != NULL) {
        struct node *temp = curr;
        curr = curr->next;
        free(temp);
    }

    free(head);
    return 0;
}


/*
Workshop Enrollment System
Enter Registration Number: 103
Enter Name: Rahul
Do you want to add another student? (y/n): y
Enter Registration Number: 101
Enter Name: Aman
Do you want to add another student? (y/n): y
Enter Registration Number: 102
Enter Name: Priya
Do you want to add another student? (y/n): n

WORKSHOP MENU
1. Add a Student
2. Remove a Student
3. Display the List
4. Count Total Participants
5. Sort the List
6. Reverse the List
7. Exit
Enter your choice: 4

Total Participants = 3

WORKSHOP MENU
Enter your choice: 5

List sorted successfully!

WORKSHOP MENU
Enter your choice: 3

Node Address       Reg No     Name                 Next Address
--------------------------------------------------------------------------
0x...              101        Aman                 0x...
0x...              102        Priya                0x...
0x...              103        Rahul                (nil)

WORKSHOP MENU
Enter your choice: 6

List reversed successfully!

WORKSHOP MENU
Enter your choice: 3

Node Address       Reg No     Name                 Next Address
--------------------------------------------------------------------------
0x...              0x...      Rahul                0x...
0x...              102        Priya                0x...
0x...              101        Aman                 (nil)

WORKSHOP MENU
Enter your choice: 7
Exiting Workshop Enrollment System.
*/