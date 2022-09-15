// Reverse Binary
#include <stdio.h>
#include <string.h>
int main(void){
	int num, remainder;
	int i = 1;
	int bin = 0;
	char finalBin[100];
	char result[100];
	int a,count = 0;
	printf("Enter a number to find the reverse binary representation: ");
	scanf("%d", &num);
	if(num < 0)
		printf("Error: Number must be a positive integer.");
	else{
	while(num != 0){
		remainder = num % 2;
		num /= 2;
		bin += remainder * i;
		i *= 10;
	}
	sprintf(finalBin, "%d", bin);

	while(finalBin[count] != '\0')
		count++;
	a = count - 1;
	
	for(int b = 0; b < count; b++){
		result[b] = finalBin[a];
		a--;
	
	}
	printf("%s\n", result);
	}
}
