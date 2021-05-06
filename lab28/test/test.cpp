//
// Created by Vlad on 20.04.2021.
//

#include "Task.h"

bool Test_CalcAverage(){
    bool result = true;

    int actual[3];
    int expected[3] = {0, 1, 0};

    Task test;
    test.ForTest(3);

    ifstream fin;
    fin.open("TestResult.txt");
    for (int i = 0; i < 3; ++i) {
        fin >> actual[i];
    }
    remove("TestResult.txt");

    for (int i = 0; i < 3; ++i) {
        if (actual[i] == expected[i])
            result &= true;
        else
            result &= false;
    }

    return result;
}

bool Test_FindMaxElem(){
    bool result = true;

    int actual[3];
    int expected[3] = {3, 3, 2};

    Task test;
    test.ForTest(4);

    ifstream fin;
    fin.open("TestResult.txt");
    for (int i = 0; i < 3; ++i) {
        fin >> actual[i];
    }
    remove("TestResult.txt");

    for (int i = 0; i < 3; ++i) {
        if (actual[i] == expected[i])
            result &= true;
        else
            result &= false;
    }

    return result;
}

bool Test_FindMinElem(){
    bool result = true;

    int actual[3];
    int expected[3] = {-2, -1, -3};

    Task test;
    test.ForTest(5);

    ifstream fin;
    fin.open("TestResult.txt");
    for (int i = 0; i < 3; ++i) {
        fin >> actual[i];
    }
    remove("TestResult.txt");

    for (int i = 0; i < 3; ++i) {
        if (actual[i] == expected[i])
            result &= true;
        else
            result &= false;
    }

    return result;
}

bool Test_FindPositiveNumber(){
    bool result = true;

    int actual[3];
    int expected[3] = {2, 2, 2};

    Task test;
    test.ForTest(6);

    ifstream fin;
    fin.open("TestResult.txt");
    for (int i = 0; i < 3; ++i) {
        fin >> actual[i];
    }
    remove("TestResult.txt");

    for (int i = 0; i < 3; ++i) {
        if (actual[i] == expected[i])
            result &= true;
        else
            result &= false;
    }

    return result;
}

bool Test_FindNegativeNumber(){
    bool result = true;

    int actual[3];
    int expected[3] = {1, 1, 1};

    Task test;
    test.ForTest(8);

    ifstream fin;
    fin.open("TestResult.txt");
    for (int i = 0; i < 3; ++i) {
        fin >> actual[i];
    }
    remove("TestResult.txt");

    for (int i = 0; i < 3; ++i) {
        if (actual[i] == expected[i])
            result &= true;
        else
            result &= false;
    }

    return result;
}

bool Test_FindMaxElemPos(){
    bool result = true;

    int actual[3];
    int expected[3] = {2, 1, 2};

    Task test;
    test.ForTest(9);

    ifstream fin;
    fin.open("TestResult.txt");
    for (int i = 0; i < 3; ++i) {
        fin >> actual[i];
    }
    remove("TestResult.txt");

    for (int i = 0; i < 3; ++i) {
        if (actual[i] == expected[i])
            result &= true;
        else
            result &= false;
    }

    return result;
}

bool Test_FindCountMaxElem(){
    bool result = true;

    int actual[3];
    int expected[3] = {1, 1, 1};

    Task test;
    test.ForTest(10);

    ifstream fin;
    fin.open("TestResult.txt");
    for (int i = 0; i < 3; ++i) {
        fin >> actual[i];
    }
    remove("TestResult.txt");

    for (int i = 0; i < 3; ++i) {
        if (actual[i] == expected[i])
            result &= true;
        else
            result &= false;
    }

    return result;
}

int main(){
    bool result = true;

    cout << "\n|------ТЕСТ МЕТОДА ПОИСКА СРЕДНЕГО ЗНАЧЕНИЯ МАСИВОВ-------|\n\n";
    result = Test_CalcAverage();
    if (result){
        cout << endl << "РЕЗУЛЬТАТ ТЕСТА: Good job so far\n";
    }else{
        cout << "D'oh";
    }

    cout << "\n|------ТЕСТ МЕТОДА ПОИСКА МАКСИМАЛЬНЫХ ЗНАЧЕНИЙ МАССИВА-------|\n\n";
    result = Test_FindMaxElem();
    if (result){
        cout << endl << "РЕЗУЛЬТАТ ТЕСТА: Good job so far\n";
    }else{
        cout << "D'oh";
    }

    cout << "\n|------ТЕСТ МЕТОДА ПОИСКА МИНИМАЛЬНЫХ ЗНАЧЕНИЙ МАССИВА-------|\n\n";
    result = Test_FindMinElem();
    if (result){
        cout << endl << "РЕЗУЛЬТАТ ТЕСТА: Good job so far\n";
    }else {
        cout << "D'oh";
    }

    cout << "\n|------ТЕСТ МЕТОДА ПОИСКА ПОЗИТИВНИХ ЗНАЧЕНИЙ МАССИВА-------|\n\n";
    result = Test_FindPositiveNumber();
    if (result){
        cout << endl << "РЕЗУЛЬТАТ ТЕСТА: Good job so far\n";
    }else {
        cout << "D'oh";
    }

    cout << "\n|------ТЕСТ МЕТОДА ПОИСКА НЕГАТИВНЫХ ЗНАЧЕНИЙ МАССИВА-------|\n\n";
    result = Test_FindNegativeNumber();
    if (result){
        cout << endl << "РЕЗУЛЬТАТ ТЕСТА: Good job so far\n";
    }else {
        cout << "D'oh";
    }

    cout << "\n|------ТЕСТ МЕТОДА ПОИСКА ПОЗИЦИИ МАКСИМАЛЬНОГО ЗНАЧЕНИЯ МАССИВА-------|\n\n";
    result = Test_FindMaxElemPos();
    if (result){
        cout << endl << "РЕЗУЛЬТАТ ТЕСТА: Good job so far\n";
    }else {
        cout << "D'oh";
    }

    cout << "\n|------ТЕСТ МЕТОДА ПОИСКА КОЛИЧЕСТВА ЭЛЕМЕНТОВ С МАКСИМАЛЬНЫМ ЗНАЧЕНИЕМ МАССИВА-------|\n\n";
    result = Test_FindCountMaxElem();
    if (result){
        cout << endl << "РЕЗУЛЬТАТ ТЕСТА: Good job so far\n";
    }else {
        cout << "D'oh";
    }

    cout << "\n|------------------------------------------------|";
    return 0;
}