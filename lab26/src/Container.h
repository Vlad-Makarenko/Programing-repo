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
    size_t getcount() const;
    void ShowAll() const;
    Backpack& FindGermanCityBackpack() const;
    Backpack& SplitLineToObject(const string &object) const;
    void ReadFromFile(const string &path) ;
    void WriteToFile(const string &path);
    Backpack& operator[](const size_t index) const;
    friend ifstream& operator>>(ifstream &in, List& list);
    friend istream & operator>>(istream &in , List& list);
};

ostream & operator<<(ostream &out ,const List& list);

ofstream & operator<<(ofstream &out ,const List& list);
//istream & operator>>(istream &in, Backpack& backpack);


//|---------------------------Наследник 1-------------------------|\\

class LeatherBackpackList {
    LeatherBackpack **LeatherBackpacks;
    size_t Count;
public:
    LeatherBackpackList();

    LeatherBackpackList(const LeatherBackpackList &copy);

    virtual ~LeatherBackpackList();

    void setCount(const int count);

    void addBackpack( LeatherBackpack& backpack);

    LeatherBackpack& getLeatherBackpack (int index) const;

    LeatherBackpack& FindGermanVelourBackpack();

    LeatherBackpack& FindSuedeNoLiningBackpack();

    LeatherBackpack& FindBlueMaxVolumeBackpack();

    void SortByVolume();

    virtual void ShowAll() const;
};

//|---------------------------Наследник 2-------------------------|\\


class FabricBackpackList {
    FabricBackpack **FabricBackpacks;
    size_t Count;
public:
    FabricBackpackList();

    FabricBackpackList(const FabricBackpackList &copy);

    virtual ~FabricBackpackList();

    void setCount(const int count);

    void addBackpack (FabricBackpack& backpack);

    FabricBackpack& getFabricBackpack (int index) const;

    FabricBackpack& FindBlueMaxVolumeBackpack();

    void SortByVolume();

    virtual void ShowAll() const;
};

void FindBlueMaxVolumeBackpack(FabricBackpack& fabricBackpack, LeatherBackpack& leatherBackpack);

#endif //LAB23_CONTAINER_H
