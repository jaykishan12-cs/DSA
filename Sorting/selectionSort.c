#include<stdio.h>
#include"array.h"

//pull up approach 
void selection(int arr[],int n)
{

    int i,j;
    int min;

    for(i=0;i<=n-2;i++)
    {
        min = i;
        for(j=i;j<n;j++)
        {
            if(arr[j] < arr[min])
            {
                min =j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

}
void main()
{
    int arr[100];
    int n;
    printf("enter number of elements : ");
    scanf("%d",&n);

    input(arr,n);
    selection(arr,n);
    display(arr,n);

}