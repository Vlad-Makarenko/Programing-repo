//
// Created by Vlad on 22.03.2021.
//

#ifndef LAB15_LAB17_LIB_H
#define LAB15_LAB17_LIB_H

/**
 * @file lib.h
 * @brief Файл з описом структури рюкзаків, перерахуванням призначень рюкзаків та функцій
 * оперування рюкзаками
 *
 * @author Makarenko V.
 * @date 22-march-2021
 * @version 1.0
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <errno.h>

/**
 * Кількість структур у масиві
 */
#define COUNT 6

/**
 * Перелік призначень
 */
enum Purpose{
    URBAN,
    TACTICAL,
    TOURIST
};

/**
 * Структура «Рюкзак»
 */
struct Backpack{
    int laptop_department; // 1 - yes; 0 - no.
    char color[10];
    int volume;
    char country[15];
    enum Purpose enumPurpose;
};

/**
 * Функція читання з файлу
 *
 * Функція читає данні з заданого файлу та записує їх в задану структуру
 * @param name масив структур {@link Backpack} для заповнення
 */
void ReadFromFile(struct Backpack **name);

/**
 * Функція генерації об'єму
 *
 * Функція генерує випадковий об'єм у заданому діапазоні
 * @param backpacks масив структур {@link Backpack} для заповнення
 */
void random_number_generation(struct Backpack **backpacks);

/**
 * Функція порівняння
 *
 * Функція порівнює строки між собою
 * @param a перша строка для порівняння
 * @param b друга строка для порівняння
 * @return результат порівняння: 1 - перша строка довше другої, 0 - строки
 * рівні, -1 - перша строка коротше другої
 */
int comparator(char a[15], char b[15]);

/**
 * Функція сортування
 *
 * Функція сортує масив структур за заданим критерієм
 * @param backpacks масив структур {@link Backpack} який буде сортуватись
 * @param criterion критерії за яким буде відбуватись сортування
 * @param size кількість структур в масиві
 */
void SortByCriterion(struct Backpack **backpacks, char criterion[18], int size);

/**
 * Функція виводу в консоль
 *
 * Функція виводить відсортований масив структур на екран
 * @param backpacks масив структур {@link Backpack} що виводиться
 */
void PrintInConsole(struct Backpack **backpacks);

/**
 * Функція виводу в файл
 *
 * Функція виводить відсортований масив структур в файл
 * @param backpacks масив структур {@link Backpack} що виводиться
 */
void PrintInFile(struct Backpack **backpacks);

/**
 * Функція пошуку об'єкту
 *
 * Функція знаходить серед масиву структур німецький міський рюкзак
 * @param backpacks масив структур {@link Backpack} в якому відбуваєтья пошук
 * @param size кількість структур в масиві
 * @return повертає знайдену структуру
 */
struct Backpack*  FindGermanBackpack(struct Backpack **backpacks, int size);

/**
 * Функція виводу в бінарний файл
 *
 * Функція виводить відсортований масив структур в бінарний файл
 * @param backpacks масив структур {@link Backpack} що виводиться
 */
void WriteToBinaryFile(struct Backpack **backpacks);

/**
 * Функція читання з бінарного файлу
 *
 * Функція читає данні з заданого бінарного файлу та записує їх в задану структуру
 * @param backpacks масив структур {@link Backpack} для заповнення
 */
void ReadFromBinaryFile(struct Backpack **backpacks);


#endif //LAB15_LAB17_LIB_H
