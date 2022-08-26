// program takes two numbers from user and print their sum
#include <stdio.h>

int main(void){

	// define two int variables
	int number1 = 0;
	int number2 = 0;

	// prompt the user to input first number
	printf("Enter first number: \n");
	scanf("%d", &number1);

	// prompt the user to input second number
	printf("Enter second number: \n");
	scanf("%d", &number2);

	// define a variable for sum
	int sum = 0;
	sum = number1 + number2;

	// print the sum
	printf("The sum is %d\n", sum);
}

