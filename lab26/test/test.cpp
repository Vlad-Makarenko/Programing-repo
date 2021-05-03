//
// Created by Vlad on 20.04.2021.
//

//#include "Backpack.h"
#include "Container.h"

bool Test_addLeatherBackpack(){
    bool result = true;

    LeatherBackpack leatherBackpack(false, "Black", 33, Firm("Nike", "USA"), URBAN, true, VELOUR);
    LeatherBackpack leatherBackpack1(true, "Blue", 44, Firm("Puma", "USA"), TACTICAL, false, SUEDE);

    auto * leatherBackpackList = new LeatherBackpackList;

    leatherBackpackList->addBackpack(leatherBackpack);
    leatherBackpackList->addBackpack(leatherBackpack1);

    for (int i = 0; i < 2; ++i) {

        if (leatherBackpackList->getLeatherBackpack(i).getlaptop_department() == leatherBackpack.getlaptop_department()
            && leatherBackpackList->getLeatherBackpack(i).getcolor() == leatherBackpack.getcolor()
            && leatherBackpackList->getLeatherBackpack(i).getvolume() == leatherBackpack.getvolume()
            && leatherBackpackList->getLeatherBackpack(i).getpurpose() == leatherBackpack.getpurpose()
            && leatherBackpackList->getLeatherBackpack(i).getfirm().getCountry() == leatherBackpack.getfirm().getCountry()
            && leatherBackpackList->getLeatherBackpack(i).getfirm().getName() == leatherBackpack.getfirm().getName()
            && leatherBackpackList->getLeatherBackpack(i).getlining() == leatherBackpack.getlining()
            && leatherBackpackList->getLeatherBackpack(i).getLeather() == leatherBackpack.getLeather()) {
            result &= true;
        } else {
            result &= false;
        }
    }
    return result;
}

bool Test_FindGermanVelourBackpack(){
    bool result = true;

    LeatherBackpack leatherBackpack(false, "Black", 33, Firm("Nike", "USA"), TOURIST, true, ANILINE);
    LeatherBackpack leatherBackpack1(true, "Red", 44, Firm("Puma", "USA"), TACTICAL, false, SUEDE);
    LeatherBackpack leatherBackpack2(false, "Blue", 24, Firm("Adidas", "Germany"), URBAN, true, VELOUR);
    //leatherBackpack.Print();
    auto * leatherBackpackList = new LeatherBackpackList;

    leatherBackpackList->addBackpack(leatherBackpack);
    leatherBackpackList->addBackpack(leatherBackpack1);
    leatherBackpackList->addBackpack(leatherBackpack2);

    cout <<  "Ожидаемый результат:" << endl;
    PrintForm1();
    cout << endl;
    leatherBackpack2.Print();
    cout << endl;

    cout << endl << "Актуальный результат:" << endl;
    PrintForm1();
    cout << endl;
    LeatherBackpack * actual = &leatherBackpackList->FindGermanVelourBackpack();
    cout << endl;

    if (actual->getlaptop_department() == leatherBackpack2.getlaptop_department()
            && actual->getcolor() == leatherBackpack2.getcolor()
            && actual->getvolume() == leatherBackpack2.getvolume()
            && actual->getpurpose() == leatherBackpack2.getpurpose()
            && actual->getfirm().getCountry() == leatherBackpack2.getfirm().getCountry()
            && actual->getfirm().getName() == leatherBackpack2.getfirm().getName()
            && actual->getlining() == leatherBackpack2.getlining()
            && actual->getLeather() == leatherBackpack2.getLeather()){

        result &= true;
    } else {
        result &= false;
    }
    //delete actual;
    return result;
}

bool Test_FindSuedeNoLiningBackpack(){
    bool result = true;

    LeatherBackpack leatherBackpack(false, "Black", 33, Firm("Nike", "USA"), TOURIST, true, ANILINE);
    LeatherBackpack leatherBackpack1(true, "Red", 44, Firm("Puma", "USA"), TACTICAL, false, SUEDE);
    LeatherBackpack leatherBackpack2(false, "Blue", 24, Firm("Adidas", "Germany"), URBAN, true, VELOUR);
    //leatherBackpack.Print();
    auto * leatherBackpackList = new LeatherBackpackList;

    leatherBackpackList->addBackpack(leatherBackpack);
    leatherBackpackList->addBackpack(leatherBackpack1);
    leatherBackpackList->addBackpack(leatherBackpack2);

    cout << "Ожидаемый результат:" << endl;
    PrintForm1();
    cout << endl;
    leatherBackpack1.Print();
    cout << endl;

    cout << endl << "Актуальный результат:" << endl;
    PrintForm1();
    cout << endl;
    LeatherBackpack * actual = &leatherBackpackList->FindSuedeNoLiningBackpack();
    cout << endl;

    if (actual->getlaptop_department() == leatherBackpack1.getlaptop_department()
        && actual->getcolor() == leatherBackpack1.getcolor()
        && actual->getvolume() == leatherBackpack1.getvolume()
        && actual->getpurpose() == leatherBackpack1.getpurpose()
        && actual->getfirm().getCountry() == leatherBackpack1.getfirm().getCountry()
        && actual->getfirm().getName() == leatherBackpack1.getfirm().getName()
        && actual->getlining() == leatherBackpack1.getlining()
        && actual->getLeather() == leatherBackpack1.getLeather()){

        result &= true;
    } else {
        result &= false;
    }
    //delete actual;
    return result;
}

bool Test_addFabricBackpack(){
    bool result = true;

    FabricBackpack fabricBackpack(false, "Black", 33, Firm("Nike", "USA"), URBAN, true, SYNTHETICS);
    FabricBackpack fabricBackpack1(true, "Blue", 44, Firm("Puma", "USA"), TACTICAL, false, TARP);

    auto * fabricBackpackList = new FabricBackpackList;

    fabricBackpackList->addBackpack(fabricBackpack);
    fabricBackpackList->addBackpack(fabricBackpack1);

    for (int i = 0; i < 2; ++i) {

        if (fabricBackpackList->getFabricBackpack(i).getlaptop_department() == fabricBackpack.getlaptop_department()
            && fabricBackpackList->getFabricBackpack(i).getcolor() == fabricBackpack.getcolor()
            && fabricBackpackList->getFabricBackpack(i).getvolume() == fabricBackpack.getvolume()
            && fabricBackpackList->getFabricBackpack(i).getpurpose() == fabricBackpack.getpurpose()
            && fabricBackpackList->getFabricBackpack(i).getfirm().getCountry() == fabricBackpack.getfirm().getCountry()
            && fabricBackpackList->getFabricBackpack(i).getfirm().getName() == fabricBackpack.getfirm().getName()
            && fabricBackpackList->getFabricBackpack(i).getwaterproof() == fabricBackpack.getwaterproof()
            && fabricBackpackList->getFabricBackpack(i).getFabric() == fabricBackpack.getFabric()) {
            result &= true;
        } else {
            result &= false;
        }
    }


    return result;
}

int main(){
    bool result = true;
//    cout << "\n|------ТЕСТ ДОБАВЛЕНИЯ В СПИСОК НАСЛЕДНИКА 1------|\n\n";
//    result = Test_addLeatherBackpack();
//    if (result){
//        cout << "РЕЗУЛЬТАТ ТЕСТА: Good job so far\n";
//    }else{
//        cout << "D'oh";
//    }
//    cout << "\n|------ТЕСТ ДОБАВЛЕНИЯ В СПИСОК НАСЛЕДНИКА 2-------|\n\n";
//    result = Test_addFabricBackpack();
//    if (result){
//        cout << "РЕЗУЛЬТАТ ТЕСТА: Good job so far\n";
//    }else{
//        cout << "D'oh";
//    }
    cout << "\n|------ТЕСТ МЕТОДА 1-------|\n\n";
    result = Test_FindGermanVelourBackpack();
    if (result){
        cout << endl << "РЕЗУЛЬТАТ ТЕСТА: Good job so far\n";
    }else{
        cout << "D'oh";
    }
    cout << "\n|------ТЕСТ МЕТОДА 2-------|\n\n";
    result = Test_FindSuedeNoLiningBackpack();
    if (result){
        cout << endl << "РЕЗУЛЬТАТ ТЕСТА: Good job so far\n";
    }else{
        cout << "D'oh";
    }
    cout << "\n|------------------------------------------------|";
    return 0;
}