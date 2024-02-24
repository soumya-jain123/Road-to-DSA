//Store ‘n’ numbers (integers or real) in an array. Conduct a linear search for a 
//given number and report success or failure in the form of a suitable message.


#include <stdio.h>

#define MAX_SIZE 100

int linear_search(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // Return the index where the key is found
        }
    }
    return -1; // Return -1 if key is not found
}

int main() {
    int n, key, arr[MAX_SIZE];

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_SIZE) {
        printf("Invalid array size.\n");
        return 1;
    }

    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter the number to search for: ");
    scanf("%d", &key);

    int index = linear_search(arr, n, key);
    if (index != -1) {
        printf("The number %d is found at index %d.\n", key, index);
    } else {
        printf("The number %d is not found in the array.\n", key);
    }

    return 0;
}
