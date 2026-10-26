/*
Name: Aayush Mishra
PRN: 1262253653
Batch: A3
Btech CSE (CLOUD)
*/

#include <stdio.h>
#include <string.h>

struct Student {
    int roll_no;
    char name[50];
    float m1, m2, m3;
    float percentage;
};

// Search Functions
int linear_search(struct Student students[], int size, int target_roll);
int binary_search(struct Student students[], int size, int target_roll);

// Sorting Functions
void selection_sort(struct Student students[], int size);
void insertion_sort(struct Student students[], int size);
void shell_sort(struct Student students[], int size);

// Utility Functions
void display_students(struct Student students[], int size);
void display_record(struct Student s);

int main() {
    int size = 2; // Adjustable size
    struct Student students[2];
    int choice, target_roll, result_index;
    int is_sorted = 0; // Tracks if array is sorted for binary search

    printf("=== Enter Details for %d Students ===\n", size);
    for (int i = 0; i < size; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Enter Roll Number: ");
        scanf("%d", &students[i].roll_no);
        printf("Enter Name: ");
        scanf("%s", students[i].name);
        
        printf("Enter Marks 1: ");
        scanf("%f", &students[i].m1);
        
        printf("Enter Marks 2: ");
        scanf("%f", &students[i].m2);
        
        printf("Enter Marks 3: ");
        scanf("%f", &students[i].m3);
        
        // Automatic percentage calculation (assuming total per subject is 100)
        students[i].percentage = (students[i].m1 + students[i].m2 + students[i].m3) / 3.0f;
        printf("Calculated Percentage: %.2f%%\n", students[i].percentage);
    }

    while (1) {
        printf("\n================ MENU ================\n");
        printf("1. Display All Records\n");
        printf("2. Linear Search\n");
        printf("3. Binary Search\n");
        printf("4. Selection Sort\n");
        printf("5. Insertion Sort\n");
        printf("6. Shell Sort\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_students(students, size);
                break;

            case 2:
                printf("\nEnter Roll Number to search: ");
                scanf("%d", &target_roll);
                result_index = linear_search(students, size, target_roll);
                if (result_index != -1) {
                    printf("\nRecord Found!");
                    display_record(students[result_index]);
                } else {
                    printf("\nStudent with Roll Number %d not found.\n", target_roll);
                }
                break;

            case 3:
                if (!is_sorted) {
                    printf("\n[Warning] Binary search requires records to be sorted by Roll No first.");
                    printf("\nSorting automatically using Selection Sort...\n");
                    selection_sort(students, size);
                    is_sorted = 1;
                }
                printf("\nEnter Roll Number to search: ");
                scanf("%d", &target_roll);
                result_index = binary_search(students, size, target_roll);
                if (result_index != -1) {
                    printf("\nRecord Found!");
                    display_record(students[result_index]);
                } else {
                    printf("\nStudent with Roll Number %d not found.\n", target_roll);
                }
                break;

            case 4:
                selection_sort(students, size);
                is_sorted = 1;
                printf("\nArray sorted using Selection Sort!\n");
                display_students(students, size);
                break;

            case 5:
                insertion_sort(students, size);
                is_sorted = 1;
                printf("\nArray sorted using Insertion Sort!\n");
                display_students(students, size);
                break;

            case 6:
                shell_sort(students, size);
                is_sorted = 1;
                printf("\nArray sorted using Shell Sort!\n");
                display_students(students, size);
                break;

            case 7:
                printf("\nExiting program. Goodbye!\n");
                return 0;

            default:
                printf("\nInvalid choice! Please select between 1 and 7.\n");
        }
    }

    return 0;
}

// Linear Search Implementation
int linear_search(struct Student students[], int size, int target_roll) {
    for (int i = 0; i < size; i++) {
        if (students[i].roll_no == target_roll) {
            return i;
        }
    }
    return -1;
}

// Binary Search Implementation (Requires sorted array)
int binary_search(struct Student students[], int size, int target_roll) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (students[mid].roll_no == target_roll) {
            return mid;
        }
        if (students[mid].roll_no < target_roll) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

// Selection Sort Implementation
void selection_sort(struct Student students[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (students[j].roll_no < students[min_idx].roll_no) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            struct Student temp = students[i];
            students[i] = students[min_idx];
            students[min_idx] = temp;
        }
    }
}

// Insertion Sort Implementation
void insertion_sort(struct Student students[], int size) {
    for (int i = 1; i < size; i++) {
        struct Student key = students[i];
        int j = i - 1;
        while (j >= 0 && students[j].roll_no > key.roll_no) {
            students[j + 1] = students[j];
            j--;
        }
        students[j + 1] = key;
    }
}

// Shell Sort Implementation
void shell_sort(struct Student students[], int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            struct Student temp = students[i];
            int j;
            for (j = i; j >= gap && students[j - gap].roll_no > temp.roll_no; j -= gap) {
                students[j] = students[j - gap];
            }
            students[j] = temp;
        }
    }
}

// Helper: Display single record
void display_record(struct Student s) {
    printf("\n-------------------------\n");
    printf("Roll No    : %d\n", s.roll_no);
    printf("Name       : %s\n", s.name);
    printf("Marks 1    : %.2f\n", s.m1);
    printf("Marks 2    : %.2f\n", s.m2);
    printf("Marks 3    : %.2f\n", s.m3);
    printf("Percentage : %.2f%%\n", s.percentage);
    printf("-------------------------\n");
}

// Helper: Display array of students
void display_students(struct Student students[], int size) {
    printf("\n=== Student Records ===");
    for (int i = 0; i < size; i++) {
        display_record(students[i]);
    }
}

/*$ 

=== Enter Details for 2 Students ===

Student 1:
Enter Roll Number: 101
Enter Name: Amit
Enter Marks 1: 80
Enter Marks 2: 85
Enter Marks 3: 90
Calculated Percentage: 85.00%

Student 2:
Enter Roll Number: 102
Enter Name: Rahul
Enter Marks 1: 75
Enter Marks 2: 80
Enter Marks 3: 85
Calculated Percentage: 80.00%

================ MENU ================
1. Display All Records
2. Linear Search
3. Binary Search
4. Selection Sort
5. Insertion Sort
6. Shell Sort
7. Exit
Enter your choice: 1

=== Student Records ===
-------------------------
Roll No    : 101
Name       : Amit
Marks 1    : 80.00
Marks 2    : 85.00
Marks 3    : 90.00
Percentage : 85.00%
-------------------------

-------------------------
Roll No    : 102
Name       : Rahul
Marks 1    : 75.00
Marks 2    : 80.00
Marks 3    : 85.00
Percentage : 80.00%
-------------------------

================ MENU ================
Enter your choice: 7

Exiting program. Goodbye!
$
*/