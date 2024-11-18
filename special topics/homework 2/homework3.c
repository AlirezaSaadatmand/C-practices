#include <stdio.h>

int main(){

    int fnum = 0 , snum = 0 , tnum = 0 , fcount = 0 , scount = 0 , tcount = 0;

    while (1){
        int number;
        scanf("%d" , &number);
        if (fnum == 0){
            fnum = number;
            fcount++;
        }else if(!snum && number != fnum){
            snum = number;
            scount++;
        }else if(!tnum && number != fnum && number != snum){
            tnum = number;
            tcount++;
        }else{
            if (number == fnum){
                fcount++;
            }else if(number == snum){
                scount++;
            }else if(number == tnum){
                tcount++;
            }
        }
        if(fnum != number && snum != number && tnum != number){
            break;
        }
    }
    
    printf("%d\n%d\n%d" , fcount , scount , tcount);
    return 0;
}