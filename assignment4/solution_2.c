// GCD
#include <stdio.h>

int GCD(int x, int y);

int main(void){

        int x;
        int y;

        printf("Enter 1st positive integer: ");
        scanf("%d", &x);
        printf("Enter 2nd positive integer: ");
        scanf("%d", &y);

        printf("GCD of %d and %d is %d\n", x, y, GCD(x, y));
}

int GCD(int x, int y){

        int result;

        for(int i = 1; i <= x && i <= y; i++){
                if(x % i == 0 && y % i == 0)
                        result = i;
        }

        return result;

}
