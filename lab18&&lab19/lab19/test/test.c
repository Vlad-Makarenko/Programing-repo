//
// Created by Vlad on 01.04.2021.
//

/**
 * @file test.c
 * @brief Файл з тестами на реалізації функцій сортування списку, вставки
 * та видаленя елементу зі списку
 *
 * @author Makarenko V.
 * @date 01-apr-2021
 * @version 1.0
 */
#include "list.h"


/**
 * Верифікація роботи функції {@link NewListBackpack}
 * на основі набора масивів вхідних та очікуваних даних
 *
 * @return стан проходження тестів: true - тести пройшли успішно, false - частина
 * тестів не пройшла
 */
bool Test_NewListBackpack(){
    bool result = true;

    struct ListBackpack * expected = malloc(sizeof (struct ListBackpack));
    struct ListBackpack * actual = NewListBackpack(1, "green", 44, "Ukraine", 0 );
    char color[10] = "green";
    char country[15] = "Ukraine";
    expected->laptop_department = 1;
    for (int i = 0; i < 10; ++i) {
        expected->color[i] = color[i];
    }
    expected->volume = 44;
    for (int i = 0; i < 15; ++i) {
        expected->country[i] = country[i];
    }
    expected->enumPurpose = 0;
    expected->next = NULL;
    expected->prev = NULL;

    if(expected->laptop_department == actual->laptop_department && expected->volume == actual->volume && expected->enumPurpose == actual->enumPurpose && strcmp(actual->color, expected->color)==0 && strcmp(expected->country, actual->country)==0){
            result &= true;
    }else{
        result &= false;
    }
    return result;
}

/**
 * Верифікація роботи функції {@link InsertElement}
 * на основі набора масивів вхідних та очікуваних даних
 *
 * @return стан проходження тестів: true - тести пройшли успішно, false - частина
 * тестів не пройшла
 */
bool Test_InsertElement() {
    bool result = true;

    struct List *list = NewList();
    AddElementEnd(list, 1, "red", 33, "China", 0);
    AddElementEnd(list, 0, "blue", 22, "Usa", 1);
    AddElementEnd(list, 1, "black", 11, "Poland", 2);

    InsertElement(list, 1, 0, "green", 44, "Ukraine", 0);

    struct List *expected = NewList();
    struct ListBackpack *first = NewListBackpack(1, "red", 33, "China", 0);
    struct ListBackpack *second = NewListBackpack(0, "green", 44, "Ukraine", 0);
    struct ListBackpack *third = NewListBackpack(0, "blue", 22, "Usa", 1);
    struct ListBackpack *forth = NewListBackpack(1, "black", 11, "Poland", 2);
    first->prev = NULL;
    first->next = second;
    second->prev = first;
    second->next = third;
    third->prev = second;
    third->next = forth;
    forth->prev = third;
    forth->next = NULL;
    expected->head = first;
    expected->tail = forth;

    struct ListBackpack *backpack = list->head;
    struct ListBackpack *expected1 = expected->head;
    for (; backpack != NULL && expected != NULL; backpack = backpack->next, expected1 = expected1->next) {
        if (backpack->laptop_department == expected1->laptop_department && expected1->volume == backpack->volume &&
            expected1->enumPurpose == backpack->enumPurpose && strcmp(backpack->color, expected1->color) == 0 &&
            strcmp(expected1->country, backpack->country) == 0) {
            result &= true;
        } else {
            result &= false;
        }
    }
    return result;
}

/**
 * Верифікація роботи функції {@link DeleteElement}
 * на основі набора масивів вхідних та очікуваних даних
 *
 * @return стан проходження тестів: true - тести пройшли успішно, false - частина
 * тестів не пройшла
 */
bool Test_DeleteElement(){
    bool result = true;

    struct List *list = NewList();
    AddElementEnd(list, 1, "red", 33, "China", 0);
    AddElementEnd(list, 0, "blue", 22, "Usa", 1);
    AddElementEnd(list, 1, "black", 11, "Poland", 2);

    DeleteElement(list, 2);

    struct List *expected = NewList();
    struct ListBackpack *first = NewListBackpack(1, "red", 33, "China", 0);
    struct ListBackpack *second = NewListBackpack(0, "blue", 22, "Usa", 1);

    first->prev = NULL;
    first->next = second;
    second->prev = first;
    second->next = NULL;
    expected->head = first;
    expected->tail = second;

    struct ListBackpack *backpack = list->head;
    struct ListBackpack *expected1 = expected->head;
    for (; backpack != NULL && expected != NULL; backpack = backpack->next, expected1 = expected1->next) {
        if (backpack->laptop_department == expected1->laptop_department && expected1->volume == backpack->volume &&
            expected1->enumPurpose == backpack->enumPurpose && strcmp(backpack->color, expected1->color) == 0 &&
            strcmp(expected1->country, backpack->country) == 0) {
            result &= true;
        } else {
            result &= false;
        }
    }

    return result;
}

/**
 * Верифікація роботи функції {@link SortListByCriterion}
 * на основі набора масивів вхідних та очікуваних даних
 *
 * @return стан проходження тестів: true - тести пройшли успішно, false - частина
 * тестів не пройшла
 */
bool Test_SortListByCriterion(){
    bool result = true;

    struct List *list = NewList();
    AddElementEnd(list, 1, "red", 33, "China", 0);
    AddElementEnd(list, 0, "green", 44, "Ukraine", 0);
    AddElementEnd(list, 0, "blue", 22, "Usa", 1);
    AddElementEnd(list, 1, "black", 11, "Poland", 2);

    SortListByCriterion(list, compareVolume );

    struct List *expected1 = NewList();
    struct ListBackpack *first1 = NewListBackpack(1, "black", 11, "Poland", 2);
    struct ListBackpack *second1 = NewListBackpack(0, "blue", 22, "Usa", 1);
    struct ListBackpack *third1 = NewListBackpack(1, "red", 33, "China", 0);
    struct ListBackpack *forth1 = NewListBackpack(0, "green", 44, "Ukraine", 0);
    first1->prev = NULL;
    first1->next = second1;
    second1->prev = first1;
    second1->next = third1;
    third1->prev = second1;
    third1->next = forth1;
    forth1->prev = third1;
    forth1->next = NULL;
    expected1->head = first1;
    expected1->tail = forth1;

    struct ListBackpack *backpack = list->head;
    struct ListBackpack *expectedL = expected1->head;
    for (; backpack != NULL && expected1 != NULL; backpack = backpack->next, expectedL = expectedL->next) {
        if (backpack->laptop_department == expectedL->laptop_department && expectedL->volume == backpack->volume &&
        expectedL->enumPurpose == backpack->enumPurpose && strcmp(backpack->color, expectedL->color) == 0 &&
            strcmp(expectedL->country, backpack->country) == 0) {
            result &= true;
        } else {
            result &= false;
        }
    }

    SortListByCriterion(list, compareLd);

    struct List *expected2 = NewList();
    struct ListBackpack *first2 = NewListBackpack(0, "green", 44, "Ukraine", 0);
    struct ListBackpack *second2 = NewListBackpack(0, "blue", 22, "Usa", 1);
    struct ListBackpack *third2 = NewListBackpack(1, "black", 11, "Poland", 2);
    struct ListBackpack *forth2 = NewListBackpack(1, "red", 33, "China", 0);
    first2->prev = NULL;
    first2->next = second2;
    second2->prev = first2;
    second2->next = third2;
    third2->prev = second2;
    third2->next = forth2;
    forth2->prev = third2;
    forth2->next = NULL;
    expected2->head = first2;
    expected2->tail = forth2;

    backpack = list->head;
    expectedL = expected2->head;
    for (; backpack != NULL && expected2 != NULL; backpack = backpack->next, expectedL = expectedL->next) {
        if (backpack->laptop_department == expectedL->laptop_department && expectedL->volume == backpack->volume &&
            expectedL->enumPurpose == backpack->enumPurpose && strcmp(backpack->color, expectedL->color) == 0 &&
            strcmp(expectedL->country, backpack->country) == 0) {
            result &= true;
        } else {
            result &= false;
        }
    }

    SortListByCriterion(list, compareColor);

    struct List *expected3 = NewList();
    struct ListBackpack *first3 = NewListBackpack(1, "black", 11, "Poland", 2);
    struct ListBackpack *second3 = NewListBackpack(0, "blue", 22, "Usa", 1);
    struct ListBackpack *third3 = NewListBackpack(0, "green", 44, "Ukraine", 0);
    struct ListBackpack *forth3 = NewListBackpack(1, "red", 33, "China", 0);
    first3->prev = NULL;
    first3->next = second3;
    second3->prev = first3;
    second3->next = third3;
    third3->prev = second3;
    third3->next = forth3;
    forth3->prev = third3;
    forth3->next = NULL;
    expected3->head = first3;
    expected3->tail = forth3;

    backpack = list->head;
    expectedL = expected3->head;
    for (; backpack != NULL && expected3 != NULL; backpack = backpack->next, expectedL = expectedL->next) {
        if (backpack->laptop_department == expectedL->laptop_department && expectedL->volume == backpack->volume &&
            expectedL->enumPurpose == backpack->enumPurpose && strcmp(backpack->color, expectedL->color) == 0 &&
            strcmp(expectedL->country, backpack->country) == 0) {
            result &= true;
        } else {
            result &= false;
        }
    }

    SortListByCriterion(list, compareCountry);

    struct List *expected4 = NewList();
    struct ListBackpack *first4 = NewListBackpack(1, "red", 33, "China", 0);
    struct ListBackpack *second4 = NewListBackpack(1, "black", 11, "Poland", 2);
    struct ListBackpack *third4 = NewListBackpack(0, "green", 44, "Ukraine", 0);
    struct ListBackpack *forth4 = NewListBackpack(0, "blue", 22, "Usa", 1);
    first4->prev = NULL;
    first4->next = second4;
    second4->prev = first4;
    second4->next = third4;
    third4->prev = second4;
    third4->next = forth4;
    forth4->prev = third4;
    forth4->next = NULL;
    expected4->head = first4;
    expected4->tail = forth4;

    backpack = list->head;
    expectedL = expected4->head;
    for (; backpack != NULL && expected4 != NULL; backpack = backpack->next, expectedL = expectedL->next) {
        if (backpack->laptop_department == expectedL->laptop_department && expectedL->volume == backpack->volume &&
            expectedL->enumPurpose == backpack->enumPurpose && strcmp(backpack->color, expectedL->color) == 0 &&
            strcmp(expectedL->country, backpack->country) == 0) {
            result &= true;
        } else {
            result &= false;
        }
    }

    SortListByCriterion(list, comparePurpose);

    struct List *expected5 = NewList();
    struct ListBackpack *first5 = NewListBackpack(1, "red", 33, "China", 0);
    struct ListBackpack *second5 = NewListBackpack(0, "green", 44, "Ukraine", 0);
    struct ListBackpack *third5 = NewListBackpack(0, "blue", 22, "Usa", 1);
    struct ListBackpack *forth5 = NewListBackpack(1, "black", 11, "Poland", 2);
    first5->prev = NULL;
    first5->next = second5;
    second5->prev = first5;
    second5->next = third5;
    third5->prev = second5;
    third5->next = forth5;
    forth5->prev = third5;
    forth5->next = NULL;
    expected5->head = first5;
    expected5->tail = forth5;

    backpack = list->head;
    expectedL = expected5->head;
    for (; backpack != NULL && expected5 != NULL; backpack = backpack->next, expectedL = expectedL->next) {
        if (backpack->laptop_department == expectedL->laptop_department && expectedL->volume == backpack->volume &&
            expectedL->enumPurpose == backpack->enumPurpose && strcmp(backpack->color, expectedL->color) == 0 &&
            strcmp(expectedL->country, backpack->country) == 0) {
            result &= true;
        } else {
            result &= false;
        }
    }

    return result;
}

///**
// * Верифікація роботи функції {@link SortByCriterion}
// * на основі набора масивів вхідних та очікуваних даних
// *
// * @return стан проходження тестів: true - тести пройшли успішно, false - частина
// * тестів не пройшла
// */
//    bool Test_SortByCriterion(){
//    struct Backpack ** backpacks = malloc(3 * sizeof (struct Backpack));
//    for(int i = 0; i < 3; i++){
//        *(backpacks + i) = malloc(sizeof (struct Backpack));
//    }
//    (*(backpacks + 0))->laptop_department = 1;
//    strcpy((*(backpacks + 0))->color, "green");
//    (*(backpacks + 0))->volume = 10;
//    stpcpy((*(backpacks + 0))->country, "Ukraine");
//    (*(backpacks + 0))->enumPurpose = TOURIST;
//
//    (*(backpacks + 1))->laptop_department = 0;
//    strcpy((*(backpacks + 1))->color, "blue");
//    (*(backpacks + 1))->volume = 30;
//    stpcpy((*(backpacks + 1))->country, "German");
//    (*(backpacks + 1))->enumPurpose = URBAN;
//
//    (*(backpacks + 2))->laptop_department = 1;
//    strcpy((*(backpacks + 2))->color, "red");
//    (*(backpacks + 2))->volume = 20;
//    stpcpy((*(backpacks + 2))->country, "England");
//    (*(backpacks + 2))->enumPurpose = TACTICAL;
//
//    struct Backpack ** expectedLD = malloc(3 * sizeof (struct Backpack));
//    for(int i = 0; i < 3; i++){
//        *(expectedLD + i) = malloc(sizeof (struct Backpack));
//    }
//
//    (*(expectedLD + 0))->laptop_department = 0;
//    strcpy((*(expectedLD + 0))->color, "blue");
//    (*(expectedLD + 0))->volume = 30;
//    stpcpy((*(expectedLD + 0))->country, "German");
//    (*(expectedLD + 0))->enumPurpose = URBAN;
//
//    (*(expectedLD + 1))->laptop_department = 1;
//    strcpy((*(expectedLD + 1))->color, "green");
//    (*(expectedLD + 1))->volume = 10;
//    stpcpy((*(expectedLD + 1))->country, "Ukraine");
//    (*(expectedLD + 1))->enumPurpose = TOURIST;
//
//    (*(expectedLD + 2))->laptop_department = 1;
//    strcpy((*(expectedLD + 2))->color, "red");
//    (*(expectedLD + 2))->volume = 20;
//    stpcpy((*(expectedLD + 2))->country, "England");
//    (*(expectedLD + 2))->enumPurpose = TACTICAL;
//
//    struct Backpack ** expected_color = malloc(3 * sizeof (struct Backpack));
//    for(int i = 0; i < 3; i++){
//        *(expected_color + i) = malloc(sizeof (struct Backpack));
//    }
//    (*(expected_color +  0))->laptop_department = 0;
//    strcpy((*(expected_color + 0))->color, "blue");
//    (*(expected_color + 0))->volume = 30;
//    stpcpy((*(expected_color + 0))->country, "German");
//    (*(expected_color + 0))->enumPurpose = URBAN;
//
//    (*(expected_color + 1))->laptop_department = 1;
//    strcpy((*(expected_color + 1))->color, "green");
//    (*(expected_color + 1))->volume = 10;
//    stpcpy((*(expected_color + 1))->country, "Ukraine");
//    (*(expected_color + 1))->enumPurpose = TOURIST;
//
//    (*(expected_color + 2))->laptop_department = 1;
//    strcpy((*(expected_color + 2))->color, "red");
//    (*(expected_color + 2))->volume = 20;
//    stpcpy((*(expected_color + 2))->country, "England");
//    (*(expected_color + 2))->enumPurpose = TACTICAL;
//
//    struct Backpack ** expected_volume = malloc(3 * sizeof (struct Backpack));
//    for(int i = 0; i < 3; i++){
//        *(expected_volume + i) = malloc(sizeof (struct Backpack));
//    }
//    (*(expected_volume + 0))->laptop_department = 1;
//    strcpy((*(expected_volume + 0))->color, "green");
//    (*(expected_volume + 0))->volume = 10;
//    stpcpy((*(expected_volume + 0))->country, "Ukraine");
//    (*(expected_volume + 0))->enumPurpose = TOURIST;
//
//    (*(expected_volume + 1))->laptop_department = 1;
//    strcpy((*(expected_volume + 1))->color, "red");
//    (*(expected_volume + 1))->volume = 20;
//    stpcpy((*(expected_volume + 1))->country, "England");
//    (*(expected_volume + 1))->enumPurpose = TACTICAL;
//
//    (*(expected_volume + 2))->laptop_department = 0;
//    strcpy((*(expected_volume + 2))->color, "blue");
//    (*(expected_volume + 2))->volume = 30;
//    stpcpy((*(expected_volume + 2))->country, "German");
//    (*(expected_volume + 2))->enumPurpose = URBAN;
//
//    struct Backpack ** expected_country = malloc(3 * sizeof (struct Backpack));
//    for(int i = 0; i < 3; i++){
//        *(expected_country + i) = malloc(sizeof (struct Backpack));
//    }
//    (*(expected_country + 0))->laptop_department = 1;
//    strcpy((*(expected_country + 0))->color, "red");
//    (*(expected_country + 0))->volume = 20;
//    stpcpy((*(expected_country + 0))->country, "England");
//    (*(expected_country + 0))->enumPurpose = TACTICAL;
//
//    (*(expected_country + 1))->laptop_department = 0;
//    strcpy((*(expected_country + 1))->color, "blue");
//    (*(expected_country + 1))->volume = 30;
//    stpcpy((*(expected_country + 1))->country, "German");
//    (*(expected_country + 1))->enumPurpose = URBAN;
//
//    (*(expected_country + 2))->laptop_department = 1;
//    strcpy((*(expected_country + 2))->color, "green");
//    (*(expected_country + 2))->volume = 10;
//    stpcpy((*(expected_country + 2))->country, "Ukraine");
//    (*(expected_country + 2))->enumPurpose = TOURIST;
//
//    struct Backpack ** expected_purpose = malloc(3 * sizeof (struct Backpack));
//    for(int i = 0; i < 3; i++){
//        *(expected_purpose + i) = malloc(sizeof (struct Backpack));
//    }
//    (*(expected_purpose + 0))->laptop_department = 0;
//    strcpy((*(expected_purpose + 0))->color, "blue");
//    (*(expected_purpose + 0))->volume = 30;
//    stpcpy((*(expected_purpose + 0))->country, "German");
//    (*(expected_purpose + 0))->enumPurpose = URBAN;
//
//    (*(expected_purpose + 1))->laptop_department = 1;
//    strcpy((*(expected_purpose + 1))->color, "red");
//    (*(expected_purpose + 1))->volume = 20;
//    stpcpy((*(expected_purpose + 1))->country, "England");
//    (*(expected_purpose + 1))->enumPurpose = TACTICAL;
//
//    (*(expected_purpose + 2))->laptop_department = 1;
//    strcpy((*(expected_purpose + 2))->color, "green");
//    (*(expected_purpose + 2))->volume = 10;
//    stpcpy((*(expected_purpose + 2))->country, "Ukraine");
//    (*(expected_purpose + 2))->enumPurpose = TOURIST;
//
//    char laptop_department[18] = "laptop_department";
//    char color[18] = "color";
//    char volume[18] = "volume";
//    char country[18] = "country";
//    char enumPurpose[18] = "purpose";
//
//    bool result = true;
//
//
//    SortByCriterion(backpacks, laptop_department, 3);
//    for(int i = 0; i < 3; i++){
//        if((*(backpacks + i))->laptop_department == ((*(expectedLD + i))->laptop_department)){
//            result &= true;
//        }else{
//            result &= false;
//        }
//    }
//
//    SortByCriterion(backpacks, color, 3);
//    for(int i = 0; i < 3; i++){
//        if(strcmp((*(backpacks + i))->color, (*(expected_color + i))->color) == 0){
//            result &= true;
//        }else{
//            result &= false;
//        }
//    }
//
//    SortByCriterion(backpacks, volume, 3);
//    for(int i = 0; i < 3; i++) {
//        if ((*(backpacks + i))->volume == ((*(expected_volume + i))->volume)) {
//            result &= true;
//        } else {
//            result &= false;
//        }
//    }
//
//    SortByCriterion(backpacks, country, 3);
//    for(int i = 0; i < 3; i++){
//        if(strcmp((*(backpacks + i))->country, (*(expected_country + i))->country) == 0){
//            result &= true;
//        }else{
//            result &= false;
//        }
//    }
//
//    SortByCriterion(backpacks, enumPurpose, 3);
//    for(int i = 0; i < 3; i++){
//        if((*(backpacks + i))->enumPurpose == ((*(expected_purpose + i))->enumPurpose)){
//            result &= true;
//        }else{
//            result &= false;
//        }
//    }
//
//    for (int  i = 0; i < 3; i ++){
//        free(*(backpacks + i));
//    }
//    for (int  i = 0; i < 3; i ++){
//        free(*(expectedLD + i));
//    }
//    for (int  i = 0; i < 3; i ++){
//        free(*(expected_volume + i));
//    }
//    for (int  i = 0; i < 3; i ++){
//        free(*(expected_country + i));
//    }
//    for (int  i = 0; i < 3; i ++){
//        free(*(expected_purpose + i));
//    }
//    for (int  i = 0; i < 3; i ++){
//        free(*(expected_color + i));
//    }
//
//    return result;
//}
//
///**
// * Верифікація роботи функції {@link FindGermanBackpack}
// * на основі набора масивів вхідних та очікуваних даних
// *
// * @return стан проходження тестів: true - тести пройшли успішно, false - частина
// * тестів не пройшла
// */
//bool Test_FindGermanBackpack(){
//    struct Backpack ** backpacks = malloc(3 * sizeof (struct Backpack));
//    for(int i = 0; i < 3; i++){
//        *(backpacks + i) = malloc(sizeof (struct Backpack));
//    }
//    (*(backpacks + 0))->laptop_department = 1;
//    strcpy((*(backpacks + 0))->color, "green");
//    (*(backpacks + 0))->volume = 10;
//    stpcpy((*(backpacks + 0))->country, "Ukraine");
//    (*(backpacks + 0))->enumPurpose = TOURIST;
//
//    (*(backpacks + 1))->laptop_department = 0;
//    strcpy((*(backpacks + 1))->color, "blue");
//    (*(backpacks + 1))->volume = 30;
//    stpcpy((*(backpacks + 1))->country, "Germany");
//    (*(backpacks + 1))->enumPurpose = URBAN;
//
//    (*(backpacks + 2))->laptop_department = 1;
//    strcpy((*(backpacks + 2))->color, "red");
//    (*(backpacks + 2))->volume = 20;
//    stpcpy((*(backpacks + 2))->country, "England");
//    (*(backpacks + 2))->enumPurpose = TACTICAL;
//
//    struct Backpack * expected = malloc(sizeof (struct Backpack));
//
//    expected->laptop_department = 0;
//    strcpy(expected->color, "blue");
//    expected->volume = 30;
//    stpcpy(expected->country, "Germany");
//    expected->enumPurpose = URBAN;
//
//    bool result = true;
//
//    struct Backpack *actual = FindGermanBackpack(backpacks, 3);
//
//    if(strcmp(actual->country, expected->country) == 0){
//        result = true;
//    }else{
//        result = false;
//    }
//
//    for (int  i = 0; i < 3; i ++){
//        free(*(backpacks + i));
//    }
//
//    free(expected);
//
//    return result;
//}

/**
 * Точка входу модуля тестування.
 *
 * Запускає розроблені функції верифікації функцій роботи з списком
 * {@link ListBackpack}.
 *
 * По завершенню тестів виводиться на екран резуміюча інформація про стан
 * проходження тестів.
 *
 * @return стан проходження тестів: true - тести пройшли успішно, false - частина
 * тестів не пройшла
 */
int main(){
    bool result = true;
    printf("\n|------ТЕСТ СОЗДАНИЯ НОВОГО ЭЛЕМЕНТА------|\n\n");
    result &= Test_NewListBackpack();
    if (result == true){
        printf("РЕЗУЛЬТАТ ТЕСТА: Good job so far\n");
    }else{
        printf("D'oh");
    }
    printf("\n|------ТЕСТ ВСТАВКИ НОВОГО ЭЛЕМЕНТА------|\n\n");
    result &= Test_InsertElement();
    if (result == true){
        printf("РЕЗУЛЬТАТ ТЕСТА: Good job so far\n");
    }else{
        printf("D'oh");
    }
    printf("\n|------ТЕСТ УДАЛЕНИЯ ЭЛЕМЕНТА------|\n\n");
    result &= Test_DeleteElement();
    if (result == true){
        printf("РЕЗУЛЬТАТ ТЕСТА: Good job so far\n");
    }else{
        printf("D'oh");
    }
    printf("\n|------ТЕСТ СОРТИРОВКИ ЭЛЕМЕНТОВ------|\n\n");
    result &= Test_SortListByCriterion();
    if (result == true){
        printf("РЕЗУЛЬТАТ ТЕСТА: Good job so far\n");
    }else{
        printf("D'oh");
    }

//    printf("\n|------ТЕСТ СОРТИРОВКИ СТРУКТУРЫ------|\n\n");
//    result &= Test_SortByCriterion();
//    if (result == true){
//        printf("РЕЗУЛЬТАТ ТЕСТА: Good job so far\n");
//    }else{
//        printf("D'oh");
//    }
//    printf("\n|------ТЕСТ ПОИСКА СТРУКТУРЫ------|\n\n");
//    result &= Test_FindGermanBackpack();
//    if (result == true){
//        printf("РЕЗУЛЬТАТ ТЕСТА: Good job so far\n");
//    }else{
//        printf("D'oh");
//    }
    printf("\n|------------------------------------|");
    return 0;
}