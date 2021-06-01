#include "Container.hpp"
//#include "Backpack.h"


int main() {

    LeatherBackpack leatherBackpack(false, "Black", 33, Firm("Nike", "USA"), TOURIST, true, ANILINE);
    LeatherBackpack leatherBackpack1(true, "Red", 44, Firm("Puma", "USA"), TACTICAL, false, SUEDE);
    LeatherBackpack leatherBackpack2(false, "Blue", 24, Firm("Adidas", "Germany"), URBAN, true, VELOUR);
    LeatherBackpack leatherBackpack3(true, "Green", 51, Firm("Deuter", "Germany"), URBAN, false, VELOUR);


    FabricBackpack fabricBackpack (false, "Blue", 43, Firm("A.M.G", "Ukraine"), URBAN, true, SYNTHETICS);
    FabricBackpack fabricBackpack2 (true, "Orange", 38, Firm("Adidas", "Germany"), TACTICAL, false, TARP);
    FabricBackpack fabricBackpack3 (false, "Black" , 33,Firm( "Gucci" , "Italy"), TOURIST, true, COTTON);

    List<Backpack> *list;

    list->addBackpack(&leatherBackpack);
    list->addBackpack(&leatherBackpack1);
    list->addBackpack(&leatherBackpack2);
    list->addBackpack(&leatherBackpack3);
    list->addBackpack(&fabricBackpack);
    list->addBackpack(&fabricBackpack2);
    list->addBackpack(&fabricBackpack3);


    //Исходный список
    cout << "|-----------------------------------------------------------ORIGINAL LIST-----------------------------------------------------------|" << endl;
    PrintForm3();
    cout << endl;
    //list->ShowAll();
    for(auto &backpack : *list){
        backpack->Print();
        cout << endl;
    }
    cout << "|-----------------------------------------------------------------------------------------------------------------------------------|" << endl;
    cout << endl;


    //Метод 1
    cout << "|-------------------------------------------------GERMAN URBAN BACKPACK WITH VELOUR-------------------------------------------------|" << endl;
    PrintForm1();
    cout << endl;
    list->FindGermanVelourBackpack();
    cout << "|-----------------------------------------------------------------------------------------------------------------------------------|" << endl;
    cout << endl;

    //Метод 2
    cout << "|---------------------------------------------------SUEDE BACKPACK WITHOUT LINING---------------------------------------------------|" << endl;
    PrintForm1();
    cout << endl;
    list->FindSuedeNoLiningBackpack();
    cout << "|-----------------------------------------------------------------------------------------------------------------------------------|" << endl;
    cout << endl;

    //Метод 3
    cout << "|-----------------------------------------------------BLUE MAX VOLUME BACKPACK------------------------------------------------------|" << endl;
    cout << endl;
    auto del = list->FindBlueMaxVolumeBackpack();
    cout << "|-----------------------------------------------------------------------------------------------------------------------------------|" << endl;
    cout << endl;

    cout << "|------------------------------------------------------------SORTED LIST------------------------------------------------------------|" << endl;
    PrintForm3();
    cout << endl;
    list->SortByVolume(true);
    //list->ShowAll();
    for(auto &backpack : *list){
        backpack->Print();
        cout << endl;
    }
    cout << "|-----------------------------------------------------------------------------------------------------------------------------------|" << endl;
    cout << endl;


//    list->DeleteElement(2);
//    list->ShowAll();

    delete del;
    delete list;
    return 0;
}