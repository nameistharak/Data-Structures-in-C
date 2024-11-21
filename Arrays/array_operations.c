#include <stdio.h>

#define MAX_SIZE 100

// Function declarations
void display(int arr[], int n);
int insert(int arr[], int n, int element, int position);
int delete(int arr[], int n, int position);
int search(int arr[], int n, int element);

int main() {
    int arr[MAX_SIZE];
    int n = 0; // Current size of the array
    int choice, element, position;

    printf("Array Operations:\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Search\n");
    printf("4. Display\n");
    printf("5. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the element to insert: ");
            scanf("%d", &element);
            printf("Enter the position to insert (1 to %d): ", n + 1);
            scanf("%d", &position);
            n = insert(arr, n, element, position);
            break;
        case 2:
            printf("Enter the position to delete (1 to %d): ", n);
            scanf("%d", &position);
            n = delete(arr, n, position);
            break;
        case 3:
            printf("Enter the element to search: ");
            scanf("%d", &element);
            position = search(arr, n, element);
            if (position != -1)
                printf("Element found at position %d\n", position + 1);
            else
                printf("Element not found\n");
            break;
        case 4:
            display(arr, n);
            break;
        case 5:
            printf("Exiting program.\n");
            return 0;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to display the array
void display(int arr[], int n) {
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert an element at a given position
int insert(int arr[], int n, int element, int position) {
    if (n >= MAX_SIZE) {
        printf("Array overflow! Cannot insert more elements.\n");
        return n;
    }
    if (position < 1 || position > n + 1) {
        printf("Invalid position! Please enter a position between 1 and %d.\n", n + 1);
        return n;
    }

    for (int i = n; i >= position - 1; i--) {
        arr[i + 1] = arr[i];
    }
    arr[position - 1] = element;
    printf("Element inserted successfully.\n");
    return n + 1;
}

// Function to delete an element from a given position
int delete(int arr[], int n, int position) {
    if (n == 0) {
        printf("Array underflow! Cannot delete from an empty array.\n");
        return n;
    }
    if (position < 1 || position > n) {
        printf("Invalid position! Please enter a position between 1 and %d.\n", n);
        return n;
    }

    for (int i = position - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    printf("Element deleted successfully.\n");
    return n - 1;
}

// Function to search for an element in the array
int search(int arr[], int n, int element) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == element) {
            return i; // Return the index of the element
        }
    }
    return -1; // Element not found
}
