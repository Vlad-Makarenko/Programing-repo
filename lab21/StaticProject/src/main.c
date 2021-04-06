//
// Created by Vlad on 01.04.2021.
//

/**
 * @mainpage
 * # Загальне завдання
 * 1. **Розробити** функцію, яка зчитує список з файлу
 * 2. **Розробити** функцію, яка записує дані(список) у файлу;
 * 3. **Розробити** функцію, яка виводить список на екран;
 * 4. **Розробити** функцію, яка буде сортувати список за заданим критерієм;
 * 5. **Розробити** функцію, яка буде знаходити заданий еолемент у списку;
 * 6. **Розробити** функцію, яка видаляє елемент зі списку;
 * 7. **Розробити** функцію, яка вставляє новий елемент по індексу;
 * 8. **Реалізувати** діалоговий режим спілкування з користувачем№
 *
 * @author Makarenko V.
 * @date 01-apr-2021
 * @version 1.0
 */

/**
 * @file main.c
 * @brief Файл з демонстрацією роботи роботи розроблених функцій
 *
 * @author Makarenko V.
 * @date 01-apr-2021
 * @version 1.0
 */

#include "entity.h"

/**
 * Головна функція.
 *
 * Послідовність дій:
 * - створення списку
 * - запит у дії у користувача
 * - виконання запиту користувача
 * - звільнення виделіної пам'яті
 * @return успішний код повернення з програми (0)
 */
int main() {
    srand(time(NULL));
    time_t begin = clock();

    int flag;
    printf("Enter the assembly type (0 - with DEBUG, 1 - without DEBUG): ");
    scanf("%d", &flag);
    if(flag == 0) {
        const char *func = __FUNCTION__;
        log_info("start");
        time_t CurTime;
        struct tm * TimeInfo;
        time ( &CurTime );
        TimeInfo = localtime ( &CurTime );
        log_info("Function: %s" , func );
        log_info("Time & Date: %s", asctime (TimeInfo));
    }
    struct List *list = NewList();
    ReadListFromFile(list);
    for (int i = 0; i < 44; ++i) {
        int index;
        printf(" |----------OPTIONS OF ACTION----------|\n");
        printf(" | 1. Display the list on the screen\n");
        printf(" | 2. Find an item in the list\n");
        printf(" | 3. Remove an item from the list\n");
        printf(" | 4. Sort the list\n");
        printf(" | 5. Insert a new item into the list\n");
        printf(" | 6. Exit\n");
        printf(" |-------------------------------------|\n");
        printf(" | Choose an action: ");
        scanf("%d", &index);
        printf("|-------------------------------------|\n");

        switch (index) {
            case 1:
                printf("\n |--------------------------------------------------------------------|\n");
                printf(" | Enter the direction of the list output (0 - from head to tail; 1 - from tail to head): ");
                int side;
                scanf("%d", &side);
                printf("|\n |-------------------------------LIST-------------------------------|\n\n");
                ShowList(list, side, flag);
                printf(" |--------------------------------------------------------------------|\n\n");
                PrintListInFile(list, side);
                break;
            case 2:
                printf("\n |-------------Search criteria-------------|\n");
                printf(" | 1. Place for laptop\n");
                printf(" | 2. Color\n");
                printf(" | 3. Volume\n");
                printf(" | 4. Country\n");
                printf(" | 5. Purpose\n");
                printf(" |-----------------------------------------|\n");
                printf(" | Enter the criterion by which to search for a backpack: ");
                int number;
                scanf("%d", &number);
                FindBackpack(list, number,  flag);
                break;
            case 3:
                printf("\n\n |---------------------------------------|");
                printf("\n | Enter the index of the element to remove: ");
                int pos;
                scanf("%d", &pos);
                DeleteElement(list, pos,  flag);
                printf(" | Item removed\n");
                printf(" |---------------------------------------|\n\n\n");
                break;
            case 4:
                printf("\n |-------------Sorting criteria-------------|\n");
                printf(" | 1. Place for laptop\n");
                printf(" | 2. Color\n");
                printf(" | 3. Volume\n");
                printf(" | 4. Country\n");
                printf(" | 5. Purpose\n");
                printf(" |---------------------------------------|\n");
                printf(" | Enter the criteria by which to sort the list: ");
                int num;
                scanf("%d", &num);
                switch (num) {
                    case 1:
                        SortListByCriterion(list, compareLd, flag);
                        printf("| List sorted!\n");
                        printf(" |-----------------------------------------|\n\n");
                        break;
                    case 2:
                        SortListByCriterion(list, compareColor, flag);
                        printf(" | List sorted!\n");
                        printf(" |-----------------------------------------|\n\n");
                        break;
                    case 3:
                        SortListByCriterion(list, compareVolume, flag);
                        printf("| List sorted!\n");
                        printf(" |-----------------------------------------|\n\n");
                        break;
                    case 4:
                        SortListByCriterion(list, compareCountry, flag);
                        printf("| List sorted!\n");
                        printf(" |-----------------------------------------|\n\n");
                        break;
                    case 5:
                        SortListByCriterion(list, comparePurpose, flag);
                        printf("| List sorted!\n");
                        printf(" |-----------------------------------------|\n\n");
                        break;
                    default:
                        printf(" | ERROR: Incorrect option\n");
                        printf(" |-----------------------------------------|\n\n");
                        break;
                }
                break;
            case 5:
                printf("\n |-------------Insert element-------------|");
                printf("\n | Enter the item you want to insert into the list:\n");
                int LD;
                char color[10];
                int volume;
                char country[15];
                int aim;
                printf(" | Place for laptop(1-Yes, 0-No): ");
                scanf("%d", &LD);
                printf("| Enter color: ");
                scanf("%s", color);
                printf("| Enter volume: ");
                scanf("%d", &volume);
                printf("| Enter country: ");
                scanf("%s", country);
                printf("| Enter target (0-City, 1-Tactical, 2-Tourist): ");
                scanf("%d", &aim);
                printf(" |------------------------------------------|");
                printf("\n | Enter the position after which you want to insert the item into the list: ");
                int position;
                scanf("%d", &position);
                InsertElement(list,  position, LD, color ,  volume,  country,  aim, flag);
                printf("| Insert completed!");
                printf("\n |---------------------------------------|\n\n");
                break;
            case 6:
                FreeList(list, flag);
                printf(" | Program completed successfully\n");
                time_t end = clock();
                double time_spent = (double)(end - begin)/ CLOCKS_PER_SEC;
                if (flag == 0)
                    printf(" | Time spent executing the program: %lf second(s)\n", time_spent);
                printf(" |-------------------------------------|\n\n");
                return 0;
            default:
                printf("| ERROR: Incorrect option\n");
                printf(" |-------------------------------------|\n\n");
                break;
        }
    }
    FreeList(list, flag);
    //Lab15();
    return 0;
}
