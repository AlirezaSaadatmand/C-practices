#include <stdio.h>

int main(){

    int count;
    scanf("%d" , &count);

    int money = 1000;

    int bought = 0;

    int lastPrice = 0;

    int bagCount = 0;

    for (int i = 0 ; i < count;i++){
        int input;
        scanf("%d" , &input);
        if((input < lastPrice || i == count -1) && bought){
            if (i != count - 1){
                money = bagCount * lastPrice;
                bought = 0;
            }else{
                money = bagCount * input;
                bought = 0;
            }
        }
        if(!bought && money > input){
            bought = 1;
            bagCount = money / input;
        }
        lastPrice = input;
    }
    
    printf("%d" , money - 1000);

    return 0;
}