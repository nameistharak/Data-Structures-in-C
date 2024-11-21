#include <stdio.h>
#define MAX 100

int main() {
    int arr[MAX];
    int n, i, j;

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

    // Insertion Sort Algorithm
    for (i = 1; i < n; i++) {
        int key = arr[i];
        j = i - 1;

        // Move elements greater than key one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    // Display sorted array
    printf("Sorted Array is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
