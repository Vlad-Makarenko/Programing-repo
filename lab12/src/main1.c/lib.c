//
// Created by Vlad on 11.02.2021.
//

#include "lib.h"

void fill_initial_array(int size, int *initial_array){
    for (int i = 0; i < SIZE; i++){
        printf("enter a number(from 1 to 10): ");
        scanf("%i", &(*(initial_array + i)));
    }
}

void fill_array_of_repeats(int size, int *initial_array, int *array_of_repeats){
    int count = 0;
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++) {
            if (*(initial_array + i) == *(initial_array + j)) {
                count++;
            }
        }
        *(array_of_repeats + i) = count;
        count = 0;
    }
}
int size_of_result(int size, int *initial_array, int *array_of_repeats){
    int new_size = 0;
    int flag = 0;
    for (int i = 0; i < SIZE; i++){
        if (*(array_of_repeats + i) == 1){
            continue;
        }else{
            for (int j = 0; j < i; j++){
                if(*(initial_array + i) == *(initial_array + j)) {
                    flag = 1;
                }
            }
            if (flag == 0){
                new_size += 1;
            }
            flag = 0;
        }
    }
    return new_size;
}
void fill_result_array(int size, int *initial_array, int *array_of_repeats, int *result_array){
    int k = 0;
    int flag = 0;
    for (int i = 0; i < SIZE; i++){
        if (*(array_of_repeats + i) == 1){
            continue;
        }else{
            for (int j = 0; j < i; j++){
                if(*(initial_array + i) == *(initial_array + j)) {
                    flag = 1;
                }
            }
            if (flag == 0){
                *(result_array + k) = *(initial_array + i);
                *(result_array + k + 1) = *(array_of_repeats + i);
                k += 2;
            }
            flag = 0;
        }
    }
}

void print_result(int *result_array, int size){
    printf("result: ");
    for(int i = 0; i < size * 2; i++){
        printf("%i", *(result_array + i));
    }
}