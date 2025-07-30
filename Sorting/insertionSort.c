#include<stdio.h>
#include"array.h"

void insertionSort(int arr[],int n)
{
    int i,j,num,w = 0;

    for(i=1;i<n;i++)
    {
        num = arr[i]; 
        j = i-1;

        while(j >=0 && num < arr[j])
        {
            w++;
            arr[j+1] = arr[j];
            arr[j] = num;
            j--;
        }
    }
    printf("while = %d\n ",w);
}

void main()
{
    int arr[100];
    int n;
    printf("Enter No of elements : ");
    scanf("%d",&n);
    input(arr,n);

    insertionSort(arr,n);

    display(arr,n);
}