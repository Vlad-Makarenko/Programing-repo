#include <stdlib.h>
#include <time.h>

float Square_root (int number); // задємо фунцкію для розрахунку квадратного кореня з задано числа

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
