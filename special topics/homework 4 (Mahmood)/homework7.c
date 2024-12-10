#include <stdio.h>

int main() {

    char buffer[100];
    fgets(buffer, sizeof(buffer), stdin);

    char oldChar , newChar;
    scanf("%c %c" , &oldChar , &newChar);

    int count = 0;

    for (int i = 0 ; i < 100 ; i++){
        if (buffer[i] == '\0') break;

        if (buffer[i] == oldChar) {
            count = i;
        }
    }
    buffer[count] = newChar;

    printf("%s" , buffer);

    return 0;
}