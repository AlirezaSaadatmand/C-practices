#include <stdio.h>

int *get_next_prime_number(int m, int n,int *arr){
    int counter = 0;
    while (counter != n){
        m++;
        int c = 0;
        for (int i = 2; i <= m / 2; i++) {
            if (m % i == 0){
                c++;
            }
        }
        if (c == 0){
            arr[counter] = m;
            counter++;
        }
        
    }
    return arr;
}

int main() {

    int i , m , n;
    scanf("%d %d", &m, &n);

    int arr[n];

    int *primes = get_next_prime_number(m, n, arr);

    for( i = 0 ; i < n ; i++){
        printf("%d\n", *(primes + i));
    }

    return 0;
}