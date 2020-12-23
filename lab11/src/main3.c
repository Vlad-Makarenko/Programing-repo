#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


float find_min_max_pos(int size, float *array, int pos_min_max[]);
void fill_res_arr(float *array, float *result_arr, int pos1, int pos2);

#define SIZE 10

int main()
{
    srand(time(NULL));
    
    float *array= malloc(SIZE * sizeof(float));
    for (int i = 0; i < SIZE; i++){
        *(array + i) = rand() % 10000 /(float)10000;
    }
    
    int pos_min_max[2] = {0};
    int size_of_res = find_min_max_pos(SIZE, array, pos_min_max);
    float *result_arr = malloc(size_of_res * sizeof(float));
    
    fill_res_arr(array, result_arr, pos_min_max[0], pos_min_max[1]);
    free(result_arr);
    free(array);
    return 0;
}


float find_min_max_pos(int size, float *array, int pos_min_max[])
{
    int temp_pos = 1;
    int count_pos = 0;
    int temp_first_pos = 0;
    int firts_pos = 0;
    int last_pos = 0;
    for (int i = 0; i < SIZE; i++) {
        if (*(array + i) >= *(array + i - 1)) {
            if (temp_pos == 1) {
                temp_first_pos = i - 1;
            }
            temp_pos += 1;
        }else{
            if (temp_pos > count_pos) {
                count_pos = temp_pos;
                firts_pos = temp_first_pos;
                last_pos = i - 1;
            }
            temp_pos = 1;
        }
    }
    pos_min_max[0] = firts_pos;
    pos_min_max[1] = last_pos; 
    return count_pos;
}

void fill_res_arr (float *array, float *result_arr, int pos1, int pos2){
    for (int i = pos1; i <= pos2; i++ ){
        *(result_arr + i - pos1) = *(array + i);
    }
}



