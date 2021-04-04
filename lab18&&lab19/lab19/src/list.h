//
// Created by Vlad on 01.04.2021.
//
#include "data.h"

#ifndef LAB19_LIST_H
#define LAB19_LIST_H

/**
 * Структура «Рюкзак»
 */
struct ListBackpack{
    int laptop_department; // 1 - yes; 0 - no.
    char color[10];
    int volume;
    char country[15];
    enum Purpose enumPurpose;
    struct ListBackpack *next;
    struct ListBackpack *prev;
};

/**
 * Двоспрямований список
 */
struct List {
    struct ListBackpack *head;
    struct ListBackpack *tail;
};

/**
 * Функція створення списку
 *
 * Функція створює список
 */
struct List *NewList();

/**
 * Функція створення елементів списку
 *
 * Функція створює новий елемент списку
 * @param a наявність відділу для ноутбука
 * @param b колір
 * @param c об'єм
 * @param d країна
 * @param f призначення
 * @return повертає створений елемент
 */
struct ListBackpack *NewListBackpack(int a, char b[10], int c, char d[15], int f);

/**
 * Функція додавання нового елементу в кінець списку
 *
 * Функція додає новий елемент в кінець списку
 * @param list список {@link ListBackpack} для додавання елементу
 * @param a наявність відділу для ноутбука
 * @param b колір
 * @param c об'єм
 * @param d країна
 * @param f призначення
 */
void AddElementEnd(struct List *list, int a, char b[10], int c, char d[15], int f);

/**
 * Функція додавання нового елементу в початок списку
 *
 * Функція додає новий елемент в початок списку
 * @param list список {@link ListBackpack} для додавання елементу
 * @param a наявність відділу для ноутбука
 * @param b колір
 * @param c об'єм
 * @param d країна
 * @param f призначення
 */
void AddElementBegin(struct List *list, int a, char b[10], int c, char d[15], int f);

/**
 * Функція додавання нового елементу в список по індексу
 *
 * Функція додає новий елемент в список по індексу
 * @param pos місце куди додати новий елемент
 * @param list список {@link ListBackpack} для додавання елементу
 * @param a наявність відділу для ноутбука
 * @param b колір
 * @param c об'єм
 * @param d країна
 * @param f призначення
 */
void InsertElement(struct List *list, int pos, int a, char b[10], int c, char d[15], int f);

/**
 * Функція видалення елементу зі списку
 *
 * Функція видаляє елемент зі списку
 * @param pos з якого буде видалено елемент
 * @param list список {@link ListBackpack} для видалення елементу
 */
void DeleteElement(struct List *list, int pos);

/**
 * Функція читання з файлу
 *
 * Функція читає данні з заданого файлу та записує їх в список
 * @param list список {@link ListBackpack} для заповнення
 */
void ReadListFromFile(struct List* list);

/**
 * Функція виводу в консоль
 *
 * @param list список {@link ListBackpack} для зчитування
 * @param side напрям списку
 */
void ShowList(struct List *list, int side);

/**
 * Функція запису у файл
 *
 * Функція записує у файл заданий список
 * @param list список {@link ListBackpack} для зчитування
 * @param side напрям списку
 */
void PrintListInFile(struct List *list, int side);

/**
 * Функція пошуку об'єкту
 *
 * Функція знаходить заданий елемент списку
 * @param list список {@link ListBackpack} для пошуку
 * @param index поле, яке треба знайти
 */
void FindBackpack(struct List * list, int index);

/**
 * Функція порівняння елементів списку
 *
 * Функція порівнює наявність відділу для ноутбука
 * @param a елемент списку {@link ListBackpack} для порівняння
 * @param b елемент списку {@link ListBackpack} для порівняння
 */
int compareLd(struct ListBackpack* a, struct ListBackpack* b);

/**
 * Функція порівняння елементів списку
 *
 * Функція порівнює кольора
 * @param a елемент списку {@link ListBackpack} для порівняння
 * @param b елемент списку {@link ListBackpack} для порівняння
 */
int compareColor(struct ListBackpack* a, struct ListBackpack* b);

/**
 * Функція порівняння елементів списку
 *
 * Функція порівнює об'єм
 * @param a елемент списку {@link ListBackpack} для порівняння
 * @param b елемент списку {@link ListBackpack} для порівняння
 */
int compareVolume(struct ListBackpack* a, struct ListBackpack* b);

/**
 * Функція порівняння елементів списку
 *
 * Функція порівнює країни
 * @param a елемент списку {@link ListBackpack} для порівняння
 * @param b елемент списку {@link ListBackpack} для порівняння
 */
int compareCountry(struct ListBackpack* a, struct ListBackpack* b);

/**
 * Функція порівняння елементів списку
 *
 * Функція порівнює призначення
 * @param a елемент списку {@link ListBackpack} для порівняння
 * @param b елемент списку {@link ListBackpack} для порівняння
 */
int comparePurpose(struct ListBackpack* a, struct ListBackpack* b);

/**
 * Функція сортування елементів списку
 *
 * Функція порівнює наявність відділу для ноутбука
 * @param list список {@link ListBackpack} для сортування
 * @param compare викликає функції порівняння заданих полів
 */
void SortListByCriterion(struct List *list, int(*compare)(struct ListBackpack*, struct ListBackpack*));

/**
 * Функція очищення пам'яті
 *
 * Функція очищує список
 * @param list список {@link ListBackpack} для очищення
 */
void FreeList(struct List *list);

#endif //LAB19_LIST_H
