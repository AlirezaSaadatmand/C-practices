#include <stdio.h>

int main(){

    int number;
    scanf("%d" , &number);

    int matrix[number][number];

    for (int i = 0 ; i < number ; i++){
        for (int j = 0 ; j < number ; j++){
            scanf("%d" , &matrix[i][j]);
        }
    }

    for (int i = 0; i < number; i++){
        for (int j = 0; j < number; j++){
            if (i <= j){
                printf("%d " , matrix[i][j]);
            }else{
                printf("  ");
            }
        }
        printf("\n");
    }

    return 0;
}