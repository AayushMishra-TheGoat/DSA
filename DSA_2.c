/*
Name: Aayush Mishra
PRN: 1262253653
Batch: A3
Btech CSE (CLOUD)
*/

#include <stdio.h>

void accept(int A[5][5], int r, int c);
void display(int A[5][5], int r, int c);
void simple_transpose(int A[26][3], int B[26][3]);
void fast_transpose(int A[26][3], int B[26][3]);

int main()
{
    int A[5][5];
    int r, c, B[26][3], T[26][3];
    int k, ch;

    printf("Enter the number of rows and columns: ");
    scanf("%d%d", &r, &c);

    if (r <= 0 || r > 5 || c <= 0 || c > 5)
    {
        printf("Invalid dimensions!\n");
        return 1;
    }

    printf("\nInput for Matrix:\n");
    accept(A, r, c);

    printf("\nOriginal Matrix:\n");
    display(A, r, c);

    B[0][0] = r;
    B[0][1] = c;
    k = 1;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (A[i][j] != 0)
            {
                B[k][0] = i;
                B[k][1] = j;
                B[k][2] = A[i][j];
                k++;
            }
        }
    }

    B[0][2] = k - 1;

    do
    {
        printf("\nMENU\n");
        printf("1. Simple Transpose\n");
        printf("2. Fast Transpose\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                simple_transpose(B, T);

                printf("\nSimple Transpose:\n");
                printf("Row\tCol\tValue\n");

                for (int i = 0; i <= T[0][2]; i++)
                    printf("%d\t%d\t%d\n",
                           T[i][0], T[i][1], T[i][2]);
                break;

            case 2:
                fast_transpose(B, T);

                printf("\nFast Transpose:\n");
                printf("Row\tCol\tValue\n");

                for (int i = 0; i <= T[0][2]; i++)
                    printf("%d\t%d\t%d\n",
                           T[i][0], T[i][1], T[i][2]);
                break;

            case 3:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (ch != 3);

    return 0;
}

void accept(int A[5][5], int r, int c)
{
    printf("Enter elements:\n");

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
}

void display(int A[5][5], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            printf("%d\t", A[i][j]);

        printf("\n");
    }
}

void simple_transpose(int A[26][3], int B[26][3])
{
    int numofc, numofterms, next, c, term;

    B[0][0] = A[0][1];
    B[0][1] = A[0][0];
    B[0][2] = A[0][2];

    numofterms = A[0][2];
    numofc = A[0][1];

    next = 1;

    for (c = 0; c < numofc; c++)
    {
        for (term = 1; term <= numofterms; term++)
        {
            if (A[term][1] == c)
            {
                B[next][0] = A[term][1];
                B[next][1] = A[term][0];
                B[next][2] = A[term][2];
                next++;
            }
        }
    }
}

void fast_transpose(int A[26][3], int B[26][3])
{
    int m = A[0][0];
    int n = A[0][1];
    int t = A[0][2];

    int S[26] = {0};
    int T[26] = {0};

    B[0][0] = n;
    B[0][1] = m;
    B[0][2] = t;

    if (t == 0)
        return;

    for (int i = 1; i <= t; i++)
        S[A[i][1]]++;

    T[0] = 1;

    for (int i = 1; i < n; i++)
        T[i] = T[i - 1] + S[i - 1];

    for (int i = 1; i <= t; i++)
    {
        int j = A[i][1];
        int pos = T[j];

        B[pos][0] = A[i][1];
        B[pos][1] = A[i][0];
        B[pos][2] = A[i][2];

        T[j]++;
    }
}


/*Enter the number of rows and columns: 3 3

Input for Matrix:
Enter elements:
Element [0][0]: 0
Element [0][1]: 0
Element [0][2]: 3
Element [1][0]: 0
Element [1][1]: 4
Element [1][2]: 0
Element [2][0]: 5
Element [2][1]: 0
Element [2][2]: 0

Original Matrix:
0       0       3
0       4       0
5       0       0

----- MENU -----
1. Simple Transpose
2. Fast Transpose
3. Exit
Enter your choice: 1

Simple Transpose:
Row     Col     Value
3       3       3
0       2       5
1       1       4
2       0       3

----- MENU -----
1. Simple Transpose
2. Fast Transpose
3. Exit
Enter your choice: 2

Fast Transpose:
Row     Col     Value
3       3       3
0       2       5
1       1       4
2       0       3

Exiting program.
*/