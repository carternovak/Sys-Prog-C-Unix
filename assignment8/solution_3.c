#include <stdio.h>
#include <stdlib.h>

typedef struct Array Array;
struct Array {
    int * data;
    size_t length;
};

Array * new_array(size_t len);
int array_get(Array* arr, int index);
void array_set(Array* arr, int index, int value);
void delete_array(Array* arr);

int main() {
    Array * arr = new_array(5);
    array_set(arr, 0, 2);
    array_set(arr, 1, 3);
    array_set(arr, 2, 5);
    array_set(arr, 3, 7);
    array_set(arr, 4, 11);
    
    for (int i = 0; i < 5; i++) {
        printf("%d ", array_get(arr, i));
    }
    
    delete_array(arr);
}

Array * new_array(size_t len){
    Array * arr = (Array *) malloc(sizeof(Array));
    arr->data = (int*)malloc(100 * len * sizeof(int));
    
    for(int i = 0; i < len; i++){
        arr->data = 0;
    }
    return arr;
}

int array_get(Array* arr, int index){
    return arr[index].data;
}

void array_set(Array* arr, int index, int value){
    arr[index].data = value;
}

void delete_array(Array* arr){
    free(arr);
}


