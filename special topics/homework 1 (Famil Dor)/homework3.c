#include <stdio.h>

int main(){
    int first , second , number;
    scanf("%d %d" , &first ,&second);
    scanf("%d" , &number);
    int sum = 0;
    for(int i = first;i < second;i++){
        int count = 0;
        for(int j = 1;j <= i;j++){
            if (i % j == 0){
                count++;
            }
        }
        if(count == 2){
            sum += i;
        }
    }
    printf("%d" , sum - number);
    return 0;
}