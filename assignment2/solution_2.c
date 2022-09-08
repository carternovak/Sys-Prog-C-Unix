// Triangle Properties
#include <stdio.h>

int main(void){

	int firstA;
	int secondA;
	int thirdA;
	int isValid;
	int iso;

	printf("Input first angle: ");
	scanf("%d", &firstA);
	printf("Input second  angle: ");
	scanf("%d", &secondA);
	printf("Input third angle: ");
	scanf("%d", &thirdA);

	if(((firstA + secondA + thirdA) == 180) && (firstA > 0) && (secondA > 0) && (thirdA > 0)){
		printf("The triangle is valid\n");
		isValid = 1;
	}else{
		printf("The triangle is invalid\n");
		isValid = 0;
	}
	if(isValid == 1){
		if (firstA && secondA && thirdA < 90)
			printf("It's an acute triangle\n");
		else if (firstA || secondA || thirdA == 90)
			printf("It's a right triangle\n");
		else if (firstA || secondA || thirdA > 90)
			printf("It's an obtuse triangle\n");
	}

	if(isValid == 1){
		if ((firstA == secondA) && (firstA == thirdA)){
			printf("It's isosceles\n");
			iso = 1;
		}
		else if ((firstA == secondA) && (secondA == thirdA)){
			printf("It's isosceles\n");
			iso = 1;
		}
		else if ((firstA == thirdA) && (secondA == thirdA)){
			printf("It's isosceles\n");
			iso = 1;
		}
		else{
			printf("It's not isosceles\n");
			iso = 0;
		}
	}
	if(iso == 1){
		if((firstA == secondA) && (secondA == thirdA))
			printf("The triangle is equilateral\n");
	}

}
		
