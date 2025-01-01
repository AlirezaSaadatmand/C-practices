#include <stdio.h>

struct Date {
    int year;
    int month;
    int day;
};


int main(){
    int n;
    scanf("%d", &n);
    struct Date dates[n];
    struct Date date;
    for (int i = 0 ; i < n ; i++){
        scanf("%d %d %d" , &date.day , &date.month , &date.year);
        dates[i] = date;
    }

    for (int date = 0 ; date < n ; date++){
        printf("%d.%d.%d\n", dates[date].year , dates[date].month , dates[date].day);
    }
    return 0;
}