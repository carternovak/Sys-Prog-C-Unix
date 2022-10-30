#include<stdio.h>
#include<string.h>

int indexOf(char *haystack, char *needle, int fromIndex){
  
	int res = -1; //store the starting index
  	for (int i = fromIndex; haystack[i] != '\0'; i++) {
    		res = -1;
    		for (int j = fromIndex; needle[j] != '\0'; j++) {
      			if (haystack[i + j] != needle[j]) {
        			res = -1;
        			break;
      			}
      			res = i;
    		}
    		if (res != -1)
      			break;
  	}
  	return res;
}

int main(void){
  //variable declaration
  	int index;
  	char haystack[40], needle[20];

  //taking user input
  	printf("Haystack: ");
  	scanf("%[^\n]%*c", haystack);
  	printf("Needle: ");
  	scanf("%[^\n]%*c", needle);
  	printf("From Index: ");
  	scanf("%d", &index);
  //printing the result
  	if(indexOf(haystack, needle, index)== -1)
    		printf("The needle cannot be found in the haystack.");
  	else
    		printf("The needle is found at index %d.", indexOf(haystack, needle, index));
  
}
