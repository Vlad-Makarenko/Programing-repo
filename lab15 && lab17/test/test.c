//
// Created by Vlad on 22.03.2021.
//

/**
 * @file test.c
 * @brief Файл з тестами на реалізації функцій сортування масиву структур та знаходження об`єкту
 *
 * @author Makarenko V.
 * @date 22-march-2021
 * @version 1.0
 */

#include "../src/lib.h"

/**
 * Верифікація роботи функції {@link SortByCriterion}
 * на основі набора масивів вхідних та очікуваних даних
 *
 * @return стан проходження тестів: true - тести пройшли успішно, false - частина
 * тестів не пройшла
 */
bool Test_SortByCriterion(){
    struct Backpack ** backpacks = malloc(3 * sizeof (struct Backpack));
    for(int i = 0; i < 3; i++){
        *(backpacks + i) = malloc(sizeof (struct Backpack));
    }
    (*(backpacks + 0))->laptop_department = 1;
    strcpy((*(backpacks + 0))->color, "green");
    (*(backpacks + 0))->volume = 10;
    stpcpy((*(backpacks + 0))->country, "Ukraine");
    (*(backpacks + 0))->enumPurpose = TOURIST;

    (*(backpacks + 1))->laptop_department = 0;
    strcpy((*(backpacks + 1))->color, "blue");
    (*(backpacks + 1))->volume = 30;
    stpcpy((*(backpacks + 1))->country, "German");
    (*(backpacks + 1))->enumPurpose = URBAN;

    (*(backpacks + 2))->laptop_department = 1;
    strcpy((*(backpacks + 2))->color, "red");
    (*(backpacks + 2))->volume = 20;
    stpcpy((*(backpacks + 2))->country, "England");
    (*(backpacks + 2))->enumPurpose = TACTICAL;

    struct Backpack ** expectedLD = malloc(3 * sizeof (struct Backpack));
    for(int i = 0; i < 3; i++){
        *(expectedLD + i) = malloc(sizeof (struct Backpack));
    }

    (*(expectedLD + 0))->laptop_department = 0;
    strcpy((*(expectedLD + 0))->color, "blue");
    (*(expectedLD + 0))->volume = 30;
    stpcpy((*(expectedLD + 0))->country, "German");
    (*(expectedLD + 0))->enumPurpose = URBAN;

    (*(expectedLD + 1))->laptop_department = 1;
    strcpy((*(expectedLD + 1))->color, "green");
    (*(expectedLD + 1))->volume = 10;
    stpcpy((*(expectedLD + 1))->country, "Ukraine");
    (*(expectedLD + 1))->enumPurpose = TOURIST;

    (*(expectedLD + 2))->laptop_department = 1;
    strcpy((*(expectedLD + 2))->color, "red");
    (*(expectedLD + 2))->volume = 20;
    stpcpy((*(expectedLD + 2))->country, "England");
    (*(expectedLD + 2))->enumPurpose = TACTICAL;

    struct Backpack ** expected_color = malloc(3 * sizeof (struct Backpack));
    for(int i = 0; i < 3; i++){
        *(expected_color + i) = malloc(sizeof (struct Backpack));
    }
    (*(expected_color +  0))->laptop_department = 0;
    strcpy((*(expected_color + 0))->color, "blue");
    (*(expected_color + 0))->volume = 30;
    stpcpy((*(expected_color + 0))->country, "German");
    (*(expected_color + 0))->enumPurpose = URBAN;

    (*(expected_color + 1))->laptop_department = 1;
    strcpy((*(expected_color + 1))->color, "green");
    (*(expected_color + 1))->volume = 10;
    stpcpy((*(expected_color + 1))->country, "Ukraine");
    (*(expected_color + 1))->enumPurpose = TOURIST;

    (*(expected_color + 2))->laptop_department = 1;
    strcpy((*(expected_color + 2))->color, "red");
    (*(expected_color + 2))->volume = 20;
    stpcpy((*(expected_color + 2))->country, "England");
    (*(expected_color + 2))->enumPurpose = TACTICAL;

    struct Backpack ** expected_volume = malloc(3 * sizeof (struct Backpack));
    for(int i = 0; i < 3; i++){
        *(expected_volume + i) = malloc(sizeof (struct Backpack));
    }
    (*(expected_volume + 0))->laptop_department = 1;
    strcpy((*(expected_volume + 0))->color, "green");
    (*(expected_volume + 0))->volume = 10;
    stpcpy((*(expected_volume + 0))->country, "Ukraine");
    (*(expected_volume + 0))->enumPurpose = TOURIST;

    (*(expected_volume + 1))->laptop_department = 1;
    strcpy((*(expected_volume + 1))->color, "red");
    (*(expected_volume + 1))->volume = 20;
    stpcpy((*(expected_volume + 1))->country, "England");
    (*(expected_volume + 1))->enumPurpose = TACTICAL;

    (*(expected_volume + 2))->laptop_department = 0;
    strcpy((*(expected_volume + 2))->color, "blue");
    (*(expected_volume + 2))->volume = 30;
    stpcpy((*(expected_volume + 2))->country, "German");
    (*(expected_volume + 2))->enumPurpose = URBAN;

    struct Backpack ** expected_country = malloc(3 * sizeof (struct Backpack));
    for(int i = 0; i < 3; i++){
        *(expected_country + i) = malloc(sizeof (struct Backpack));
    }
    (*(expected_country + 0))->laptop_department = 1;
    strcpy((*(expected_country + 0))->color, "red");
    (*(expected_country + 0))->volume = 20;
    stpcpy((*(expected_country + 0))->country, "England");
    (*(expected_country + 0))->enumPurpose = TACTICAL;

    (*(expected_country + 1))->laptop_department = 0;
    strcpy((*(expected_country + 1))->color, "blue");
    (*(expected_country + 1))->volume = 30;
    stpcpy((*(expected_country + 1))->country, "German");
    (*(expected_country + 1))->enumPurpose = URBAN;

    (*(expected_country + 2))->laptop_department = 1;
    strcpy((*(expected_country + 2))->color, "green");
    (*(expected_country + 2))->volume = 10;
    stpcpy((*(expected_country + 2))->country, "Ukraine");
    (*(expected_country + 2))->enumPurpose = TOURIST;

    struct Backpack ** expected_purpose = malloc(3 * sizeof (struct Backpack));
    for(int i = 0; i < 3; i++){
        *(expected_purpose + i) = malloc(sizeof (struct Backpack));
    }
    (*(expected_purpose + 0))->laptop_department = 0;
    strcpy((*(expected_purpose + 0))->color, "blue");
    (*(expected_purpose + 0))->volume = 30;
    stpcpy((*(expected_purpose + 0))->country, "German");
    (*(expected_purpose + 0))->enumPurpose = URBAN;

    (*(expected_purpose + 1))->laptop_department = 1;
    strcpy((*(expected_purpose + 1))->color, "red");
    (*(expected_purpose + 1))->volume = 20;
    stpcpy((*(expected_purpose + 1))->country, "England");
    (*(expected_purpose + 1))->enumPurpose = TACTICAL;

    (*(expected_purpose + 2))->laptop_department = 1;
    strcpy((*(expected_purpose + 2))->color, "green");
    (*(expected_purpose + 2))->volume = 10;
    stpcpy((*(expected_purpose + 2))->country, "Ukraine");
    (*(expected_purpose + 2))->enumPurpose = TOURIST;

    char laptop_department[18] = "laptop_department";
    char color[18] = "color";
    char volume[18] = "volume";
    char country[18] = "country";
    char enumPurpose[18] = "purpose";

    bool result = true;


    SortByCriterion(backpacks, laptop_department, 3);
    for(int i = 0; i < 3; i++){
        if((*(backpacks + i))->laptop_department == ((*(expectedLD + i))->laptop_department)){
            result &= true;
        }else{
            result &= false;
        }
    }

    SortByCriterion(backpacks, color, 3);
    for(int i = 0; i < 3; i++){
        if(strcmp((*(backpacks + i))->color, (*(expected_color + i))->color) == 0){
            result &= true;
        }else{
            result &= false;
        }
    }

    SortByCriterion(backpacks, volume, 3);
    for(int i = 0; i < 3; i++) {
        if ((*(backpacks + i))->volume == ((*(expected_volume + i))->volume)) {
            result &= true;
        } else {
            result &= false;
        }
    }

    SortByCriterion(backpacks, country, 3);
    for(int i = 0; i < 3; i++){
        if(strcmp((*(backpacks + i))->country, (*(expected_country + i))->country) == 0){
            result &= true;
        }else{
            result &= false;
        }
    }

    SortByCriterion(backpacks, enumPurpose, 3);
    for(int i = 0; i < 3; i++){
        if((*(backpacks + i))->enumPurpose == ((*(expected_purpose + i))->enumPurpose)){
            result &= true;
        }else{
            result &= false;
        }
    }

    for (int  i = 0; i < 3; i ++){
        free(*(backpacks + i));
    }
    for (int  i = 0; i < 3; i ++){
        free(*(expectedLD + i));
    }
    for (int  i = 0; i < 3; i ++){
        free(*(expected_volume + i));
    }
    for (int  i = 0; i < 3; i ++){
        free(*(expected_country + i));
    }
    for (int  i = 0; i < 3; i ++){
        free(*(expected_purpose + i));
    }
    for (int  i = 0; i < 3; i ++){
        free(*(expected_color + i));
    }

    return result;
}

/**
 * Верифікація роботи функції {@link FindGermanBackpack}
 * на основі набора масивів вхідних та очікуваних даних
 *
 * @return стан проходження тестів: true - тести пройшли успішно, false - частина
 * тестів не пройшла
 */
bool Test_FindGermanBackpack(){
    struct Backpack ** backpacks = malloc(3 * sizeof (struct Backpack));
    for(int i = 0; i < 3; i++){
        *(backpacks + i) = malloc(sizeof (struct Backpack));
    }
    (*(backpacks + 0))->laptop_department = 1;
    strcpy((*(backpacks + 0))->color, "green");
    (*(backpacks + 0))->volume = 10;
    stpcpy((*(backpacks + 0))->country, "Ukraine");
    (*(backpacks + 0))->enumPurpose = TOURIST;

    (*(backpacks + 1))->laptop_department = 0;
    strcpy((*(backpacks + 1))->color, "blue");
    (*(backpacks + 1))->volume = 30;
    stpcpy((*(backpacks + 1))->country, "Germany");
    (*(backpacks + 1))->enumPurpose = URBAN;

    (*(backpacks + 2))->laptop_department = 1;
    strcpy((*(backpacks + 2))->color, "red");
    (*(backpacks + 2))->volume = 20;
    stpcpy((*(backpacks + 2))->country, "England");
    (*(backpacks + 2))->enumPurpose = TACTICAL;

    struct Backpack * expected = malloc(sizeof (struct Backpack));

    expected->laptop_department = 0;
    strcpy(expected->color, "blue");
    expected->volume = 30;
    stpcpy(expected->country, "Germany");
    expected->enumPurpose = URBAN;

    bool result = true;

    struct Backpack *actual = FindGermanBackpack(backpacks, 3);

    if(strcmp(actual->country, expected->country) == 0){
        result = true;
    }else{
        result = false;
    }

    for (int  i = 0; i < 3; i ++){
        free(*(backpacks + i));
    }

    free(expected);

    return result;
}

/**
 * Точка входу модуля тестування.
 *
 * Запускає розроблені функції верифікації функцій роботи з структурой
 * {@link Backpack}.
 *
 * По завершенню тестів виводиться на екран резуміюча інформація про стан
 * проходження тестів.
 *
 * @return стан проходження тестів: true - тести пройшли успішно, false - частина
 * тестів не пройшла
 */
int main()
{
    bool test = true;
    test &= Test_SortByCriterion();
    test &= Test_FindGermanBackpack();
    if (test){
        printf("All tests completed successfully");
    }else{
        printf("Some of the tests failed");
    }
    return test;
}