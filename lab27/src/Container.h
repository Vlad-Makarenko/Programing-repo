//
// Created by Vlad on 20.04.2021.
//

#ifndef LAB23_CONTAINER_H
#define LAB23_CONTAINER_H

#include "Backpack.h"

class List{
    Backpack *backpacks[ARRAY_SIZE];
    int index = -1;
public:
    List();
    List(const List &copy);

    virtual ~List();

    void addBackpack( Backpack * backpack);

    Backpack* getBackpack (int index) const;

    void ShowAll() const;

    LeatherBackpack* FindGermanVelourBackpack();

    LeatherBackpack* FindSuedeNoLiningBackpack();

    Backpack* FindBlueMaxVolumeBackpack();

    void SortByVolume();

    List & operator=( const List &copy);

};


#endif //LAB23_CONTAINER_H
