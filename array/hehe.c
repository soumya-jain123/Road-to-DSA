/* Write the program to create a 2-d array*/

#include<stdio.h>
int main(){
    int arr1[2][2] = {10,20,30,40};

    // to print the array

    for (int i =0; i<2; i++){
        for(int j =0; j<2; j++){
            printf("%d\t ",arr1[i][j]);
        }
        printf("\n");
    }
}