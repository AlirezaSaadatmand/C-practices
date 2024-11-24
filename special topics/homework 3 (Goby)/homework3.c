#include <stdio.h>
#include <math.h>
int checkFis(int a , int b , int c){
    if(pow(a , 2) + pow(b , 2) == pow(c , 2) || pow(a , 2) + pow(c , 2) == pow(b , 2) || pow(b , 2) + pow(c , 2) == pow(a , 2)){
        return 1;
    }else{
        return 0;
    }
}

int main(){

    int number;
    scanf("%d" , &number);
    int array[number];
    for (int i = 0; i < number; i++){
        scanf("%d" , &array[i]);
    }
    int count = 0;
    for(int i = 0 ; i < number ; i++){
        for (int j = i; j < number; j++){
            for (int k = j ; k < number ; k++){
                if(checkFis(array[i] , array[j] , array[k]) == 1){
                  count++;  
                }
            }
        }
    }
    printf("%d" , count);

    return 0;
}