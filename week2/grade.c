// program takes marks from user and prints pass or fail
#include <stdio.h>

int main(void){

	int marks;
	printf("enter marks\n");
	scanf("%d", &marks);

	// if marks are >= 60
	if(marks >= 60){
		puts("Pass");
	}
	// else
	else {
		puts("Fail");
	}

}

