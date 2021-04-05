
# Лабораторна робота №4. Макровизначення

## 1. Вимоги

### 1.1 Розробник

- Макаренко Владислав Олександрович;

- студент групи КІТ-120а;

- 05-квітня-2021

### 1.2 Загальне завдання

 1. **Виводити** поточну дату та час для виклику кожної фунції;

 2. **Виводити** ім'я потомчної функції;

 3. **Виводити** загальний час роботи програми;

 4. При запуску кожного тесту виводити ім'я тесту та час його виконання;

 5. **Виводити** загальний час виконання всіх тестів

### 1.3 Індивідуальне завдання

 Виконати завдання згідно варіанту
 

## 32. Опис програми на основі динамічного списку

### 2.1 Функціональне призначення

За допомогою макровизначень можна дізнатись інформацію про час виконання функцій.

### 2.2 Опис логічної структури програми

Загальне завдання виконується за допомогою розроблених функцій. Функції: `ShowList`, виводить список на екран, `FindBackpack` знаходить елемент в списку за заданим критерієм,`DeleteElement` видаляє елемент зі списку,  `SortListByCriterion` сортує список за заданим критерієм, `InsertElement` виконує вставку нового елементу в список.

_Головна функція_`main()`. Виконує взаємодію з користувачем шляхом діалогового меню. Викликає функції в залежності від запитів користувача
 _Схема алгоритму функції_ подана на рис. 8.

![enter image description here](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab18&&lab19/doc/assets/main19.png?raw=true)

Рисунок 8  --- Схема алгоритму функції `main`


_Функція видалення_ `DeleteElement`. функція приймає список, та позицію з якої видалити елемент .
_Схема алгоритму функції_ подана на рис. 9.

![Схема алгоритму функції](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab18&&lab19/doc/assets/DeleteElement.png?raw=true)

Рисунок 9 --- Схема алгоритму функції `DeleteElement`

_Функція `SortListByCriterion`:Функція приймає список та критерій для сортування.
_Схема алгоритму функції_ подана на рис. 10.
![enter image description here](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab18&&lab19/doc/assets/SortListByCriterion.png?raw=true)

Рисунок 10 --- Схема алгоритму функції  `SortListByCriterion`

_Функція_ `InsertElement`: Функція приймає список в який буде вставлено елемент, позицію, на яку буде вставлено елемент там поля елементу.
_Схема алгоритму функції_ подана на рис. 11.

![enter image description here](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab18&&lab19/doc/assets/InsertElement.png?raw=true)

Рисунок 11 --- Схема алгоритму функції  `InsertElement`




### 2.3 Важливі фрагменти програми

#### Задання макросу

``` 
#define log_info(M, ...) fprintf(stderr, "[INFO] (%s:%d) " M "\n",\
		        __FILE__, __LINE__, ##__VA_ARGS__)
  
```
#### Виведення поточних даних

```
 const char *func = __FUNCTION__;
 log_info("start");
 time_t CurTime;
 struct tm * TimeInfo;
 time ( &CurTime );
 ТimeInfo = localtime ( &CurTime );
 log_info("Function: %s" , func );
 log_info("Time & Date: %s", asctime (TimeInfo));
```
#### Розрахунок загального часу виконання програми

```
 time_t begin = clock();
 time_t end = clock();
 double time_spent = (double)(end - begin)/ CLOCKS_PER_SEC;
 printf(" | Time spent executing the program: %lf second(s)\n", time_spent);
```

### 3. Варіанти використання

Для демонстрації результатів використовується Clion. Нижче наводиться послідовність  дій запуску програми.

_Крок 1_ (рис.12 ). Початок роботи програми

![result1](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab20/doc/assets/result1.png?raw=true)
Рисунок 12 --- Результат виконання кроку 1

_Крок 2_ (див. рис.13 ). Виклик функції пошуку об'єкта

![result2](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab20/doc/assets/result2.png?raw=true)
Рисунок 13 --- Результат виконання кроку 2

_Крок 3_ (див. рис.14 ). Завершення роботи програми 

![result3](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab20/doc/assets/result3.png?raw=true)
Рисунок 14 --- Результат виконання кроку 3

_Крок 4_ (див. рис.15 ). Виконання тестів
![result4](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab20/doc/assets/result4.png?raw=true)
Рисунок 15 --- Результат виконання кроку 4
### Структура проекту

	├── lab20
	    ├── Doxyfile
	    ├── doc
	        ├── lab4.md
	        └── assets
        ├── CMakelist.txt
		├── test
            ├── test.c
		└── src
		    ├── main.c
		    ├── data.c
            ├── data.h
		    ├── lsit.c
		    └── list.h
## Висновки

Ми навчились працювати з макровизначеннями та використовувати їх

