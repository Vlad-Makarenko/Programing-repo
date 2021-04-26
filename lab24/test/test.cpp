//
// Created by Vlad on 20.04.2021.
//

//#include "Backpack.h"
#include "Container.h"

bool Test_toString(){
    bool result = true;


    Backpack backpack1 (false, "Black", 33, Firm("Nike", "USA"), TACTICAL );

    string expected = "0 Black 33 1 Nike USA\n";
    string actual = backpack1.toString();

    if (actual == expected) {
            result &= true;
    }else{
            result &= false;
    }


    return result;
}

bool Test_SplitLineToObject(){
    bool result = true;

    string  obj = "0 Black 33 1 Nike USA";
    Backpack expected (false, "Black", 33, Firm("Nike", "USA"), TACTICAL );
    Backpack actual = actual.SplitLineToObject(obj);

    if (actual.getlaptop_department() == expected.getlaptop_department()
        && actual.getcolor() == expected.getcolor()
        && actual.getvolume() == expected.getvolume()
        && actual.getpurpose() == expected.getpurpose()
        && actual.getfirm().getName() == expected.getfirm().getName()
        && actual.getfirm().getCountry() == expected.getfirm().getCountry()){
        result &= true;
    }else{
        result &= false;
    }

    return result;
}



int main(){
    bool result = true;
    cout << "\n|------ТЕСТ ПРЕОБРАЗОВАНИЕ ОБЪЕКТА В СТРОКУ------|\n\n";
    result &= Test_toString();
    if (result){
        cout << "РЕЗУЛЬТАТ ТЕСТА: Good job so far\n";
    }else{
        cout << "D'oh";
    }cout << "\n|------ТЕСТ ПРЕОБРАЗОВАНИЕ СТРОКИ В ОБЪЕКТ-------|\n\n";
    result &= Test_SplitLineToObject();
    if (result){
        cout << "РЕЗУЛЬТАТ ТЕСТА: Good job so far\n";
    }else{
        cout << "D'oh";
    }
    cout << "\n|------------------------------------------------|";
    return 0;
}