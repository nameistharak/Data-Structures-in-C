#include <stdio.h>
#define MAX 100

int main() {
    int arr[MAX];
    int n, i, j, minloc, temp;

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

    // Selection Sort Algorithm
    for (i = 0; i < n - 1; i++) {
        minloc = i;

        // Find the index of the minimum element in the unsorted part
        for (j = i + 1; j < n; j++) {
            if (arr[minloc] > arr[j]) {
                minloc = j;
            }
        }

        // Swap if the current index is not the minimum
        if (minloc != i) {
            temp = arr[i];
            arr[i] = arr[minloc];
            arr[minloc] = temp;
        }
    }

    // Display sorted array
    printf("Sorted Array is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
