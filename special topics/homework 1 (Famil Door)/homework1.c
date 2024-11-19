#include <stdio.h>

int main(){
    int count;
    scanf("%d" , &count);
    int result = 0;
    for (int i = 0;i < count;i++){
        int r;
        scanf("%d" , &r);
        result += r;
    }
    printf("%d" , result);
    return 0;
}