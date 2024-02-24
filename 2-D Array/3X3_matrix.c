#include<stdio.h>
int main(){
    int arr[3][3];
    int n,m;

    printf("Enter the elements for 2-D array\n");
    for(int i =0; i<3; i++){
        for (int j=0; j<3; j++){
            printf("Enter the element : ");
            scanf("%d", &arr[i][j]);
        }
    }

    printf("\n");
    printf("Printing the elements: \n");
    for(int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }

    printf("The Transpose matrix\n");
    for(int i=0; i<3; i++){
        for( int j=0; j<3; j++){
            printf("%d\t", arr[j][i]);
        }
        printf("\n");
    }

}