/*
Name: Aayush Mishra
PRN: 1262253653
Batch: A3
Btech CSE (CLOUD)
*/

#include <stdio.h>
#include <string.h>
#define MAX 20

struct jobQ {
    int job_id;
    char job_title[50];
};

void AddQ(struct jobQ q[]);
void DelQ(struct jobQ q[]);
void Display(struct jobQ q[]);
int isfull();
int isempty();

int front = -1;
int rear = -1;

int main() 
{
    struct jobQ j[20];
    int ch, cont = 0;

    do
    {   
        printf("\n1:Add\n2.Delete\n3:Display\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                AddQ(j);
                break;
            case 2:
                DelQ(j);
                break;
            case 3:
                Display(j);
                break;
            default:
                printf("Invalid choice\n");
        }

        printf("Do you want to continue? Press 1 to continue: ");
        scanf("%d", &cont);
    } while (cont == 1);

    return 0;
}

int isfull()
{
    if(rear == MAX - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isempty()
{
    if(front == rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void AddQ(struct jobQ q[])
{
    int jid;
    char title[50];

    if(isfull())
    {
        printf("Queue is full\n");
    }
    else
    {
        printf("Enter job id: ");
        scanf("%d", &jid);

        printf("Enter document title: ");
        scanf("%s", title);

        rear = rear + 1;
        q[rear].job_id = jid;
        strcpy(q[rear].job_title, title);
    }   
}

void DelQ(struct jobQ q[])
{
    if(isempty())
    {
        printf("Queue is empty\n");
    }
    else
    {
        front = front + 1;
        printf("Deleted job id: %d\n", q[front].job_id);
        printf("Deleted job title: %s\n", q[front].job_title);
    }
}

void Display(struct jobQ q[])
{
    int i;
    for(i = front + 1; i <= rear; i++)
    {
        printf("Job id: %d\n", q[i].job_id);
        printf("Job title: %s\n", q[i].job_title);
    }
}


/*
1:Add
2.Delete
3:Display
Enter your choice: 1
Enter job id: 101
Enter document title: Report
Do you want to continue? Press 1 to continue: 1

1:Add
2.Delete
3:Display
Enter your choice: 1
Enter job id: 102
Enter document title: Assignment
Do you want to continue? Press 1 to continue: 1

1:Add
2.Delete
3:Display
Enter your choice: 3
Job id: 101
Job title: Report
Job id: 102
Job title: Assignment
Do you want to continue? Press 1 to continue: 1

1:Add
2.Delete
3:Display
Enter your choice: 2
Deleted job id: 101
Deleted job title: Report
Do you want to continue? Press 1 to continue: 0
*/