/*
Name: Aayush Mishra
PRN: 1262253653
Batch: A3
Btech CSE (CLOUD)
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int exp;
    struct node *next;
};

// Create polynomial using the CLL algorithm
int create(struct node *H)
{
    struct node *temp = H;
    struct node *curr;
    char choice;

    do
    {
        curr = (struct node *)malloc(sizeof(struct node));

        if (curr == NULL)
        {
            printf("Memory allocation failed!\n");
            return 0;
        }

        printf("Enter coefficient and exponent: ");

        if (scanf("%d %d", &curr->coeff, &curr->exp) != 2)
        {
            free(curr);
            printf("Invalid input!\n");
            return 0;
        }

        curr->next = H;
        temp->next = curr;
        temp = curr;

        printf("Add another term? (y/n): ");

        if (scanf(" %c", &choice) != 1)
        {
            printf("Invalid input!\n");
            return 0;
        }

    } while (choice == 'y' || choice == 'Y');

    return 1;
}

// Display polynomial
void display(struct node *H)
{
    struct node *curr = H->next;
    int first = 1;

    if (curr == H)
    {
        printf("0");
        return;
    }

    while (curr != H)
    {
        if (curr->coeff != 0)
        {
            long long magnitude = curr->coeff;
            if (magnitude < 0)
                magnitude = -magnitude;

            if (first)
            {
                if (curr->coeff < 0)
                    printf("-");
            }
            else
            {
                printf(curr->coeff < 0 ? " - " : " + ");
            }

            printf("%lldx^%d", magnitude, curr->exp);
            first = 0;
        }

        curr = curr->next;
    }

    if (first)
        printf("0");
}

// Insert term in descending exponent order
int insertTerm(struct node *H, int coeff, int exp)
{
    struct node *curr = H->next;
    struct node *prev = H;

    if (coeff == 0)
        return 1;

    while (curr != H && curr->exp > exp)
    {
        prev = curr;
        curr = curr->next;
    }

    // Combine terms with the same exponent
    if (curr != H && curr->exp == exp)
    {
        curr->coeff += coeff;
        return 1;
    }

    struct node *newNode =
        (struct node *)malloc(sizeof(struct node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return 0;
    }

    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = curr;
    prev->next = newNode;

    return 1;
}

// Add two polynomials
int add(struct node *P1, struct node *P2, struct node *R)
{
    struct node *curr;

    curr = P1->next;

    while (curr != P1)
    {
        if (!insertTerm(R, curr->coeff, curr->exp))
            return 0;

        curr = curr->next;
    }

    curr = P2->next;

    while (curr != P2)
    {
        if (!insertTerm(R, curr->coeff, curr->exp))
            return 0;

        curr = curr->next;
    }

    // Remove terms whose coefficients become zero
    struct node *prev = R;
    curr = R->next;

    while (curr != R)
    {
        if (curr->coeff == 0)
        {
            prev->next = curr->next;
            free(curr);
            curr = prev->next;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }

    return 1;
}

// Free the circular linked list, including its header
void freeList(struct node *H)
{
    if (H == NULL)
        return;

    struct node *curr = H->next;

    while (curr != H)
    {
        struct node *temp = curr;
        curr = curr->next;
        free(temp);
    }

    free(H);
}

int main()
{
    struct node *P1 = (struct node *)malloc(sizeof(struct node));
    struct node *P2 = (struct node *)malloc(sizeof(struct node));
    struct node *R = (struct node *)malloc(sizeof(struct node));

    if (P1 == NULL || P2 == NULL || R == NULL)
    {
        printf("Memory allocation failed!\n");
        free(P1);
        free(P2);
        free(R);
        return 1;
    }

    // Initialize circular header nodes
    P1->next = P1;
    P2->next = P2;
    R->next = R;

    printf("\nEnter First Polynomial:\n");

    if (!create(P1))
    {
        freeList(P1);
        freeList(P2);
        freeList(R);
        return 1;
    }

    printf("\nEnter Second Polynomial:\n");

    if (!create(P2))
    {
        freeList(P1);
        freeList(P2);
        freeList(R);
        return 1;
    }

    printf("\nFirst Polynomial: ");
    display(P1);

    printf("\nSecond Polynomial: ");
    display(P2);

    if (!add(P1, P2, R))
    {
        freeList(P1);
        freeList(P2);
        freeList(R);
        return 1;
    }

    printf("\nResultant Polynomial: ");
    display(R);

    printf("\n");

    freeList(P1);
    freeList(P2);
    freeList(R);

    return 0;
}

/*
Enter First Polynomial:
Enter coefficient and exponent: 3 2
Add another term? (y/n): y
Enter coefficient and exponent: 2 1
Add another term? (y/n): n

Enter Second Polynomial:
Enter coefficient and exponent: 4 2
Add another term? (y/n): y
Enter coefficient and exponent: 5 0
Add another term? (y/n): n

First Polynomial: 3x^2 + 2x^1
Second Polynomial: 4x^2 + 5x^0
Resultant Polynomial: 7x^2 + 2x^1 + 5x^0
*/