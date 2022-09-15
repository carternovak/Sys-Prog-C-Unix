// Diamond Star
#include <stdio.h>

int main(void){

	int stars;
	printf("Enter the number of rows: \n");
	scanf("%d", &stars);
	
	while((stars % 2 == 0) || (stars < 0)){
		if((stars % 2 == 0) || (stars < 0)){
			printf("Error: Not a positive odd number\n");
			printf("Enter the number of rows: \n");
			scanf("%d", &stars);
		}
	}

	stars = stars/2 + 1;
	
	for(int i = 0; i < stars; i++){
		for(int j = 0; j < stars - i; j++)
			printf(" ");
		for(int j = 0; j < 2 * i - 1; j++)
			printf("*");
		printf("\n");
	}
	for(int i = 0; i < stars; i++){
		for(int j = 0; j < i; j++)
			printf(" ");
		for(int j = 0; j < 2 * (stars - i) - 1; j++)
			printf("*");
		printf("\n");
	}
}
