#include<stdio.h>
int main(){
    int salesman[5][3];
    // getting data

    printf("Enter the data to Sales record: \n");
    for(int i=0; i<5; i++){
        for(int j=0; j<3; j++){
            printf("Enter the sales for salesman[%d][%d]: ",i,j);
            scanf("%d",&salesman[i][j]);
        }
    }
    
    printf("The salesman record:\n");
    for(int i=0; i<5; i++){
        for(int j=0; j<3; j++){
            printf("%d\t", salesman[i][j]);
        }
        printf("\n");
    }

    // to print the total sales of each salesman
    int sales = 0;
    printf("Sales by each salesman: \n");
    for(int i= 0; i<5; i++){
        for(int j=0; j<3; j++){
            sales += salesman[i][j];
        }
        printf("Sales by salesman %d : %d\n",i,sales);
        sales = 0;
        
        printf("\n");
    }
    int sales1 = 0;
    // Total sales of each item
    printf("Total Sales of each item: \n");
    for(int j=0; j<3; j++){
        for(int i =0; i<5; ++i){
            sales1 += salesman[i][j];
        }
        printf("Total Sales of item %d : %d\n",j,sales1);
        sales1 = 0;
        printf("\n");
    }
}