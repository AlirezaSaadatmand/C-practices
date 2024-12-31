#include <stdio.h>

struct Date {
    int year;
    int month;
    int day;
};


int main(){
    int n;
    scanf("%d", &n);
    struct Date date;
    for (int i = 0 ; i < n ; i++){
        scanf("%d %d %d" , &date.day , &date.month , &date.year);
        printf("%d.%d.%d", date.year , date.month , date.day);
    }
    return 0;
}