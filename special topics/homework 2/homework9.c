#include <stdio.h>
#include <math.h>

int changeBase(int base , int number);
int sum(int number);
int checkPrime(int number);

int main(){

    int base , count;
    scanf("%d %d" , &base , &count);

    for (int i = 0;i < count;i++){
        int number;
        scanf("%d" , &number);
        number = changeBase(base , number);
        number = sum(number);
        if (checkPrime(number)){
            printf("Avvale!\n");
        }else{
            printf("Avval nist!\n");
        }
    }

    return 0;
}


int changeBase(int base , int number){
    int result = 0;

    int index = 0;
    while (number > 0){
        int num = number % 10;
        result += num * pow(base, index);
        number /= 10;
        index++;
    }
    return result;
}

int sum(int number){
    int result = 0;
    for (int i = 1 ; i <= number ; i++){
        if(number % i == 0){
            result += i;
        }
    }
    return result;
}

int checkPrime(int number){
    int count = 0;
    for (int i = 1; i <= number; i++){
        if (number % i == 0){
            count++;
        }
    }
    if (count == 2){
        return 1;
    }else{
        return 0;
    }
}