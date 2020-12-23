#include <stdlib.h>
#include <time.h>

#define SIZE 5

void fill_array(int size, int array[SIZE][SIZE]);
void fill_res_array(int size, int array[SIZE][SIZE], int result_array[SIZE]);
void sort_array(int size, int result_array[SIZE]);
int main(){
    
    srand(time(NULL));
    
    int *array = (int*)malloc(SIZE * sizeof(int *));
    for(int i = 0; i<SIZE; i++){
        array[i] = (int *)malloc(SIZE * sizeof(int));
    }
    int *result_array = malloc(SIZE * sizeof(int));
    
    
    fill_array(SIZE, array);
    fill_res_array(SIZE, array, result_array);
    sort_array(SIZE, result_array);
            
    free(array);
    free(result_array);

}

void fill_array(int size, int array[SIZE][SIZE]){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            *(*(array + i) + j) = rand() % 10;
        }
    }
}

void fill_res_array(int size, int array[SIZE][SIZE], int result_array[SIZE]){
    for(int i = 0; i < SIZE; i++){
        *(result_array + i) = *(*(array + i) + i);
    }
}

void sort_array(int size, int result_array[SIZE]){
    int temp = 0;
    for (int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if (*(result_array + i) < *(result_array + j)) {
                temp = *(result_array + j);
                *(result_array + j) = *(result_array + i);
                *(result_array + i) = temp;
            }
        }
    }
}
