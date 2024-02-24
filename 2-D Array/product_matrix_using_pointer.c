// Find the product of two matrix using pointers.

#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10

void matrix_product(int *matrix1, int *matrix2, int *result, int rows1, int cols1, int rows2, int cols2) {
    if (cols1 != rows2) {
        printf("Error: Number of columns in the first matrix must be equal to the number of rows in the second matrix.\n");
        return;
    }

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            int sum = 0;
            for (int k = 0; k < cols1; k++) {
                sum += (*(matrix1 + i * cols1 + k)) * (*(matrix2 + k * cols2 + j));
            }
            *(result + i * cols2 + j) = sum;
        }
    }
}

void display_matrix(int *matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", *((matrix + i * cols) + j)); // Output the matrix element value, not its address
        }
        printf("\n");
    }
}

int main() {
    int matrix1[MAX_ROWS][MAX_COLS], matrix2[MAX_ROWS][MAX_COLS], result[MAX_ROWS][MAX_COLS];
    int rows1, cols1, rows2, cols2;

    printf("Enter the number of rows and columns of the first matrix: ");
    scanf("%d %d", &rows1, &cols1);

    printf("Enter the elements of the first matrix:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter the number of rows and columns of the second matrix: ");
    scanf("%d %d", &rows2, &cols2);

    printf("Enter the elements of the second matrix:\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &matrix2[i][j]);
        }
    }

    if (cols1 != rows2) {
        printf("Error: Number of columns in the first matrix must be equal to the number of rows in the second matrix.\n");
        return 1;
    }

    matrix_product(&matrix1[0][0], &matrix2[0][0], &result[0][0], rows1, cols1, rows2, cols2);

    printf("\nProduct of the matrices:\n");
    display_matrix(&result[0][0], rows1, cols2);

    return 0;
}
