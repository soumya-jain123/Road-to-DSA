/* 
Create an array ‘a1’ with ‘n’ elements. Insert an element in ith position of ‘a1’ and also delete an element 
from jth position of ‘a1’.
*/

#include<stdio.h>
#include<stdlib.h>
void INSERT(int A[], int N, int POS, int Value){
    int I =N;
    while(I >= POS){
        A[I + 1] = A[I];
        I = I - 1;
    }

    N = N +1;
    A[POS] = Value;
}

void DELETE(int A[], int N, int POS){
    int I = POS;
    while(I <= N-1){
        A[I] = A[I+1];
        I = I +1;
    }

    N = N -1;
}
int main(){

    int n;
    printf("Enter the size of element you want: ");
    scanf("%d",&n);
    int *arr = (int *)malloc(n*sizeof(int));

    for(int i=0; i<n; i++){
        printf("Enter the element %d: ", i);
        scanf("%d", &arr[i]);
    }
    int number, pos;
    printf("Enter the element you want to insert: ");
    scanf("%d", &number);
    printf("Enter the position: ");
    scanf("%d", &pos);

    INSERT(arr, n, pos, number);
    printf("The updated array is: \n");
    for(int i=0; i<n+1; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    DELETE(arr,n,pos);
    printf("array after deleting the element from the array: \n");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    free(arr);

}