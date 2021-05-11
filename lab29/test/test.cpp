//
// Created by Vlad on 20.04.2021.
//

#include "list.hpp"


bool Test_getElement(){
    bool result = true;

    List<int> list;

    int a = 3;
    int b = 5;
    int c = 4;

    list.addElement(&a);
    list.addElement(&b);
    list.addElement(&c);

    int actual = list.getElement(1);


    if (actual == b){
        result &= true;
    } else {
        result &= false;
    }
    return result;
}

bool Test_SortList(){
    bool result = true;

    List<int> list;

    int a = 3;
    int b = 5;
    int c = 4;

    list.addElement(&a);
    list.addElement(&b);
    list.addElement(&c);

    list.SortList();

    List<int> expected;

    int a1 = 3;
    int b1 = 5;
    int c1 = 4;

    expected.addElement(&a1);
    expected.addElement(&c1);
    expected.addElement(&b1);

    for (int i = 0; i < 3; ++i) {
        if (list.getElement(i) == expected.getElement(i)) {
            result &= true;
        } else {
            result &= false;
        }
    }
    return result;
}


bool Test_deleteElement(){
    bool result = true;

    List<int> list;

    int a = 3;
    int b = 5;
    int c = 4;

    list.addElement(&a);
    list.addElement(&b);
    list.addElement(&c);

    list.deleteElement(1);

    List<int> expected;

    expected.addElement(&a);
    expected.addElement(&c);

    for (int i = 0; i < 2; ++i) {
        if (list.getElement(i) == expected.getElement(i)) {
            result &= true;
        } else {
            result &= false;
        }
    }
    return result;
}

bool Test_FindMinElement(){
    bool result = true;

    List<int> list;

    int a = 3;
    int b = 5;
    int c = 4;

    list.addElement(&a);
    list.addElement(&b);
    list.addElement(&c);

    int actual = list.FindMinElement();


    if (actual == a) {
        result &= true;
    } else {
        result &= false;
    }

    return result;
}

bool Test_FindIndexElement(){
    bool result = true;

    List<int> list;

    int a = 3;
    int b = 5;
    int c = 4;

    list.addElement(&a);
    list.addElement(&b);
    list.addElement(&c);

    int actual = list.FindIndexElement(c);

    if (actual == 2) {
        result &= true;
    } else {
        result &= false;
    }
    return result;
}

int main(){
    bool result = true;
    cout << "\n|------ТЕСТ ПОЛУЧЕНИЯ ЭЛЕМЕНТА ПО ИНДЕКСУ-------|\n\n";
    result = Test_getElement();
    if (result){
        cout << endl << "РЕЗУЛЬТАТ ТЕСТА: Good job so far\n";
    }else{
        cout << "D'oh";
    }

    cout << "\n|------ТЕСТ УДАЛЕНИЯ ЭЛЕМЕНТА-------|\n\n";
    result = Test_deleteElement();
    if (result){
        cout << endl << "РЕЗУЛЬТАТ ТЕСТА: Good job so far\n";
    }else{
        cout << "D'oh";
    }

    cout << "\n|------ТЕСТ СОРТИРОВКИ СПИСКА-------|\n\n";
    result = Test_SortList();
    if (result){
        cout << endl << "РЕЗУЛЬТАТ ТЕСТА: Good job so far\n";
    }else{
        cout << "D'oh";
    }

    cout << "\n|------ТЕСТ ПОИСКА ИНДЕКСА ЭЛЕМЕНТА-------|\n\n";
    result = Test_FindIndexElement();
    if (result){
        cout << endl << "РЕЗУЛЬТАТ ТЕСТА: Good job so far\n";
    }else{
        cout << "D'oh";
    }

    cout << "\n|------ТЕСТ ПОИСКА МИНИМАЛЬНОГО ЭЛЕМЕНТА-------|\n\n";
    result = Test_FindMinElement();
    if (result){
        cout << endl << "РЕЗУЛЬТАТ ТЕСТА: Good job so far\n";
    }else{
        cout << "D'oh";
    }

    cout << "\n|------------------------------------------------|";
    return 0;
}