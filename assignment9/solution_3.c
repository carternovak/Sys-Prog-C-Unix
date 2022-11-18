// AND, OR, and XOR pairs
#include <stdio.h>

int main() {
    
    int size, counter;
    int even = 0; 
    int odd = 0;
    int b = 0;
    int c = 0;
    
    printf("Input size of array: ");
    scanf("%d", &size);
    printf("Input array elements (no commas): ");
    int pairs[size];

    for(int i = 0; i < size; i++) {
        scanf("%d", &pairs[i]);
        if(pairs[i] % 2 == 0)
            even++;
        else
            odd++;
    }

    int a = (odd * (odd - 1)) / 2;

    for(int i = 0; i < size; i++) {
        if(pairs[i] % 2 == 1)
            b += (size - 1 - i);
        else {
            counter = 0;
            for(int j = i + 1; j < size; j++) 
                if(pairs[j] % 2 == 1)
                    counter++;
            b += counter;
        }
    }

    for(int i = 0; i < size; i++) {
        if(pairs[i] % 2 == 1) {
            counter = 0;
            for(int j = i + 1; j < size; j++)
                if(pairs[j] % 2 == 0)
                    counter++;
            c += counter;
        } else {
            counter = 0;
            for(int j = i + 1; j < size; j++)
                if(pairs[j] % 2 == 1)
                    counter++;
            c += counter;
        }
    }

    printf("Total AND pairs: %d\n", a);
    for(int i = 0; i < size; i++)
        if(pairs[i] % 2 == 1) 
            for(int j = i + 1; j < size; j++)
                if(pairs[j] % 2 == 1)
                    printf("(%d, %d)\n", pairs[i], pairs[j]);
        

    printf("Total OR pairs: %d\n", b);
    for(int i = 0; i < size; i++) {
        if(pairs[i] % 2 == 1)
            for(int j = i + 1; j < size; j++)
                printf("(%d, %d)\n", pairs[i], pairs[j]);
        else 
            for(int j = i + 1; j < size; j++)
                if(pairs[j] % 2 == 1)
                    printf("(%d, %d)\n", pairs[i], pairs[j]);
    }

    printf("Total XOR pairs: %d\n", c);
    for(int i = 0; i < size; i++) {
        if(pairs[i] % 2 == 1)
            for(int j = i + 1; j < size;j++)
                if(pairs[j] % 2 == 0)
                    printf("(%d, %d)\n", pairs[i], pairs[j]);
        else
            for(int j = i + 1; j < size; j++)
                if(pairs[j] % 2 == 1) 
                    printf("(%d, %d)\n", pairs[i], pairs[j]);
    }

    return 0;
}
