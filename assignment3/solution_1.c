// Domain names
#include <stdio.h>

int main(void) {

	char letter1 = 'a';
	char letter2 = 'a';
	for(int i = 0; i < 26; i++){
		for(int k = 0; k < 26; k++){
			printf("www.%c%c.com\n", letter1, letter2);
			letter2++;
		}
		letter2 = 'a';
		letter1++;
	}

}
