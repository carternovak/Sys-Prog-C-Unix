// Merge Sorted Arrays
#include <stdio.h>

void printSortedMergedArray(int array1[], int lenArray1, int array2[], int lenArray2);

int main(void){

	int length1, length2;
	printf("Input size of array 1: ");
	scanf("%d", &length1);

	int set1[length1];
	printf("Input array 1: ");
	for(int i = 0; i < length1; i++)
        	scanf(" %d", &set1[i]);

	printf("Input size of array 2: ");
	scanf("%d", &length2);

	int set2[length2];
	printf("Input array 2: ");
	for(int j = 0; j < length2; j++)
        	scanf(" %d", &set2[j]);

	printSortedMergedArray(set1, length1, set2, length2);

}

void printSortedMergedArray(int array1[], int lenArray1, int array2[], int lenArray2){

	int i, j, counter = 0;
	int total = lenArray1 + lenArray2;
	int result[total];

	for(i = 0; i < lenArray1; i++){
	
		if(j == lenArray2){
			i--;
			break;
		}else if(i == lenArray1){
			j--;
			break;	
		}

		for(j = 0; j < lenArray2; j++)
		{
			if(array1[i] < array2[j]){
				result[counter] = array1[i];
				counter++;
				i++;
				j--;
			}else if(array1[i] > array2[j]){
				result[counter] = array2[j];
				counter++;
			}else{
				result[counter] = array1[i];
				counter++;
				i++;
				result[counter] = array2[j];
				counter++;
			}
		}
	}

	while(i < lenArray1){
		result[counter] = array1[i];
		i++;
		counter++;
	}
	while(j < lenArray2){
		result[counter] = array2[j];
		j++;
		counter++;
	}

	if(lenArray1 == 0){
		for(int x = 0; x < lenArray2; x++)
			printf("%d ", array2[x]);
	}else if(lenArray2 == 0){
		for(int y = 0; y < lenArray1; y++)
			printf("%d ", array1[y]);
	}else{
		for(int a = 0; a < total; a++)
			printf(" %d", result[a]);
	}
}
