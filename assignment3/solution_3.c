// Reverse Fizz-Buzz
#include <stdio.h>

int main(void){

	int start;
	printf("Enter the starting Fizz Buzz number: ");
	scanf("%d", &start);

	if(start > 0){
		while(start > 0){
			for(int i = 0; i < 4; i++){
				if(start == 0)
					break;
				if((start % 3 == 0) && (start % 5 == 0))
					printf("Fizz-Buzz ");
				else if (start % 3 == 0)
					printf("Fizz ");
				else if (start % 5 == 0)
					printf("Buzz ");
				else
					printf("%d ", start);
				start--;
			}
			printf("\n");
		}
	}
}
