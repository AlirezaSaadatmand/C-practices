#include <stdio.h>

int main(){
    int number;
    scanf("%d" , &number);

    int sum = 0 , multiple = 1 , number1 = number , number2 = number , count1 = 0 , count2 = 0;

    while (number1 > 9)
    {
        while (number1 != 0)
        {
            sum += number1 % 10;
            number1 /= 10; 
        }
        if (sum>9){
            number1 = sum;
            sum = 0;
        }
        count1++;
    }
    printf("%d\n" , count1);

    while (number2 > 9)
    {
        while (number2 != 0)
        {
            multiple *= number2 % 10;
            number2 /= 10;
        }
        if (multiple > 9){
            number2 = multiple;
            multiple = 1;
        }
        count2++;
    }
    printf("%d\n" , count2);
    
    return 0;
}