#include <stdio.h>

void change(int m , int n , int x , int y);

int main(){
    int m , n , x , y , s;
    scanf("%d %d %d %d %d" , &m , &n , &x , &y , &s);

    for(int i = 0 ; i < s ; i++){
        int number;
        scanf("%d" , &number);

        if (number == 2){
            y++;
            if (y == n){
                y = 0;
            }
            change(m , n , x , y);
        }else if (number == 4){
            x--;
            if (x < 0){
                x = m - 1;
            }
            change(m , n , x , y);
        }else if (number == 6){
            x++;
            if (x == m){
                x = 0;
            }
            change(m , n , x , y);
        }else if (number == 8){
            y--;
            if (y < 0){
                y = n - 1;
            }
            change(m , n , x , y);
        }else{
            printf("Invalid number\n");
        }

    }

    return 0;
}

void change(int m , int n , int x , int y){
    for (int i = 0 ; i < m ; i++){
        for (int j = 0 ; j < n ; j++){
            if (j == x && i == y){
                printf(".");
            }else{
                printf("*");
            }
        }
        printf("\n");
    }
}