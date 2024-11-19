#include <stdio.h>

int main(){
    int number , first , sec , num1 , num2;
    scanf("%d %d %d" , &number , &first , &sec);
    int count = 1;
    while (number / 10 != 0){
        int num = number % 10;
        number /= 10;

        if (count == first){
            num1 = num;
        }else if (count == sec){
            num2 = num;
        }
        count++; 
    }
    if (num1 * num2 > 9){
        printf("%d" , num1 * num2 / 10 + num1 * num2 % 10);
    }else{
        printf("%d" , num1 * num2);
    }

    return 0;
}