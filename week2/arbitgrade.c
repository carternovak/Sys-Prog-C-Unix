// program asks user to enter grade for arbitrary number of students and computers average
#include <stdio.h>

int main(void){

	int grade;
	int total = 0;
	float avg = 0.0;
	int counter = 0;

	// add this grade to total
	puts("Enter Grade");
	scanf("%d", &grade);

	// iterate x times
	while(grade != -1){
		// add this grade to total
		total += grade;
		// incremenet counter
		counter += 1;
		// get grade from user
		puts("Enter Grade");
		scanf("%d", &grade);
	}

	// compute average
	if(counter > 0)	
		avg = (float) total / counter;
	// print average
	printf("Class average is %f\n", avg);
}
