#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    printf("Enter the size of array you want: ");
    scanf("%d",&n);

    int *arr1 = (int *)malloc(n*sizeof(int));

    for(int i=0; i<n;i++){
        printf("Enter element %d: ",i);
        scanf("%d",&arr1[i]);
    }
    float sum = 0;
    for (int i=0; i<n; i++){
        sum += arr1[i];
    }

    printf("Sum of array is: %f\n", sum);
    float mean = sum/n ;

    printf("mean of the array is: %f", mean);

    free(arr1);
}