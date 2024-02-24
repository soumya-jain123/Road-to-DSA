// Wap to convert a uppercase string to lowercase using for loop

#include<stdio.h>
int main(){
    char uppercaseStr[30] ;
    printf("Enter the string you want to be converted: ");
    scanf("%s", &uppercaseStr);
    char lowercaseStr[sizeof(uppercaseStr)];

    for(int i=0; uppercaseStr[i] != '\0'; i++){
        if(uppercaseStr[i] >= 'A' && uppercaseStr[i]<= 'Z'){
            lowercaseStr[i] = uppercaseStr[i] + ('a' - 'A');
        }else{
            lowercaseStr[i] = uppercaseStr[i];
        }
    }

    lowercaseStr[sizeof(uppercaseStr) - 1] = '\0';

    printf("Uppercase string : %s\n", uppercaseStr);
    printf("Lowercase string : %s\n", lowercaseStr);

}