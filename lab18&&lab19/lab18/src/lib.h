//
// Created by Vlad on 28.03.2021.
//

#ifndef LAB18_LIB_H
#define LAB18_LIB_H

/**
 * @file lib.h
 * @brief Файл з описом структури рюкзаків, перерахуванням призначень рюкзаків та функцій
 * оперування рюкзаками, вставки та видаленя структур з масиву структур, вставки та виделення строки
 *
 * @author Makarenko V.
 * @date 28-march-2021
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
 * Функція виводу в консоль
 *
 * Функція виводить відсортований масив структур на екран
 * @param backpacks масив структур {@link Backpack} що виводиться
 */
void PrintInConsole(struct Backpack **backpacks, int size);

/**
 * Функція вставки підрядка в рядок
 *
 * Функція вставляє підрядок в заданий рядок по заданому індексу
 * @param text текст в який буде вставлений рядок
 * @param pasted_text строка, яка буде вставлена в {@link text}
 * @param position індекс після якого буде вставлений {@link pasted_text}
 */
char * ElementInsertion(char * text, char * pasted_text, int position);

/**
 * Функція виделаеня підрядка з тексту
 *
 * Функція видаляє підрядок з тексту по заданим індексам
 * @param text текст з якого буде видалений підрядок
 * @param start_pos індекс, починаючи з якого буде видалений підрядок з {@link text}
 * @param end_pos індекс, яким закінчиться видалення підрязка з {@link text}
 */
char * ElementDeleting(char * text, int start_pos, int end_pos);

/**
 * Функція вставки структури в массив структур
 *
 * Функція вставляє задану структуру в масив структур по заданому індексу
 * @param backpacks масив структур, куди буде вставлена структура
 * @param insert структура, яка буде вставлена в {@link backpacks}
 * @param position індекс після якого буде вставлена {@link insert}
 */
struct Backpack** InsertStruct (struct Backpack **backpacks, struct Backpack *insert, int position);

/**
 * Функція виделаеня структури з масиву структур
 *
 * Функція видаляє структуру з масиву структур по заданому індексу
 * @param backpacks масив структур, звідки буде вставлена структура
 * @param position індекс після якого буде видалена структура з масиву структур {@link backpacks}
 */
struct Backpack** DeleteStruct (struct Backpack **backpacks, int position);


#endif