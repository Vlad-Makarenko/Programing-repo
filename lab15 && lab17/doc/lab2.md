
# Лабораторна робота №2. Структуровані типи даних. Модульні тести

## 1. Вимоги

### 1.1 Розробник

- Макаренко Владислав Олександрович;

- студент групи КІТ-120а;

- 22-березня-2021

### 1.2 Загальне завдання

1. **Розробити** функцію, яка читає дані(масив елементів) з файлу;  
 2. **Розробити** функцію, яка записує дані(масив елементів) у файлу;  
3. **Розробити** функцію, яка виводить масив елементів на екран;  
 4. **Розробити** функцію, яка буде сортувати масив елементів за заданим критерієм;  
 5. **Розробити** функцію, яка буде знаходити німецький міський рюкзак;  
 6. **Розробити** функцію, яка генерує чисельні елементи структури;  
 7. **Розробити** функцію, яка записує дані(масив елементів) у бінарний файлу;  
 8. **Розробити** функцію, яка читає дані(масив елементів) з бінарного файлу;
 9.  **Розробити** тести, до функцій сортування та пошуку об'єкта
  
### 1.3 Індивідуальне завдання

 Виконати завдання згідно варіанту
 
## 2. Опис програми

### 2.1 Функціональне призначення

За допомогою розроблених функцій можна зчитати масив структур з файлу, відсортувати його за заданим критерієм, та вивести його на екран або у звичайний та бінарний файли.

### 2.2 Опис логічної структури програми

Загальне завдання виконується за допомогою розроблених функцій. Функції: `ReadFromFile`, зчитує масив структур з файлу, `random_number_generation` генерує чисельні поля структури,`SortByCriterion` сортує масив структур за заданим критерієм,  `PrintInConsole` та `PrintInFile` виводять відсортований масив структур на екран та у файл відповідно,  `FindGermanBackpack`  знаходить німецький міський рюкзак, `WriteToBinaryFile` та `ReadFromBinaryFile` функції для роботи з бінарними файлами.

_Головна функція_`main()`. Викликає функції для роботи зі структурою

 _Схема алгоритму функції_ подана на рис. 1.

![enter image description here](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab15%20&&%20lab17/doc/assets/main%281%29.png?raw=true)

Рисунок 1  --- Схема алгоритму функції `main`


_Функція сортування_ `SortByCriterion`. функцію, яка викликає функцію `comparator` та сортує масив елементів за заданим критерієм.
_Схема алгоритму функції_ подана на рис. 2.

![Схема алгоритму функції](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab15%20&&%20lab17/doc/assets/SortByCriterion.png?raw=true)

Рисунок 2 --- Схема алгоритму функції `SortByCriterion`

_Функція `comparator`: Функція порівнює строки між собою та повертає результат порівняння.

![enter image description here](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab15%20&&%20lab17/doc/assets/comparator.png?raw=true)

Рисунок 3 --- Схема алгоритму функції  `comparator`

_Функція_ `FindGermanBackpack`:
 Функція знаходить структуру з німецьким міським рюкзаком та виводить її на екран

![enter image description here](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab15%20&&%20lab17/doc/assets/FindGermanBackpack.png?raw=true)

Рисунок 4 --- Схема алгоритму функції  `FindGermanBackpack`


#### Структура проекту

	├── lab15 && lab17
	    ├── Doxyfile
	    ├── Makefile
	    ├── backpacks.txt
	    ├── doc
	        ├── lab2.md
	        └── assets
	    ├── test
		    ├── test.c
	    └── src
	        ├── main.c
	        ├── lib.c
	        └── lib.h

### 2.3 Важливі фрагменти програми

#### Функція сортування масиву структур залежно від критерія

``` 
for (int i = 0; i < size; i++) {  
	  for (int j = 0; j < size - 1; j++) {  
		  flag = 0;  
		  if(strcmp(color,criterion) == 0) {  
			  flag = comparator((*(backpacks + j))->color, (*(backpacks + j + 1))->color);  
		  }else if(strcmp(country, criterion) == 0){  
			  flag = comparator((*(backpacks + j))->country, (*(backpacks + j + 1))->country);  
		  }else if(strcmp(laptop_department, criterion) == 0){  
			  if ((*(backpacks + j))->laptop_department > (*(backpacks + j + 1))->laptop_department){  
			  flag = 1;  
	          }  
		 }else if(strcmp(volume, criterion) == 0) {  
			  if ((*(backpacks + j))->volume > (*(backpacks + j + 1))->volume) {  
			  flag = 1;  
	          }  
		  }else if(strcmp(enumPurpose, criterion) == 0) {  
			  if ((*(backpacks + j))->enumPurpose > (*(backpacks + j + 1))->enumPurpose) {  
			  flag = 1;  
	          }  
		 }  
		 if (flag == 1){  
			  struct Backpack *temp = *(backpacks + j);  
              *(backpacks + j) = *(backpacks + j + 1);  
              *(backpacks + j + 1) = temp;  
        }  
	 }
 }
  
```
#### Функція `comparator`

```
int comparator(char a[15], char b[15]){  
	  if(strcmp(a,b) == 0){  
		  return 0;  
	  } else if (strcmp(a,b) < 0){  
		  return -1;  
	  } else if (strcmp(a,b) > 0){  
		  return 1;  
	  }  
  return 0;  
}
```


### 3. Варіанти використання

Для демонстрації результатів використовується Clion. Нижче наводиться послідовність  дій запуску програми.

_Крок 1_ (рис.5 ). Виводиться відсортований масив структур за заданим критерієм(volume)

![result1](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab15%20&&%20lab17/doc/assets/result1.png?raw=true)

Рисунок 5 --- Результат виконання кроку 1

_Крок 2_ (див. рис.6 ). Виконується функція пошуку об'єкту

![result2](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab15%20&&%20lab17/doc/assets/result2.png?raw=true)

Рисунок 6 --- Результат виконання кроку 2

_Крок 3_ (див. рис.7 ). Результат виконання тестів

![enter image description here](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab15%20&&%20lab17/doc/assets/result3%281%29.png?raw=true)

Рисунок 7 --- Результат виконання кроку 3

## Висновки

Ми навчились працювати зі структурованими типами даних та розробляти модульні тести до функцій.

