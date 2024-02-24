#include<stdio.h>
int main(){
    int arr1[5][5], arr2[5][5];
    int sum[5][5];

    int row1,row2,row3,col1,col2,col3;

    printf("Enter the rows for 1st, 2nd and sum matrix : ");
    scanf("%d %d %d", &row1, &row2, &row3);

    printf("Enter the columns for 1st, 2nd and sum matrix: ");
    scanf("%d %d %d", &col1, &col2, &col3);

    printf("Enter the elements for 2-D array1\n");
    for(int i =0; i<row1; i++){
        for (int j=0; j<col1; j++){
            printf("Enter the element %d: ",j);
            scanf("%d", &arr1[i][j]);
        }
    }

    printf("Enter the elements for 2-D array2\n");
    for(int i =0; i<row2; i++){
        for (int j=0; j<col2; j++){
            printf("Enter the element %d: ",j);
            scanf("%d", &arr2[i][j]);
        }
    }

    printf("Sum of two matrix: ");
    for(int i =0; i<row3; i++){
        for (int j=0; j<col3; j++){
            sum[i][j] = arr1[i][j] + arr2[i][j];
        }
    }

    printf("Sum of two matrix: \n");
    for(int i =0; i<row3; i++){
        for (int j=0; j<col3; j++){
            printf("%d\t", sum[i][j]);
        }
        printf("\n");
    }
}
