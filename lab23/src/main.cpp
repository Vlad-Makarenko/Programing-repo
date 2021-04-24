#include "Container.h"
//#include "Backpack.h"


int main() {
    auto *firm = new Firm;

    firm->setName("Nike");
    firm->setCountry("USA");

    auto *backpack = new Backpack;

    backpack->setlaptop_department(true);
    backpack->setcolor("Red");
    backpack->setvolume(22);
    backpack->setfirm(firm);
    backpack->setpurpose(TACTICAL);

    //Firm firm1("Nike", "UK");

    Backpack backpack1 (false, "Black", 33, Firm("Gucci", "Italy"),  URBAN);
    Backpack backpack2 (true, "Blue", 44, Firm("Puma", "USA"), TOURIST );
    Backpack backpack3 (true, "Yellow", 55, Firm("Adidas", "Germany"), URBAN);

    List * list = new List;
    list->addBackpack(*backpack);
    list->addBackpack(backpack1);
    list->addBackpack(backpack2);
    list->addBackpack(backpack3);


    cout << "Place for laptop( 1 - Yes, 0 - No)           Purpose(0 - Urban, 1 - Tactical, 2 - Tourist)" << endl << endl;
    cout << "|--------------------------------------------ORIGINAL LIST--------------------------------------------|" << endl;
    //Исходный список
    PrintForm();
    list->ShowAll();
    cout << "|-----------------------------------------------------------------------------------------------------|" << endl;
    cout << endl;

    cout << "|----------------------------------------GERMAN URBAN BACKPACK----------------------------------------|" << endl;
    //Поиска Немецкого, городского рюкзака
    PrintForm();
    list->FindGermanCityBackpack();
    cout << "|-----------------------------------------------------------------------------------------------------|" << endl;
    cout << endl;

    cout << "|-------------------------------------ITEM FROM THE LIST BY INDEX-------------------------------------|" << endl;
    //Полученый элемент из списка
    Backpack temp = list->getBackpack(1);
    PrintForm();
    temp.Print();
    cout << "|-----------------------------------------------------------------------------------------------------|" << endl;
    cout << endl;

    cout << "|-------------------------------DELETING AN ITEM FROM THE LIST BY INDEX-------------------------------|" << endl;
    //Удаление элемента по индексу
    list->removeBackpack(-1);
    PrintForm();
    list->ShowAll();
    cout << "|-----------------------------------------------------------------------------------------------------|" << endl;
    cout << endl;



    delete list;
    delete firm;
    delete backpack;
    return 0;
}