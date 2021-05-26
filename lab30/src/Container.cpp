//
// Created by Vlad on 20.04.2021.
//



#include "Container.h"


List::List() {}

List::List(List &copy) :index(copy.index), backpacks(copy.backpacks) {}

List::~List(){
    while (!backpacks.empty()){
        backpacks.pop_back();
    }
    backpacks.clear();
    backpacks.shrink_to_fit();
}


void List::DeleteAll(){
    while (!backpacks.empty()){
        backpacks.pop_back();
    }
    backpacks.clear();
    backpacks.shrink_to_fit();
    index = -1;
}


void List::addBackpack(Backpack *backpack) {
    index += 1;
    if (index >= 255) {
        return;
    }
    this->backpacks.push_back(backpack->clone());
}


vector<Backpack*> List::getBackpack(){
    return this->backpacks;
}

void List::ShowAll(){
    for (int i = 0; i <= this->index; ++i) {
        backpacks[i]->Print();
        cout << endl;
    }
}

void List::DeleteElement(int index){
    if (index > backpacks.size()){
        index = backpacks.size();
    } else if(index < 0){
        index = 0;
    }
    vector<Backpack*>::iterator pos = backpacks.begin() + index;
    backpacks.erase(pos);
    this->index--;
}


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

vector<LeatherBackpack*> List::FindGermanVelourBackpack(){
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

bool predS(Backpack *a)
{
    if (a->GetType() == 'L') {
        auto *Le = (LeatherBackpack *) a->clone();
        if (Le->getLeather() == SUEDE && Le->getlining() == false) {
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

vector<LeatherBackpack*>  List::FindSuedeNoLiningBackpack(){
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

bool functorF(Backpack* A, Backpack* B){
    bool result = false;
    if (A->GetType() == 'L' && B->GetType() == 'L') {
        auto *temp1 = (LeatherBackpack *) A->clone();
        auto *temp2 = (LeatherBackpack *) B->clone();
        if (temp1->getvolume() > temp2->getvolume()) {
            result = true;
        }
        delete temp1;
        delete temp2;
    }
    if (A->GetType() == 'F' && B->GetType() == 'F') {
        auto *temp3 = (FabricBackpack *) A->clone();
        auto *temp4 = (FabricBackpack *) B->clone();
        if (temp3->getvolume() > temp4->getvolume()) {
            result = true;
        }
        delete temp3;
        delete temp4;
    }
    if (A->GetType() == 'F' && B->GetType() == 'L') {
        auto *temp3 = (FabricBackpack *) A->clone();
        auto *temp1 = (LeatherBackpack *) B->clone();
        if (temp3->getvolume() > temp1->getvolume()) {
            result = true;
        }
        delete temp1;
        delete temp3;
    }

    if (A->GetType() == 'L' && B->GetType() == 'F') {
        auto *temp1 = (LeatherBackpack *) A->clone();
        auto *temp3 = (FabricBackpack *) B->clone();
        if (temp1->getvolume() > temp3->getvolume()) {
            result = true;
        }
        delete temp1;
        delete temp3;
    }

    return result;
}

void List::SortByVolume(bool flag) {
    if (flag) {
        std::sort(backpacks.begin(), backpacks.end(), functorT);
    } else{
        std::sort(backpacks.begin(), backpacks.end(), functorF);
    }
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

Backpack*  List::FindBlueMaxVolumeBackpack(){
    vector<Backpack*> temp;
    temp.reserve(this->backpacks.size());
    std::copy(this->backpacks.begin(), this->backpacks.end(), std::back_inserter(temp));
    std::sort(temp.begin(), temp.end(), functorF);
    auto iter = temp.begin();
    iter = std::find_if(iter, temp.end(), predM);
    if(*iter == NULL){
        cout << "ERROR: Nothing found" << endl;
    }
    if ( ((Backpack*)*iter)->GetType() == 'L' ){
        PrintForm1();
        cout << endl;
        ((LeatherBackpack*)*iter)->Print();
        cout << endl;
    } else{
        PrintForm2();
        cout << endl;
        ((FabricBackpack*)*iter)->Print();
        cout << endl;
    }

    while (!temp.empty()){
        temp.pop_back();
    }
    temp.clear();
    temp.shrink_to_fit();
    return ((Backpack*)*iter)->clone();
}

void List::InsertList(List &in) {
    this->backpacks.reserve(this->index + in.index);
    auto iter = this->backpacks.end();
    for (int i = 0; i < in.index; ++i) {
        this->backpacks.insert(iter + i, in.backpacks[i]);
    }
    this->index += in.index;

}


//------------------------------------------------\\

void ShowMap(const map<string, set<string>>& m3){
    std::for_each(m3.begin(), m3.end(), [&](const std::pair<string, set<string>>& pair){
        auto iter = pair.first;
        cout.width(20);
        cout << iter << ": ";
        cout.width(5);
        for(const auto &elem: pair.second){
            if (m3.rbegin()->first == pair.first && pair.second.upper_bound(elem) == pair.second.end()) {
                cout << elem << ".";
            } else if(pair.second.upper_bound(elem) == pair.second.end()) {
                cout << elem << ";";
            } else{
                cout << elem << ", ";
            }
        }
        cout << endl;
    });
}

void ExcellentTask(){
    map<string, set<string>> m1, m2, m3;

    m1 = {
            { "Ukraine", { "Kharkiv", "Kiev" } },
            { "Russia", { "Moscow", "Belgorod" } },
            { "Belarus", { "Minsk", "Bobruysk" } },
    };
    m2 = {
            { "Poland", {  "Warsaw" } },
            { "Russia", { "St. Petersburg" } },
            { "Ukraine", { "Kharkiv", "Zaporizhya" } },
    };
    m3 = m1;

    std::for_each(m2.begin(), m2.end(), [&](const std::pair<string, set<string>>& pair){
        auto iter = m3.find(pair.first);
        if(iter == m3.end()){
            m3.insert(pair);
        } else{
            iter->second.insert(pair.second.begin(), pair.second.end());
        }
    });

    cout.width(12);
    cout << "Map 1:" << endl;
    ShowMap(m1);
    cout << endl;

    cout.width(12);
    cout << "Map 2:" << endl;
    ShowMap(m2);
    cout << endl;

    cout.width(12);
    cout << "Result map:" << endl;
    ShowMap(m3);
    cout << endl;

}