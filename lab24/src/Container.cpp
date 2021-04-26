//
// Created by Vlad on 20.04.2021.
//



#include "Container.h"


List::List() : backpacks(nullptr), Count(0) {}

List::List(const List &copy) : Count(copy.Count){
    backpacks = new Backpack*[Count];
    for (int i = 0; i < Count; ++i) {
        backpacks[i] = new Backpack(*copy.backpacks[i]);
    }
}

void List::setCount(const int count) {
    this->Count = count;
}

List::~List(){
    //cout << "\nDestructor <List>" << endl;
    for (int i = 0; i < this->Count; ++i) {
        delete this->backpacks[i];
    }
    delete[] backpacks;

}

void List::addBackpack(Backpack &backpack) {
    auto **temp = new Backpack*[this->Count + 1];

    memcpy(temp, backpacks, sizeof(Backpack) * Count);
//    memcpy(temp + Count, *backpack, sizeof(Backpack));
//    for (int i = 0; i < this->Count; ++i) {
//        temp[i] = this->backpacks[i];
//    }
    temp[Count] = &backpack;

    delete [] this->backpacks;
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

Backpack& List::SplitLineToObject(const string &object) const{
    string buffer = object;
    string str;
    stringstream buf;
    int flag = 0;
    int pos = 0;
    auto *temp = new Backpack;
    int len = object.length();
    for (int i = 0; i < len; ++i) {
        if(object[i] == ' '){
            if (flag == 0){
                pos = buffer.find(' ');
                str = buffer.substr(0, pos);
                int LD;
                buf << str;
                buf >> LD;
                temp->setlaptop_department(LD);
                buffer.erase(0, pos + 1);
                buf.clear();
                flag++;
                pos = i;
            }else if (flag == 1){
                pos = buffer.find(' ');
                str = buffer.substr(0, pos);
                temp->setcolor(str);
                buffer.erase(0, pos + 1);
                flag++;
            }else if (flag == 2) {
                pos = buffer.find(' ');
                str = buffer.substr(0, pos);
                int vol;
                buf << str;
                buf >> vol;
                temp->setvolume(vol);
                buffer.erase(0, pos + 1);
                buf.clear();
                flag++;
            } else if (flag == 3){
                pos = buffer.find(' ');
                str = buffer.substr(0, pos);
                int aim;
                buf << str;
                buf >> aim;
                switch (aim) {
                    case 0:
                        temp->setpurpose(URBAN);
                        break;
                    case 1:
                        temp->setpurpose(TACTICAL);
                        break;
                    case 2:
                        temp->setpurpose(TOURIST);
                    default:
                        break;
                }
                buf.clear();
                buffer.erase(0, pos + 1);
                flag++;
            }else if(flag == 4){
                //str = buffer.substr(0);
                for (int j = 0; j < buffer.length(); ++j) {
                    if(buffer[j] == ' '){
                        pos = buffer.find(' ');
                        string name = buffer.substr(0, pos);
                        buffer.erase(0, pos + 1);
                        pos = buffer.find(' ');
                        string country = buffer.substr(0, pos);
                        Firm *firm = new Firm(name, country);
                        temp->setfirm(firm);
                        break;
                    }
                }
                break;
            }
        }
    }
    return *temp;
}

//void List::ReadFromFile(string &path) {
//    ifstream fin;
//    fin.open(path);
//    string obj;
//    int LD;
//    int volume;
//    int aim;
//    string name;
//    string country;
//    string color;
//    Purpose purpose;
//
//    this->setCount(0);
//    this->backpacks = new Backpack*[6];
//    if (!fin.is_open()) {
//        cout << "ERROR: The file did not open!" << endl;
//    } else {
//        for (int i = 0; i < 6; ++i) {
//            fin >> LD >> color >> volume >> aim >> name >> country;
//            switch (aim) {
//                case 0:
//                    purpose = URBAN;
//                    break;
//                case 1:
//                    purpose = TACTICAL;
//                    break;
//                case 2:
//                    purpose = TOURIST;
//                default:
//                    break;
//            }
//            Backpack backpack(LD, color, volume, Firm(name, country), purpose);
//            this->backpacks[i] = &backpack;
//            Count++;
//            //this->addBackpack(backpack);
//        }
//    }
//    //this->ShowAll();
//
//    fin.close();
//}

void List::ReadFromFile(const string &path) {

    ifstream fin;
    fin.open(path);
    string obj;

    this->setCount(6);
    delete [] this->backpacks;
    this->backpacks = new Backpack*[Count];
    for (int i = 0; i < Count; ++i) {
        if (!fin.is_open()) {
            cout << "ERROR: The file did not open!" << endl;
        } else {
            getline(fin, obj);
            this->backpacks[i] = &this->SplitLineToObject(obj);
        }
    }
    //this->ShowAll();

    fin.close();
}

void List::WriteToFile(const string &path) {
    ofstream fout;
    fout.open(path);

    for (int i = 0; i < Count; ++i) {
        if (!fout.is_open()) {
            cout << "ERROR: The file did not open!" << endl;
        } else {
            fout << this->getBackpack(i).toString();
        }
    }


    fout.close();
}

//void List::Print() {
//    for (int i = 0; i < this->Count; ++i) {
//        Backpack *temp = this->backpacks[i];
//        temp->Print();
//    }
//}