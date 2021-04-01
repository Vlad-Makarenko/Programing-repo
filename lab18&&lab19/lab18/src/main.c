//
// Created by Vlad on 28.03.2021.
//

/**
 * @mainpage
 * # Загальне завдання
 * 1. **Розробити** функцію, яка реалізує вставку в рядок "s" другий рядок "s2"
 * в "і" - у позицію рядка "s";
 * 2. **Розробити** функцію, видалення з рядка "" усіх символів з індексами в
 * заданому діапазоні;
 * 3. **Розробити** функцію додавання та видалення елементів з динамічного
 * масиву вашої прикладної області
 *
 * @author Makarenko V.
 * @date 28-march-2021
 * @version 1.0
 */

/**
 * @file main.c
 * @brief Файл з демонстрацією роботи роботи розроблених функцій
 *
 * @author Makarenko V.
 * @date 28-march-2021
 * @version 1.0
 */

#include "lib.h"

/**
 * Головна функція.
 *
 * Послідовність дій:
 * - створення масиву із {@link COUNT} рюкзаків
 * - вставка заданого підрядка в заданий рядок за допомогою функції {@link ElementInsertion}
 * - видалення підрядка з заданого рядка за допомогою функції {@link ElementDeleting}
 * - зчитування масиву структур {@link Backpack} з файлу за допомогою функції {@link ReadFromFile}
 * - генерація чисельних даних для кожної структури за допомогою функції {@link random_number_generation}
 * - вставка структури в масив структур по заданому індексу за допомогою функціїї {@link InsertStruct}
 * - видалення структури з масиву структур по заданому індексу за допомогою функції {@link DeleteStruct}
 * - звільненя виділеної пам'яті
 * @return успішний код повернення з програми (0)
 */
int main() {
    char* text1 = malloc(sizeof (char)* 255);
    char* passed_text = malloc(sizeof (char)* 255);
    char* text2 = malloc(sizeof (char)* 255);
    struct Backpack ** backpacks = malloc(COUNT * sizeof (struct Backpack));
    for(int i = 0; i < COUNT; i++){
        *(backpacks + i) = malloc(sizeof (struct Backpack));
    }
    struct Backpack * backpacksIN = malloc(sizeof (struct Backpack));


    printf("Введите текст: ");
    scanf("%s", text1);
    printf("Введите вставляемую строку: ");
    scanf("%s", passed_text);
    int position;
    printf("Введите позицию, после которой вставить строку: ");
    scanf("%i", &position);
    char* result_insert = ElementInsertion(text1, passed_text, position);
    printf("Результат добавления: %s\n\n", result_insert);

    int start_pos;
    int end_pos;
    printf("Введите текст: ");
    scanf("%s", text2);
    printf("Введите начальную позицию для удаления: ");
    scanf("%d", &start_pos);
    printf("Введите конечную позицию для удаления: ");
    scanf("%d", &end_pos);
    char* result_deleting = ElementDeleting(text2, start_pos, end_pos);
    printf("Результат удаления: %s\n\n", result_deleting);


    ReadFromFile(backpacks);

    random_number_generation(backpacks);

    struct Backpack * insert = malloc(sizeof (struct Backpack));

    (insert)->laptop_department = 1;
    strcpy(insert->color, "yellow");
    insert->volume = 44;
    stpcpy(insert->country, "Italy");
    insert->enumPurpose = URBAN;

    printf("Вставляемая структура:\n\n");
    printf("Availability of a laptop department: Yes\n");
    printf("Color: %s\n", insert->color);
    printf("Volume: %d liter(s)\n", insert->volume);
    printf("Producing country: %s\n", insert->country);
    printf("The purpose: city backpack\n");
    printf("\n");

    int pos;
    printf("Введите позицию, на которую вставить структуру: ");
    scanf("%i", &pos);

    InsertStruct(backpacks, insert, pos);

    printf("\nМассив структур:\n\n");
    PrintInConsole(backpacks, COUNT);

    int pos1;
    printf("Введите позицию, после которой удалить структуру: ");
    scanf("%i", &pos1);

    DeleteStruct(backpacks, pos1);


    free(result_insert);
    free(text1);
    free(passed_text);
    free(result_deleting);
    free(text2);
    free(backpacksIN);
    free(insert);
    for (int  i = 0; i < COUNT; i ++){
        free(*(backpacks + i));
    }
    return 0;
}
