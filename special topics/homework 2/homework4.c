#include <stdio.h>

int main(){
    int count;
    scanf("%d" , &count);
    for(int i = 0;i < count;i++){
        int number;
        scanf("%d" , &number);
        switch (number)
        {
        case 1:
            printf("Saturday\n");
            break;
        case 2:
            printf("Sunday\n");
            break;
        case 3:
            printf("Monday\n");
            break;
        case 4:
            printf("Tuesday\n");
            break;
        case 5:
            printf("Wednesday\n");
            break;
        case 6:
            printf("Tursday\n");
            break;
        case 7:
            printf("Friday\n");
            break;
        default:
            break;
        }
    }
    return 0;
}