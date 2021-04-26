//
// Created by Vlad on 20.04.2021.
//

#ifndef LAB23_CONTAINER_H
#define LAB23_CONTAINER_H

#include "Backpack.h"

class List{
    Backpack **backpacks;
    size_t Count;
public:
    List();
    List(const List &copy);
    virtual ~List();
    void setCount(const int count);

    void addBackpack( Backpack& backpack);
    void removeBackpack( int index);
    Backpack& getBackpack (int index) const;
    void ShowAll() const;
    Backpack& FindGermanCityBackpack() const;
    Backpack& SplitLineToObject(const string &object) const;
    void ReadFromFile(const string &path) ;
    void WriteToFile(const string &path);
    //void Print();
};


#endif //LAB23_CONTAINER_H
