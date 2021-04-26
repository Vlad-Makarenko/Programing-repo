//
// Created by Vlad on 20.04.2021.
//

#include "Backpack.h"

//|------------------------FIRM------------------------|\\

Firm::Firm() : Name(), Country() {
    //cout << "\ndefault constructor <Firm> " << endl;
}

Firm::Firm(string Name,  string Country): Name(Name), Country(Country){
    //cout << "\nConstructor with arguments <Firm> " << endl;
}

Firm::Firm(const Firm &copy) : Name(copy.Name), Country(copy.Country) {
    //cout << "\nCopy constructor <Firm> " << endl;
}

Firm::~Firm() = default; // {
    //cout << "\nDestructor <Firm>" << endl;
//}

string Firm::getName() const {
    return this->Name;
}

string  Firm::getCountry() const {
    return this->Country;
}

void Firm::setName(const string &name){
    this->Name = name;
}

void Firm::setCountry(const string &country) {
    this->Country = country;
}

void Firm::Print(){
    cout << Name;
    cout.width(18);
    cout << Country << endl;
}

//|------------------------BACKPACK------------------------|\\

Backpack::Backpack() : laptop_department(false), color(), volume(0), firm(), enumPurpose(URBAN) {
   // cout << "\nDefault constructor <Backpack>" << endl;
}

Backpack::Backpack(int laptop_department,  string color, int volume, const Firm& firm, enum Purpose purpose) :
        laptop_department(laptop_department), color(color), volume(volume), firm(firm), enumPurpose(purpose){
   // cout << "\nConstructor with arguments <Backpack>" << endl;
} //!!!!!

Backpack::Backpack(const Backpack &copy) : laptop_department(copy.laptop_department), color(copy.color),
                                 volume(copy.volume), firm(copy.firm), enumPurpose(copy.enumPurpose) {
    //cout << "\nCopy constructor <Backpack>" << endl;
}

Backpack:: ~Backpack()  = default; //{
    //cout << "\nDestructor <Backpack>" << endl;
//}

int Backpack::getlaptop_department() const {
    return this->laptop_department;
}

string Backpack:: getcolor() const {
    return this->color;
}

int Backpack:: getvolume() const {
    return this->volume;
}

Firm Backpack:: getfirm() const {
    return this->firm;
}

Purpose Backpack:: getpurpose() const {
    return this->enumPurpose;
}

void Backpack:: setlaptop_department(const int laptop_department)  {
    this->laptop_department = laptop_department;
}

void Backpack:: setcolor(const string color) {
    this->color = color;
}

void Backpack:: setvolume( const int volume) {
    this->volume = volume;
}

void Backpack:: setfirm(Firm *firm1) {
    firm.setName(firm1->getName());
    firm.setCountry(firm1->getCountry());
}

void Backpack:: setpurpose(const Purpose purpose) {
    this->enumPurpose = purpose;
}

void Backpack:: Print(){

    cout.width(17);
    cout  << laptop_department;
    cout.width(15);
    cout << color;
    cout.width(17);
    cout << volume;
    cout.width(18);
    cout << enumPurpose;
    cout.width(15);
    firm.Print();
}

string Backpack::toString() const {
    stringstream result;
    result << getlaptop_department() << " " << getcolor() << " " << getvolume() << " " << getpurpose() << " "
            << getfirm().getName() << " " << getfirm().getCountry() << endl;
    return result.str();
}

Backpack& Backpack::SplitLineToObject(const string &object) const{
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
                        pos = buffer.find('\r');
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

void PrintForm(){
    cout.width(10);
    cout << "Place for laptop:";
    cout.width(15);
    cout << "Color:";
    cout.width(18);
    cout <<" Volume: ";
    cout.width(18);
    cout << "Purpose: ";
    cout.width(15);
    cout << "Firm: ";
    cout.width(17);
    cout << " Country:" << endl;
}