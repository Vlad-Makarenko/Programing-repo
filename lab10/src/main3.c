/**
 * @file main3.c
 * @brief варіативна функція
 *
 * @author Makarenko V.
 * @date 14-dec-2020
 * @version 1.0
 */

#include <stdarg.h>
/** 
 * Кількість елементів
 */
#define SIZE 7

/**
 * Функція, що визначає, скільки серед заданої послідовності чисел таких пар, 
 * у котрих перше число менше наступного.
 *
 * @param numbers перелік чисел
 * @param result кількість пар чисел
 * @return result
 */

int function (int numbers, ... );

/**
 * Головна функція.
 *
 * Послідовність дій:
 * - створення змінної, в яку буде записаний результат виконання функції
 * - виклик функціїї function
 * @return успішний код повернення з програми (0)
 * @param result результат виконання функції function
 */

int main()
{
    	int result = function(SIZE, 3, 9, 3, 9, 1, 1, 4);
    	return 0;
}

int function (int numbers, ... )
{
	int result = 0;
	va_list factor;
	va_start(factor, numbers);
	int tmp1 = va_arg(factor, int);
	for (int i = 0; i < SIZE; i++){
		int tmp2 = va_arg(factor, int);
		if (tmp1 < tmp2) {
		    result += 1;
		}
		tmp1 = tmp2;
	}
	    
	va_end(factor);
    	return result;
}
