#include <stdio.h>

int kashi(int tol){

    if (tol == 2){
        return 2;
    }else if(tol == 1){
        return 1;
    }else if(tol == 0){
        return 0;
    }else{
        return kashi(tol - 1) + kashi(tol - 2);
    }

}

int main(){

    printf("%d" , kashi(8));

    return 0;
}