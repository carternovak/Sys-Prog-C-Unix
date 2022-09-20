// Compute the Series
#include <stdio.h>
#include <math.h>

int x, n, L, R, primeNumber;

int factorial(int num){

	if(num == 1)
		return 1;
	else
		return (num * factorial(num - 1));
}

int nextPrime(int L){

	for(int i = 2; i*i <= L; i++)
		if(L % i == 0)
			return nextPrime(L + 1);
	return L;

}

float computeSeries(int x, int n, int L, int R) {

	float result = 0;
	int bob = L;
	for(int i = 1; i <= n; i++){
		if(nextPrime(bob) < R){
			result += (pow(x, i) / factorial(i)) + nextPrime(bob);
			bob = nextPrime(bob) + 1;
		}else{
			result += (pow(x, i) / factorial(i));
		}

	}
	
	return result;
}

int main(void) {

	printf("Enter the value of X: ");
	scanf("%d", &x);	
	printf("Enter the value of n: ");
	scanf("%d", &n);	
	printf("Enter the value of L: ");
	scanf("%d", &L);	
	printf("Enter the value of R: ");
	scanf("%d", &R);
	
	printf("%f", computeSeries(x, n, L, R));	

}
