// array.h
#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>

// Function to input array elements
void input(int arr[],int size) {
    
    printf("Enter %d elements: ", size);
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to display array elements
void display(int arr[], int size) {
    // printf("Array elements: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

#endif
