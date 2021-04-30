//
// Created by Vlad on 20.04.2021.
//

//#include "Backpack.h"
#include "Container.h"

bool Test_comparison_operator(){
    bool result = true;

    Backpack backpack1 (false, "Black", 33, Firm("Nike", "USA"), TACTICAL );
    Backpack backpack2 (false, "Black", 33, Firm("Nike", "USA"), TACTICAL );

    if (backpack2 == backpack1) {
            result &= true;
    }else{
            result &= false;
    }


    return result;
}

bool Test_operator_equals(){
    bool result = true;

    Backpack backpack1 (false, "Black", 33, Firm("Nike", "USA"), TACTICAL );
    Backpack backpack2 = backpack1;

    if (backpack2 == backpack1) {
        result &= true;
    }else{
        result &= false;
    }

    return result;
}

bool Test_operator_index(){
    bool result = true;

    Backpack backpack1 (false, "Black", 33, Firm("Nike", "USA"), TACTICAL );
    Backpack backpack2 (true, "Blue", 44, Firm("Puma", "Ukraine"), TOURIST );
    Backpack backpack3 (true, "Red", 55, Firm("Adidas", "Germany"), URBAN );
    List list;
    list.setCount(0);
    list.addBackpack(backpack1);
    list.addBackpack(backpack2);
    list.addBackpack(backpack3);

    if (backpack2 == list[1]) {
        result &= true;
    }else{
        result &= false;
    }

    return result;
}

int main(){
    bool result = true;
    cout << "\n|------ТЕСТ ПЕРЕГРУЗКИ ОПЕРАТОРА  =  ------|\n\n";
    result = Test_operator_equals();
    if (result){
        cout << "РЕЗУЛЬТАТ ТЕСТА: Good job so far\n";
    }else{
        cout << "D'oh";
    }
    cout << "\n|------ТЕСТ ПЕРЕГРУЗКИ ОПЕРАТОРА  ==  -------|\n\n";
    result = Test_comparison_operator();
    if (result){
        cout << "РЕЗУЛЬТАТ ТЕСТА: Good job so far\n";
    }else{
        cout << "D'oh";
    }
    cout << "\n|------------------------------------------------|";
    return 0;
}