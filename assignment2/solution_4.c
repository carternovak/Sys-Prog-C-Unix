// Date Validity
#include <stdio.h>

int main(void){

	int year;
	int month;
	int day;
	int leapYear;

	printf("Enter a year: ");
	scanf("%d", &year);
	printf("Enter a month: ");
	scanf("%d", &month);
	printf("Enter a day: ");
	scanf("%d", &day);
	
	if(year % 4 != 0)
		leapYear = 0;
	else if(year % 100 != 0)
		leapYear = 1;
	else if(year % 400 != 0)
		leapYear = 0;
	else
		leapYear = 1;

	if((year < 0) || (day < 0) || (month < 0) || (day > 31) || (month > 12))
		printf("The date is invalid.\n");
	else if (((month == 4) || (month == 6) || (month == 9) || (month == 11)) && (day > 30))
		printf("The date is invalid.\n");
	else if ((month == 2) && (leapYear == 0) && (day > 28))
		printf("The date is invalid.\n");
	else if ((month == 2) && (leapYear == 1) && (day > 29))
		printf("The date is invalid.\n");
	else
		printf("The date is valid.\n");



}
