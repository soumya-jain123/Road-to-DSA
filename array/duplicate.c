#include<stdio.h>
#include<stdlib.h>

int hasDuplicate(int arr[], int size){
    for (int i=0; i<size-1; i++){
        for(int j=i+1; j<size; j++){
            if(arr[i] == arr[j]){
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    int n;
    printf("Enter the size of array you want: ");
    scanf("%d",&n);

    int *arr1 = (int *)malloc(n*sizeof(int)); 

    for(int i=0; i<n;i++){
        printf("Enter element %d: ",i);
        scanf("%d",&arr1[i]);
    }

   
    int size = n;

    if(hasDuplicate(arr1, size)){
        printf("The array has duplicate elements.\n");
    }else{
        printf("The array does not have duplicate elements.\n");
    }

    free(arr1); 
    return 0;
}
