#include <stdio.h>

int main(){
    int flag = 0;
    int number;
    scanf("%d" , &number);
    int numbers[number];
    for (int i = 0; i < number ; i++){
        scanf("%d" , &numbers[i]);
    }

    for (int i = 0 ; i < number ; i++){
        int sum = 0;
        for (int j = 0 ; j < number ; j++){
            if (i != j){
                sum += numbers[j];
            }
        }
        if (numbers[i] == sum){
            flag = 1;
            break;
        }
    }
    if (flag){
        printf("YES");
    }else{
        printf("NO");
    }
    return 0;
}