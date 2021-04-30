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
    cout << *test1;
    //test1->Print();
    list->addBackpack(*test1);
    cout.put('\0');
    cout << "|-----------------------------------------------------------------------------------------------------|" << endl;
    cout << endl;



    cout << "|--------------------------------------------ORIGINAL LIST--------------------------------------------|" << endl;
    //Исходный список
    PrintForm();
    cout << *list;
    //list->ShowAll();
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
    cout << temp;
    //temp.Print();
    cout << "|-----------------------------------------------------------------------------------------------------|" << endl;
    cout << endl;

    cout << "|-------------------------------DELETING AN ITEM FROM THE LIST BY INDEX-------------------------------|" << endl;
    //Удаление элемента по индексу
    list->removeBackpack(2);
    PrintForm();
    cout << *list;
    //list->ShowAll();
    cout << "|-----------------------------------------------------------------------------------------------------|" << endl;
    cout << endl;

    //Запись результата в файл
    path = "D:\\Programing-repo\\lab24\\temp.txt";

    //Перегрузка записи в файл
    list->WriteToFile(path);

    delete test1;
    delete list;
    return 0;
}