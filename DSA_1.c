/*
Name: Aayush Mishra
PRN: 1262253653
Batch: A3
Btech CSE (CLOUD)
*/


#include <stdio.h>

void accept(int m[10][10], int r, int c);
void display(int m[10][10], int r, int c);
void add(int m1[10][10], int m2[10][10], int r, int c);
void sub(int m1[10][10], int m2[10][10], int r, int c);
void multiply(int m1[10][10], int m2[10][10],
              int r1, int c1, int c2);
void trans(int m1[10][10], int r, int c);

int main(void)
{
    int m1[10][10], m2[10][10];
    int r, c, ch;

    printf("Enter the number of rows and columns for the matrices: ");
    scanf("%d%d", &r, &c);

    if (r < 1 || r > 10 || c < 1 || c > 10)
    {
        printf("Invalid matrix dimensions!\n");
        return 1;
    }

    printf("\nInput for Matrix 1:\n");
    accept(m1, r, c);

    printf("\nInput for Matrix 2:\n");
    accept(m2, r, c);

    printf("\nMatrix Operation Menu:");
    printf("\n1. Addition");
    printf("\n2. Subtraction");
    printf("\n3. Multiplication");
    printf("\n4. Transpose (Matrix 1)");
    printf("\nEnter your choice (from 1 to 4): ");
    scanf("%d", &ch);

    switch (ch)
    {
        case 1:
            add(m1, m2, r, c);
            break;

        case 2:
            sub(m1, m2, r, c);
            break;

        case 3:
            multiply(m1, m2, r, c, c);
            break;

        case 4:
            trans(m1, r, c);
            break;

        default:
            printf("\nInvalid choice!\n");
    }

    return 0;
}

void accept(int m[10][10], int r, int c)
{
    printf("Enter elements:\n");

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }
}

void display(int m[10][10], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            printf("%d\t", m[i][j]);

        printf("\n");
    }
}

void add(int m1[10][10], int m2[10][10], int r, int c)
{
    int sum[10][10];

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            sum[i][j] = m1[i][j] + m2[i][j];

    printf("\nResult of Addition:\n");
    display(sum, r, c);
}

void sub(int m1[10][10], int m2[10][10], int r, int c)
{
    int diff[10][10];

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            diff[i][j] = m1[i][j] - m2[i][j];

    printf("\nResultant Matrix (Subtraction):\n");
    display(diff, r, c);
}

void multiply(int m1[10][10], int m2[10][10],
              int r1, int c1, int c2)
{
    int prod[10][10] = {0};

    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            for (int k = 0; k < c1; k++)
                prod[i][j] += m1[i][k] * m2[k][j];

    printf("\nResultant Matrix (Multiplication):\n");
    display(prod, r1, c2);
}

void trans(int m1[10][10], int r, int c)
{
    int t[10][10];

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            t[j][i] = m1[i][j];

    printf("\nTranspose of Matrix 1:\n");
    display(t, c, r);
}


/*Enter the number of rows and columns for the matrices: 2 2

Input for Matrix 1:
Enter elements:
Element [0][0]: 1
Element [0][1]: 2
Element [1][0]: 3
Element [1][1]: 4

Input for Matrix 2:
Enter elements:
Element [0][0]: 5
Element [0][1]: 6
Element [1][0]: 7
Element [1][1]: 8

Matrix Operation Menu:
1. Addition
2. Subtraction
3. Multiplication
4. Transpose (Matrix 1)
Enter your choice (from 1 to 4): 1

Result of Addition:
6       8
10      12
*/
