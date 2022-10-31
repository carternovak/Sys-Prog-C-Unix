#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* replaceAll(const char* string, char *target, char *replacement);

int main(void){  
    	char str[100];
    	char targetStr[100];
    	char replacementStr[100];
    
    	printf("Enter a string: ");
    	scanf(" %[^\n]%*c", str);
    	
    	printf("Enter the target: ");
    	scanf(" %[^\n]%*c", targetStr);
    	
    	printf("Enter replacement: ");
    	scanf(" %[^\n]%*c", replacementStr);
    
    	printf("%s\n", replaceAll(str, targetStr, replacementStr));
}

char* replaceAll(const char* string, char *target, char *replacement){
    	const char *ogstring = string;
    	char *result = (char*)malloc(sizeof(char)*100);
    	int i = 0, j = 0, k = 0, temp = 0, begin = 0; 
    
    	while (string[i] != '\0'){
        	if (string[i] == target[j]) {
            		if (!temp)
                		begin = i;
            		j++;
            		if (target[j] == '\0')
                		break;
            		temp = 1;
        	}else{ 
            		temp = 0;
			begin = 0;
			j = 0;
		}
        	i++;
    	}
    
    	printf("Output: ");
    	if (target[j] == '\0' && temp){
        	for (i = 0; i < begin; i++)
            		*(result + k++) = string[i];

        	for (j = 0; j < strlen(replacement); j++){
            		*(result + k++) = replacement[j];
            		i++;
        	}

        	for (j = begin + strlen(target); j < strlen(string); j++){
            		*(result + k++) = string[j];
            		i++;
        	}

        	*(result + k++) = '\0';
    	}else{
		printf("%s\n", string);
		printf("Explanation: Since the target cannot be found in the original string we return the original string itself.\n");
    	}
    
    	return result;
}

