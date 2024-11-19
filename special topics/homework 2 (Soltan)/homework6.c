#include <stdio.h>

int main(){
    int i,j,k,n,c;
    printf("\n Enter the limit: ");
    scanf("%d",&n);
    printf("\n ");
     
    for(i=0;i<n;i++)
    {
        c=1;
        for(j=0;j<=i;j++){
            printf(" %d ",c);
            c=(c*(i-j)/(j+1));
        }
        printf("\n");
    }
    
    return 0;
}