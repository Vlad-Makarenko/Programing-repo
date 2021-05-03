#include "Container.h"
//#include "Backpack.h"


int main() {
    List * list = new List;
    string path = "D:\\Programing-repo\\lab24\\Backpacks.txt";

    //Перегрузка чтения из файла
    list->ReadFromFile(path);


    //Ввод списка(перегразка ввода/вывода списка)
//    cin >> *list;
//    PrintForm();
//    cout << *list;

    //Перегрузка оператора =
//    Backpack backpack;
//    backpack.operator=(list->operator[](3));
//    backpack.Print();

    //Перегрузка операторов сравнения ==/!=
//    bool  result;
//    if (list->getBackpack(1) != list->getBackpack(2)){
//        result = true;
//    } else{
//        result = false;
//    }
//    cout << result;


    //Перегрузка операторов ввода/вывода для базового класса
//    Backpack backpack;
//    cin >> backpack;
//    PrintForm();
//    cout << backpack;

    cout << "Place for laptop( 1 - Yes, 0 - No)           Purpose(0 - Urban, 1 - Tactical, 2 - Tourist)" << endl << endl;

    cout << "|----------------------------------CREATE THE STRING FROM THE OBJECT----------------------------------|" << endl;
    //Объект представленый в строке
    string test = list->getBackpack(4).toString();
    PrintForm();
    cout << endl;
    list->getBackpack(4).Print();
    cout << endl << "> Information about the object in the line: " << test;
    cout << "|-----------------------------------------------------------------------------------------------------|" << endl;
    cout << endl;

    cout << "|----------------------------------CREATE THE OBJECT FROM THE STRING----------------------------------|" << endl;
    //Парсинг строки на поля объектa
    string obj = "0 Orange 26 2 A.M.G Ukraine";
    cout << endl << ">The string from which to get the object: " << obj << endl << endl;
    Backpack *test1 = &test1->SplitLineToObject(obj);
    PrintForm();
    cout << endl;
    cout << *test1;
    //test1->Print();
    list->addBackpack(*test1);
    cout.put('\0');
    cout << "|-----------------------------------------------------------------------------------------------------|" << endl;
    cout << endl;



    cout << "|--------------------------------------------ORIGINAL LIST--------------------------------------------|" << endl;
    //Исходный список
    PrintForm();
    cout << endl;
    cout << *list;
    //list->ShowAll();
    cout << "|-----------------------------------------------------------------------------------------------------|" << endl;
    cout << endl;

//    cout << "|----------------------------------------GERMAN URBAN BACKPACK----------------------------------------|" << endl;
//    //Поиска Немецкого, городского рюкзака
//    PrintForm();
//    cout << endl;
//    list->FindGermanCityBackpack();
//    cout << endl << "|-----------------------------------------------------------------------------------------------------|" << endl;
//    cout << endl;

    cout << "|-------------------------------------ITEM FROM THE LIST BY INDEX-------------------------------------|" << endl;
    //Полученый элемент из списка
    Backpack temp = list->getBackpack(1);
    PrintForm();
    cout << endl;
    cout << temp;
    //temp.Print();
    cout << "|-----------------------------------------------------------------------------------------------------|" << endl;
    cout << endl;

    cout << "|-------------------------------DELETING AN ITEM FROM THE LIST BY INDEX-------------------------------|" << endl;
    //Удаление элемента по индексу
    list->removeBackpack(2);
    PrintForm();
    cout << endl;
    cout << *list;
    //list->ShowAll();
    cout << "|-----------------------------------------------------------------------------------------------------|" << endl;
    cout << endl;

    //Запись результата в файл
    path = "D:\\Programing-repo\\lab24\\temp.txt";

    //Перегрузка записи в файл
    list->WriteToFile(path);

//|---------------------------Наследник 1-------------------------|\\

    cout << endl;
    cout << "|----------------------------------------------------------INHERITOR 1 LIST----------------------------------------------------------|" << endl;
    LeatherBackpack leatherBackpack(false, "Black", 33, Firm("Nike", "USA"), TOURIST, true, ANILINE);
    LeatherBackpack leatherBackpack1(true, "Red", 44, Firm("Puma", "USA"), TACTICAL, false, SUEDE);
    LeatherBackpack leatherBackpack2(false, "Blue", 24, Firm("Adidas", "Germany"), URBAN, true, VELOUR);
    //leatherBackpack.Print();
    auto * leatherBackpackList = new LeatherBackpackList;

    leatherBackpackList->addBackpack(leatherBackpack);
    leatherBackpackList->addBackpack(leatherBackpack1);
    leatherBackpackList->addBackpack(leatherBackpack2);
    PrintForm1();
    cout << endl;
    leatherBackpackList->ShowAll();
    cout << "|------------------------------------------------------------------------------------------------------------------------------------|" << endl;
    cout << endl;

    //Метод 1
    cout << "|--------------------------------------------------GERMAN URBAN BACKPACK WITH VELOUR-------------------------------------------------|" << endl;
    //Поиска Немецкого, городского рюкзака
    PrintForm1();
    cout << endl;
    leatherBackpackList->FindGermanVelourBackpack();
    cout << endl << "|------------------------------------------------------------------------------------------------------------------------------------|" << endl;
    cout << endl;

    //Метод 2
    cout << "|----------------------------------------------------SUEDE BACKPACK WITHOUT LINING---------------------------------------------------|" << endl;
    PrintForm1();
    cout << endl;
    leatherBackpackList->FindSuedeNoLiningBackpack();
    cout << endl << "|------------------------------------------------------------------------------------------------------------------------------------|" << endl;
    cout << endl;

//|---------------------------Наследник 2-------------------------|\\

    cout << "|-----------------------------------------------------------INHERITOR 2 LIST---------------------------------------------------------|" << endl;
    FabricBackpack fabricBackpack (false, "Red", 43, Firm("A.M.G", "Ukraine"), URBAN, true, SYNTHETICS);
    FabricBackpack fabricBackpack2 (true, "Orange", 38, Firm("Adidas", "Germany"), TACTICAL, false, TARP);
    FabricBackpack fabricBackpack3 (false, "Black" , 33,Firm( "Gucci" , "Italy"), TOURIST, true, COTTON);
    //fabricBackpack.Print();
    auto *fabricBackpackList = new FabricBackpackList;

    fabricBackpackList->addBackpack(fabricBackpack);
    fabricBackpackList->addBackpack(fabricBackpack2);
    fabricBackpackList->addBackpack(fabricBackpack3);
    PrintForm2();
    cout << endl;
    fabricBackpackList->ShowAll();
    cout << "|------------------------------------------------------------------------------------------------------------------------------------|" << endl;
    cout << endl;


    cout << "|------------------------------------------------------BLUE MAX VOLUME BACKPACK------------------------------------------------------|" << endl;
    //Поиска Немецкого, городского рюкзака
    cout << endl;
    FabricBackpack * tempfabricbackpack = &fabricBackpackList->FindBlueMaxVolumeBackpack();
    LeatherBackpack * templeatherbackpack = &leatherBackpackList->FindBlueMaxVolumeBackpack();
    FindBlueMaxVolumeBackpack(*tempfabricbackpack, *templeatherbackpack);
    cout << endl << "|------------------------------------------------------------------------------------------------------------------------------------|" << endl;
    cout << endl;


    delete templeatherbackpack;
    delete tempfabricbackpack;
    delete test1;
    delete list;
    delete leatherBackpackList;
    delete fabricBackpackList;
    return 0;
}