#include <stdio.h>

void reverseString(char *str) {
    int size = 0;
    while (1){
        if (str[size] != '\0'){
            size++;
        }else{
            break;
        }
    }

    char temp;
    for (int i = 0 ; i <= size / 2 ; i++){
        temp = str[size - 1 - i];
        str[size - 1 - i] = str[i];
        str[i] = temp;
    }
}

int main() {
    char str[100];

    scanf("%s", str);

    reverseString(str);

    printf("%s\n", str);

    return 0;
}
