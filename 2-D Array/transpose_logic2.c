#include <stdio.h>
int main(){
    int rows, cols, i, j;
    
    printf("Enter number of rows and columns of matrix: ");
    scanf("%d %d", &rows, &cols);

    int matrix[10][10];
    printf("Enter elements of the matrix:\n");
    for(i=0; i<rows; i++){
        for(j=0; j<cols; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    int transposed[rows][cols];
    for(int i=0; i<rows; ++i){
        for(j =0; j<cols; ++j){
            transposed[j][i] = matrix[i][j];
        }
    }

    printf("the transposed matrix is given by:\n");
    for(int i=0; i<cols; ++i){
        for(int j=0; j<rows; ++j){
            printf("%d\t", transposed[i][j]);
        }
        printf("\n");
    }
}