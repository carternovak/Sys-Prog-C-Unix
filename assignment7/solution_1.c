#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_STR_LEN 1000
#define MAX_WORD_LEN 100

char** myTokenizer(char* str, const char *delim);

int main(void){
    	char input_str[MAX_STR_LEN + 1];
    	char delimiter[MAX_WORD_LEN + 1];
    	char** tokens;
    	int num_tokens;

    	printf("Input the string: ");
    	fgets(input_str, MAX_STR_LEN + 1, stdin);

    	printf("Input the delimiter: ");
    	fgets(delimiter, MAX_WORD_LEN + 1, stdin);

    // remove the trailing newline character from the delimiter
    	//delimiter[strlen(delimiter) - 1] = '\0';

    // call myTokenizer to tokenize the string
    	tokens = myTokenizer(input_str, delimiter);

    // print the tokens
    	for (num_tokens = 0; tokens[num_tokens] != NULL; num_tokens++) {
        	printf("%s\n", tokens[num_tokens]);
    	}

    // free the memory allocated by myTokenizer
    	free(tokens);

    	return 0;
}

char** myTokenizer(char* str, const char *delim) {
    
	int i;
    	int num_tokens = 0;
    	int token_index = 0;
    	char* current_token;
    	char** tokens;

    // first count how many tokens are in the string
    	for (i = 0; i < strlen(str); i++) {
        	if (strchr(delim, str[i]) != NULL) {
            // found a delimiter, so increment the token counter
            		num_tokens++;
        	}
    	}

    // add space for the null terminator at the end of the array
    	num_tokens++;

    // allocate space for the array of token strings
    	tokens = (char**) malloc(num_tokens * sizeof(char*));

    // now loop through the string again, extracting each token
    	current_token = strtok(str, delim);
    	while (current_token != NULL) {
        // allocate space for the token string
        	tokens[token_index] = (char*) malloc((strlen(current_token) + 1) * sizeof(char));
        	strcpy(tokens[token_index], current_token);
        	token_index++;

        // get the next token
        	current_token = strtok(NULL, delim);
    	}

    // add the null terminator at the end of the array
    	tokens[token_index] = NULL;

    	return tokens;
}
