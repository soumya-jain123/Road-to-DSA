#include<stdio.h>
int main(){
    int student[5][3];

    printf("Enter the data for each student: \n");
    for(int i=0; i<5; i++){
        for(int j=0; j<3; j++){
            printf("Enter the marks for student %d, subject %d: ",i,j);
            scanf("%d",&student[i][j]);
        }
    }

    // to print the data
    for(int i=0; i<5; i++){
        for(int j=0; j<3; j++){
            printf("%d\t",student[i][j]);
        }
        printf("\n");
    }

    // to print the highest marks in each subject
    for(int i=0; i<3; i++){
        int highest = student[0][i];
        for(int j=0; j<5; j++){
            if (highest<student[j][i]){
                highest = student[j][i];
            }
            printf("Highest in subject %d is: %d", i, highest);
            printf("\n");
        }
    }
}