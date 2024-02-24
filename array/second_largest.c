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

    int largest = arr1[0];
    int second_lar = arr1[1];

    for( int i = 2; i<n; i++){

        if (largest < arr1[i]){
            largest = arr1[i];
        }

        if (largest < second_lar && (second_lar < arr1[i])){
            second_lar = arr1[i];
        }
        
    }

    printf("largest number is %d and second largest is %d", largest, second_lar);
    free(arr1);
}