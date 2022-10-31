#include<stdio.h>
#include<string.h>

int indexOf(char *haystack, char *needle, int fromIndex);

int main(void){
  	int index;
  	char haystack[40], needle[20];

  	printf("Haystack: ");
  	scanf("%[^\n]%*c", haystack);
  	printf("Needle: ");
  	scanf("%[^\n]%*c", needle);
  	printf("From Index: ");
  	scanf("%d", &index);
	
	int search = indexOf(haystack, needle, index);
  	if(search == -1)
    		printf("The needle cannot be found in the haystack.\n");
  	else
    		printf("The needle is found at index %d.\n", indexOf(haystack, needle, index));
  
}

int indexOf(char *haystack, char *needle, int fromIndex){

	int result = -1;
  	for (int i = fromIndex; haystack[i] != '\0'; i++) {
    		result = -1;
    		for (int j = fromIndex; needle[j] != '\0'; j++) {
      			if (haystack[i + j] != needle[j]) {
        			result = -1;
        			break;
      			}
      			result = i;
    		}
    		if (result != -1)
      			break;
  	}
  	return result;

}
