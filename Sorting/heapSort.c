#include<stdio.h>
#include "array.h"

void heapdown(int heap[],int root,int lastIdx)
{
    printf("in heapdown \n");
    int leftChildIdx,rightChildIdx,largerChildIdx,temp;

    leftChildIdx = root * 2 + 1;
    rightChildIdx = root * 2 + 2;

    if(leftChildIdx <= lastIdx)
    {
        if(rightChildIdx <= lastIdx)
        {
            if(heap[leftChildIdx] > heap[rightChildIdx])
            {
                largerChildIdx = leftChildIdx;
            }
            else{
                largerChildIdx = rightChildIdx;
            }
        }
        else{
            largerChildIdx = leftChildIdx;
        }

        if(heap[root] < heap[largerChildIdx])
        {
            temp = heap[root];
            heap[root] =heap[largerChildIdx];
            heap[largerChildIdx] = temp;

            heapdown(heap,largerChildIdx,lastIdx);
        }
    }

}

void heapup(int heap[],int newnode)
{
        printf("in heapup");

    int parentIdx,temp;

    if(newnode > 0)
    {
        parentIdx = (newnode - 1)/2;

        if(heap[parentIdx]  < heap[newnode])
        {
            temp = heap[newnode];
            heap[newnode] = heap[parentIdx];
            heap[parentIdx] = temp;

            heapup(heap,parentIdx);
        }
    }
}

void heapSort(int arr[],int n)
{
        printf("in heapsort");

    int i,temp;

    for(i =1;i<n;i++)
    {
        heapup(arr,i);
    }

    for(i =n-1;i>0;i++)
    {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapdown(arr,0,i-1);
    }
}
int main()
{
    int arr[100],n;

    printf("Enter Number of elements : ");
    scanf("%d",&n);

    printf("Enter %d elements : ",n);
    for(int i =0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }


    heapSort(arr,n);

    printf("Sorted array : \n");
    for(int i =0;i<n;i++)
    {
        printf("%d",&arr[i]);
    }
}