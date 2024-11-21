#include <stdio.h>
#define MAX 100

// Function declarations
void quicksort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

int main() {
    int a[MAX];
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

    // Perform quicksort
    quicksort(a, 0, n - 1);

    // Display sorted array
    printf("Sorted Array is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}

// Recursive function to sort the array
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pivot = partition(arr, low, high);

        // Recursively sort the subarrays
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}

// Function to partition the array and return the pivot index
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1;       // Index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap arr[i + 1] and arr[high] (or pivot)
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1; // Return the pivot index
}
