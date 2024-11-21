#include <stdio.h>
#define MAX 100

// Function declaration
int linear_search(int arr[], int n, int x);

int main() {
    int arr[MAX];
    int n, x, i;
    
    // Input size of the array
    printf("Enter Size of the Array: ");
    scanf("%d", &n);

    if (n > MAX) {
        printf("Array size exceeds the maximum allowed size (%d).\n", MAX);
        return 1;
    }
    
    // Input array elements
    printf("Enter the Array Elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Input the element to search
    printf("Enter Search Element: ");
    scanf("%d", &x);
    
    // Perform linear search
    int result = linear_search(arr, n, x);
    
    if (result == -1) {
        printf("Element not found in the array!\n");
    } else {
        printf("Element found at index %d (0-based indexing).\n", result);
    }
    
    return 0;
}

// Function to perform linear search
int linear_search(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i; // Return the index if the element is found
        }
    }
    return -1; // Return -1 if the element is not found
}
