//
// Created by Vlad on 11.02.2021.
//

#ifndef PROGRAMING_REPO_LIB_H
#define PROGRAMING_REPO_LIB_H

/**
* @file lib.h
* @brief Завдання №3
*
* @author Makarenko V.
* @date 14-dec-2020
* @version 1.0
*/


#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

/**
* Розмір вхідного масиву
*/

#define SIZE 10


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

/*
 * функція для виводу результату на екран
 *
 * @param result_array - масив, який буде виведений на екран
 * @param size - розмір масиву
 */

void print_result(int *result_array, int size);

#endif //PROGRAMING_REPO_LIB_H
