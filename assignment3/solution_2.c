// Prime Factorization
#include <stdio.h>

int main(void){

	int num;

	printf("Enter a positive integer that you wish to find prime factors of: ");
	scanf("%d", &num);
	if(num == 1)
		printf("1 has no prime factorization");
	else {
		int prime = 2;
		printf("The prime factorization of %d is: ", num);
		while (num > 1){
			if(num % prime == 0){
				printf("%d ", prime);
				num /= prime;
			}else
				prime++;
		}
	}

}
