//
// Created by Vlad on 20.04.2021.
//

//#include "Backpack.h"
#include "Container.h"

bool Test_removeBackpack(){
    bool result = true;
    List * list1 = new List;
    List * expected = new List;
    list1->setCount(0);
    expected->setCount(0);

    Backpack backpack1 (false, "Black", 33, Firm("Nike", "UK"), TACTICAL );
    Backpack backpack2 (true, "Blue", 44, Firm("Puma", "USA"), TOURIST );
    Backpack backpack3 (true, "Yellow", 55, Firm("Adidas", "Germany"), URBAN);

    Backpack backpack4 (false, "Black", 33, Firm("Nike", "UK"), TACTICAL );
    Backpack backpack5 (true, "Yellow", 55, Firm("Adidas", "Germany"), URBAN);

    list1->addBackpack(backpack1);
    list1->addBackpack(backpack2);
    list1->addBackpack(backpack3);

    expected->addBackpack(backpack4);
    expected->addBackpack(backpack5);

    list1->removeBackpack(1);

    for (int i = 0; i < 2; ++i) {
        Backpack temp = list1->getBackpack(i);
        Backpack temp1 = expected->getBackpack(i);
        if (temp.getlaptop_department() == temp1.getlaptop_department()
            && list1->getBackpack(i).getcolor() == expected->getBackpack(i).getcolor()
            && list1->getBackpack(i).getfirm().getCountry() == expected->getBackpack(i).getfirm().getCountry()
            && list1->getBackpack(i).getfirm().getName() == expected->getBackpack(i).getfirm().getName()
            && list1->getBackpack(i).getpurpose() == expected->getBackpack(i).getpurpose()
            && list1->getBackpack(i).getvolume() == expected->getBackpack(i).getvolume()) {
            result &= true;
        }else{
            result &= false;
        }
    }

    //delete list;
    //delete expected;
    return result;
}

bool Test_getBackpack(){
    bool result = true;
    List * list = new List;
    list->setCount(0);

    Backpack backpack1 (false, "Black", 33, Firm("Nike", "UK"), TACTICAL );
    Backpack backpack2 (true, "Blue", 44, Firm("Puma", "USA"), TOURIST );
    Backpack backpack3 (true, "Yellow", 55, Firm("Adidas", "Germany"), URBAN);

    list->addBackpack(backpack1);
    list->addBackpack(backpack2);
    list->addBackpack(backpack3);

    Backpack expected = list->getBackpack(2);

    if (list->getBackpack(2).getlaptop_department() == expected.getlaptop_department()
        && list->getBackpack(2).getcolor() == expected.getcolor()
        && list->getBackpack(2).getfirm().getCountry() == expected.getfirm().getCountry()
        && list->getBackpack(2).getfirm().getName() == expected.getfirm().getName()
        && list->getBackpack(2).getpurpose() == expected.getpurpose()
        && list->getBackpack(2).getvolume() == expected.getvolume()){
        result &= true;
    }else{
        result &= false;
    }

    return result;
}

bool Test_FindGermanCityBackpack(){
    bool result = true;
    List * list = new List;
    list->setCount(0);

    Backpack backpack1 (false, "Black", 33, Firm("Nike", "UK"), TACTICAL );
    Backpack backpack2 (true, "Blue", 44, Firm("Puma", "USA"), TOURIST );
    Backpack backpack3 (true, "Yellow", 55, Firm("Adidas", "Germany"), URBAN);
    //cout << "ERROR before";

    //list->ShowAll();

    list->addBackpack(backpack1);
    list->addBackpack(backpack2);
    list->addBackpack(backpack3);

    Backpack expected = list->FindGermanCityBackpack();
    cout << endl;


    if (expected.getpurpose() == URBAN && expected.getfirm().getCountry() == "Germany"){
        result &= true;
    }else{
        result &= false;
    }

    return result;
}

int main(){
    bool result = true;
    //cout << "ERROR before";
    cout << "\n|------ТЕСТ УДАЛЕНИЯ ЭЛЕМЕНТА------|\n\n";
    //cout << "ERROR after";
    result &= Test_removeBackpack();
    if (result){
        cout << "РЕЗУЛЬТАТ ТЕСТА: Good job so far\n";
    }else{
        cout << "D'oh";
    }
    cout << "\n|------ТЕСТ ПОЛУЧЕНИЯ ЭЛЕМЕНТА ПО ИНДЕКСУ------|\n\n";
    result &= Test_getBackpack();
    if (result){
        cout << "РЕЗУЛЬТАТ ТЕСТА: Good job so far\n";
    }else{
        cout << "D'oh";
    }
    cout << "\n|------ТЕСТ ПОИСКА ЭЛЕМЕНТА------|\n\n";
    result &= Test_FindGermanCityBackpack();
    if (result){
        cout << "РЕЗУЛЬТАТ ТЕСТА: Good job so far\n";
    }else{
        cout << "D'oh";
    }
    cout << "\n|------------------------------------|";
    return 0;
}