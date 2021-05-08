//
// Created by Vlad on 20.04.2021.
//



#include "Container.h"


List::List() {}

List::List(const List &copy) :index(copy.index) {
    for (int i = 0; i <= copy.index; i++) {
        backpacks[i] = copy.backpacks[i]->clone();
    }
}

List::~List(){
    while (index >= 0){
        delete backpacks[index];
        index--;
    }
}

void List::addBackpack(Backpack *backpack) {
    index += 1;
    if (index >= 255) {
        return;
    }
    backpacks[index] = backpack->clone();
    //cout << index;
}


Backpack* List::getBackpack(int index) const{
    if(index < 0){
        index= 0;
    }
    if(index >= this->index) {
        index = this->index - 1;
    }

    return backpacks[index]->clone();
}

void List::ShowAll() const {
    for (int i = 0; i <= this->index; ++i) {
        backpacks[i]->Print();
        cout << endl;
    }
}


List& List::operator=(const List &copy) {
    if (this == &copy) // a = a;
        return *this;
    while (index >= 0){
        delete backpacks[index];
        index--;
    }
    for (int i = 0; i <= copy.index; i++) {
        backpacks[i] = copy.backpacks[i]->clone();
    }
    index = copy.index;
    return *this;
}


LeatherBackpack* List::FindGermanVelourBackpack(){
    LeatherBackpack *temp;// = new LeatherBackpack;
    bool flag = true;
    for (int i = 0; i <= index; ++i) {
        if (backpacks[i]->GetType() == 'L'){
            temp = (LeatherBackpack*)getBackpack(i);
            if ( temp->getLeather() == VELOUR
                 && temp->getfirm().getCountry() == "Germany"
                 && temp->getpurpose() == URBAN){
                temp->Print();
                cout << endl;
                flag = false;
                break;
            }
        }

    }
    if (flag){
        cout << "ERROR: Nothing found" << endl;
        return nullptr;
    }
    return temp;
}

LeatherBackpack*  List::FindSuedeNoLiningBackpack(){
    LeatherBackpack *temp;// = new LeatherBackpack;
    bool flag = true;
    for (int i = 0; i <= index; ++i) {
        if (backpacks[i]->GetType() == 'L'){
            temp = (LeatherBackpack*)getBackpack(i);
            if ( temp->getLeather() == SUEDE && temp->getlining() == false) {
                temp->Print();
                cout << endl;
                flag = false;
                break;
            }
        }

    }
    if (flag){
        cout << "ERROR: Nothing found" << endl;
        return nullptr;
    }
    return temp;
}

void List::SortByVolume() {
    LeatherBackpack *temp1;
    LeatherBackpack *temp2;
    FabricBackpack *temp3;
    FabricBackpack *temp4;
    for (int i = 0; i <= index; i++) {
        for (int j = 0; j <= index - 1; j++) {
            if (backpacks[j]->GetType() == 'L' && backpacks[j + 1]->GetType() == 'L') {
                temp1 = (LeatherBackpack *) getBackpack(j);
                temp2 = (LeatherBackpack *) getBackpack(j+ 1);
                if(temp1->getvolume() > temp2->getvolume()){
                    LeatherBackpack *temp = (LeatherBackpack *)getBackpack(j);
                    backpacks[j] = backpacks[j+1];
                    backpacks[j+1] = temp;
                }
            }
            if (backpacks[j]->GetType() == 'F' && backpacks[j + 1]->GetType() == 'F') {
                temp3 = (FabricBackpack *) getBackpack(j);
                temp4 = (FabricBackpack *) getBackpack(j+ 1);
                if(temp3->getvolume() > temp4->getvolume()){
                    FabricBackpack *temp = (FabricBackpack *)getBackpack(j);
                    backpacks[j] = backpacks[j+1];
                    backpacks[j+1] = temp;
                }
            }
            if (backpacks[j]->GetType() == 'F' && backpacks[j + 1]->GetType() == 'L') {
                temp3 = (FabricBackpack *) getBackpack(j);
                temp1 = (LeatherBackpack *) getBackpack(j+ 1);
                if(temp3->getvolume() > temp1->getvolume()){
                    FabricBackpack *temp = (FabricBackpack *)getBackpack(j);
                    backpacks[j] = backpacks[j+1];
                    backpacks[j+1] = temp;
                }
            }
            if (backpacks[j]->GetType() == 'L' && backpacks[j + 1]->GetType() == 'F') {
                temp1 = (LeatherBackpack *) getBackpack(j);
                temp3 = (FabricBackpack *) getBackpack(j+ 1);
                if(temp1->getvolume() > temp3->getvolume()){
                    LeatherBackpack *temp = (LeatherBackpack *)getBackpack(j);
                    backpacks[j] = backpacks[j+1];
                    backpacks[j+1] = temp;
                }
            }

        }
    }

}

Backpack* List::FindBlueMaxVolumeBackpack(){
    LeatherBackpack *temp1;
    FabricBackpack *temp2;
    bool flag1 = false;
    bool flag2 = false;
    SortByVolume();
    for (int i = index; i >= 0; --i) {
        if (backpacks[i]->GetType() == 'L') {
            temp1 = (LeatherBackpack *) getBackpack(i);
            if (temp1->getcolor() == "Blue" ){
                PrintForm1();
                cout << endl;
                temp1->Print();
                cout << endl;
                flag1 = true;
                break;
            }
        }
        if (backpacks[i]->GetType() == 'F') {
            temp2 = (FabricBackpack *) getBackpack(i);
            if (temp2->getcolor() == "Blue" ){
                PrintForm2();
                cout << endl;
                temp2->Print();
                cout << endl;
                flag2 = true;
                break;
            }
        }

    }
    if (flag1){
        return temp1;
    }
    if (flag2 ){
        return temp2;
    } else{
        cout << "ERROR: Nothing found" << endl;
        return nullptr;
    }


}
