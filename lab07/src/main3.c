#include <stdarg.h>
#define SIZE 7

int function (int numbers, ... );

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
