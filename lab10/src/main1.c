/**
 * @mainpage
 * # Загальне завдання
 * 1. **Сформувати** функцию, що буде рухувати квадратний корінь з числа
 * 2. **Сформувати** функцію, що буде премножати матрицю саму на себе
 * 3. **Сформувати** варіаивну функцію, що буде рахувати кількість пар чисел, в яких наступне число меньше попереднього
 *
 * @author Makarenko V.
 * @date 14-dec-2020
 * @version 1.0
 */

/**
 * @file main1.c
 * @brief Квадратний корінь з числа
 *
 * @author Makarenko V.
 * @date 14-dec-2020
 * @version 1.0
 */

 
#include <stdlib.h>
#include <time.h>

/**
 * функція для розрахунку квадратного кореня з числа
 *
 * Послідовність дій:
 * - створення змінних, я які буде записаний результат
 * - розрахунок результату, за допомогою цикла whie
 * @return result
 * @param result добутий корінь із заданого числа
 */

float Square_root (int number); // задємо фунцкію для розрахунку квадратного кореня з задано числа

/**
 * Головна функція.
 *
 * Послідовність дій:
 * - створення змінної, в яку буде записане число
 * - створення змінних, я які буде записаний результат виконання функіїї
 * - виклик функціїї Square_root для числа згенерованого функцією rand
 * - виклик функціїї Square_root для заданого нами числа
 * @return успішний код повернення з програми (0)
 * @param number число, я якого отримаємо корінь
 * @param result1 результат першого виклику функції Square_root
 * @param result2 результат другого виклику функції Square_root
 */

int main ()
{
	srand(time(NULL));
	int number;
	float result1 = Square_root (number = rand() % 50); //робимо перший виклик для випадкового числа, заданого функцією "rand()"
	float result2 = Square_root (number = 25); //робимо другий вкилик для зданого нами числа
	return 0;
}
	
//описуємо функцію для розрахунку квадратного кореня
float Square_root (int number) 
{
    	float result = 0.0001;
	while (result * result <= number) {
		result += 0.0001;
    	}
    
  	return result;
}
