//
// Created by Vlad on 20.04.2021.
//


#include "Container.h"

void List::setCount(const int count) {
    this->Count = count;
}

List::~List(){
    cout << "\nDestructor <List>" << endl;
    for (int i = 0; i < this->Count; ++i) {
        delete this->backpacks[i];
    }
    delete[] backpacks;

}

void List::addBackpack(Backpack &backpack) {
    auto **temp = new Backpack*[this->Count + 1];
    //cout << Count;
    for (int i = 0; i < this->Count; ++i) {
        temp[i] = new Backpack;
        temp[i] = this->backpacks[i];
    }
    temp[Count] = &backpack;
    //delete [] this->backpacks;
    this->backpacks = temp;
    this->Count +=1;
}

void List::removeBackpack(int index) {
    auto **temp = new Backpack*[this->Count - 1];

    if(index < 0){
        index= 0;
    }
    if(index >= this->Count) {
        index = this->Count - 1;
    }

    memcpy(temp, backpacks, sizeof (Backpack) * (index));
    memcpy(temp + index, backpacks + index + 1, sizeof (Backpack) * (Count - index));

    delete [] this->backpacks;
    this->backpacks = temp;
    this->Count -= 1;
}

Backpack& List::getBackpack(int index) const{
    if(index < 0){
        index= 0;
    }
    if(index >= this->Count) {
        index = this->Count - 1;
    }

    return *backpacks[index];
}

void List::ShowAll() const {
    for (int i = 0; i < this->Count; ++i) {
        Backpack temp = getBackpack(i);
        temp.Print();
    }
}

Backpack& List::FindGermanCityBackpack() const{
    string country = "Germany";
    Purpose purpose = URBAN;
    int index = - 1;
    for (int i = 0; i < this->Count; ++i) {
        Backpack temp = getBackpack(i);
        if(country == temp.getfirm().getCountry() && purpose == temp.getpurpose()){
            temp.Print();
            index = i;
        }
    }
    if (index == -1){
        cout << "ERROR: German city backpack not found" << endl;
        return getBackpack(0);
    } else {
        return getBackpack(index);
    }
}


//void List::Print() {
//    for (int i = 0; i < this->Count; ++i) {
//        Backpack *temp = this->backpacks[i];
//        temp->Print();
//    }
//}