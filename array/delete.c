void DELETE (int A[], int N, int POS){
    int I = POS;
    while(I <= N - 1){
        A[I] = A[I + 1];
        I = I + 1;
    }
    N = N - 1;

}
#include <stdio.h>
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

    DELETE(arr1, n, 3);
    for(int i =0 ; i<n-1; i++){
        printf("Element %d: %d\n",i+1, arr1[i]);
    }
}