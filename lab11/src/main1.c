/**
 * @mainpage
 * # Загальне завдання
 *  Визначити, чи є в масиві елементи, що повторюються; якщо такі є, створити масив, в  якому вказати
 * скільки разів які елементи повторюються.
 * 
 *
 * @author Makarenko V.
 * @date 22-dec-2020
 * @version 0.1
 */

/**
 * @file main1.c
 * @brief Завдання №1
 *
 * @author Makarenko V.
 * @date 14-dec-2020
 * @version 1.0
 */

 
#include <stdlib.h>
#include <time.h>

/**
 * функція для заповнення вхідного масиву
 *
 * @param initial_array - отриманий масив елементів
 */


void fill_initial_array(int size, int *initial_array);

/**
 * функція для розрахунку кількості повторів кожного елемента у вхідному масиві
 *
 * @param count кількість повторів одного елемента
 */
 
void fill_array_of_repeats(int size, int *initial_array, int *array_of_repeats);

/**
 * функція для розрахунку розміру результуючого масиву
 *
 * @param new_size - розмір результуючого масиву
 * @param flag  - змінна, для виконання умови
 */
 
int size_of_result(int size, int *initial_array, int *array_of_repeats);

/**
 * функція для заповнення результуючого масиву
 *
 * @param k - змінна, для правильного заповнення результуючого масиву
 * @param flag - змінна для виконання умови
 */
 
void fill_result_array(int size, int *initial_array, int *array_of_repeats, int *result_array);

/**
 * Розмір вхідного масиву
 */

#define SIZE 10

/**
 * Головна функція.
 *
 * Послідовність дій:
 * - створення створення вхідного масиву
 * - створення масиву з кількість повторів елементі у вхідному масиві
 * - виклик функціїї fill_initial_array для заповнення вхідного масиву випадковими числами
 * - виклик функціїї fill_array_of_repeats для заповнення масиву, кількістью повторів елементів
 * - виклик функціїї size_of_result для визначення розміру результуючого масиву
 * - створення динамічного самиву
 * - виклик функціїї fill_result_array для заповнення результуючого масиву
 * @return успішний код повернення з програми (0)
 * @param new_size - розмір результуючого масиву
 */


int main()
{
    srand(time(NULL));
    
    int *initial_array = malloc(SIZE * sizeof(int));
    int *array_of_repeats = malloc(SIZE * sizeof(int));
    
    fill_initial_array(SIZE, initial_array);
    fill_array_of_repeats(SIZE, initial_array, array_of_repeats);
    
    int new_size = size_of_result(SIZE, initial_array, array_of_repeats);
    
    int *result_array = malloc(new_size * 2 * sizeof(int));
   
    fill_result_array(new_size, initial_array, array_of_repeats, result_array);
    
    free(result_array);
    free(initial_array);
    free(array_of_repeats);
    
    
    
    return 0;
}

void fill_initial_array(int size, int *initial_array) {
    for (int i = 0; i < SIZE; i++) {
        *(initial_array + i) = rand() % 5 + 1;
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
