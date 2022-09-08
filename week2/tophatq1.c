// Top Hat Question
#include <stdio.h>

int main(void){

	int marks;
	printf("Enter marks\n");
	scanf("%d", &marks);

	// if marks are >= 90
	if(marks >= 90){
		puts("A");
	}
	// else
	else if(marks >= 80){
		puts("B");
	}
	else if(marks >= 70){
		puts("C");
	}
	else if(marks >= 60){
		puts("D");
	}
	else if(60 > marks){
		puts("F");
	}

