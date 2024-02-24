// Find the sum of rows and columns of matrix of given order (row x column).

#include<stdio.h>
int main(){
    int m,n;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &m, &n);
    int matrix[m][n];

    printf("Enter the values in the matrix: \n");
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("Element %d:", j);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("The matrix is: \n");
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nSum of rows:\n");
    for(int i=0; i<m; i++){
        int rowSum =0;
        for(int j=0; j<n; j++){
            rowSum += matrix[i][j];
        }
        printf("Sum of row %d: %d\n", i+1, rowSum);
    }

    printf("\nSum of columns:\n");
    for(int j=0; j<n; j++){
        int colSum =0;
        for(int i=0; i<m; i++){
            colSum += matrix[i][j];
        }
        printf("Sum of columns %d: %d\n", j + 1, colSum);
    }


}