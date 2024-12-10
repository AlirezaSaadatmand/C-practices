#include <stdio.h>

int main() {

    int lettersCursor = 0;

    char letters[100];
    int count[100];

    for (int i = 0 ; i < 100 ; i++){
        count[i] = 0;
    }

    char buffer[100];
    fgets(buffer, sizeof(buffer), stdin);
    
    for (int i = 0 ; i < sizeof(buffer) / sizeof(char) ; i++){
        if (buffer[i] == '\0') break;
        int in = -1;
        for (int j = 0 ; j < lettersCursor ; j++){
            if (letters[j] == buffer[i]) {
                in = j;
            }
        }
        if (in != -1){
            count[in] += 1;

        } else {
            if (buffer[i] != ' '){
                letters[lettersCursor] = buffer[i];
                count[lettersCursor]++;
                lettersCursor++;
            }
        }
    }
    int max = 0;
    for (int i = 0 ; i < lettersCursor-1 ; i++){
        if (count[i] > max){
            max = count[i];
        }
    }
    printf("%d" , max);
    return 0;
}