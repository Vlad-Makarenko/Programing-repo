//
// Created by Vlad on 28.03.2021.
//

/**
 * @file test.c
 * @brief Файл з тестами на реалізації функцій вставки та видалення рядків та структур
 *
 * @author Makarenko V.
 * @date 28-march-2021
 * @version 1.0
 */


#include "lib.h"


/**
 * Верифікація роботи функції {@link ElementInsertion}
 * на основі вхідних та очікуваних даних
 *
 * @return стан проходження тестів: true - тести пройшли успішно, false - частина
 * тестів не пройшла
 */
bool Test_ElementInsertion(){
    bool result = true;
    char *expected = "abraTEXT2cadabra";
    char* actual = ElementInsertion("abracadabra","TEXT2", 4);
    if(strcmp(expected, actual) == 0){
        result = true;
    } else{
        result = false;
    }
    printf("Ожидаемый результат: %s\n\nРезультат вставки: %s\n\n", expected, actual);

    free(expected);
    free(actual);
    return result;
}

/**
 * Верифікація роботи функції {@link ElementDeleting}
 * на основі вхідних та очікуваних даних
 *
 * @return стан проходження тестів: true - тести пройшли успішно, false - частина
 * тестів не пройшла
 */
bool Test_ElementDeleting(){
    bool result = true;
    char *expected = "abrara";
    char* actual = ElementDeleting("abracadabra",4, 8);
    if(strcmp(expected, actual) == 0){
        result = true;
    } else{
        result = false;
    }
    printf("Ожидаемый результат: %s\n\nРезультат удаления: %s\n\n", expected, actual);

    free(expected);
    free(actual);
    return result;
}

/**
 * Верифікація роботи функції {@link InsertStruct}
 * на основі набора масивів вхідних та очікуваних даних
 *
 * @return стан проходження тестів: true - тести пройшли успішно, false - частина
 * тестів не пройшла
 */
bool Test_InsertStruct(){
    bool result = true;

    struct Backpack * insert = malloc(sizeof (struct Backpack));
    (insert)->laptop_department = 1;
    strcpy(insert->color, "yellow");
    insert->volume = 44;
    stpcpy(insert->country, "Italy");
    insert->enumPurpose = URBAN;


    struct Backpack ** pBackpack = malloc((COUNT + 1) * sizeof (struct Backpack));
    for(int i = 0; i < COUNT + 1; i++){
        *(pBackpack + i) = malloc(sizeof (struct Backpack));
    }

    (*(pBackpack + 0))->laptop_department = 1;
    strcpy((*(pBackpack + 0))->color, "green");
    (*(pBackpack + 0))->volume = 10;
    stpcpy((*(pBackpack + 0))->country, "Ukraine");
    (*(pBackpack + 0))->enumPurpose = TOURIST;

    (*(pBackpack + 1))->laptop_department = 0;
    strcpy((*(pBackpack + 1))->color, "blue");
    (*(pBackpack + 1))->volume = 30;
    stpcpy((*(pBackpack + 1))->country, "German");
    (*(pBackpack + 1))->enumPurpose = URBAN;

    (*(pBackpack + 2))->laptop_department = 1;
    strcpy((*(pBackpack + 2))->color, "green");
    (*(pBackpack + 2))->volume = 10;
    stpcpy((*(pBackpack + 2))->country, "Ukraine");
    (*(pBackpack + 2))->enumPurpose = TOURIST;

    (*(pBackpack + 3))->laptop_department = 0;
    strcpy((*(pBackpack + 3))->color, "blue");
    (*(pBackpack + 3))->volume = 30;
    stpcpy((*(pBackpack + 3))->country, "German");
    (*(pBackpack + 3))->enumPurpose = URBAN;

    (*(pBackpack + 4))->laptop_department = 1;
    strcpy((*(pBackpack + 4))->color, "red");
    (*(pBackpack + 4))->volume = 20;
    stpcpy((*(pBackpack + 4))->country, "England");
    (*(pBackpack + 4))->enumPurpose = TACTICAL;

    (*(pBackpack + 5))->laptop_department = 1;
    strcpy((*(pBackpack + 5))->color, "red");
    (*(pBackpack + 5))->volume = 20;
    stpcpy((*(pBackpack + 5))->country, "England");
    (*(pBackpack + 5))->enumPurpose = TACTICAL;


    struct Backpack ** expected = malloc((COUNT + 1) * sizeof (struct Backpack));
    for(int i = 0; i < COUNT + 1; i++){
        *(expected + i) = malloc(sizeof (struct Backpack));
    }

    (*(expected + 0))->laptop_department = 1;
    strcpy((*(expected + 0))->color, "green");
    (*(expected + 0))->volume = 10;
    stpcpy((*(expected + 0))->country, "Ukraine");
    (*(expected + 0))->enumPurpose = TOURIST;

    (*(expected + 1))->laptop_department = 0;
    strcpy((*(expected + 1))->color, "blue");
    (*(expected + 1))->volume = 30;
    stpcpy((*(expected + 1))->country, "German");
    (*(expected + 1))->enumPurpose = URBAN;

    (*(expected + 2))->laptop_department = 1;
    strcpy((*(expected + 2))->color, "yellow");
    (*(expected + 2))->volume = 44;
    stpcpy((*(expected + 2))->country, "Italy");
    (*(expected + 2))->enumPurpose = URBAN;

    (*(expected + 3))->laptop_department = 1;
    strcpy((*(expected + 3))->color, "green");
    (*(expected + 3))->volume = 10;
    stpcpy((*(expected + 3))->country, "Ukraine");
    (*(expected + 3))->enumPurpose = TOURIST;

    (*(expected + 4))->laptop_department = 0;
    strcpy((*(expected + 4))->color, "blue");
    (*(expected + 4))->volume = 30;
    stpcpy((*(expected + 4))->country, "German");
    (*(expected + 4))->enumPurpose = URBAN;

    (*(expected + 5))->laptop_department = 1;
    strcpy((*(expected + 5))->color, "red");
    (*(expected + 5))->volume = 20;
    stpcpy((*(expected + 5))->country, "England");
    (*(expected + 5))->enumPurpose = TACTICAL;

    (*(expected + 6))->laptop_department = 1;
    strcpy((*(expected + 6))->color, "red");
    (*(expected + 6))->volume = 20;
    stpcpy((*(expected + 6))->country, "England");
    (*(expected + 6))->enumPurpose = TACTICAL;

    printf("Ожидаемый результат:\n\n");
    PrintInConsole(expected, 7);

    struct Backpack** actual = InsertStruct(pBackpack, insert, 2);

    for (int i = 0; i < COUNT + 1; ++i) {
        struct Backpack * tempA = *(actual + i);
        struct Backpack * tempE = *(expected + i);
        if(tempE->laptop_department == tempA->laptop_department && tempE->volume == tempA->volume && tempE->enumPurpose == tempA->enumPurpose && strcmp(tempA->color, tempE->color)==0 && strcmp(tempE->country, tempA->country)==0){
            result &= true;
        }else{
            result &= false;
        }
    }

    for (int i = 0; i < COUNT;  ++i) {
        free(*(pBackpack + i));
    }
    for (int i = 0; i < COUNT - 1;  ++i) {
        free(*(expected + i));
    }
    for (int i = 0; i < COUNT - 1;  ++i) {
        free(*(actual + i));
    }
    return result;
}

/**
 * Верифікація роботи функції {@link DeleteStruct}
 * на основі набора масивів вхідних та очікуваних даних
 *
 * @return стан проходження тестів: true - тести пройшли успішно, false - частина
 * тестів не пройшла
 */
bool Test_DeleteStruct(){
    bool result = true;

    struct Backpack ** pBackpack = malloc((COUNT + 1) * sizeof (struct Backpack));
    for(int i = 0; i < COUNT + 1; i++){
        *(pBackpack + i) = malloc(sizeof (struct Backpack));
    }

    (*(pBackpack + 0))->laptop_department = 1;
    strcpy((*(pBackpack + 0))->color, "green");
    (*(pBackpack + 0))->volume = 10;
    stpcpy((*(pBackpack + 0))->country, "Ukraine");
    (*(pBackpack + 0))->enumPurpose = TOURIST;

    (*(pBackpack + 1))->laptop_department = 0;
    strcpy((*(pBackpack + 1))->color, "blue");
    (*(pBackpack + 1))->volume = 30;
    stpcpy((*(pBackpack + 1))->country, "German");
    (*(pBackpack + 1))->enumPurpose = URBAN;

    (*(pBackpack + 2))->laptop_department = 1;
    strcpy((*(pBackpack + 2))->color, "green");
    (*(pBackpack + 2))->volume = 10;
    stpcpy((*(pBackpack + 2))->country, "Ukraine");
    (*(pBackpack + 2))->enumPurpose = TOURIST;

    (*(pBackpack + 3))->laptop_department = 0;
    strcpy((*(pBackpack + 3))->color, "blue");
    (*(pBackpack + 3))->volume = 30;
    stpcpy((*(pBackpack + 3))->country, "German");
    (*(pBackpack + 3))->enumPurpose = URBAN;

    (*(pBackpack + 4))->laptop_department = 1;
    strcpy((*(pBackpack + 4))->color, "red");
    (*(pBackpack + 4))->volume = 20;
    stpcpy((*(pBackpack + 4))->country, "England");
    (*(pBackpack + 4))->enumPurpose = TACTICAL;

    (*(pBackpack + 5))->laptop_department = 1;
    strcpy((*(pBackpack + 5))->color, "red");
    (*(pBackpack + 5))->volume = 20;
    stpcpy((*(pBackpack + 5))->country, "England");
    (*(pBackpack + 5))->enumPurpose = TACTICAL;


    struct Backpack ** expected = malloc((COUNT - 1) * sizeof (struct Backpack));
    for(int i = 0; i < COUNT + 1; i++){
        *(expected + i) = malloc(sizeof (struct Backpack));
    }

    (*(expected + 0))->laptop_department = 1;
    strcpy((*(expected + 0))->color, "green");
    (*(expected + 0))->volume = 10;
    stpcpy((*(expected + 0))->country, "Ukraine");
    (*(expected + 0))->enumPurpose = TOURIST;

    (*(expected + 1))->laptop_department = 0;
    strcpy((*(expected + 1))->color, "blue");
    (*(expected + 1))->volume = 30;
    stpcpy((*(expected + 1))->country, "German");
    (*(expected + 1))->enumPurpose = URBAN;

    (*(expected + 2))->laptop_department = 0;
    strcpy((*(expected + 2))->color, "blue");
    (*(expected + 2))->volume = 30;
    stpcpy((*(expected + 2))->country, "German");
    (*(expected + 2))->enumPurpose = URBAN;

    (*(expected + 3))->laptop_department = 1;
    strcpy((*(expected + 3))->color, "red");
    (*(expected + 3))->volume = 20;
    stpcpy((*(expected + 3))->country, "England");
    (*(expected + 3))->enumPurpose = TACTICAL;

    (*(expected + 4))->laptop_department = 1;
    strcpy((*(expected + 4))->color, "red");
    (*(expected + 4))->volume = 20;
    stpcpy((*(expected + 4))->country, "England");
    (*(expected + 4))->enumPurpose = TACTICAL;

    printf("Ожидаемый результат:\n\n");
    PrintInConsole(expected, 5);

    struct Backpack** actual = DeleteStruct(pBackpack, 2);

    for (int i = 0; i < COUNT - 1; ++i) {
        struct Backpack * tempA = *(actual + i);
        struct Backpack * tempE = *(expected + i);
        if(tempE->laptop_department == tempA->laptop_department && tempE->volume == tempA->volume && tempE->enumPurpose == tempA->enumPurpose && strcmp(tempA->color, tempE->color)==0 && strcmp(tempE->country, tempA->country)==0){
            result &= true;
        }else{
            result &= false;
        }
    }

    for (int i = 0; i < COUNT;  ++i) {
        free(*(pBackpack + i));
    }
    for (int i = 0; i < COUNT - 1;  ++i) {
        free(*(expected + i));
    }
    for (int i = 0; i < COUNT - 1;  ++i) {
        free(*(actual + i));
    }

    return result;
}

/**
 * Точка входу модуля тестування.
 *
 * Запускає розроблені функції
 *
 * По завершенню тестів виводиться на екран резуміюча інформація про стан
 * проходження тестів.
 *
 * @return стан проходження тестів: true - тести пройшли успішно, false - частина
 * тестів не пройшла
 */
int main(){
    bool result = true;
    printf("\n|------ТЕСТ ВСТАВКИ СТРОКИ В СТРОКУ------|\n\n");
    result &= Test_ElementInsertion();
    if (result == true){
        printf("РЕЗУЛЬТАТ ТЕСТА: Good job so far\n");
    }else{
        printf("D'oh");
    }
    printf("\n|------ТЕСТ УДАЛЕНИЯ СТРОКИ ИЗ СТРОКУ------|\n\n");
    result &= Test_ElementDeleting();
    if (result == true){
        printf("РЕЗУЛЬТАТ ТЕСТА: Good job so far\n");
    }else{
        printf("D'oh");
    }
    printf("\n|------ТЕСТ ВСТАВКИ СТРУКТУРЫ В МАССИВ СТРУКТУР------|\n\n");
    result &= Test_InsertStruct();
    if (result == true){
        printf("РЕЗУЛЬТАТ ТЕСТА: Good job so far\n");
    }else{
        printf("D'oh");
    }
    printf("\n|------ТЕСТ УДАЛЕНИЯ СТРУКТУРЫ ИЗ МАССИВА СТРУКТУР------|\n\n");
    result &= Test_DeleteStruct();
    if (result == true){
        printf("РЕЗУЛЬТАТ ТЕСТА: Good job so far\n");
    }else{
        printf("D'oh");
    }
    printf("\n|---------------------------------------------|");
    return 0;
}