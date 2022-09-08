// Income Calculator
#include <stdio.h>

int main(void){

	char employee;
	char marriage;
	char vacation;
	double monthSal;
	double weekSal;
	double hourSal;
	double annualSal;
	double normalSal;
	double overtimeSal;
	double productSal;
	double tax;
	double finalIncome;
	int overtimeMonth;
	int overtimeWeek;
	int overtimeDay;
	int normalWeek;
	int sold;

	printf("Input employee type: ");
	scanf("%c", &employee);

	if(employee == 'A'){
		printf("Input monthly salary: ");
		scanf("%lf", &monthSal);
		annualSal = monthSal * 12;
	} else if(employee == 'S'){
		printf("Input monthly salary: ");
		scanf("%lf", &monthSal);
		printf("Input overtime working hours each month: ");
		scanf("%d", &overtimeMonth);
		if(overtimeMonth > 10)
			overtimeMonth = 10;
		else if(overtimeMonth < 0)
			overtimeMonth = 0;
		normalSal = monthSal * 12;
		overtimeSal = 0.00625 * monthSal * 1.5 * overtimeMonth * 12;
		annualSal = normalSal + overtimeSal;
	} else if(employee == 'E'){
		printf("Input monthly salary: ");
		scanf("%lf", &monthSal);
		printf("Input overtime working hours per day: ");
		scanf("%d", &overtimeDay);
		if(overtimeDay > 1)
			overtimeDay = 1;
		else if(overtimeDay < 0)
			overtimeDay = 0;
		printf("Input sold product number in a year: ");
		scanf("%d", &sold);
		printf("Is this employee going to take a vacation for a month? ");
		scanf(" %c", &vacation);
		if(vacation == 'y'){
			normalSal = monthSal * 11 + monthSal * 0.5;
			overtimeSal = (1/160) * monthSal * 1.35 * overtimeDay * 20 * 11;
		}else{
			normalSal = monthSal * 12;
			overtimeSal = (1/160) * monthSal * 1.35 * overtimeDay * 20 * 12;
		}
		productSal = sold * 600;
		annualSal = normalSal + overtimeSal + productSal;
	} else if(employee == 'P'){
		printf("Input weekly salary: ");
		scanf("%lf", &weekSal);
		printf("Input overtime working hours each week: ");
		scanf("%d", &overtimeWeek);
		if(overtimeWeek > 10)
			overtimeWeek = 10;
		if(overtimeWeek < 0)
			overtimeWeek = 0;
		printf("Input sold product number in a year: ");
		scanf("%d", &sold);

		normalSal = weekSal * 48;
		overtimeSal = (1/40) * weekSal * overtimeWeek * 48;
		productSal = sold * 600;
		annualSal = normalSal + overtimeSal + productSal;
	} else if(employee == 'H'){
		printf("Input hourly salary: ");
		scanf("%lf", &hourSal);
		printf("Input normal working hours each week: ");
		scanf("%d", &normalWeek);
		if(normalWeek > 10)
			normalWeek = 10;
		if(normalWeek < 0)
			normalWeek = 0;
		normalSal = hourSal * normalWeek * 48;
		overtimeSal = hourSal * 1.25 * overtimeWeek * 48;
		annualSal = normalSal + overtimeSal;
	}

	printf("Is this Employee married (y/n): ");
	scanf(" %c", &marriage);

	if(marriage == 'y'){
		if(annualSal > 32000){
			tax = annualSal * .25;
			finalIncome = annualSal - tax;
		}else if(annualSal <= 32000){
			tax = annualSal * .1;
			finalIncome = annualSal - tax;
		}
	}else{
		if(annualSal > 64000){
			tax = annualSal * .25;
			finalIncome = annualSal - tax;
		}else if(annualSal <= 64000){
			tax = annualSal * .1;
			finalIncome = annualSal - tax;
		}
	}
	printf("This employee's annual income is $%lf before tax and $%lf after tax\n", annualSal, finalIncome);


}
