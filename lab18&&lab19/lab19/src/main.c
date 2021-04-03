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

#include "list.h"

/**
 * Головна функція.
 *
 * Послідовність дій:
 * - створення списку
 * - запит у дії у користувача
 * - виконання запиту користувача
 * @return успішний код повернення з програми (0)
 */
int main() {

    struct List *ls = NewList();
    ReadListFromFile(ls);
    for (int i = 0; i < 44; ++i) {
        int index;
        printf(" |----------ВАРИАНТЫ ДЕЙСТВИЙ----------|\n");
        printf(" |\t1. Вывести список на экран\n");
        printf(" |\t2. Найти в списке элемент\n");
        printf(" |\t3. Удалить элемент из списка\n");
        printf(" |\t4. Сортировать список\n");
        printf(" |\t5. Вставить новый элемент в список\n");
        printf(" |\t6. Выход\n");
        printf(" |-------------------------------------|\n");
        printf(" |\tВыберите действие: ");
        scanf("%d", &index);
        printf(" |-------------------------------------|\n");

        switch (index) {
            case 1:
                printf("\n |--------------------------------------------------------------------|\n");
                printf(" |\tВведите направление выводу спика(0 - от головы к хвосту; 1 - от хвоста к голове): ");
                int side;
                scanf("%d", &side);
                printf(" |\n |-------------------------------СПИСОК-------------------------------|\n\n");
                ShowList(ls, side);
                printf(" |--------------------------------------------------------------------|\n\n");
                PrintListInFile(ls, side);
                break;
            case 2:
                printf("\n |-------------Критерии поиска-------------|\n");
                printf(" |\t1. C наличием отдела для ноутбука\n");
                printf(" |\t2. Цвет\n");
                printf(" |\t3. Обьем\n");
                printf(" |\t4. Страна\n");
                printf(" |\t5. Цель использования\n");
                printf(" |-----------------------------------------|\n");
                printf(" |\tВведите критерий, по которому искать рюкзак: ");
                int number;
                scanf("%d", &number);
                FindBackpack(ls, number);
                break;
            case 3:
                printf("\n\n |---------------------------------------|");
                printf("\n |\tВведите индекс елемента, который удалить: ");
                int pos;
                scanf("%d", &pos);
                DeleteElement(ls, pos);
                printf(" |\tЕлемент удален\n");
                printf(" |---------------------------------------|\n\n\n");
                break;
            case 4:
                printf("\n |-------------Критерии сортировки-------------|\n");
                printf(" |\t1. Наличие отдела для ноутбука\n");
                printf(" |\t2. Цвет\n");
                printf(" |\t3. Обьем\n");
                printf(" |\t4. Страна\n");
                printf(" |\t5. Цель использования\n");
                printf(" |-----------------------------------------|\n");
                printf(" |\tВведите критерий, по которому сортировать список: ");
                int num;
                scanf("%d", &num);
                switch (num) {
                    case 1:
                        SortListByCriterion(ls, compareLd);
                        printf(" |\tСписок отсортирован!\n");
                        printf(" |-----------------------------------------|\n\n");
                        break;
                    case 2:
                        SortListByCriterion(ls, compareColor);
                        printf(" |\tСписок отсортирован!\n");
                        printf(" |-----------------------------------------|\n\n");
                        break;
                    case 3:
                        SortListByCriterion(ls, compareVolume);
                        printf(" |\tСписок отсортирован!\n");
                        printf(" |-----------------------------------------|\n\n");
                        break;
                    case 4:
                        SortListByCriterion(ls, compareCountry);
                        printf(" |\tСписок отсортирован!\n");
                        printf(" |-----------------------------------------|\n\n");
                        break;
                    case 5:
                        SortListByCriterion(ls, comparePurpose);
                        printf(" |\tСписок отсортирован!\n");
                        printf(" |-----------------------------------------|\n\n");
                        break;
                    default:
                        printf(" |\tERROR: Некорректный вариант\n");
                        printf(" |-----------------------------------------|\n\n");
                        break;
                }
                break;
            case 5:
                printf("\n |-------------Вставка элемента-------------|");
                printf("\n |\tВведите элемент, который нужно вставить в список:\n");
                int LD;
                char color[10];
                int volume;
                char country[15];
                int aim;
                printf(" |\tНаличие отдела для ноутбука(1-Да, 0-Нет): ");
                scanf("%d", &LD);
                printf(" |\tВведите цвет: ");
                scanf("%s", color);
                printf(" |\tВведите объём: ");
                scanf("%d", &volume);
                printf(" |\tВведите страну: ");
                scanf("%s", country);
                printf(" |\tВведите цель(0-Городской, 1-Тактический, 2-Туристический): ");
                scanf("%d", &aim);
                printf(" |------------------------------------------|");
                printf("\n |\tВведите позицию, после которой нужно вставить элемент в список: ");
                int position;
                scanf("%d", &position);
                InsertElement(ls,  position, LD, color ,  volume,  country,  aim);
                printf(" |\tВставка выполнена!");
                printf("\n |---------------------------------------|\n\n");
                break;
            case 6:
                free(ls);
                printf(" |\tПрограмма выполнена успешно\n");
                printf(" |-------------------------------------|\n\n");
                return 0;
            default:
                printf("|\tERROR: Некорректный вариант\n");
                printf(" |-------------------------------------|\n\n");
                break;
        }
    }
    //Lab15();
    return 0;
}
