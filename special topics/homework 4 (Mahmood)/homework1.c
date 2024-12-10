#include <stdio.h>

void sort(int* arr){
    int temp;
    for (int i = 0 ; i < 5 ; i++){

        for (int j = 0 ; j < i ; j++){
            if ( arr[i] < arr[j]){
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }

    }
}

int main(){

    int numbers[5];
    for (int i = 0 ; i < 5 ; i++){
        scanf("%d" , &numbers[i]);
    }

    sort(numbers);

    for (int i = 0 ; i < 5 ; i++){
        printf("%d\n" , numbers[i]);
    }

    return 0;
}