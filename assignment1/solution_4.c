// Q4 Circle Area, Diameter and Circumference
#include <stdio.h>

int main(void) {
	
	float pi = 3.14159;
	int r;
	printf("Enter the radius: ");
	scanf("%d", &r);

	int area = pi * r * r;
	int diameter = 2 * r;
	int circum = 2 * pi * r;

	printf("The Area of a circle with radius %d is %d\n", r, area); 
	printf("The Diameter of a circle with radius %d is %d\n", r, diameter); 
	printf("The Circumference of a circle with radius %d is %d\n", r, circum); 
}
