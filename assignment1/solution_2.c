// Printing a custom sentence
#include <stdio.h>

int main(void) {
	int month;
	int year;
	int age;
	
	printf("Enter current month: ");
	scanf("%d", &month);

	printf("Enter current year: ");
	scanf("%d", &year);

	printf("Enter your age: ");
	scanf("%d", &age);

	printf("It is month %d of the year %d and you are %d years old!\n", month, year, age);
}
