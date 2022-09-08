// program asks user to enter grade for 10 students and computers average
#include <stdio.h>

int main(void){

	int grade;
	int total = 0;
	float avg;
	int counter = 1;

	// iterate 10 times
	while(counter <= 10){
		// get grade from user
		puts("Enter Grade");
		scanf("%d", &grade);

		// add this grade to total
		total = total + grade;
		// incremenet counter
		counter += 1;
	}

	// compute average
	avg = (float) total / 10;
	// print average
	printf("Class average is %f\n", avg);
}
