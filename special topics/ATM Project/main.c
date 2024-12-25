#include <stdio.h>

int prime(int number);

int main(){
	int a , b;
	scanf("%d %d" , &a , &b);

	for (int i = a ; i < b ; i++){
		if (prime(i)){
			printf("%d \t" , i);
		}
	}
	return 0;
}

int prime(int number){
	int count = 0;
	for (int i = 2 ; i < number ; i++){
		if (number % i == 0){
			count++;
		}
	}
	if (count == 0){
		return 1;
	}else{
		return 0;
	}
}