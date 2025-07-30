#include<stdio.h>
#include<conio.h>
#include"array.h"
void merge(int arr[],int low,int mid,int high)
{
    int temp[100];
    int i,j,k;
    i=low;
    j=mid+1;
    k=0;

    while(i<=low && j<=high)
    {
        if(arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
    }

    while(i<=mid)
    {
        temp[k++] = arr[i++];
    }

     while(j<=high)
    {
        temp[k++] = arr[j++];
    }

    for(i = low,k=0;i<=high;i++,k++)
    {
        arr[i] = temp[k];
    }
}
void mergeSort(int arr[],int low,int high)
{
    if(low >= high) return;

    int mid =(low+high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}

void main()
{
    int arr[100];
    int n,i;

    printf("Enter no of elements in array :");
    scanf("%d",&n);

    input(arr,n);
    

    mergeSort(arr,0,n-1);

    printf("---------------------------------------\n");
    printf("Sorted array : ",arr);
    display(arr,n);
    //    for(i =0;i<n;i++)
//     {
//         printf("%d ",arr[i]);
//     }
 }