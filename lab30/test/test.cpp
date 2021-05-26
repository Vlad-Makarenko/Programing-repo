//
// Created by Vlad on 20.04.2021.
//

//#include "Backpack.h"
#include "Container.h"


bool Test_FindGermanVelourBackpack(){
    bool result = true;

    LeatherBackpack leatherBackpack(false, "Black", 33, Firm("Nike", "USA"), TOURIST, true, ANILINE);
    LeatherBackpack leatherBackpack1(true, "Red", 44, Firm("Puma", "USA"), TACTICAL, false, SUEDE);
    LeatherBackpack leatherBackpack2(false, "Blue", 24, Firm("Adidas", "Germany"), URBAN, true, VELOUR);


    FabricBackpack fabricBackpack (false, "Blue", 43, Firm("A.M.G", "Ukraine"), URBAN, true, SYNTHETICS);
    FabricBackpack fabricBackpack2 (true, "Orange", 38, Firm("Adidas", "Germany"), TACTICAL, false, TARP);
    FabricBackpack fabricBackpack3 (false, "Black" , 33,Firm( "Gucci" , "Italy"), TOURIST, true, COTTON);

    List list;
    list.addBackpack(&leatherBackpack);
    list.addBackpack(&leatherBackpack1);
    list.addBackpack(&leatherBackpack2);
    list.addBackpack(&fabricBackpack);
    list.addBackpack(&fabricBackpack2);
    list.addBackpack(&fabricBackpack3);

    cout <<  "Ожидаемый результат:" << endl;
    PrintForm1();
    cout << endl;
    leatherBackpack2.Print();
    cout << endl;

    cout << endl << "Актуальный результат:" << endl;
    PrintForm1();
    cout << endl;
    vector<LeatherBackpack*> actual = list.FindGermanVelourBackpack();
    cout << endl;

    if (actual[0]->getlaptop_department() == leatherBackpack2.getlaptop_department()
            && actual[0]->getcolor() == leatherBackpack2.getcolor()
            && actual[0]->getvolume() == leatherBackpack2.getvolume()
            && actual[0]->getpurpose() == leatherBackpack2.getpurpose()
            && actual[0]->getfirm().getCountry() == leatherBackpack2.getfirm().getCountry()
            && actual[0]->getfirm().getName() == leatherBackpack2.getfirm().getName()
            && actual[0]->getlining() == leatherBackpack2.getlining()
            && actual[0]->getLeather() == leatherBackpack2.getLeather()){

        result &= true;
    } else {
        result &= false;
    }
    for (auto &i: actual) {
        actual.pop_back();
    }
    return result;
}

bool Test_FindSuedeNoLiningBackpack(){
    bool result = true;

    LeatherBackpack leatherBackpack(false, "Black", 33, Firm("Nike", "USA"), TOURIST, true, ANILINE);
    LeatherBackpack leatherBackpack1(true, "Red", 44, Firm("Puma", "USA"), TACTICAL, false, SUEDE);
    LeatherBackpack leatherBackpack2(false, "Blue", 24, Firm("Adidas", "Germany"), URBAN, true, VELOUR);


    FabricBackpack fabricBackpack (false, "Blue", 43, Firm("A.M.G", "Ukraine"), URBAN, true, SYNTHETICS);
    FabricBackpack fabricBackpack2 (true, "Orange", 38, Firm("Adidas", "Germany"), TACTICAL, false, TARP);
    FabricBackpack fabricBackpack3 (false, "Black" , 33,Firm( "Gucci" , "Italy"), TOURIST, true, COTTON);

    List list;
    list.addBackpack(&leatherBackpack);
    list.addBackpack(&leatherBackpack1);
    list.addBackpack(&leatherBackpack2);
    list.addBackpack(&fabricBackpack);
    list.addBackpack(&fabricBackpack2);
    list.addBackpack(&fabricBackpack3);

    cout << "Ожидаемый результат:" << endl;
    PrintForm1();
    cout << endl;
    leatherBackpack1.Print();
    cout << endl;

    cout << endl << "Актуальный результат:" << endl;
    PrintForm1();
    cout << endl;
    vector<LeatherBackpack*> actual = list.FindSuedeNoLiningBackpack();
    cout << endl;

    if (actual[0]->getlaptop_department() == leatherBackpack1.getlaptop_department()
        && actual[0]->getcolor() == leatherBackpack1.getcolor()
        && actual[0]->getvolume() == leatherBackpack1.getvolume()
        && actual[0]->getpurpose() == leatherBackpack1.getpurpose()
        && actual[0]->getfirm().getCountry() == leatherBackpack1.getfirm().getCountry()
        && actual[0]->getfirm().getName() == leatherBackpack1.getfirm().getName()
        && actual[0]->getlining() == leatherBackpack1.getlining()
        && actual[0]->getLeather() == leatherBackpack1.getLeather()){

        result &= true;
    } else {
        result &= false;
    }
    for (auto &i: actual) {
        actual.pop_back();
    }
    return result;
}


bool Test_FindBlueMaxVolumeBackpack(){
    bool result = true;

    LeatherBackpack leatherBackpack(false, "Black", 33, Firm("Nike", "USA"), TOURIST, true, ANILINE);
    LeatherBackpack leatherBackpack1(true, "Red", 44, Firm("Puma", "USA"), TACTICAL, false, SUEDE);
    LeatherBackpack leatherBackpack2(false, "Blue", 24, Firm("Adidas", "Germany"), URBAN, true, VELOUR);


    FabricBackpack fabricBackpack (false, "Blue", 43, Firm("A.M.G", "Ukraine"), URBAN, true, SYNTHETICS);
    FabricBackpack fabricBackpack2 (true, "Orange", 38, Firm("Adidas", "Germany"), TACTICAL, false, TARP);
    FabricBackpack fabricBackpack3 (false, "Black" , 33,Firm( "Gucci" , "Italy"), TOURIST, true, COTTON);

    List list;
    list.addBackpack(&leatherBackpack);
    list.addBackpack(&leatherBackpack1);
    list.addBackpack(&leatherBackpack2);
    list.addBackpack(&fabricBackpack);
    list.addBackpack(&fabricBackpack2);
    list.addBackpack(&fabricBackpack3);

    cout << "Ожидаемый результат:" << endl;
    PrintForm2();
    cout << endl;
    fabricBackpack.Print();
    cout << endl;

    cout << endl << "Актуальный результат:" << endl;
    auto * actual = (FabricBackpack*)list.FindBlueMaxVolumeBackpack();
    cout << endl;

    if (actual->getlaptop_department() == fabricBackpack.getlaptop_department()
        && actual->getcolor() == fabricBackpack.getcolor()
        && actual->getvolume() == fabricBackpack.getvolume()
        && actual->getpurpose() == fabricBackpack.getpurpose()
        && actual->getfirm().getCountry() == fabricBackpack.getfirm().getCountry()
        && actual->getfirm().getName() == fabricBackpack.getfirm().getName()
        && actual->getwaterproof() == fabricBackpack.getwaterproof()
        && actual->getFabric() == fabricBackpack.getFabric()){

        result &= true;
    } else {
        result &= false;
    }
    delete actual;
    return result;
}

int main(){
    bool result = true;
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

    cout << "\n|------ТЕСТ МЕТОДА 3-------|\n\n";
    result = Test_FindBlueMaxVolumeBackpack();
    if (result){
        cout << endl << "РЕЗУЛЬТАТ ТЕСТА: Good job so far\n";
    }else{
        cout << "D'oh";
    }

    cout << "\n|------------------------------------------------|";
    return 0;
}