#include<stdio.h>
#define max 100
#include<stdlib.h>
#include<string.h>

#define SS 10

#define QUEUE_UNDERFLOW -40000
#define QUEUE_OVERFLOW 1
#define INVALID_ELEMENT 2

typedef struct{
    int items[SS] ;
    int front , rear;
}Queue;


void heapup(int x[],int newnode){
	int parentnode,temp;
	if(newnode>0){
		parentnode=(newnode-1)/2;
		if(x[parentnode]>x[newnode]){
			temp=x[parentnode];
			x[parentnode]=x[newnode];
			x[newnode]=temp;
			heapup(x,parentnode);
			}
		}
}

void heapdown(int x[],int root,int lastIndex){
	int leftchildIdx,rightchildIdx,temp,largerchildIdx;
	leftchildIdx=root*2+1;
	rightchildIdx=root*2+2;//rightchildIdx=leftchildIdx+1
	if(leftchildIdx<=lastIndex){
		if(rightchildIdx<=lastIndex){
			if(x[leftchildIdx]<x[rightchildIdx])
				largerchildIdx=leftchildIdx;
			else
				largerchildIdx=rightchildIdx;
		}
		else
			largerchildIdx=leftchildIdx;

		if(x[root]>x[largerchildIdx]){
			temp=x[root];
			x[root]=x[largerchildIdx];
			x[largerchildIdx]=temp;
			heapdown(x,largerchildIdx,lastIndex);
		}
	}
}
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
	int i;
    if(isFull(*pq))
    {
        printf("\n Queue Overflow");
        return;
    }

    pq->items[++pq->rear] = element;
	printf("\n %d Element Added",element);

	heapup(pq->items,pq->rear);

}

void remove2(Queue *pq)
{
    if(isEmpty(*pq))
    {
        printf("\n Queue Underflow");
        return;
    }

    printf("\n Deleted Element : %d", pq->items[0]);


    pq->items[0] = pq->items[pq->rear];
    pq->rear--;

    heapdown(pq->items, 0, pq->rear);
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
        printf("\n1.Insert \n2.Remove\n3.Display\n4.Exit");
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