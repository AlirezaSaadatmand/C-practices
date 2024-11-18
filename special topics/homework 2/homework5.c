#include <stdio.h>

int factorial(int number);
int main(){

    int fnum , snum = 0;
    char op;
    
    scanf("%d %c" , &fnum , &op , &snum);
    if (op == '!'){
        printf("%d" , factorial(fnum));
    }else{
        scanf("%d" , &snum);
        if (op == '+'){
            printf("%d" , fnum + snum);
        }else if(op == '-'){
            printf("%d" , fnum - snum);
        }else if(op == '*'){
            printf("%d" , fnum * snum);
        }else if(op == '/'){
            if (snum != 0){
                printf("%d" , fnum / snum);
            }
        }
    }
    return 0;
}

int factorial(int number){
    int result = 1;
    for(int i = number ; i>0;i--){
        result *= i;
    }
    return result;
}