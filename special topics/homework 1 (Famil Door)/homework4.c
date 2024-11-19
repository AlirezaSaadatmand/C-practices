#include <stdio.h>

int main(){
    int number;
    scanf("%d" , &number);
    int flag = 1;
    int first = number % 10;
    while (1){
        int reminder = number % 10;
        if (first == 0 && flag){
            flag = 0;
        }else{
            printf("%d" , reminder);
        }
        number = number / 10;
        if (number == 0){
            break;
        }
    }
    return 0;
}