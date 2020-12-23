#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void fill_array(int size, int array[]);
void find_min_max_pos(int size, int array[], int pos_min_max[]);
void fill_res_arr(int array[], int result_arr[], int pos1, int pos2);

#define SIZE 20

int main()
{

    srand(time(NULL));

    int array[SIZE] = {0};
    fill_array(SIZE, array);

    int pos_min_max[2] = {0};
    find_min_max_pos(SIZE, array,pos_min_max);
    int size_of_res = pos_min_max[1] - pos_min_max[0] + 1;
    int *result_arr = malloc(size_of_res * sizeof(int));
    
    fill_res_arr(array, result_arr, pos_min_max[0], pos_min_max[1]);
    free(result_arr);
    return 0;
}

void fill_array(int size, int array[])
{
    for (size_t i = 0; i < SIZE; i++)
    {
        array[i] = rand() % 20 - 10;
    }
}

void find_min_max_pos(int size, int array[], int pos_min_max[])
{
    int temp_sum = 0;
    int sum = 0;
    int temp_first_pos = 0;
    int firts_pos = 0;
    int last_pos = 0;
    for (int i = 0; i < SIZE; i++) {
        if (array[i] > 0) {
            if (temp_sum == 0) {
                temp_first_pos = i;
            }
            temp_sum += array[i];
        }else{
            if (temp_sum > sum) {
                sum = temp_sum;
                firts_pos = temp_first_pos;
                last_pos = i - 1;
            }
            temp_sum = 0;
        }
    }
    pos_min_max[0] = firts_pos;
    pos_min_max[1] = last_pos;    
}

void fill_res_arr (int array[], int result_arr[], int pos1, int pos2){
    for (int i = pos1; i <= pos2; i++ ){
        *(result_arr + (i - pos1)) = array[i];
    }
}
