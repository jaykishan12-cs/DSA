#include<stdio.h>
#define MAX 100

int  findIndex(int arr[], int n,int key,int index[])
{
    int i,x=0;
    for(i =0;i<n;i++)
    {
        if(arr[i] == key)
        {
            index[x] = i;
            x++;
        
        }
    }
    return x;
}
int main()
{
    int arr[MAX],x;
    int i,n,key,index[MAX];
    printf("Enter no of elements : ");
    scanf("%d",&n);

    printf("Enter %d elements : ",n);
    for(i =0;i<n;i++)
        scanf("%d",&arr[i]);

    printf("Enter element to search : ");
    scanf("%d",&key);

    x = findIndex(arr,n,key,index);
 
    if(x>0)
    {
        printf("%d found at index's = ",key);
        for(int a = 0;a<x;a++)
        {
            printf("%d ",index[a]);
        }
    }
    else{
        printf("%d not found",key);
    }

}