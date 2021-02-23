#include <stdlib.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>

#define SLESH "/"

/**
 * Функція, що проходить по всім файлам та директоріям і виводить їх на екран
 *
 * @param directory_name назва директорії, яку проходимо
 * @param count_of_space кількість відступів для побудови структури каталогу
**/
void tree_function(char *directory_name, int count_of_space);


/**
 * Виводить результат розграхунку розміру директорії
**/
void print_size_of_directory();


/**
 * Функція, що рахує розмір заданої директоріїї
 *
 * @param directory_name назва директорії, розмір якої буде рахуватись
**/
double calculate_size_of_directory(char *directory_name);

/**
 * Функція, що рахує розмір заданого файлу
 *
 * @param file файл, розмір якого рахуєтся
**/
long int calculate_file_size(FILE * file);

/**
 * функція, що виконує записує результат у файл
 *
 * @param file_name - назва файлу, куди буде записаний результат
 * @param result - результат, який буде записаний у файл
 */
void write_to_file(char *file_name, float result);

/**
 * функція, що читає данні з файлу
 *
 * @param file_name - назва файлу, з якого отримаємо данні
 * @param content - змінная, в яку буде записаний вміст файлу
 * @param size - максималька кількість символів для зчитування
 */
void read_from_file(char *file_name, char *content, int size);

/**
 * Функція, що отримує необхідні данні для виконання операції
**/
int do_arithmetic_operation ();

/**
 * функція, що виконує операцію залежно від вхідних даних
 *
 * @param result - приймає результат операції
 */
float do_operation(int operand_left, int operand_right, char oper);


