//
// Created by Vlad on 20.04.2021.
//

#ifndef LAB23_CONTAINER_H
#define LAB23_CONTAINER_H

#include "Backpack.h"

bool predG(Backpack *a);

bool predS(Backpack *a);

bool functorT(Backpack* A, Backpack* B);

bool predM(Backpack *a);



template<typename T>
class List{
    vector<T*> backpacks;
public:
    List() = default;
    List(List &copy) = default;

    virtual ~List(){
        while (!backpacks.empty()){
            backpacks.pop_back();
        }
        backpacks.clear();
        backpacks.shrink_to_fit();
    }


    typedef typename std::vector<T*>::iterator iterator;

    iterator begin(){
        return backpacks.begin();
    }

    iterator end(){
        return backpacks.end();
    }

    void addBackpack( Backpack* backpack){
        this->backpacks.push_back(backpack->clone());
    }

    void addItem( T& item){
        this->backpacks.push_back(item);
    }

    vector<T*> getBackpack (){
        return this->backpacks;
    }



    void ShowAll(){
        for(Backpack *o : backpacks){
            o->Print();
            cout << endl;
        }
    }

    vector<LeatherBackpack*> FindGermanVelourBackpack(){
        vector<LeatherBackpack*> res;
        bool flag = true;
        auto iter = backpacks.begin();
        while (true) {
            iter = std::find_if(iter, this->backpacks.end(), predG);
            if(*iter == NULL){
                break;
            }
            flag = false;
            res.push_back((LeatherBackpack*)*iter);
            ((LeatherBackpack*)*iter)->Print();
            cout << endl;
            iter++;
        }
        if (flag){
            cout << "ERROR: Nothing found" << endl;
        }
        return res;
    }

    vector<LeatherBackpack*> FindSuedeNoLiningBackpack(){
        vector<LeatherBackpack*> res;
        bool flag = true;
        auto iter = backpacks.begin();
        while (*iter) {
            iter = std::find_if(iter, this->backpacks.end(), predS);
            if(*iter == NULL){
                break;
            }
            flag = false;
            ((LeatherBackpack*)*iter)->Print();
            cout << endl;
            res.push_back((LeatherBackpack*)*iter);
            iter++;
        }
        if (flag){
            cout << "ERROR: Nothing found" << endl;
        }
        return res;
    }

    Backpack* FindBlueMaxVolumeBackpack(){
        auto temp = getBackpack();
        std::sort(temp.begin(), temp.end(), functorT);
        std::reverse(temp.begin(), temp.end());

        auto iter = temp.begin();
        iter = std::find_if(iter, temp.end(), predM);
        if (iter == temp.end()) {
            cout << "ERROR: Nothing found" << endl;
        }
        if (((Backpack*)*iter)->GetType() == 'L') {
            PrintForm1();
            cout << endl;
            ((LeatherBackpack*)*iter)->Print();
            cout << endl;
        }
        else {
            PrintForm2();
            cout << endl;
            ((FabricBackpack*)*iter)->Print();
            cout << endl;
        }

        while (!temp.empty()) {
            temp.pop_back();
        }
        temp.clear();
        temp.shrink_to_fit();
        return ((Backpack*)*iter)->clone();
    }

    void SortByVolume(bool flag){
        std::sort(backpacks.begin(), backpacks.end(), functorT);
        if(!flag){
            std::reverse(backpacks.begin(), backpacks.end());
        }
    }



};

bool predG(Backpack *a)
{
    if (a->GetType() == 'L') {
        auto *Le = (LeatherBackpack *) a->clone();
        if (Le->getfirm().getCountry() == "Germany"
            && Le->getLeather() == VELOUR
            && Le->getpurpose() == URBAN) {
            delete Le;
            return true;
        } else {
            delete Le;
            return false;
        }
    } else{
        return false;
    }
}

bool predS(Backpack *a)
{
    if (a->GetType() == 'L') {
        auto *Le = (LeatherBackpack *) a->clone();
        if (Le->getLeather() == SUEDE && !Le->getlining()) {
            delete Le;
            return true;
        } else {
            delete Le;
            return false;
        }
    } else {
        return false;
    }
}

bool functorT(Backpack* A, Backpack* B){
    bool result = false;

    if (A->GetType() == 'L' && B->GetType() == 'L') {
        auto *temp1 = (LeatherBackpack *) A->clone();
        auto *temp2 = (LeatherBackpack *) B->clone();
        if (temp1->getvolume() < temp2->getvolume()) {
            result = true;
        }
        delete temp1;
        delete temp2;
    }
    if (A->GetType() == 'F' && B->GetType() == 'F') {
        auto *temp3 = (FabricBackpack *) A->clone();
        auto *temp4 = (FabricBackpack *) B->clone();
        if (temp3->getvolume() < temp4->getvolume()) {
            result = true;
        }
        delete temp4;
        delete temp3;
    }
    if (A->GetType() == 'F' && B->GetType() == 'L') {
        auto *temp3 = (FabricBackpack *) A->clone();
        auto *temp1 = (LeatherBackpack *) B->clone();
        if (temp3->getvolume() < temp1->getvolume()) {
            result = true;
        }
        delete temp1;
        delete temp3;
    }

    if (A->GetType() == 'L' && B->GetType() == 'F') {
        auto *temp1 = (LeatherBackpack *) A->clone();
        auto *temp3 = (FabricBackpack *) B->clone();
        if (temp1->getvolume() < temp3->getvolume()) {
            result = true;
        }
        delete temp1;
        delete temp3;
    }
    return result;
}

bool predM(Backpack *a)
{
    auto *Le = (LeatherBackpack*) a->clone();
    if(Le->getcolor() == "Blue"){
        delete Le;
        return true;
    } else{
        delete Le;
        return false;
    }
}

#endif //LAB23_CONTAINER_H
