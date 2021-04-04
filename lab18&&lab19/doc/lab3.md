
# Лабораторна робота №3. Динамічні масиви. Динамічні списки

## 1. Вимоги

### 1.1 Розробник

- Макаренко Владислав Олександрович;

- студент групи КІТ-120а;

- 04-квітня-2021

### 1.2 Загальне завдання

* 1. **Розробити** функцію, яка зчитує список з файлу

* 2. **Розробити** функцію, яка записує дані(список) у файлу;

* 3. **Розробити** функцію, яка виводить список на екран;

* 4. **Розробити** функцію, яка буде сортувати список за заданим критерієм;

* 5. **Розробити** функцію, яка буде знаходити заданий еолемент у списку;

* 6. **Розробити** функцію, яка видаляє елемент зі списку;

* 7. **Розробити** функцію, яка вставляє новий елемент по індексу;

* 8. **Реалізувати** діалоговий режим спілкування з користувачем
* * 1. **Розробити** функцію, яка зчитує список з файлу

* 2. **Розробити** функцію, яка записує дані(список) у файлу;

* 3. **Розробити** функцію, яка виводить список на екран;

* 4. **Розробити** функцію, яка буде сортувати список за заданим критерієм;

* 5. **Розробити** функцію, яка буде знаходити заданий еолемент у списку;

* 6. **Розробити** функцію, яка видаляє елемент зі списку;

* 7. **Розробити** функцію, яка вставляє новий елемент по індексу;

* 8. **Реалізувати** діалоговий режим спілкування з користувачем№
* 9. **Розробити** функцію, яка реалізує вставку в рядок "s" другий рядок "s2" в "і" - у позицію рядка "s";
* 10. **Розробити** функцію, видалення з рядка "" усіх символів з індексами в заданому діапазоні;

* 11. **Розробити** функцію додавання та видалення елементів з динамічного масиву вашої прикладної області
  
### 1.3 Індивідуальне завдання

 Виконати завдання згідно варіанту
 
## 2. Опис програми на основі динамічних масивів

### 2.1 Функціональне призначення

За допомогою розроблених функцій можна вставити підрядок в рядок, видалити підрядок з рядка, вставити та видалити структуру з масиву структур

### 2.2 Опис логічної структури програми

Загальне завдання виконується за допомогою розроблених функцій. Функції: `ElementInsertion`, виконує вставку підрядка в рядок, `ElementDeleting`виконує видалення підрядка з рядка,`InsertStruct` виконує вставку структури в масив структур,  `DeleteStruct` видаляє структуру з масиву структур.

_Головна функція_`main()`. Викликає розроблені функції 
 _Схема алгоритму функції_ подана на рис. 1.

![enter image description here](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab18&&lab19/doc/assets/main18.png?raw=true)
Рисунок 1  --- Схема алгоритму функції `main`


_Функція вставки_ `ElementInsertion`. функція приймає два рядки, та позицію, на яку вставляти рядок. Повертає новий рядок .
_Схема алгоритму функції_ подана на рис. 2.

![Схема алгоритму функції](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab18&&lab19/doc/assets/ElementInsertion.png?raw=true)
Рисунок 2 --- Схема алгоритму функції `ElementInsertion`

_Функція `ElementDeleting`:Функція приймає текста, та позицію для видалення з нього підрядка. Повертає новий рядок.
_Схема алгоритму функції_ подана на рис. 3.
![enter image description here](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab18&&lab19/doc/assets/ElementDeleting.png?raw=true)
Рисунок 3 --- Схема алгоритму функції  `ElementDeleting`

_Функція_ `InsertStruct`: Функція приймає масив структур, в який треба вставити нову структуру, структуру, яку будет ставлено та позиція на яку вставити структуру.
_Схема алгоритму функції_ подана на рис. 4.

![enter image description here](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab18&&lab19/doc/assets/InsertStruct.png?raw=true)
Рисунок 4 --- Схема алгоритму функції  `InsertStruct`

_Функція_ `DeleteStruct`: Функція приймає масив структур, з якого треба видалити структуру та позицію з якої треба видалити структуру структуру.
_Схема алгоритму функції_ подана на рис. 5.
![enter image description here](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab18&&lab19/doc/assets/DeleteStruct.png?raw=true)

Рисунок 5 --- Схема алгоритму функції  `DeleteStruct`



### 2.3 Важливі фрагменти програми

#### Функція вставки підрядка в рядок

``` 
char *ElementInsertion(char * text, char * pasted_text, int position)
{
if(position < 0){
	position = 0;
}
if(position > strlen(text)){
	position = strlen(text);
}
char* new_text = malloc((strlen(text) + strlen(pasted_text))* sizeof (char));
memcpy(new_text, text, position);
memcpy(new_text + position, pasted_text, strlen(pasted_text));
memcpy(new_text + position + strlen(pasted_text), text + position, strlen(text) - position);
*(new_text + strlen(pasted_text) + strlen(text)) = '\0';
return new_text;
}
  
```
#### Функція видалення структури з масиву структур

```
struct Backpack** DeleteStruct (struct Backpack **backpacks, int position)
{
struct Backpack ** result = malloc((COUNT - 1) * sizeof (struct Backpack));
for(int i = 0; i < COUNT - 1; i++){
	*(result + i) = malloc(sizeof (struct Backpack));
}
if(position < 0){
	position = 0;
}
if(position >= COUNT - 1) {
	position = COUNT;
}
memcpy(*result, *backpacks, sizeof (struct Backpack) * (position + 1));
memcpy(*(result + position), *(backpacks + position + 1), sizeof (struct Backpack) * (COUNT - position));
printf("\nРезульат удаления:\n\n");
PrintInConsole(result, COUNT - 1);
return result;
}
```


### 3. Варіанти використання

Для демонстрації результатів використовується Clion. Нижче наводиться послідовність  дій запуску програми.

_Крок 1_ (рис.6 ). Демонстрація роботи функцій вставки та видалення з рядку.

![result1](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab18&&lab19/doc/assets/result1.png?raw=true)
Рисунок 6 --- Результат виконання кроку 1

_Крок 2_ (див. рис.7 ). Демонстрація виконання функції вставки структури в масив структур по індексу

![result2](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab18&&lab19/doc/assets/result2.png?raw=true)
Рисунок 7 --- Результат виконання кроку 2

_Крок 3_ (див. рис.8 ). Демонстрація виконання функції видалення структури з масиву структур по індексу

![enter image description here](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab18&&lab19/doc/assets/result3.png?raw=true)
Рисунок 7 --- Результат виконання кроку 3

## 3. Опис програми на основі динамічного списку

### 3.1 Функціональне призначення

За допомогою розроблених функцій можна вставити елемент в список, видалити видалити елемент зі списку, відсортувати список та виконувати взаємодію з користувачем.

### 3.2 Опис логічної структури програми

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




### 3.3 Важливі фрагменти програми

#### Функція вставки елементу в список

``` 
void InsertElement(struct List *list, int pos, int a, char b[10], int c, char d[15], int f)
{

	if(pos <= 0){
		AddElementBegin(list, a, b, c, d, f);
		return;
	}
	struct ListBackpack *p = list->head;
	for(int i = pos; i > 0; i--){
		if(!p) {
			AddElementEnd(list, a, b, c, d, f);
			return;
		}
		p = p->next;
	}
	struct ListBackpack * backpack = NewListBackpack(a, b, c, d, f);
	backpack->prev = p->prev;
	backpack->next = p;
	backpack->next->prev = backpack;
	backpack->prev->next = backpack;
}
  
```
#### Функція видалення елементу зі списку

```
void DeleteElement(struct List *list, int pos){
	if(pos < 0){
		return;
	}
	struct ListBackpack *p = list->head;
	if(pos == 0){
		if(!list->head){
			return;
		}
		list->head = list->head->next;
		if(p->next){
			p->next->prev = NULL;
		}else{
			list->tail = NULL;
		}
		free(p);
		return;
	}
	for(int i = pos; i > 0; i--){
		if(!p) {
			return;
		}
		p = p->next;
	}
	p->prev->next = p->next;
	if(p->next){
		p->next->prev = p->prev;
	}else{
		list->tail = p->prev;
	}
	free(p);
}
```


### 3. Варіанти використання

Для демонстрації результатів використовується Clion. Нижче наводиться послідовність  дій запуску програми.

_Крок 1_ (рис.12 ). Демонстрація діалогового меню.

![result1](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab18&&lab19/doc/assets/result4.png?raw=truee)
Рисунок 12 --- Результат виконання кроку 1

_Крок 2_ (див. рис.13 ). Виклик функції сортування за критерієм "об'єм"

![result2](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab18&&lab19/doc/assets/result5.png?raw=true)
Рисунок 13 --- Результат виконання кроку 2

_Крок 3_ (див. рис.14 ). Результат виклику функції сортування 

![enter image description here](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab18&&lab19/doc/assets/result6.png?raw=true)
Рисунок 14 --- Результат виконання кроку 3

_Крок 4_ (див. рис.15 ). Перевірка на витоки пам'яті. Витоків пам'яті не знайдено.
![enter image description here](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab18&&lab19/doc/assets/valgrind.png?raw=true)
Рисунок 15 --- Результат виконання кроку 4
### Структура проекту

	├── lab18 && lab19
	    ├── Doxyfile
	    ├── backpacks.txt
	    ├── doc
	        ├── lab2.md
	        └── assets
	    ├── lab18
		    ├── CMakelist.txt
		    ├── test
			    ├── test.c
		    └── src
		        ├── main.c
		        ├── lib.c
		        └── lib.h
			    ├── test.c
	    └── lab19
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

Ми навчились працювати зі динамічними масивами та динамічними списками

