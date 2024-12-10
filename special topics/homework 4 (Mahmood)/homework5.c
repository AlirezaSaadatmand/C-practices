#include <stdio.h>
int main() {
    char string[100];
    scanf("%s" , &string);

    for (int i = 0; i < 100; i++) {
        if ( string[i] == '\0' ) {
            break;
        }
        int checkNext = 1;
        for (char c = 'a'; c <= 'z'; ++c){
            if (string[i] == c) {
                printf("%c" , string[i]);
                checkNext = 0;
                break;
            }
        }
        if (!checkNext){
            continue;
        }
        for (char c = 'A'; c <= 'Z'; ++c){
            if (string[i] == c) {
                printf("%c" , string[i]);
                break;
            } 
        }
    }
    return 0;
}