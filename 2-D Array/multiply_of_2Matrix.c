#include<stdio.h>
int main(){
    int arr1[10][10], arr2[10][10];
    int multi[10][10];

    int row1,row2,row3,col1,col2,col3;

    printf("Enter the value of rows for 1st, 2nd and multiplication matrix: ");
    scanf("%d %d %d", &row1, &row2, &row3);
    
    printf("Enter the value of columns for 1st, 2nd & multiplication matrix: ");
    scanf("%d %d %d", &col1, &col2, &col3);

    printf("Enter the elements for 2-D matrix 1:\n");
    for(int i=0 ; i<row1; i++){
        for(int j=0; j<col1; j++){
            printf("Enter the Element for %d row and %d column: ",i,j);
            scanf("%d", &arr1[i][j]);
        }
    }

    printf("Enter the elements for 2-D matrix 2:\n");
    for(int i=0; i<row2; i++){
        for(int j=0; j<col2; j++){
            printf("Enter the Element for %d row and %d column: ",i,j);
            scanf("%d", &arr2[i][j]);
        }
    }

    for(int i=0; i<row3; i++){
        for(int j=0; j<col3; j++){
            multi[i][j] =0;
            for(int k=0; k<col3; k++){
                multi[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    printf("Multiplication matrix is: \n");
    for(int i=0; i<row3; i++){
        for(int j=0; j<col3; j++){
            printf("%d\t", multi[i][j]);
        }
        printf("\n");
    }
}