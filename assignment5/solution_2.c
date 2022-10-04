// Student Directory
#include <stdio.h>
#include <stdlib.h>
#define NCOLS 4

void filterStudents(int students[][NCOLS], int minAge, int minYear, int minGrade);

int main(void){
    
    	int students[5][NCOLS] = {{1,18,11,90}, {2,16,10,75}, {3,15,9,85}, {4,10,10,60}, {5,11,9,60}};
    	int filters[3];
    
    	printf("Enter filtering parameters:\n");
    	for(int i = 0; i <= 2; i++)
        	scanf("%d", &filters[i]);
        	
	filterStudents(students, filters[0], filters[1], filters[2]);
	printf("\n");
    	return 0;
}

void filterStudents(int students[5][NCOLS], int minAge, int minYear, int minGrade){

        int age, year, grade;

        for (int i = 0; i < 5; i++){
                for (int j = 1; j < NCOLS + 1; j++){
                        if (j == 1)
				age = students[i][j];
                        if (j == 2)
				year = students[i][j];
                        if (j == 3)
				grade = students[i][j];
                }

                if (age >= minAge && year >= minYear && grade >= minGrade)
                        printf("%d ", students[i][0]);
                
        }
}
