// Jaccard Similarity
#include <stdio.h>

void checkSet(int input[], int input_length);

int findIntersection(int input1[], int input1_length, int input2[], int input2_length);

int findUnion(int input1[], int input1_length, int input2[], int input2_length);

void calculateJaccard(int input1[], int input1_length, int input2[], int input2_length);

int main(void){

	int length1, length2;
	printf("Input first set length: ");
	scanf("%d", &length1);

	int set1[length1];
	printf("Input first set: ");
	for(int i = 0; i < length1; i++)
		scanf(" %d", &set1[i]);

	printf("Input second set length: ");
	scanf("%d", &length2);

	int set2[length2];
	printf("Input second set: ");
	for(int j = 0; j < length2; j++)
		scanf(" %d", &set2[j]);

	calculateJaccard(set1, length1, set2, length2);
}

void checkSet(int input[], int input_length){
	
	if(input_length == 0)
		printf("Set cannot be empty");
}

int findIntersection(int input1[], int input1_length, int input2[], int input2_length){

	int counter = 0;

	for(int i = 0; i < input1_length - 1; i++){
		for(int j = 0; j < input2_length - 1; j++){
			if(input1[i] == input2[j])
				counter++;
		}
	}
	return counter;
	/*
	int intersect[counter];
	int temp = 0;
	for(int a = 0; a < input1_length - 1; a++){
		for(int b = 0; b < input2_length - 1; b++){
			if(input1[a] == input2[b]){
				intersect[temp] = input1[a];
				temp++;
			}
		}
	}

	for(int x = 0; x < counter; x++)
		printf("%d ", intersect[x]);
	*/
}

int findUnion(int input1[], int input1_length, int input2[], int input2_length){

	int counter = 0;
	int m = input1[input1_length - 1];
    	int n = input2[input2_length - 1];
    	int ans = 0;
    	if (m > n)
        	ans = m;
    	else
        	ans = n;

    	int table[ans + 1];
    	for (int i = 0; i < ans + 1; i++)
        	table[i] = 0;

	counter++;
     	++table[input1[0]];

     	for (int i = 1; i < input1_length; i++) {
         	if (input1[i] != input1[i - 1]) {
            		++table[input1[i]];
			counter++;
        	}
    	}

    	for (int j = 0; j < input2_length; j++) {
        	if (table[input2[j]] == 0) {
            		++table[input2[j]];
			counter++;
        	}
    	}
	return counter;
}

void calculateJaccard(int input1[], int input1_length, int input2[], int input2_length){

	double intersect = findIntersection(input1, input1_length, input2, input2_length);
	double numUnion = findUnion(input1, input1_length, input2, input2_length);
	printf("Jaccard similarity is %.2f\n", intersect / numUnion);
}
