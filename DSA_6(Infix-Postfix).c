/*
Name: Aayush Mishra
PRN: 1262253653
Batch: A3
Btech CSE (CLOUD)
*/

#include <stdio.h>
#include <ctype.h>
#define MAX 10

char stack[MAX];
int top = -1;

void Push(char ch);
char pop();
int isfull();
int isempty();
int isp(char ch);
int icp(char ch);
void in_POST(char inexp[]);

int main()
{
    char infix[20];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    in_POST(infix);

    return 0;
}

void Push(char ch)
{
    if (!isfull())
    {
        top = top + 1;
        stack[top] = ch;
    }
    else
    {
        printf("Pushing is not possible (Stack Overflow)\n");
    }
}

char pop()
{
    if (!isempty())
    {
        char temp = stack[top];
        top--; 
        return temp;    
    }
    else 
    {
        printf("Deletion not possible (Stack Underflow)\n");
        return '\0';
    }
}

int isfull()
{
    if (top == MAX - 1)
        return 1;
    else
        return 0;
}

int isempty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

int isp(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else if (ch == '*' || ch == '/' || ch == '%')  
    {
        return 2;
    }
    else if (ch == '^')                    
    {
        return 3;
    }
    else
        return 0;
}

int icp(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else if (ch == '*' || ch == '/' || ch == '%')  
    {
        return 2;
    }
    else if (ch == '^')                    
    {
        return 4;
    }
    else
        return 0;
}  

void in_POST(char inexp[])
{
    int k = 0, i = 0;
    char tkn;
    char postexp[20];

    tkn = inexp[i];
    while (tkn != '\0')
    {
        if (isalpha(tkn))
        {
            postexp[k] = inexp[i];
            k++;
        }
        else
        {
            if (tkn == '(')
            {
                Push('(');
            }
            else if (tkn == ')')
            {
                while (!isempty() && stack[top] != '(')
                {
                    postexp[k] = pop();
                    k++;
                }
                if (!isempty() && stack[top] == '(')
                {
                    pop();
                }
            }
            else 
            {
                while (!isempty() && isp(stack[top]) >= icp(tkn))
                {
                    postexp[k] = pop();
                    k++;
                }
                Push(tkn);
            }
        }
        i++;
        tkn = inexp[i];
    }

    while (!isempty())
    {
        postexp[k] = pop();
        k++;
    }
    postexp[k] = '\0';

    printf("Postfix expression: %s\n", postexp);
}

/*
Enter infix expression: A+B*C
Postfix expression: ABC*+
*/