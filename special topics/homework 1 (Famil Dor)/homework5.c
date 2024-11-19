#include <stdio.h>

int main(){
    int a , b , n;
    scanf("%d %d %d" , &a , &b , &n);
    for(int i = 1 ; i < n;i++){
        if (a % i == 0 && (a - i) % b == 0){
            printf("%d  %d\n" , i , n - i); 
        }
    }
    return 0;
}