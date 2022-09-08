// Simple Calculator
#include <stdio.h>
#include <math.h>

int main(void){

	double num1;
	double num2;
	char operator;
	double solution;

	scanf("%lf %c %lf", &num1, &operator, &num2);

	switch(operator) {
		case'+': 
			solution = num1 + num2;
			printf("%lf\n", solution);
			break; 
		case'-': 
			solution = num1 - num2;
			printf("%lf\n", solution);
			break; 
		case'*': 
			solution = num1 * num2;
			printf("%lf\n", solution);
			break; 
		case'/':
		       if (num2 == 0){
		       		printf("Error: dividing by zero\n");
		 		break;
		       }else{
	       			solution = num1 / num2;
	 			printf("%lf\n", solution);
				break;
		       }			
		case'%': 
		        solution = (int)num1 % (int) num2;
			printf("%d\n", (int)solution);
			break; 
		case'^': 
			solution = pow(num1, num2);
			printf("%lf\n", solution);
			break; 
		case'r': 
			solution = pow(num2, (1 / num1));
			printf("%lf\n", solution);
			break; 
	}

}
