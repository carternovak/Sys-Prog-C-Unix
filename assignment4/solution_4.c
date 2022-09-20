#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char text;
int x, y, a, b, point, sum;
int roll = 1;

void rollDice(void);
int getSum(int m, int n);
void checkCraps(int score);

int main(void){
        srand(time(NULL));
        printf("Would you like to play a game of craps? Type y for yes or n for no: ");
        scanf("%c", &text);
        if(text == 'y'){
                rollDice();
                checkCraps(getSum(x,y));
                return 0;
        }
        if(text == 'n'){
                puts("Exiting...");
                return 0;
        }
}

void rollDice(void){
        printf("Dice are rolling...\n");

        if(roll == 1){
                x = 1 + rand() % 6;
                y = 1 + rand() % 6;
                printf("Score on dice are: %d and %d\n", x, y);

        }
        else{
                a = 1 + rand() % 6;
                b = 1 + rand() % 6;
                printf("Score on dice are: %d and %d\n", a, b);

        }
}

int getSum(int m, int n){

        printf("Sum is: %d\n", m + n);
        return m + n;
}

void checkCraps(int score){

        if (roll = 1){
                if(score == 11 || score == 7){
                        puts("Congratulations, you won!");
                        sum = score;
                        point = score;
                }
                else if(score == 2 || score == 3 || score == 12){
                        puts("Sorry you have lost and the house has won!");
                        sum = score;
                        point = score;
                }
                else{
                        point = score;
                        printf("Your point is: %d\n", point);
                        roll++;
			rollDice();
                        sum = getSum(a,b);

                        while(sum != point || sum != 7){
                                if(sum == point || sum == 7)
                                        break;
         		
	                        rollDice();
        	                sum = getSum(a,b);
                        }
                }
        }
        
        if(a + b == point)
                printf("You won!\n");
        if(a + b == 7)
                printf("You lost!\n");
}
