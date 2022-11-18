#include <stdio.h>

int main() {

    int N;
    int total = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &N);
    printf("Enter the elements of the array (no commas): ");
    int array[N];

    for(int i = 0; i < N; i++) {
        scanf("%d", &array[i]);
        total += array[i];
    }
    printf("%d\n", total - ((N * (N - 1)) / 2));
    
    return 0;
}
