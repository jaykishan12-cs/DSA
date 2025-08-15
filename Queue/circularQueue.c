#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define SIZE 10
typedef struct {
    int items[SIZE];
    int front,rear;
    int count;
}cQueue;

int isEmpty(cQueue q)
{
    return q.count == 0;
}

int isFull(cQueue q)
{
    return q.count == SIZE;
}

void enqueue(cQueue *pq,int element)
{
    if(isFull(*pq))
    {
        printf("\n Queue Overflow , cannot insert");
        return;
    }

    pq->rear = (++pq->rear) % SIZE;
    pq->items[pq->rear] = element;
    pq->count++;
    printf("\n Element inserted");
}

void dequeue(cQueue *pq)
{
    int temp;
    if(isEmpty(*pq))
    {
        printf("\n Queue Underflow");
        return;
    }

    temp = pq->items[pq->front];
    pq->front = (pq->front + 1) % SIZE;

    pq->count--;
    printf("\n Element Deleted - %d",temp);
}

void display(cQueue q)
{
    int i;
    if(isEmpty(q))
    {
        printf("\n Queue is empty ! noting to show");
        return;
    }
    printf("\n  Queue: ");
    if(q.front<= q.rear)
    {
        for(i=q.front;i<= q.rear;i++)
        {
            printf("%d ",q.items[i]);
        }
    }
    else{
        for(i=q.front; i < SIZE;i++)
        {
            printf("%d ",q.items[i]);
        }
        for(i=0;i<=q.rear;i++)
        {
            printf("%d ",q.items[i]);
        }
    }
}
int main()
{
    cQueue q;
    q.front =0;
    q.rear =-1;
    q.count=0;
    int choice,element;


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
            enqueue(&q,element);
            break;
        
        case 2:
            dequeue(&q);
            break;

        case 3:
            display(q);
            break;

        case 4:
            exit(EXIT_SUCCESS);
        }
    }
}