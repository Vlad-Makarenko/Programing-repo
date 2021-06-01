#include "Container.hpp"


int main() {

    LeatherBackpack leatherBackpack(false, "Black", 33, Firm("Nike", "USA"), TOURIST, true, ANILINE);
    LeatherBackpack leatherBackpack1(true, "Red", 44, Firm("Puma", "USA"), TACTICAL, false, SUEDE);
    LeatherBackpack leatherBackpack2(false, "Blue", 24, Firm("Adidas", "Germany"), URBAN, true, VELOUR);


    FabricBackpack fabricBackpack (false, "Blue", 43, Firm("A.M.G", "Ukraine"), URBAN, true, SYNTHETICS);
    FabricBackpack fabricBackpack1 (true, "Orange", 38, Firm("Adidas", "Germany"), TACTICAL, false, TARP);
    FabricBackpack fabricBackpack2 (false, "Black" , 33,Firm( "Gucci" , "Italy"), TOURIST, true, COTTON);

    {

        List<unique_ptr<Backpack>> list;

        unique_ptr<Backpack> uniquePtr(new LeatherBackpack(leatherBackpack));
        unique_ptr<Backpack> uniquePtr1(new LeatherBackpack(leatherBackpack1));
        unique_ptr<Backpack> uniquePtr2(new LeatherBackpack(leatherBackpack2));
        unique_ptr<Backpack> uniquePtr3(new FabricBackpack(fabricBackpack));
        unique_ptr<Backpack> uniquePtr4(new FabricBackpack(fabricBackpack1));
        unique_ptr<Backpack> uniquePtr5(new FabricBackpack(fabricBackpack2));
        {
            unique_ptr<Backpack> uniquePtr6(std::move(uniquePtr)); // После выполнения uniquePtr ни на что не указывает
            cout << "Demo: " << endl;
            uniquePtr6.get()->Print();
            cout << endl << endl;
            uniquePtr = std::move(uniquePtr6);  // После выполнения uniquePtr возврщается прежнее значение, а uniquePtr6
                                                // больше ни на что не указывает
        }

        list.addItem(&uniquePtr);
        list.addItem(&uniquePtr1);
        list.addItem(&uniquePtr2);
        list.addItem(&uniquePtr3);
        list.addItem(&uniquePtr4);
        list.addItem(&uniquePtr5);



        //Исходный список
        cout << "|----------------------------------------------------------unique_ptr LIST----------------------------------------------------------|" << endl;
        PrintForm3();
        cout << endl;
        for (auto &backpack : list) {
            backpack->get()->Print();  // используем метод get() для конвертации std::unique_ptr в обычный указатель
            cout << endl;
        }
        cout << "|-----------------------------------------------------------------------------------------------------------------------------------|" << endl;
        cout << endl;

    }

    {
        List<shared_ptr<Backpack>> list;

        shared_ptr<Backpack> sharedPtr (new LeatherBackpack(leatherBackpack));
        shared_ptr<Backpack> sharedPtr1  (new LeatherBackpack(leatherBackpack1));
        shared_ptr<Backpack> sharedPtr2  (new LeatherBackpack(leatherBackpack2));
        shared_ptr<Backpack> sharedPtr3  (new FabricBackpack(fabricBackpack));
        shared_ptr<Backpack> sharedPtr4  (new FabricBackpack(fabricBackpack1));
        shared_ptr<Backpack> sharedPtr5  (new FabricBackpack(fabricBackpack2));
        shared_ptr<Backpack> sharedPtr6  (sharedPtr);   // sharedPtr6 указывает на тот же объект, что и sharedPtr
                                                        // и в таком случае объект будет уичтожен только тогда,
                                                        // когда оба этих указателей выйдут за облость видимости функции


        list.addItem(&sharedPtr);
        list.addItem(&sharedPtr1);
        list.addItem(&sharedPtr2);
        list.addItem(&sharedPtr3);
        list.addItem(&sharedPtr4);
        list.addItem(&sharedPtr5);
        list.addItem(&sharedPtr6);



        //Исходный список
        cout << "|----------------------------------------------------------shared_ptr LIST----------------------------------------------------------|" << endl;
        PrintForm3();
        cout << endl;
        for (auto &backpack : list) {
            backpack->get()->Print();  // используем метод get() для конвертации std::shared_ptr в обычный указатель
            cout << endl;
        }
        cout << "|-----------------------------------------------------------------------------------------------------------------------------------|" << endl;
        cout << endl;

    }

    {
        List<weak_ptr<Backpack>> list;

        shared_ptr<Backpack> sharedPtr (new LeatherBackpack(leatherBackpack));
        shared_ptr<Backpack> sharedPtr1  (new LeatherBackpack(leatherBackpack1));
        shared_ptr<Backpack> sharedPtr2  (new LeatherBackpack(leatherBackpack2));
        shared_ptr<Backpack> sharedPtr3  (new FabricBackpack(fabricBackpack));
        shared_ptr<Backpack> sharedPtr4  (new FabricBackpack(fabricBackpack1));
        shared_ptr<Backpack> sharedPtr5  (new FabricBackpack(fabricBackpack2));

        // weak_ptr используется, когда нужен умный указатель, который имеет доступ к ресурсу, но не считается его владельцем.
        weak_ptr<Backpack> weakPtr = sharedPtr;
        weak_ptr<Backpack> weakPtr1 = sharedPtr1;
        weak_ptr<Backpack> weakPtr2 = sharedPtr2;
        weak_ptr<Backpack> weakPtr3 = sharedPtr3;
        weak_ptr<Backpack> weakPtr4 = sharedPtr4;
        weak_ptr<Backpack> weakPtr5 = sharedPtr5;
        weak_ptr<Backpack> weakPtr6 = weakPtr;


        list.addItem(&weakPtr);
        list.addItem(&weakPtr1);
        list.addItem(&weakPtr2);
        list.addItem(&weakPtr3);
        list.addItem(&weakPtr4);
        list.addItem(&weakPtr5);
        list.addItem(&weakPtr6);



        //Исходный список
        cout << "|----------------------------------------------------------weak_ptr LIST----------------------------------------------------------|" << endl;
        PrintForm3();
        cout << endl;
        for (auto &backpack : list) {
            backpack->lock()->Print();  //используем метод lock() для конвертации std::weak_ptr в std::shared_ptr
            cout << endl;
        }
        cout << "|-----------------------------------------------------------------------------------------------------------------------------------|" << endl;
        cout << endl;

    }

    return 0;
}