/**
 * @mainpage
 * # Загальне завдання
 *  Розробити мінікалькулятор
 * 
 *
 * @author Makarenko V.
 * @date 24-dec-2020
 * @version 0.1
 */

/**
 * @file main3.c
 * @brief Завдання №3
 *
 * @author Makarenko V.
 * @date 24-dec-2020
 * @version 1.0
 */

#include <string.h>

/**
 * функція, що виконує операцію залежно від вхідних даних
 *
 * @param result - приймає результат операції
 */
 
float do_operation(int operand_left, int operand_right, char oper);

/**
 * Вхідна строка
 */

#define STR "25*55"

/**
 * Головна функція.
 *
 * Послідовність дій:
 * - створення буферу
 * - визначення першлого числа у виразі
 * - визначення виду операції
 * - визначення другого числа у виразі
 * - виклик функціїї do_operation для розрахунку вираза
 * @return успішний код повернення з програми (0)
 * @param op_left  - преше число у виразі
 * @param op_right - друге число у виразі
 * @param op - вид операції
 * @param result - приймає результат виконання функції
 */


int main () {

    char * buffer = malloc(strlen(STR) * sizeof(char));

    int op_left = strtol(STR, &buffer, 10);
    char op = buffer[0];
    int op_right = strtol(buffer + 1, NULL, 10);

    float result = do_operation(op_left, op_right, op);

    free(buffer);

    return 0;
}

float do_operation(int operand_left, int operand_right, char oper) {
    float result = 0;
    switch (oper) {
        case '+' : result = operand_left + operand_right; break;
        case '-' : result = operand_left - operand_right; break;
        case '*' : result = operand_left * operand_right; break;
        case '/' :
            if (operand_right != 0) {
                result = (float) operand_left / (float) operand_right;
            }
            break;
        default: result = 0;
    }
    return result;
}result
