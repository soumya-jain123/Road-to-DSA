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

    int min_num = arr1[0];
    int index = 0;
    // finding smallest number
    for(int i =1;i<n; i++){
        if (min_num > arr1[i])
        {
            min_num = arr1[i];
            index = i;
        }
    }

    printf("Minimum number is %d at index %d",min_num,index);

    free(arr1);
}