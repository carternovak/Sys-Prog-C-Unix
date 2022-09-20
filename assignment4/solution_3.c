// Perfect number
#include <stdio.h>

int isPerfectNumber(int num);

int main(void){

	int num;
	printf("Enter a number: ");
	scanf("%d", &num);
	isPerfectNumber(num);
}

int isPerfectNumber(int num){

	int sum = 0;
	for(int i = 1; i <= num / 2; i++){
		if(num % i == 0)
			sum += i;
	}

	if(sum == num && num > 0)
		printf("%d is a perfect number\n", num);
	else
		printf("%d is not a perfect number\n", num);

}
