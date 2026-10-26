/*
Name: Aayush Mishra
PRN: 1262253653
Batch: A3
Btech CSE (CLOUD)
*/

#include <stdio.h> 
#include <string.h> 
struct jobQ 
{ 
    int jobid; 
    char jobtitle[30]; 
}; 
#define max 5 
int front=-1; 
int rear=-1; 
void AddQ(struct jobQ q[]); 
void DelQ(struct jobQ q[]); 
void Display(struct jobQ q[]); 
int isfull(); 
int isempty(); 
int main() { 
    struct jobQ j[20]; 
    int ch,cont=0; 

    do{ 
        printf("\n1:Add\n2:Delete\n3:Display"); 
        printf("\n Enter your choice"); 
        scanf("%d",&ch); 

        switch(ch) 
        { 
            case 1:AddQ(j);break; 
            case 2:DelQ(j);break; 
            case 3:Display(j);break; 
        } 
        printf("\ndo you want to continue, press 1 to continue"); 
        scanf("%d",&cont); 
    }while(cont==1); 
    return 0; 
} 
void AddQ(struct jobQ q[]) 
{ 
    int jid; 
    char title[30]; 
    printf("enter job id:"); 
    scanf("%d",&jid); 
    printf("enter document title"); 
    scanf("%s",title); 
    if(isfull()) 
    { 
        printf("Adding is not possible"); 
    } 
    else 
    { 
        rear=((rear+1) % max); 
        q[rear].jobid=jid; 
        strcpy(q[rear].jobtitle,title); 
        if(front == -1)             
            front = rear;            
    } 
} 
void DelQ(struct jobQ q[]) 
{ 
    if (isempty()) 
    { 
        printf("queue is empty"); 
    } 
    else{ 
        printf("jobid=%d",q[front].jobid);       
        printf("title=%s",q[front].jobtitle);   
        if(front == rear)                      
        {                                      
            front = -1;                        
            rear = -1;                         
        }                                      
        else                                   
        {                                      
            front=((front+1) % max);           
        }                                      
    } 
} 
int isfull() 
{ 
    if((rear + 1) % max == front) 
        return 1; 
    else 
        return 0; 
} 
int isempty() 
{ 
    if(front == -1) 
        return 1; 
    else  
        return 0; 
} 
void Display(struct jobQ q[]){ 
    int i; 
    if(isempty())                        
    {                                    
        printf("\nqueue is empty");      
    }                                    
    else                                 
    {                                     
        i=front;                          
        while(1)
        {                            
            printf("\n job id =%d",q[i].jobid); 
            printf("\n job title =%s",q[i].jobtitle); 
            if(i == rear)                
                break;                  
            i=(i+1) % max;               
        }                                
    }                                    
}

/*
1:Add
2:Delete
3:Display
 Enter your choice: 1
enter job id:101
enter document title:Report

do you want to continue, press 1 to continue: 1

1:Add
2:Delete
3:Display
 Enter your choice: 1
enter job id:102
enter document title:Assignment

do you want to continue, press 1 to continue: 1

1:Add
2:Delete
3:Display
 Enter your choice: 3
 job id =101
 job title =Report
 job id =102
 job title =Assignment

do you want to continue, press 1 to continue: 1

1:Add
2:Delete
3:Display
 Enter your choice: 2
jobid=101title=Report

do you want to continue, press 1 to continue: 0
*/