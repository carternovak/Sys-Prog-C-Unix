// Q5 nth term of Arithmetic Progression
#include <stdio.h>

int main(void){
	
	int a;
	int d;
	int n;
	
	printf("Enter the starting number of AP series: ");
	scanf("%d", &a);
	printf("Enter the common difference: ");
	scanf("%d", &d);
	printf("Enter the nth term to be found: ");
	scanf("%d", &n);

	int formula = a + (n - 1) * d;
	printf("The %dth term of the series is: %d\n", n, formula);
}
