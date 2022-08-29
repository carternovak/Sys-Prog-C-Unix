// Q3 Simple Arithmetic
#include <stdio.h>

int main(void){

	int a;
	int b;

	printf("Enter first integer 'a': ");
	scanf("%d", &a);
	printf("Enter second integer 'b': ");
	scanf("%d", &b);

	int sum = a + b;
	int difference = a - b;
	int product = a * b;
	int remainder = a % b;

	printf("The sum of %d and %d is: %d \n", a, b, sum);
	printf("The difference  of %d and %d is: %d \n", a, b, difference);
	printf("The product of %d and %d is: %d \n", a, b, product);
	printf("The remainder  of %d and %d is: %d \n", a, b, remainder);
}
