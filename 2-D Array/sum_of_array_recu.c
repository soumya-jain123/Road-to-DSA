#include<stdio.h>

int sumArray(int arr[], int size){
    if(size == 0){
        return 0;
    }

    int sum = arr[size-1];
    size--;

    return (sum + sumArray(arr, size));
}
int main(){
    int arr[20], num_ele;

    printf("Enter the number of elements in array: ");
    scanf("%d", &num_ele);

    for(int i=0; i<num_ele; i++){
        printf("Enter the element %d in array: ", i);
        scanf("%d", &arr[i]);
    }

    int sum_of_elements = sumArray(arr, num_ele);

    printf("The sum of elements is : %d", sum_of_elements);
}