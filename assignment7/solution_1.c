#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ** myTokenizer(char * str, const char * delim);

int main(void){
        char * string = malloc(500 * sizeof(char *));
        char * delimiter = malloc(500 * sizeof(char *));

        printf("Input the string: ");
        fgets(string, 500, stdin);

        printf("Input the delimiter: ");
        fgets(delimiter, 500, stdin);

        char * lowerDelim = delimiter;

        for(int i = 0; i < strlen(lowerDelim); i++)
                lowerDelim[i] = tolower(lowerDelim[i]);

        char ** result = myTokenizer(string, lowerDelim);
	printf("Output: ");
        if(strcmp(string, *result) == 0)
                printf("NULL\n");
        else
                for(int i = 0; * result[i] != '\0'; i++)
                        printf("%s\n", result[i]);
}

char ** myTokenizer(char * str, const char * delim){
        int strLen = strlen(str);
        int delimLen = strlen(delim);

        char ** result = (char **) malloc(500 * (sizeof(char *)));

        int a = 0, b = 0, c = 0;
        int d;
        int target = 1;

        while(a < strLen){
                result[a] = (char *) malloc(500 * sizeof(char *));

                for(d = 0; d < delimLen - 1; d++)
                        if(tolower(delim[d] != tolower(str[a + d])))
                                target = 0;

                if(target == 1){
                        c +=  1;
                        b = 0;
                        result[c][b] = str[a];
                        a += (delimLen - 1);
                }else{
                        result[c][b] = str[a];
                        a += 1;
                        b += 1;
                }

                target = 1;
        }

        return result;

}
