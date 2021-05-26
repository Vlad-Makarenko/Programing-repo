#include "Container.h"
//#include "Backpack.h"


int main() {

    LeatherBackpack leatherBackpack(false, "Black", 33, Firm("Nike", "USA"), TOURIST, true, ANILINE);
    LeatherBackpack leatherBackpack1(true, "Red", 44, Firm("Puma", "USA"), TACTICAL, false, SUEDE);
    LeatherBackpack leatherBackpack2(false, "Blue", 24, Firm("Adidas", "Germany"), URBAN, true, VELOUR);
    LeatherBackpack leatherBackpack3(true, "Green", 51, Firm("Deuter", "Germany"), URBAN, false, VELOUR);


    FabricBackpack fabricBackpack (false, "Blue", 43, Firm("A.M.G", "Ukraine"), URBAN, true, SYNTHETICS);
    FabricBackpack fabricBackpack2 (true, "Orange", 38, Firm("Adidas", "Germany"), TACTICAL, false, TARP);
    FabricBackpack fabricBackpack3 (false, "Black" , 33,Firm( "Gucci" , "Italy"), TOURIST, true, COTTON);

    List *list = new List;
    list->addBackpack(&leatherBackpack);
    list->addBackpack(&leatherBackpack1);
    list->addBackpack(&leatherBackpack2);
    list->addBackpack(&leatherBackpack3);
    list->addBackpack(&fabricBackpack);
    list->addBackpack(&fabricBackpack2);
    list->addBackpack(&fabricBackpack3);


    LeatherBackpack leatherBackpack4(false, "Red", 56, Firm("Adidas", "Poland"), TACTICAL, true, SUEDE);
    LeatherBackpack leatherBackpack5(true, "White", 45, Firm("Xiaomi", "China"), TOURIST, false, ANILINE);

    FabricBackpack fabricBackpack4 (false, "Yellow", 29, Firm("A.M.G", "Ukraine"), URBAN, true, SYNTHETICS);
    FabricBackpack fabricBackpack5 (true, "Orange", 19, Firm("Taikkss", "China"), TACTICAL, false, TARP);


    List *NewList = new List;
    NewList->addBackpack(&leatherBackpack4);
    NewList->addBackpack(&leatherBackpack5);
    NewList->addBackpack(&fabricBackpack4);
    NewList->addBackpack(&fabricBackpack5);


    //Исходный список
    cout << "|-----------------------------------------------------------ORIGINAL LIST-----------------------------------------------------------|" << endl;
    PrintForm3();
    cout << endl;
    list->ShowAll();
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
    list->ShowAll();
    cout << "|-----------------------------------------------------------------------------------------------------------------------------------|" << endl;
    cout << endl;

    cout << "|-----------------------------------------------------------INSERT LIST------------------------------------------------------------|" << endl;
    PrintForm3();
    cout << endl;
    NewList->ShowAll();
    cout << "|-----------------------------------------------------------------------------------------------------------------------------------|" << endl;
    cout << endl;

    cout << "|---------------------------------------------------------NEW ORIGINAL LIST---------------------------------------------------------|" << endl;
    PrintForm3();
    cout << endl;
    list->InsertList(*NewList);
    list->ShowAll();
    cout << "|-----------------------------------------------------------------------------------------------------------------------------------|" << endl;
    cout << endl;

    cout << "|----------------------------------------------------------EXCELLENT TASK-----------------------------------------------------------|" << endl;
    ExcellentTask();
    cout << "|-----------------------------------------------------------------------------------------------------------------------------------|" << endl;
    cout << endl;


//    list->DeleteElement(2);
//    list->ShowAll();

    delete del;
    delete list;
    delete NewList;
    return 0;
}