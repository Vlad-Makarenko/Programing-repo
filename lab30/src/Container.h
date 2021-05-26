//
// Created by Vlad on 20.04.2021.
//

#ifndef LAB23_CONTAINER_H
#define LAB23_CONTAINER_H

#include "Backpack.h"

class List{
    vector<Backpack*> backpacks;
    int index = -1;
public:
    List();
    List(List &copy);

    virtual ~List();

    void addBackpack( Backpack * backpack);

    vector<Backpack*> getBackpack ();

    void ShowAll();

    vector<LeatherBackpack*> FindGermanVelourBackpack();

    vector<LeatherBackpack*> FindSuedeNoLiningBackpack();

    Backpack* FindBlueMaxVolumeBackpack();

    void SortByVolume(bool flag);

    void InsertList(List &in);

    void DeleteElement(int index);

    void DeleteAll();


};

void ExcellentTask();

#endif //LAB23_CONTAINER_H
