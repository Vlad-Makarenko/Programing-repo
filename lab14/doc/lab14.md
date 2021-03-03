
# Лабораторна робота №14. Взаємодія з файлами

## 1. Вимоги

### 1.1 Розробник

- Макаренко Владислав Олександрович;

- студент групи КІТ-120а;

- 25-лютого-2021

### 1.2 Загальне завдання

1. Вивести структуру файлів та каталогів, як це робить утиліта tree.

 2. Визначити об'єм запитаного каталогу. 

### 1.3 Індивідуальне завдання

 Переробити программу, з лабораторної роботи №13, під взаємодію з файлами
 
## 2. Опис програми

### 2.1 Функціональне призначення

За допомогою взаємодії з файлами, программа виводе на екран структуру каталога (як це робить утиліта `tree`); рахує розмір заданого каталогу; виконує арифметичну операцію беручи данні з заданого файла, а виводить результат в заданий файл.

### 2.2 Опис логічної структури програми

Загальне завдання виконується за допомогою рекурсії. Функції `tree_function`, `calculate_size_of_directory` рекурсивно перебирають кожен каталог та файл и виводить структуру заданого каталога в першому завдані; та розмір заданого каталогу в другому завдані. В індивідуальному завдані функція `read_from_file` зчитує інформацію з заданого файл; `do_operation` виконує арифметичну операцію; та `write_to_file`  записує результат в заданий файл.

_Головна функція_`main()`. Викликає функції `tree_function`, `print_size_of_directory`,  `do_arithmetic_operation` для виконання загальних та індивідуального завдань
 _Схема алгоритму функції_ подана на рис. 1.

![Схема алгоритму функції](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab14/doc/assets/main.png?raw=true)
Рисунок 1  --- Схема алгоритму функції `main`


_Функція, що виводе структуру каталогу_ `tree_function`. Функція рекурсивно перебирає усі файли та каталоги даного каталога та виводе іх на екран, як це робить утиліта `tree`.
_Схема алгоритму функції_ подана на рис. 2.

![Схема алгоритму функції](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab14/doc/assets/tree_function.png?raw=true)
Рисунок 2 --- Схема алгоритму функції `tree_function`

_Функція, що виводить розмір каталогу_ `print_size_of_directory`:
 Функція запитує у користувача назву каталогу та викликає функції `calculate_size_of_directory` та `calculate_file_size` для розрахунку розміру запитуваного каталогу, після чого виводе результат на екран.

_Функція_ `do_arithmetic_operation`:
 Функція викликає функцію `read_from_file` для зчитування вхідних данних з файлу, потім викликаеться функція `do_operation` яка виконує арифметичну операцію; і в кінці функція `write_to_file` записує результат у файл.


#### Структура проекту

    ├── lab14
    ├── Doxyfile
    ├── Makefile
    ├── input.txt
    ├── doc
        ├── lab14.md
        └── assets
    └── src
        ├── main.c
        ├── lib.c
        └── lib.h

### 2.3 Важливі фрагменти програми



#### Опис функціяї ```tree_function```, яка приймає назву директорії і кількість відступів  та виводить сруктуру каталогу

``` 
void tree_function(char *directory_name, int count_of_space)
{
    DIR *folder;
    struct dirent *directory;

    folder = opendir(directory_name);
    if (folder != NULL)
    {
        while ((directory = readdir(folder)))
        {
            if (strcmp(directory->d_name, ".") != 0 && strcmp(directory->d_name, "..") != 0)
            {
                printf(" |");
                printf("%*c", count_of_space, ' ');
                printf("+---");
                printf("%s\n", directory->d_name);
                char *full_name_of_subdirectory = malloc((strlen(directory_name) + 1 + strlen(directory->d_name)) * sizeof(char));
                strcpy(full_name_of_subdirectory, directory_name);
                strcat(full_name_of_subdirectory, SLESH);
                strcat(full_name_of_subdirectory, directory->d_name);
                tree_function(full_name_of_subdirectory, count_of_space + 4);
                free(full_name_of_subdirectory);
            }
        }
    }

    closedir(folder);
}
  
```


### 3. Варіанти використання

Для демонстрації результатів використовується Clion. Нижче наводиться послідовність  дій запуску програми у режимі відлагодження.

_Крок 1_ (рис.3 ). Виконуємо завдання для відображення структури каталогу

![result1](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab14/doc/assets/Task1.png?raw=true)
Рисунок 3 --- Результат виконання завдання №1

_Крок 2_ (див. рис.4 ). Виконуємо завдання для розрахунку розміру каталога

![result2](https://github.com/Vlad-Makarenko/Programing-repo/blob/main/lab14/doc/assets/Task2.png?raw=true)
Рисунок 4 --- Результат виконання завдання №2


## Висновки

Ми навчились розробляти програми для взаємодії з файлами та каталогами.

