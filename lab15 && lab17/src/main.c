//
// Created by Vlad on 22.03.2021.
//

/**
 * @mainpage
 * # Загальне завдання
 * 1. **Розробити** функцію, яка читає дані(масив елементів) з файлу;
 * 2. **Розробити** функцію, яка записує дані(масив елементів) у файлу;
 * 3. **Розробити** функцію, яка виводить масив елементів на екран;
 * 4. **Розробити** функцію, яка буде сортувати масив елементів за заданим критерієм;
 * 5. **Розробити** функцію, яка буде знаходити німецький міський рюкзак;
 * 6. **Розробити** функцію, яка генерує чисельні елементи структури;
 * 7. **Розробити** функцію, яка записує дані(масив елементів) у бінарний файлу;
 * 8. **Розробити** функцію, яка читає дані(масив елементів) з бінарного файлу;
 *
 * @author Makarenko V.
 * @date 22-march-2021
 * @version 1.0
 */

/**
 * @file main.c
 * @brief Файл з демонстрацією роботи структури {@link Backpack} та методів
 * оперування нею.
 *
 * @author Makarenko V.
 * @date 22-march-2021
 * @version 1.0
 */

#include "lib.h"

/**
 * Головна функція.
 *
 * Послідовність дій:
 * - створення масиву із {@link COUNT} рюкзаків
 * - зчитування масиву структур {@link Backpack} з файлу за допомогою функції {@link ReadFromFile}
 * - генерація чисельних даних для кожної структури за допомогою функції {@link random_number_generation}
 * - сортування структур за заданим критерієм за допомогою функції {@link SortByCriterion}
 * - вивід даних про всі рюкзаки на екран за допомогою функції {@link PrintInConsole}
 * - вивід даних про всі рюкзаки у файл за допомогою функції {@link PrintInFile}
 * - знаходження німецького міського рюкзака за допомогою функції {@link FindGermanBackpack}
 * - вивід даних про всі рюкзаки у бінарний файл за допомогою функції {@link WriteToBinaryFile}
 * - зчитування масиву структур {@link Backpack} з бінарного файлу за допомогою функції {@link ReadFromBinaryFile}
 * - звільненя виділеної пам'яті
 * @return успішний код повернення з програми (0)
 */
int main(){
    struct Backpack ** backpacks = malloc(COUNT * sizeof (struct Backpack));
    for(int i = 0; i < COUNT; i++){
        *(backpacks + i) = malloc(sizeof (struct Backpack));
    }
    ReadFromFile(backpacks);

    random_number_generation(backpacks);

    char buf[18];
    printf("Enter a sort criterion: ");
    scanf("%s", buf);
    printf("\n");

    SortByCriterion(backpacks, buf, COUNT);

    PrintInConsole(backpacks);

    PrintInFile(backpacks);

    FindGermanBackpack(backpacks, COUNT);

    WriteToBinaryFile(backpacks);

    ReadFromBinaryFile(backpacks);


    for (int  i = 0; i < COUNT; i ++){
        free(*(backpacks + i));
    }

    return 0;
}
