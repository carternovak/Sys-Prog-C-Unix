// Binomial Distribution
#include<stdio.h>
#include<math.h>

float binomialDistribution(int k, int n, float p);

int main(void){

        int k;
        int n;
        float p;

        printf("Enter k value: ");
        scanf("%d", &k);
        printf("Enter n value: ");
        scanf("%d", &n);
        printf("Enter p value: ");
        scanf("%f", &p);

        printf("The answer is: %f\n", binomialDistribution(k, n, p));

}

float binomialDistribution(int k, int n, float p){

        int result = 1;
	int a = k;
        if (a > n /2){
                a = n - a;
        }

        for (int i = 1; i <= a; i++){
                result *= (n - a + i);
                result /= i;
        }

        return result * pow(p, k) * pow(1 - p, n - k);

}

