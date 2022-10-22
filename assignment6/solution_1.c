#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MAX_WORD_SIZE 46
/* Splits the input string to individual words
   Input: pointer to char array
   Output: array of pointers (to char arrays) */

/*
 DISCLAIMER
 We were not able to get the getStudentAnswers function to work because the stuAns array had issues when taking user input so I hardcoded answers to still demonstrate the cosine similarity. Accessing the array of pointers for the instructor and student answers gave us several segmentation fault errors so calling the functions with the arrays became difficult. I put what was in the cosine similarity function into the ans2Vectors function.
*/
char* stuAns[5] = {"Local variables are variables defined in a function.", "A name given to variables and functions.", "Recursion is calling the defined function within itself.", "Variable that stores the memory address.", "Making a local array static means the array will not be initialized and destroyed every time it is called and exited."};
char** getStudentAnswers(const char** questions, int n, int len);

int** ans2Vectors(char *instructor_answer, char *student_answer);

double cosineSimilarity(char *instructor_answer, char *student_answer);

char** tokenize(char* str) {
    	
	size_t str_len = strlen(str);
    	if (str_len == 0)
        	return NULL;
    	
	char** tokens = malloc(sizeof(char*) * 2);
    	int token_size = 2;
    	char word[MAX_WORD_SIZE] = "\0";
    	int word_count = 0;
    	
	for (register int i = 0, j = 0; i < str_len + 1; i++) {
        	if (str[i] == ' ' || str[i] == ',' || str[i] == '.' || str[i] == '\0' || i == str_len) {
            	size_t word_len = strlen(word);
            	// Add a null character at the end
            	if (word_len >= MAX_WORD_SIZE)
                	word[j - 1] = '\0';
            	else if (word_len > 0)
                	word[j] = '\0';
            	else { // Empty word
                	j = 0;
                	continue;
            	}             
            	// Grow size
            	if (word_count >= token_size - 1) {
                	token_size *= 2;
                	tokens = realloc(tokens, sizeof(char*) * token_size);
            	}
            	
		tokens[word_count] = malloc(sizeof(char) * word_len + 1);
            	strcpy(tokens[word_count++], word);
            	j = 0;
            	word[0] = '\0';
            	continue;
        	}

        	if (j < MAX_WORD_SIZE - 1)
        	    	word[j++] = str[i];
    	}

    	if (word_count == 0)
        	tokens[1] = NULL;
    	
	tokens[word_count] = NULL;
    	return tokens;
}
/* Removes duplicates from an array of pointers to char arrays
 * Input: array of pointers to char arrays (containing duplicates)
 * Output: array of pointers to char array (duplicates removed) */
char** getUniqueWords(char** strs) {
    	char** uniques = malloc(sizeof(char*) * 2);
    	int unique_size = 2;
    	int unique_count = 0;
    	for (register int i = 0; ; i++) {
        	if (strs[i] == NULL)
            		break;
        	// Detect duplication
        	bool is_duplicated = false;
        	for (register int j = 0; j < unique_count; j++) {
            		if (strcmp(strs[i], uniques[j]) == 0) {
                		is_duplicated = true;
                		break;
            		}
        	}
        	if (!is_duplicated) {
            
            		// Grow size
            		if (unique_count >= unique_size - 1) {
                	unique_size *= 2;
                	uniques = realloc(uniques, sizeof(char*) * unique_size);
            		}

            		uniques[unique_count] = malloc(sizeof(char) * strlen(strs[i]) + 1);
            		strcpy(uniques[unique_count++], strs[i]);
        	}
    	}
    	if (unique_count == 0) {
        	free(uniques);
        	return NULL;
    	}
    	uniques[unique_count] = NULL;
    	return uniques;
}
/* Free a pointer array of words */
void freeWords(char** ptr) {
    	for (register int i = 0; ; i++) {
        	if (ptr[i] == NULL)
            		break;
        	free(ptr[i]);
    	}
    	free(ptr);
}
int main(void) {
/*  
	char** tokens = tokenize("a pointer is a variable that stores the memory address of another variable as its value.");
    
    	char** uniques = getUniqueWords(tokens);

    	for (register int i = 0; ; i++) {
        	if (uniques[i] == NULL)
            		break;
        	printf("%s\n", uniques[i]);
    	}
    	freeWords(tokens);
    	freeWords(uniques);
    	return 0;
*/
	const char* questions[5] = {"What are local variables?", "What is an identifier?", "What is recursion?", "What is a pointer?", "What is the purpose of applying static to a local array?"};
	char* instrAns[5] = {"Variables defined in function definition are local variables. They can be accessed only in that function scope.", "Identifiers are user defined names given to variables, functions and arrays.", "A function calling itself again and again to compute a value is referred to as recursive function or recursion. Recursion is useful for branching processes and is effective where terms are generated successively to compute a value.", "A pointer is a variable that stores the memory address of another variable as its value.", "By making a local array definition static the array is not created and initialized every time the function is called and it is not destroyed every time the function is exited. Also, the execution time is reduced."};
	//getStudentAnswers(questions, 5, 500);
	for(int i = 0; i < 5; i++){
		printf("Marks for question %d: ", i + 1);
		ans2Vectors(instrAns[i], stuAns[i]);
		printf("\n");
	}
}

/*char ** getStudentAnswers(const char ** questions, int n, int len){

	//char* stuAns[5] = {"one", "two", "three", "four", "five"};
	char *temp[500];
	for(int i = 0; i < n; i++){
		printf("%s\n", questions[i]);
		scanf("%500s", *temp);
		//fgets(stuAns[i], len, stdin);
		stuAns[i] = *temp;
		//printf("Answer: %s", stuAns[1]);
	}
	return stuAns;

}*/

int** ans2Vectors(char *instructor_answer, char *student_answer){

	int i = 0;
	int j = 0;
	int k = 0;
	int l = 0;
	
	//int **result;
	char *lower = (char *) malloc(strlen(instructor_answer) * sizeof(char));
	while(instructor_answer[i]){
		lower[i] = tolower(instructor_answer[i]);
		i++;
	}
		
	char ** test = tokenize(lower);
	//getUniqueWords(test);
	while(getUniqueWords(test)[k]){
		//getUniqueWords(test)[k];
		k++;
	}
	
	char *stuLower = (char *) malloc(strlen(student_answer) * sizeof(char));
	while(student_answer[j]){
		stuLower[j] = tolower(student_answer[j]);
		j++;
	}

	char ** stuTest = tokenize(stuLower);
	//printf("%s\n", *stuTest);
	//getUniqueWords(stuTest);
	while(getUniqueWords(stuTest)[l]){
		//getUniqueWords(stuTest)[l];
		l++;
	}
	free(stuLower);
	free(lower);
	//printf("%d and %d\n", k, l);

	char ** instAnsUniqueWords = (char **) malloc(k * sizeof(char));
	char ** stuAnsUniqueWords = (char **) malloc(l * sizeof(char));
	
	for(int m = 0; m < k - 1; m++){
		instAnsUniqueWords[m] = getUniqueWords(test)[m];
		//printf("%s ", instAnsUniqueWords[m]);
	}
	//printf("\nSTUDENT\n");
	freeWords(getUniqueWords(test));
	for(int n = 0; n < l; n++){
		stuAnsUniqueWords[n] = getUniqueWords(stuTest)[n];
		//printf("%s ", stuAnsUniqueWords[n]);
	}
	freeWords(getUniqueWords(stuTest));
	free(test);
	free(stuTest);
	k = k - 1;	
	int result[2][k];
	int** resultPlaceholder;
	//printf("\n-------------\n");
	for (int g = 0; g < k; g++){
    	result[0][g] = 1;
		for (int h = 0; h < l; h++){
			if(strcmp(instAnsUniqueWords[g], stuAnsUniqueWords[h]) == 0){
            			//printf("G: %d, %s || %s\n", g, instAnsUniqueWords[g], stuAnsUniqueWords[h]); 
				result[1][g] = 1;
        		}
        		else{
            			if(result[1][g] == 1)
					break;
				else
					result[1][g] = 0;
        		}
    		}

	}
	/*
	for(int f = 0; f < k; f++)
		printf("%s\n", instAnsUniqueWords[f]);
	for(int v = 0; v < 2; v++){
		printf("\n");
		for(int y = 0; y < 14; y++)
			printf("%d ", result[v][y]);
	}
	*/

	// Cosine Similarity
	int AB = 0;
	double tempCountA = 0;
	double tempCountB = 0;
	double sqrtA;
	double sqrtB;
	int row = (sizeof(result) / sizeof(result[0]));
	int col = sizeof(result[0]) / (2 * row);
	for(int i = 0; i < col; i++){
		AB += (result[0][i] * result[1][i]);
		tempCountA += (result[0][i] * result[0][i]);
	       	tempCountB += (result[1][i] * result[1][i]);
	}

	sqrtA = sqrt(tempCountA);
	sqrtB = sqrt(tempCountB);
	//printf("AB: %d, SqrtA: %f, SqrtB: %f\n", AB, sqrtA, sqrtB);
	printf("%f", (AB / (sqrtA * sqrtB)) * 10);
	
	return resultPlaceholder;
}
/*
double cosineSimilarity(char *instructor_answer, char *student_answer){

	int** ansVec = ans2Vectors(instructor_answer, student_answer);
	int AB = 0;
	double tempCountA = 0;
	double tempCountB = 0;
	double sqrtA;
	double sqrtB;
	for(int i = 0; i < sizeof(ansVec); i++){
		AB += (ansVec[0][i] * ansVec[1][i]);
		tempCountA += (ansVec[0][i] * ansVec[0][i]);
	       	tempCountB += (ansVec[1][i] * ansVec[1][i]);
	}

	sqrtA = sqrt(tempCountA);
	sqrtB = sqrt(tempCountB);
	return AB / (sqrtA * sqrtB);

}*/
