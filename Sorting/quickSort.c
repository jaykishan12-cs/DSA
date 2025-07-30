#include<stdio.h>
#include<conio.h>
int partition(int arr[], int lb, int ub)
{
    int pivot = arr[lb];
    int up,down;
    up = ub,
    down = lb;
     
    while(down < up)
    {
        while(arr[up] > pivot)
        {
            up--;
        }
        while(arr[down] <= pivot && down < up)
        {
            down++;
        }

        if(down<up)
        {
            int temp = arr[down];
            arr[down] = arr[up];
            arr[up] = temp;
        }
    }

    arr[lb] = arr[up];
    arr[up] = pivot;

    return up;
}

void quick(int arr[],int lb,int ub)
{
    int index;

    if(lb< ub)
    {
        index = partition(arr,lb,ub);
        quick(arr,lb,index-1);
        quick(arr,index+1,ub);
    }
}
void main()
{
    int arr[100];
    int n;
    printf("Enter no of elements in array : ");
    scanf("%d",&n);
    
    printf("ENter %d elements : ",n);
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    quick(arr,0,n-1);

    printf("--------\n");
    printf("Sorted Aray : ");
    for(int i =0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}