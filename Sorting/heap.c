#include <stdio.h>

// Heap Down for Max Heap
void heapdown(int heap[], int root, int lastIdx) {
    int left = 2 * root + 1;
    int right = 2 * root + 2;
    int largest = root;
    int temp;

    if (left <= lastIdx && heap[left] > heap[largest])
        largest = left;

    if (right <= lastIdx && heap[right] > heap[largest])
        largest = right;

    if (largest != root) {
        temp = heap[root];
        heap[root] = heap[largest];
        heap[largest] = temp;

        heapdown(heap, largest, lastIdx);
    }
}

// Heap Up for Insertion
void heapup(int heap[], int index) {
    int parent = (index - 1) / 2;
    int temp;

    if (index > 0 && heap[parent] < heap[index]) {
        temp = heap[parent];
        heap[parent] = heap[index];
        heap[index] = temp;

        heapup(heap, parent);
    }
}

// Heap Sort Function
void heapSort(int arr[], int n) {
    int i, temp;

    // Build Max Heap
    for (i = 1; i < n; i++) {
        heapup(arr, i);
    }

    // Sorting
    for (i = n - 1; i > 0; i--) {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapdown(arr, 0, i - 1);
    }
}

// Input Function
void input(int arr[], int n) {
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

// Output Function
void display(int arr[], int n) {
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main Function
int main() {
    int arr[100], n;

    printf("Enter Number of elements: ");
    scanf("%d", &n);

    input(arr, n);
    heapSort(arr, n);
    display(arr, n);

    return 0;
}
