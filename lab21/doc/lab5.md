
# Лабораторна робота №5. Створення бібліотек

## 1. Вимоги

### 1.1 Розробник

- Макаренко Владислав Олександрович;

- студент групи КІТ-120а;

- 07-квітня-2021

### 1.2 Загальне завдання

1. На базі розробленого функціоналу по роботі з прикладною галуззю сформувати статичну та динамічну бібліотеки
2. За допомогою утиліти ```nm``` дослідити перелік функцій, що має бібліотека. 


### 1.3 Індивідуальне завдання

 Виконати завдання згідно варіанту
 

## 2. Опис програми 

### 2.1 Функціональне призначення

За допомогою ```makefile``` створюється статична та динамічна бібліотеки

### 2.2 Опис логічної структури статичної бібліотеки

Для створення статичної бібліотеки в ``makefile`` в команду ``compile: `` записуємо наступні строки:

```
compile:
	cp src/entity.h ../shared
	$(CC) -c $(C_OPTS) src/entity.c -o ./dist/entity.o
	ar rcs ./dist/libentity.a ./dist/entity.o
	cp ./dist/libentity.a ../shared
```
І після виконання команди ``make compile``  створюється статична бібліотека.

Для компіляції проекту з використання вище створеної бібліотеки необхідно в   ``makefile`` в команду ``compile: `` записати наступну строку:
```
compile:
	$(CC) -I../StaticLib/dist src/main.c -lentity -L../StaticLib/dist -o dist/main.bin
```
І після виконання команди ``make compile``  компілюється проект на основі створеної статичної бібліотеки.


### 2.3 Опис логічної структури динамічної бібліотеки


Для створення динамічної бібліотеки в ``makefile`` в команду ``compile: `` записуємо наступні строки:

```
compile:
	cp src/list.h ../shared
	$(CC) -c $(C_OPTS) -fPIC -I../StaticLib/dist src/list.c -o dist/list.o
	$(CC) -shared dist/list.o ../StaticLib/dist/libentity.a -o dist/liblist.so
	cp dist/liblist.so ../shared
```
І після виконання команди ``make compile``  створюється динамічна бібліотека.

Для компіляції проекту з використання вище створеної бібліотеки необхідно в   ``makefile`` в команду ``compile: `` записати наступні строки:
```
compile:
	$(CC) -I../StaticLib/dist/ src/main.c -lentity -L../StaticLib/dist/ -o dist/main.bin
	cp ../SharedLib/dist/liblist.so ./dist
```
І після виконання команди ``make compile``  компілюється проект на основі створеної динамічної бібліотеки.


### 3. Демонстрація виконання утиліти ``nm``

Для демонстрації результатів використовується термінал в Clion. 

_Крок 1_ (рис.1 ). Утиліта ``nm`` для статичної бібліотеки

![result1](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab21/doc/Screenshot_1.png?raw=true)
![enter image description here](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab21/doc/Screenshot_2.png?raw=true)
Рисунок 1 --- Результат виконання кроку 1

_Крок 2_ (див. рис.2 ). Утиліта ``nm`` для динамічної бібліотеки

![result2](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab21/doc/Screenshot_3.png?raw=true)
Рисунок 2 --- Результат виконання кроку 2


### Структура проекту

	├── lab21
	    ├── SharedLib
	    	├── src
	        ├── test
	        └── makefile
	    ├── SharedProject
	        ├── src
	        ├── test
	        └── makefile
        ├── StaticLib
        	├── src
	        ├── test
	        └── makefile
		├── StaticProject
            ├── src
	        ├── test
	        └── makefile
		└── doc
		    ├── assets
		    └── lab5.md
## Висновки

Ми навчились створювати статичну та динамічну бібліотеки 

