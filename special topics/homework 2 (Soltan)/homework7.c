#include <stdio.h>

int main(){

    int number;
    scanf("%d" , &number);

    int change;
    int changeCount = 0;

    int lastNumber;
    int count = 0;
    while (number / 10 != 0){
        int num = number % 10;
        number /= 10;
        
        if (count != 0){
            if (num > lastNumber){
                if (change == 0){
                    changeCount++;
                }
                change = 1;
            }else if (num < lastNumber){
                if (change == 1){
                    changeCount++;
                }
                change = 0;
            }
        }
        lastNumber = num;
        count++;
    }
    printf("%d" , changeCount);
    if (changecount > 1){
        printf("Bad Tartibe!");
    }else{
        printf("Khosh Tartibe!");
    }
    return 0;
}