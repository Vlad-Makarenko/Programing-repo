/**
 * @file main2.c
 * @brief Множення матриці саму на себе
 *
 * @author Makarenko V.
 * @date 14-dec-2020
 * @version 1.0
 */

#include <stdlib.h>
#include <time.h>
/**
 * Розмір матриці
 */
#define SIZE 3

/**
 * функція для множення матриці саму на себе
 *
 * Послідовність дій:
 * - створення масиву, в який буде записаний результат множення
 * - процес множення матриць, за допомогою циклів for
 * @return успішний код повернення з програми (0)
 * @param result_matrix масив, в який буде записаний результат множення матриць
 */

void matrix_multiplication (int matrix[SIZE][SIZE]); //функция, которая будет умножать матрицу саму на себя

/**
 * Головна функція.
 *
 * Послідовність дій:
 * - створення масиву
 * - заповнення масиву за допомогою функції rand()
 * - виклик функціїї matrix_multiplication 
 * @return успішний код повернення з програми (0)
 * @param matrix матриця, яку ми будемо множити саму на себе
 */

int main()
{
	srand(time(NULL));
	int matrix[SIZE][SIZE] = {0}; //задаем нашу матрицу
	// заполняее матрицу случайними числами
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			matrix[i][j] = rand() % 10;
		}
	}
	matrix_multiplication(matrix); //вызываем функцию для перемножения
	return 0;
}

// описываем работу нашей функции
void matrix_multiplication (int matrix[SIZE][SIZE])
{
	int result_matrix[SIZE][SIZE] = {0};
    	for (int i = 0; i < SIZE; i++){
        	for (int j = 0; j < SIZE; j++){
           		for (int l = 0; l < SIZE; l++) {
                		result_matrix[i][j] += matrix[i][l] * matrix[l][j];
            		}
        	}
    	}
    	return;
}
