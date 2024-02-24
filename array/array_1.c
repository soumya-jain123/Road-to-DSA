#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    printf("Enter the size of aaray:");
    scanf("%d",&n);

    int *arr1 = (int*)malloc(n*sizeof(int));

    // taking input in array
    for(int i = 0; i<n;i++){
        printf("Enter element %d:",i);
        scanf("%d", &arr1[i]);

    }

    int *arr2 = (int*)malloc(n*sizeof(int));

    // copying arr1 to arr2

    for(int i = 0; i<n; i++){
        arr2[i] = arr1[i];
    }

    // printing array2
    printf("Copied array = ");
    for(int i=0; i<n; i++){
        printf("%d ",arr2[i]);
    }
    free(arr1);
    free(arr2);
}