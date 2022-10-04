// Generate k-grams
#include <stdio.h>

void generateKGrams(int n, int k, char kGrams[][k + 1], char input[], int l);

void printKGrams(int n, int k, char kGrams[][k + 1]);

int length(char str[]);

int main(void)
{
    	char input[200];
	int k = 0;

	//printf("Input value of k: ");
	//scanf("%d", &k);
    	printf("Input the string: ");
    	scanf("%[^\n]", input);

	//printf("String length: %d\n", length(input));
	//printf("K value: %d\n", k);
    	printf("Input value of k: ");
    	scanf("%d", &k);

    	if(k < length(input)){
        
		int n = length(input) - k + 1;
        	char kGrams[n][k + 1];
        	int l = 0;
        	generateKGrams(n, k, kGrams, input, l);
        	
		for(int i = 0; i < n; i++)
        		printf("%s,", kGrams[i]);

		printf("\n");
    	}else
        	printf("Error: The value of k cannot be greater than the length of string");
}

void generateKGrams(int n, int k, char kGrams[][k + 1], char input[], int l){
    	
	for(l = 0; l < n; l++){
        	for(int i = 0; i < k; i++)
            		kGrams[l][i] = input[l + i];
        	
        	kGrams[l][k] = '\0';
    	}
}

void printKGrams(int n, int k, char kGrams[][k + 1]){

    	for(int j = 0; j < n; j++)
        	printf("%s,", kGrams[j]);
}

int length(char str[]){

    	int a = 0;
    	while(str[a] != '\0')
        	a++;
    	return a;
}
