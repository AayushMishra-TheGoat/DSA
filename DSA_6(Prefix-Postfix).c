/*
Name: Aayush Mishra
PRN: 1262253653
Batch: A3
Btech CSE (CLOUD)
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

char stack[MAX][MAX];
int top = -1;

int isFull()
{
    if (top == MAX - 1)
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

void Push(char str[])
{
    if (!isFull())
    {
        top = top + 1;
        strcpy(stack[top], str);
        printf("\nPushed element is: %s", str);
    }
}

void Pop(char str[])
{
    if (!isEmpty())
    {
        strcpy(str, stack[top]);
        top = top - 1;
    }
    else
    {
        str[0] = '\0';
    }
}

int isoperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == '^')
        return 1;
    else
        return 0;
}

void pre_post(char prefix[])
{
    char op1[MAX], op2[MAX], temp[MAX];
    int i, l;

    l = strlen(prefix);

    for (i = l - 1; i >= 0; i--)
    {
        char ch = prefix[i];

        if (isoperator(ch))
        {
            Pop(op1);
            Pop(op2);

            strcpy(temp, op1);
            strcat(temp, op2);
            strcat(temp, (char[]){ch, '\0'});

            Push(temp);
        }
        else
        {
            temp[0] = ch;
            temp[1] = '\0';
            Push(temp);
        }
    }

    Pop(temp);
    printf("\n\nThe postfix expression is: %s\n", temp);
}

int main()
{
    char prefix[MAX];

    printf("Enter the Prefix expression: ");
    scanf("%99s", prefix);

    pre_post(prefix);

    return 0;
}

/*Enter the Prefix expression: *+AB-CD

Pushed element is: D
Pushed element is: C
Pushed element is: CD
Pushed element is: -
Pushed element is: B
Pushed element is: A
Pushed element is: AB
Pushed element is: +
Pushed element is: AB+CD-

The postfix expression is: AB+CD-*
*/