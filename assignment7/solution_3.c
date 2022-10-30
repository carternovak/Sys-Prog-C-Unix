#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function to replace string 
char* replaceAll(const char* string, char *target, char *replacement)
{
    char ch;
    const char *ogstring = string;
    char *newStr = (char*)malloc(sizeof(char)*100);
    int i = 0, j = 0, k=0; 
    int flag = 0, start = 0;
    
    while (string[i] != '\0')
    {
        if (string[i] == target[j]) 
        {
            if (!flag)
                start = i;
            j++;
            if (target[j] == '\0')
                break;
            flag = 1;
        } 
        else 
            flag = start = j = 0;
        i++;
    }
    
    
    if (target[j] == '\0' && flag)
    {
        for (i = 0; i < start; i++)
        {
            *(newStr+k++) = string[i];
        }

        for (j = 0; j < strlen(replacement); j++) 
        {
            *(newStr+k++) = replacement[j];
            i++;
        }

        for (j = start + strlen(target); j < strlen(string); j++)
        {
            *(newStr+k++) = string[j];
            i++;
        }

        *(newStr+k++) = '\0';
    }else{
	printf("%s\n", string);
	printf("Since the target cannot be found in the original string we return the original string itself.\n");
    }
    
    return newStr;
}

void main() 
{ 
    //variable declaration
    char ch; 
    char str[100];
    char searchStr[100];
    char replaceStr[100];
    int i = 0, j = 0; 
    int flag = 0, start = 0;
    
    //get user input
    printf("Enter a string: ");
    scanf(" %[^\n]%*c", str);
    
    //get user input
    printf("Enter the target: ");
    scanf(" %[^\n]%*c", searchStr);
    
    //get user input
    printf("Enter replacement: ");
    scanf(" %[^\n]%*c", replaceStr);
    
    //print the new string
    printf("%s", replaceAll(str, searchStr, replaceStr));
}
