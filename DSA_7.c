/*
Name: Aayush Mishra
PRN: 1262253653
Batch: A3
Btech CSE (CLOUD)
*/

#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
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

void Push(int value)
{
    if (!isFull())
    {
        top = top + 1;
        stack[top] = value;
    }
    else
    {
        printf("Stack Overflow\n");
    }
}

int Pop()
{
    int temp;

    if (!isEmpty())
    {
        temp = stack[top];
        top = top - 1;
        return temp;
    }
    else
    {
        printf("Stack Underflow\n");
        return 0;
    }
}

int isoperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == '%')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int evaluate(char postfix[])
{
    int i = 0;
    int op1, op2, result;
    char ch;

    while (postfix[i] != '\0')
    {
        ch = postfix[i];

        if (isdigit(ch))
        {
            Push(ch - '0');
        }
        else if (isoperator(ch))
        {
            op2 = Pop();
            op1 = Pop();

            switch (ch)
            {
                case '+':
                    result = op1 + op2;
                    break;

                case '-':
                    result = op1 - op2;
                    break;

                case '*':
                    result = op1 * op2;
                    break;

                case '/':
                    result = op1 / op2;
                    break;

                case '%':
                    result = op1 % op2;
                    break;
            }

            Push(result);
        }

        i++;
    }

    return Pop();
}

int main()
{
    char postfix[MAX];
    int result;

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    result = evaluate(postfix);

    printf("Result = %d\n", result);

    return 0;
}


/*
Enter postfix expression: 23*54*+
Result = 26
*/