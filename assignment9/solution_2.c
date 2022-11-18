// File Manipulation
#include <stdio.h>

int main() {

    char txt1[100], txt2[100];
    char tempChar;
    char prevChar = ' ';
    int x = 0;

    FILE *fp1r = fopen("input21.txt","r");

    while ((tempChar = fgetc(fp1r)) != EOF) {
        if(!(tempChar=='\n' && prevChar == '\n')) {
            txt1[x] = tempChar;
            x++;
        }
        prevChar = tempChar;
    }
    txt1[x] = '\0';
    
    x = 0;
    
    FILE *fp1w = fopen("input21.txt","w");
    fputs(txt1, fp1w);

    FILE *fp2r = fopen("input22.txt","r");
    while ((tempChar = fgetc(fp2r)) != EOF) {
        if(!(tempChar == '\n' && prevChar == '\n')) {
            txt2[x] = tempChar;
            x++;
        }
        prevChar = tempChar;
    }
    txt2[x] = '\0';

    FILE *fp2w = fopen("input22.txt","w");
    fputs(txt2, fp2w);

    fclose(fp1w);
    fclose(fp2w);

    FILE *fp3 = fopen("input22.txt","a");
    fputs(txt1, fp3);

    fclose(fp3);

    return 0;
}

