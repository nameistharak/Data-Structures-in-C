#include <stdio.h>
#define MAX 100

// Function declaration
int Binary_search(int arr[], int n, int x);

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
    
    // Input array elements (in sorted order)
    printf("Enter the Array Elements in Sorted Order: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Input the element to search
    printf("Enter Search Element: ");
    scanf("%d", &x);
    
    // Perform binary search
    int result = Binary_search(arr, n, x);
    
    if (result == -1) {
        printf("Element not found in the array!\n");
    } else {
        printf("Element found at index %d (0-based indexing).\n", result);
    }
    
    return 0;
}

// Function to perform binary search
int Binary_search(int arr[], int n, int x) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2; // Calculate mid index
        
        if (arr[mid] == x) {
            return mid; // Element found
        }
        
        if (arr[mid] < x) {
            low = mid + 1; // Search in the right half
        } else {
            high = mid - 1; // Search in the left half
        }
    }
    
    return -1; // Element not found
}
