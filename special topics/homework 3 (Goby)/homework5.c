#include <stdio.h>

int calc(int a , int b){
    int number = 1;
    int min = a < b ? b : a;
    for (int i = 1 ; i <= min ; i++){
        if(a % i == 0 && b % i == 0){
            number = i;
        }
    }
    return number;
}

int main(){

    int number;
    scanf("%d" , &number);
    int numbers[number];
    for (int i = 0 ; i < number ; i++){
        scanf("%d" , &numbers[i]);
    }
    int result = 0;
    for (int i = 0 ; i < number ; i++){
        for (int j = i ; j < number ; j++){
            int r = calc(numbers[i] , numbers[j]);
            if(result < r && i != j){
                result = r;
            }
        }
    }
    printf("%d" , result);
    return 0;
}