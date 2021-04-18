
# Лабораторна робота №6. Регулярні вирази

## 1. Вимоги

### 1.1 Розробник

- Макаренко Владислав Олександрович;

- студент групи КІТ-120а;

- 18-квітня-2021

### 1.2 Загальне завдання

 1. При введені інформації про базовий тип виконати перевірку:
	   * Можна вводити тільки кириличні символи, латинські символи, цифри, пропуски, розділові знаки

	 * Не повинно бути пропусків та розділових знаків, які повторюються
	 * Перше слово не повинно починатися з маленького символу 

 2. У клас-список додати метод, що виводить на екран список усіх об'єктів, які мають одне або більше полів з щонайменше двома словами (перевірку виконати за допомогою регулярних виразів)
 
### 1.3 Індивідуальне завдання

 Виконати завдання згідно варіанту
 

## 2. Опис програми 

### 2.1 Функціональне призначення

За допомогою регулярних виразів виконується перевірка вхідного тексту

### 2.2 Опис логічної структури програми

Загальне завдання виконується за допомогою розроблених функцій. Функції:  `RegexChek` виконує перевірку вхідного тексту;`PrintFieldWithTwoWords` виводить на екран список необхідних елементів.

_Головна функція_`main()`. Виконує взаємодію з користувачем шляхом діалогового меню. Викликає функції `RegexChek` та `PrintFieldWithTwoWords` в залежності від запитів користувача
 _Схема алгоритму функції_ подана на рис. 1.

![enter image description here](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab22/doc/assets/main.png?raw=true)

Рисунок 1  --- Схема алгоритму функції `main`


_Функція перевірки_ `RegexChek`. виконує перевірку вхідного тексту за допомогою регулярних виразів, та в залежності від перевірки додає новий елемент в список .
_Схема алгоритму функції_ подана на рис. 2.

![Схема алгоритму функції](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab22/doc/assets/RegexChek.png?raw=true)

Рисунок 2 --- Схема алгоритму функції `RegexChek`

_Функція_ `PrintFieldWithTwoWords`: Функція виконує перевірку полів елементу на наявність щонайменше двух слів і в залежності від результату перевірки виводить елемент на екран
_Схема алгоритму функції_ подана на рис. 3.
![enter image description here](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab22/doc/assets/PrintFieldWithTwoWords.png?raw=true)

Рисунок 3 --- Схема алгоритму функції  `PrintFieldWithTwoWords`



### 2.3 Важливі фрагменти програми

#### Перевірка вхідного тексту за допомогою регулярних виразів

``` 
bool RegexChek(char a[1], char b[10], char c[3], char d[25], char f[1]) {  
  bool result = true;  
    regex_t regex;  
    int return_valueA = regcomp(&regex, "^[0-1]$", 0);  
    return_valueA = regexec(&regex, a, 0, NULL, 0);  
    if (return_valueA != 0) {  
  result &= false;  
    }  
  int return_valueB = regcomp(&regex, "^[A-ZА-Я][a-zа-я]*$", REG_EXTENDED);  
    return_valueB = regexec(&regex, b, 0, NULL, 0);  
    if (return_valueB != 0) {  
  result &= false;  
    }  
  int return_valueC = regcomp(&regex, "^[0-9]{1,3}$", REG_EXTENDED);  
    return_valueC = regexec(&regex, c, 0, NULL, 0);  
    if (return_valueC != 0) {  
	  result &= false;  
    }  
  int return_valueD = regcomp(&regex, "^[A-ZА-Я][a-zа-яA-ZА-Я]*((( |-|$)?[a-zA-Zа-яА-Я])*|$)?$", REG_EXTENDED);  
    return_valueD = regexec(&regex, d, 0, NULL, 0);  
    if (return_valueD != 0) {  
	  result &= false;  
    }  
  int return_valueF = regcomp(&regex, "^[0-2]$", 0);  
    return_valueF = regexec(&regex, f, 0, NULL, 0);  
    if (return_valueF != 0) {  
	  result &= false;  
    }  
  return result;  
}
  
```
#### Виведення елементів у яких хоча б одне поле має щонайменше два слова

```
 void PrintFieldWithTwoWords(struct List *list){  
	int flag = 0;  
    printf("\tPlace for laptop - (1 - Yes, 0 - No)   Purpose(0 - URBAN, 1 - TACTICAL, 2 - TOURIST)\n\n");  
    printf("    Place for laptop:              COLOR:              VOLUME:             PURPOSE:                       COUNTRY:\n");  
    for (struct ListBackpack *backpack = list->head; backpack != NULL; backpack = backpack->next) {  
		  regex_t regex;  
	      int return_value = regcomp(&regex, "^[A-ZА-Я][a-zа-яA-ZА-Я-]* ((( |-|$)?[a-zA-Zа-яА-Я-])*|$)?$", REG_EXTENDED);  
          return_value = regexec(&regex, backpack->country, 0, NULL, 0);  
          if (return_value == 0) {  
			  flag = 1;  
              printf("%20d %20s %20d %20d %30s\n", backpack->laptop_department, backpack->color, backpack->volume,  
                   backpack->enumPurpose, backpack->country);  
          }  
          }  
     if(flag == 0){  
		 printf("ERROR: Таких элементов нету\n");  
     }  
}
```


### 3. Варіанти використання

Для демонстрації результатів використовується Clion. Нижче наводиться послідовність  дій запуску програми.

_Крок 1_ (рис.4 ). Правильне та не правильне заповнення полів елементів списку

![result1](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab22/doc/assets/result1.png?raw=true)
Рисунок 4 --- Результат виконання кроку 1

_Крок 2_ (див. рис.5 ). Правильне заповнення елементів списку

![result2](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab22/doc/assets/result3.png?raw=true)
Рисунок 5 --- Результат виконання кроку 2

_Крок 3_ (див. рис.6 ). Результат роботи функції `PrintFieldWithTwoWords`

![result3](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab22/doc/assets/result2.png?raw=truee)
Рисунок 6 --- Результат виконання кроку 3


### Структура проекту

	├── lab22
	    ├── Doxyfile
	    ├── doc
	        ├── lab6.md
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

Ми навчились працювати з регулярними виразами

