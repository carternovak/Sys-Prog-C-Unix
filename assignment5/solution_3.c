// Remove Duplicates
#include <stdio.h>

void printUniqueElements(int elements[], int lenArray);

int main(void){
	int length;

	printf("Input Size of Array: ");
	scanf("%d", &length);

	int numbers[length];

	printf("Input: ");
	for(int i = 0; i < length; i++)
		scanf(" %d", &numbers[i]);

	printUniqueElements(numbers, length);	
}

void printUniqueElements(int elements[], int lenArray){
	
	int i = 0;	
	int temp[lenArray];
	
	if(lenArray > 0){
		temp[0] = elements[0];
	}
	
	int counter = 1;
	for(int j = 1; j <= lenArray - 1; j++){
		if(elements[j - 1] != elements[j]){
			temp[++i] = elements[j];
			counter++;
		}
	}

	for(int a = 0; a < counter; a++)
		printf("%d ", temp[a]);
}

