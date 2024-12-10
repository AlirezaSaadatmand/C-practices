#include <stdio.h>
#include <ctype.h>

int main() {

    char buffer[100];
    fgets(buffer, sizeof(buffer), stdin);

    for (int i = 0 ; i < 100 ; i++){
        if ( buffer[i] == '\0' ) break;

        int checkNext = 1;
        for (char c = 'a'; c <= 'z'; ++c){
            if (buffer[i] == c) {
                buffer[i] = toupper(buffer[i]);
                checkNext = 0;
                break;
            }
        }
        if (!checkNext){
            continue;
        }
        for (char c = 'A'; c <= 'Z'; ++c){
            if (buffer[i] == c) {
                buffer[i] = tolower(buffer[i]);
                break;
            } 
        }   
    }

    for (int i = 0 ; i < 100 ; i++){
        if (buffer[i] == '\n') break;
        printf("%c", buffer[i]);
    }

    return 0;
}