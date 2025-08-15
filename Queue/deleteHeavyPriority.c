#include<stdio.h>
#include<stdlib.h>

#define SS 10

#define QUEUE_UNDERFLOW -40000
#define QUEUE_OVERFLOW 1
#define INVALID_ELEMENT 2

typedef struct{
    int items[SS] ;
    int front , rear;
}Queue;

//function to check queue underflow
int isEmpty(Queue q)
{
    if(q.front> q.rear)
        return 1;
    return 0;
}

//function to check queue underflow
int isFull(Queue q)
{
    if(q.rear == SS-1)
        return 1;
    return 0;
}

void insert(Queue *pq,int element)
{
    if((isFull(*pq)))
    {
        printf("\n Queue Overflow");
        return;
    }

    pq->items[++pq->rear] = element;
    printf("\n %d Element Added",element);
}

void remove2(Queue *pq)
{
    if(isEmpty(*pq))
    {
        printf("\n Queue Underflow");
        return;
    }
    int minIndex =pq->front,i;
    for(i = pq->front ; i <= pq->rear ; i++)
    {
        if(pq->items[i] < pq->items[minIndex])
        {
            minIndex = i;
        }
    }   
    
    printf("\n Deleted Element : %d",pq->items[minIndex]);
    for (int i = minIndex; i < pq->rear; i++) {
        pq->items[i] = pq->items[i + 1];
    }
    pq->rear--;
    if(isEmpty(*pq))
    {
        pq->front = 0;
        pq->rear = -1;
    }
}

void display(Queue q)
{
    int i;
    if(isEmpty(q))
    {
        printf("\n Queue Empty ! nothing to show");
        return;
    }

    printf("\n Queue contains:");
    for(i=q.front;i<=q.rear;i++)
    {
        printf("%d ",q.items[i]);
    }
}
int main()
{
    Queue q;
    int choice,element;
    q.front = 0;
    q.rear = -1;

    while(1)
    {
        printf("\n ------ MENU ------");
        printf("\n 1.Insert \n2.Remove\n3.Display\n4.Exit");
        printf("\nEnter choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("\n Enter element to insert: ");
            scanf("%d",&element);
            insert(&q,element);
            break;
        
        case 2:
            remove2(&q);
            break;

        case 3:
            display(q);
            break;

        case 4:
            exit(EXIT_SUCCESS);
        }
    }
}