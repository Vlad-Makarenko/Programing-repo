#include "Container.h"
//#include "Backpack.h"


int main() {

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

    //Исходный список
    cout << "|-----------------------------------------------------------ORIGINAL LIST-----------------------------------------------------------|" << endl;
    PrintForm3();
    cout << endl;
    list.ShowAll();
    cout << "|-----------------------------------------------------------------------------------------------------------------------------------|" << endl;
    cout << endl;


    //Метод 1
    cout << "|--------------------------------------------------GERMAN URBAN BACKPACK WITH VELOUR-------------------------------------------------|" << endl;
    PrintForm1();
    cout << endl;
    list.FindGermanVelourBackpack();
    cout << endl << "|------------------------------------------------------------------------------------------------------------------------------------|" << endl;
    cout << endl;

    //Метод 2
    cout << "|----------------------------------------------------SUEDE BACKPACK WITHOUT LINING---------------------------------------------------|" << endl;
    PrintForm1();
    cout << endl;
    list.FindSuedeNoLiningBackpack();
    cout << endl << "|------------------------------------------------------------------------------------------------------------------------------------|" << endl;
    cout << endl;

    //Метод 3
    cout << "|------------------------------------------------------BLUE MAX VOLUME BACKPACK------------------------------------------------------|" << endl;
    cout << endl;
    list.FindBlueMaxVolumeBackpack();
    cout << endl << "|------------------------------------------------------------------------------------------------------------------------------------|" << endl;
    cout << endl;


    return 0;
}