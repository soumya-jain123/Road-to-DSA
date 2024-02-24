#include <stdio.h>


void insertNumber(int arr[], int *size, int num) {
    int i, j;
    for (i = 0; i < *size; i++) {
        if (arr[i] > num) {
            break;
        }
    }
    for (j = *size; j > i; j--) {
        arr[j] = arr[j - 1];
    }
    arr[i] = num;
    (*size)++;
}

int main() {
    int arr[100]; 
    int size, num;

    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter the elements of the array in ascending order:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number to insert: ");
    scanf("%d", &num);
    insertNumber(arr, &size, num);
    printf("Array after insertion:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
