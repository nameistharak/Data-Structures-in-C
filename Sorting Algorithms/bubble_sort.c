#include <stdio.h>
#define MAX 100

// Function declaration
void Bubble_Sort(int arr[], int n);

int main() {
    int arr[MAX];
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
        scanf("%d", &arr[i]);
    }

    // Call Bubble Sort function
    Bubble_Sort(arr, n);

    // Display sorted array
    printf("Sorted Array is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

// Function to perform Bubble Sort
void Bubble_Sort(int arr[], int n) {
    int i, j, temp;

    // Perform n-1 passes through the array
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            // Swap adjacent elements if they are in the wrong order
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
