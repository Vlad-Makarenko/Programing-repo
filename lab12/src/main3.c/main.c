//
// Created by Vlad on 11.02.2021.
//

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
#include "lib.h"

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
    int *initial_array = malloc(SIZE * sizeof(int));
    int *array_of_repeats = malloc(SIZE * sizeof(int));

    fill_initial_array(SIZE, initial_array);

    fill_array_of_repeats(SIZE, initial_array, array_of_repeats);

    int new_size = size_of_result(SIZE, initial_array, array_of_repeats);

    int *result_array = malloc(new_size * 2 * sizeof(int));

    fill_result_array(new_size, initial_array, array_of_repeats, result_array);

    print_result(result_array, new_size);

    free(result_array);
    free(initial_array);
    free(array_of_repeats);



    return 0;
}



