#include <stdlib.h>
#include <time.h>
#define SIZE 3

int matrix_multiplication (int matrix[SIZE][SIZE]); //функция, которая будет умножать матрицу саму на себя

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
	matrix_multiplication (matrix); //вызываем функцию для перемножения
	return 0;
}

// описываем работу нашей функции
int matrix_multiplication (int matrix[SIZE][SIZE])
{
	int result_matrix[SIZE][SIZE] = {0};
    	for (int i = 0; i < SIZE; i++){
        	for (int j = 0; j < SIZE; j++){
           		for (int l = 0; l < SIZE; l++) {
                		result_matrix[i][j] += matrix[i][l] * matrix[l][j];
            		}
        	}
    	}
	return result_matrix;
}
