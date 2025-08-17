#include<stdio.h>
#include<stdlib.h>

void heapup(int heap[],int newNode) {
    // printf("\n heap up");
    int parentIndex,temp;
    if(newNode > 0) {
        parentIndex = (newNode - 1)/2;
        if(heap[parentIndex] < heap[newNode]) {
            temp = heap[parentIndex];
            heap[parentIndex] = heap[newNode];
            heap[newNode] = temp;
            heapup(heap,parentIndex);
        }
    }
}

void heapdown(int heap[], int root, int lastIndex) {
    int leftChildIndex, rightChildIndex, largerChildIndex, temp;
    while (1) {
        leftChildIndex = root * 2 + 1;
        rightChildIndex = root * 2 + 2;
        largerChildIndex = root;
        if (leftChildIndex <= lastIndex && heap[leftChildIndex] > heap[largerChildIndex]) {
            largerChildIndex = leftChildIndex;
        }
        if (rightChildIndex <= lastIndex && heap[rightChildIndex] > heap[largerChildIndex]) {
            largerChildIndex = rightChildIndex;
        }
        if (largerChildIndex != root) {
            temp = heap[root];
            heap[root] = heap[largerChildIndex];
            heap[largerChildIndex] = temp;
            root = largerChildIndex;
        } else {
            break;
        }
    }
}

void heapSort(int arr[],int n) {
    // printf("\n heap sort");
    int i,temp;
    
    for(i = 1;i<n;i++) 
        heapup(arr,i);

    for(i = n-1;i>0;i--) {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapdown(arr,0,i-1);
    }
}

int main() {
    int arr[100],n;
    printf("\n Enter no of elements: ");
    scanf("%d",&n);
    printf("Enter %d elements : ",n);
    for(int i = 0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    heapSort(arr,n);
    printf("\n Sorted Array: ");
    for(int i = 0;i<n;i++) {
        printf("%d ",arr[i]);
    }
    return 0;
}
