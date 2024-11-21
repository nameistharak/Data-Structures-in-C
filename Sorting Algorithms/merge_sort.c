#include <stdio.h>
#define MAX 100

// Function declarations
void merge(int a[], int low, int mid, int high, int b[]);
void mergesort(int a[], int low, int high, int b[]);

int main() {
    int a[MAX], b[MAX];
    int n, i;

    // Input array size
    printf("Enter Array Size: ");
    scanf("%d", &n);

    if (n > MAX) {
        printf("Array size exceeds the maximum allowed size (%d).\n", MAX);
        return 1;
    }

    // Input array elements
    printf("Enter Array Elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Perform merge sort
    mergesort(a, 0, n - 1, b);

    // Display sorted array
    printf("Sorted Array is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}

// Recursive function to divide the array into subarrays
void mergesort(int a[], int low, int high, int b[]) {
    if (low < high) {
        int mid = (low + high) / 2;

        // Recursively divide and sort the left half
        mergesort(a, low, mid, b);

        // Recursively divide and sort the right half
        mergesort(a, mid + 1, high, b);

        // Merge the sorted subarrays
        merge(a, low, mid, high, b);
    }
}

// Function to merge two sorted subarrays
void merge(int a[], int low, int mid, int high, int b[]) {
    int i = low, j = mid + 1, k = low;

    // Compare and merge the elements from both subarrays
    while (i <= mid && j <= high) {
        if (a[i] <= a[j]) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }
    }

    // Copy remaining elements from the left subarray (if any)
    while (i <= mid) {
        b[k++] = a[i++];
    }

    // Copy remaining elements from the right subarray (if any)
    while (j <= high) {
        b[k++] = a[j++];
    }

    // Copy merged elements back to the original array
    for (i = low; i <= high; i++) {
        a[i] = b[i];
    }
}
