#include <stdio.h>

int main(){
    int number;
    scanf("%d" , &number);
    int array[number];
    for (int i = 0;i < number;i++){
        scanf("%d" , &array[i]);
    }
    int count = 0;
    for (int i = 0 ; i < number ; i++){
        for (int j = 0 ; j < number ; j++){
            if(j > i && array[i] > array[j]){
                count++;
            }
        }
    }
    printf("%d" , count);
    return 0;
}