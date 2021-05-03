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


    for (int i = 0; i < this->Count; ++i) {
        temp[i] = this->backpacks[i];
    }
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

    for (int i = 0; i < Count - 1; ++i) {
        if(i < index){
            temp[i] = backpacks[i];
        } else{
            temp[i] = backpacks[i+1];
        }
    }

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
    if (fin.is_open()) {
        this->setCount(6);
        delete[] this->backpacks;
        fin >> *this;
    }else{
        cout << "ERROR: The file did not open!";
    }
    fin.close();
}

void List::WriteToFile(const string &path) {
    ofstream fout;
    fout.open(path);

    if (fout.is_open()){
        fout << *this;
    }else {
        cout << "ERROR: The file did not open!";
    }
    fout.close();
}

Backpack& List::operator[](const size_t index) const{
    if (index < Count){
        return *backpacks[index];
    } else{
        return *backpacks[0];
    }
}

size_t List::getcount() const {
    return this->Count;
}

ifstream & operator>>(ifstream &in, List& list){
    int LD;
    int volume;
    string color;
    int aim;
    string name;
    string country;

    delete [] list.backpacks;
    list.backpacks = new Backpack*[list.Count];
    for (int i = 0; i < list.Count; ++i) {
        list.backpacks[i] = new Backpack;
    }

    stringstream buffer;
    regex reg("^[0-1] [A-Z][a-z]* [0-9]{1,3} [0-2] [a-zA-Z.&]* [A-Z][a-zA-Z]*");
    for (int i = 0; i < list.getcount(); ++i) {

        in >> LD;
        in >> color;
        in >> volume;
        in >> aim;
        in >> name;
        in >> country;

        buffer << LD << " " << color << " " << volume << " " << aim << " " << name << " " << country;
        //cout << buffer.str() << endl;
        if (regex_match(buffer.str(), reg)) {
            list[i].setlaptop_department(LD);
            list[i].setcolor(color);
            list[i].setvolume(volume);
            switch (aim) {
                case 0:
                    list[i].setpurpose(URBAN);
                    break;
                case 1:
                    list[i].setpurpose(TACTICAL);
                    break;
                case 2:
                    list[i].setpurpose(TOURIST);
                    break;
                default:
                    break;
            }
            Firm firm(name, country);
            list[i].setfirm(&firm);
        }
        buffer.str("");
    }

    return in;
}

ostream & operator<<(ostream &out ,const List& list){
    for (int i = 0; i < list.getcount(); ++i) {
        out << list[i];
    }
    return out;
}

ofstream & operator<<(ofstream &out ,const List& list){
    for (int i = 0; i < list.getcount(); ++i) {
        out << list[i];
    }
    return out;
}


istream & operator>>(istream &in , List& list) {
    int count;
    cout << "Enter count of object: " << endl;
    cin >> count;
    list.setCount(count);
    list.backpacks = new Backpack*[count];
    for (int i = 0; i < count; ++i) {
        list.backpacks[i] = new Backpack;
    }
    for (int i = 0; i < count; ++i) {
        cin >> list[i];
    }
    return in;
}


//|---------------------------Наследник 1-------------------------|\\

LeatherBackpackList::LeatherBackpackList() : LeatherBackpacks(nullptr), Count(0) {}

LeatherBackpackList::LeatherBackpackList(const LeatherBackpackList &copy): Count(copy.Count) {
    LeatherBackpacks = new LeatherBackpack*[Count];
    for (int i = 0; i < Count; ++i) {
        LeatherBackpacks[i] = new LeatherBackpack(*copy.LeatherBackpacks[i]);
    }
}

LeatherBackpackList:: ~LeatherBackpackList() {
    for (int i = 0; i < Count; ++i) {
        delete LeatherBackpacks[i];
    }
    delete [] LeatherBackpacks;
}

void  LeatherBackpackList::setCount(const int count){
    this->Count = count;
}

LeatherBackpack& LeatherBackpackList::getLeatherBackpack(int index) const{
    if (index < Count){
        return *LeatherBackpacks[index];
    } else{
        return *LeatherBackpacks[0];
    }
}

void  LeatherBackpackList::addBackpack( LeatherBackpack& backpack){
    auto **temp = new LeatherBackpack*[Count + 1];
    for (int i = 0; i < Count; ++i) {
        temp[i] = LeatherBackpacks[i];
    }
    temp[Count] = &backpack;
    delete [] this->LeatherBackpacks;
    this->LeatherBackpacks = temp;
    this->Count++;
}

void LeatherBackpackList::ShowAll() const{
    for (int i = 0; i < this->Count; ++i) {
        LeatherBackpack temp = getLeatherBackpack(i);
        temp.Print();
        cout << endl;
    }
}

LeatherBackpack& LeatherBackpackList::FindGermanVelourBackpack(){
    LeatherBackpack *temp = new LeatherBackpack;
    bool flag = true;
    for (int i = 0; i < Count; ++i) {
        if ( getLeatherBackpack(i).getLeather() == VELOUR
            && getLeatherBackpack(i).getfirm().getCountry() == "Germany"
            && getLeatherBackpack(i).getpurpose() == URBAN){
            temp = &getLeatherBackpack(i);
            temp->Print();
            flag = false;
        }
    }
    if (flag){
        cout << "ERROR: Nothing found";
    }
    return *temp;
}

LeatherBackpack&  LeatherBackpackList::FindSuedeNoLiningBackpack(){
    LeatherBackpack *temp = new LeatherBackpack;
    bool flag = true;
    for (int i = 0; i < Count; ++i) {
        if ( getLeatherBackpack(i).getLeather() == SUEDE
             && getLeatherBackpack(i).getlining() == false){
            temp = &getLeatherBackpack(i);
            temp->Print();
            flag = false;
        }
    }
    if (flag){
        cout << "ERROR: Nothing found";
    }
    return *temp;
}

void LeatherBackpackList::SortByVolume() {
    for (int i = 0; i < Count; ++i) {
        for (int j = 0; j < Count - 1; ++j) {
            if (getLeatherBackpack(j).getvolume() > getLeatherBackpack(j + 1).getvolume()){
                LeatherBackpack temp = getLeatherBackpack(j);
                LeatherBackpacks[j] = LeatherBackpacks[j+1];
                LeatherBackpacks[j+1] = &temp;
            }

        }
    }
}

LeatherBackpack& LeatherBackpackList::FindBlueMaxVolumeBackpack(){
    LeatherBackpack *temp = new LeatherBackpack;
    SortByVolume();
    for (int i = 0; i < Count; ++i) {
        if ( getLeatherBackpack(i).getcolor() == "Blue"){
            temp = &getLeatherBackpack(i);
            break;
        }
    }
    return *temp;
}


//|---------------------------Наследник 2-------------------------|\\


FabricBackpackList::FabricBackpackList() : FabricBackpacks(nullptr), Count(0) {}

FabricBackpackList::FabricBackpackList(const FabricBackpackList &copy) : Count(copy.Count) {
    FabricBackpacks = new FabricBackpack *[Count];
    for (int i = 0; i < Count; ++i) {
        FabricBackpacks[i] = new FabricBackpack(*copy.FabricBackpacks[i]);
    }
}

FabricBackpackList:: ~FabricBackpackList() {
    for (int i = 0; i < Count; ++i) {
        delete FabricBackpacks[i];
    }
    delete [] FabricBackpacks;
}

void FabricBackpackList:: setCount(const int count){
    this->Count = count;
}

void FabricBackpackList::addBackpack(class FabricBackpack& backpack){
    auto **temp = new FabricBackpack*[Count + 1];
    for (int i = 0; i < Count; ++i) {
        temp[i] = FabricBackpacks[i];
    }
    temp[Count] = &backpack;
    delete [] FabricBackpacks;
    this->FabricBackpacks = temp;
    this->Count++;
}

FabricBackpack& FabricBackpackList::getFabricBackpack (int index) const{
    if(index < Count){
        return *this->FabricBackpacks[index];
    } else{
        return *this->FabricBackpacks[0];
    }
}

void FabricBackpackList:: ShowAll() const{
    for (int i = 0; i < this->Count; ++i) {
        FabricBackpack temp = getFabricBackpack(i);
        temp.Print();
        cout << endl;
    }
}

void FabricBackpackList::SortByVolume() {
    for (int i = 0; i < Count; ++i) {
        for (int j = 0; j < Count - 1; ++j) {
            if (getFabricBackpack(j).getvolume() > getFabricBackpack(j + 1).getvolume()){
                FabricBackpack temp = getFabricBackpack(j);
                FabricBackpacks[j] = FabricBackpacks[j+1];
                FabricBackpacks[j+1] = &temp;
            }

        }
    }
}

FabricBackpack& FabricBackpackList::FindBlueMaxVolumeBackpack(){
    FabricBackpack *temp = new FabricBackpack;
    SortByVolume();
    for (int i = 0; i < Count; ++i) {
        if ( getFabricBackpack(i).getcolor() == "Blue"){
            temp = &getFabricBackpack(i);
            break;
        }
    }
    return *temp;
}

//_____________________________________________________\\

void FindBlueMaxVolumeBackpack(FabricBackpack& fabricBackpack, LeatherBackpack& leatherBackpack){
    if(fabricBackpack.getcolor() != "" || leatherBackpack.getcolor() != "") {
        if (fabricBackpack.getvolume() > leatherBackpack.getvolume()) {
            PrintForm2();
            cout << endl;
            fabricBackpack.Print();
        } else if (fabricBackpack.getvolume() == leatherBackpack.getvolume()) {
            PrintForm2();
            cout << endl;
            fabricBackpack.Print();
            cout << endl << endl;
            PrintForm1();
            cout << endl;
            leatherBackpack.Print();
        } else if (fabricBackpack.getvolume() < leatherBackpack.getvolume()) {
            PrintForm1();
            cout << endl;
            leatherBackpack.Print();
        }
    } else {
        cout << "ERROR: Nothing found";
    }
}
