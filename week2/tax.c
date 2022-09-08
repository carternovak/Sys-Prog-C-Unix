// program asks user for status and income and compute applicable tax
#include <stdio.h>

int main(void){

	int status;
	float income;
	float tax;

	// get user input
	puts("Enter status; 0 = Single, 1 = Married");
	scanf("%d", &status);
	puts("Enter income");
	scanf("%f", &income);
	
	// if status is single
	if(status == 0){
		// if income <= 32000
		// tax is 10% of income
		if(income <= 32000){
			tax = 0.1 * income;
		}
		// if income > 32000
		// tax is 3200 + 25% of the amount over 32000
		else if(income > 32000){
			tax = 3200 + 0.25 * (income - 32000);
		}
	}
	// else if status is married
	else if(status == 1){
		// if income <= 64000
		// tax is 10% of income
		if(income <= 64000){
			tax = 0.1 * income;
		}
		// if income > 64000
		// tax is 6400 + 25% of the amount over 64000
		else if(income > 64000){
			tax = 6400 + 0.25 * (income - 64000);
		}
	}

	printf("The tax is %.2f\n", tax);
}
