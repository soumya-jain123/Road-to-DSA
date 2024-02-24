#include <stdio.h>
void deleteNumber(int arr[], int *size, int num) {
    int i, j;
    for (i = 0; i < *size; i++) {
        if (arr[i] == num) {
            break;
        }
    }
    if (i == *size) {
        return;
    }

    for (j = i; j < *size - 1; j++) {
        arr[j] = arr[j + 1];
    }


    (*size)--;
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


    printf("Enter the number to delete: ");
    scanf("%d", &num);


    deleteNumber(arr, &size, num);


    printf("Array after deletion:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
