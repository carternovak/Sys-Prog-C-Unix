// Even or odd
#include <stdio.h>

int main(void){
	
	int num;
	printf("Input a number: ");
	scanf("%d", &num);

	if(num % 2 == 0){
		printf("%d is an even number\n", num);
	}else
		printf("%d is an odd number\n", num);
}
