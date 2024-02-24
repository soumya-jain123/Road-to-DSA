//Find the largest three distinct elements in an array:
// Input: arr[] = {10, 4, 3, 50, 23, 90} Output: 90, 50, 23

#include <stdio.h>

void find_largest_three(int arr[], int n) {
    int first_max = -2147483647; // Set to the minimum possible value for an int
    int second_max = -2147483647;
    int third_max = -2147483647;

    // Traverse the array to find the largest three distinct elements
    for (int i = 0; i < n; i++) {
        if (arr[i] > first_max) {
            third_max = second_max;
            second_max = first_max;
            first_max = arr[i];
        } else if (arr[i] > second_max && arr[i] != first_max) {
            third_max = second_max;
            second_max = arr[i];
        } else if (arr[i] > third_max && arr[i] != first_max && arr[i] != second_max) {
            third_max = arr[i];
        }
    }

    // Check if three distinct elements were found
    if (third_max == -2147483647) {
        printf("There are less than three distinct elements in the array.\n");
    } else {
        printf("The largest three distinct elements in the array are: %d, %d, %d\n", first_max, second_max, third_max);
    }
}

int main() {
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    find_largest_three(arr, n);

    return 0;
}
