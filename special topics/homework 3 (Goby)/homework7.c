#include <stdio.h>

int main(){

    int number;
    scanf("%d" , &number);

    int matrix[number][number];
    for (int i = 0; i < number; i++){
        for (int j = 0; j < number; j++){
            scanf("%d" , &matrix[i][j]);
        }
    }

    int ei , ej;

    for (int i = 0 ; i < number ; i++){
        for (int j = 0 ; j < number ; j++){
            ei = j;
            ej = i;
            if (matrix[i][j] != matrix[ei][ej]){
                printf("NO");
                return 0;
            }
        }
    }
    printf("YES");
    return 0;
}