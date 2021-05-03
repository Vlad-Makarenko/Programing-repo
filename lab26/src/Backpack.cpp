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
    cout << Country;
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
    //stringstream buf;
    int flag = 0;
    int pos = 0;
    auto *temp = new Backpack;
    int len = object.length();
    for (int i = 0; i < len; ++i) {
        if(object[i] == ' '){
            if (flag == 0){
                pos = buffer.find(' ');
                str = buffer.substr(0, pos);
                int LD = stoi(str);
                temp->setlaptop_department(LD);
                buffer.erase(0, pos + 1);
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
                int vol = stoi(str);
                temp->setvolume(vol);
                buffer.erase(0, pos + 1);
                flag++;
            } else if (flag == 3){
                pos = buffer.find(' ');
                str = buffer.substr(0, pos);
                int aim = stoi(str);
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
                buffer.erase(0, pos + 1);
                flag++;
            }else if(flag == 4){
                for (int j = 0; j < buffer.length(); ++j) {
                    if(buffer[j] == ' '){
                        pos = buffer.find(' ');
                        string name = buffer.substr(0, pos);
                        buffer.erase(0, pos + 1);
                        pos = buffer.find('\r');
                        string country = buffer.substr(0);
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

Backpack& Backpack::operator=(const Backpack &backpack) {
    if(this != &backpack){
        setlaptop_department(backpack.getlaptop_department());
        setvolume(backpack.getvolume());
        setcolor(backpack.getcolor());
        setpurpose(backpack.getpurpose());
        Firm firm1(backpack.getfirm().getName(), backpack.getfirm().getCountry());
        setfirm (&firm1);
    }
    return *this;
}

bool operator==(const Backpack& A, const Backpack& B){
    bool  result = true;
    if (A.getlaptop_department() == B.getlaptop_department()
        && A.getcolor() == B.getcolor()
        && A.getvolume() == B.getvolume()
        && A.getpurpose() == B.getpurpose()
        && A.getfirm().getName() == B.getfirm().getName()
        && A.getfirm().getCountry() == B.getfirm().getCountry()){
        result &= true;
    }else{
        result &= false;
    }
    return result;
}

bool operator!=(const Backpack& A, const Backpack& B){
    return !(A == B);
}

ostream & operator<<(ostream &out ,const Backpack& backpack){
    out.width(17);
    out << backpack.getlaptop_department();
    out.width(15);
    out << backpack.getcolor();
    out.width(17);
    out << backpack.getvolume();
    out.width(18);
    out << backpack.getpurpose();
    out.width(15);
    out << backpack.getfirm().getName();
    out.width(18);
    out << backpack.getfirm().getCountry() << endl;
    return out;
}

istream & operator>>(istream &in, Backpack& backpack){
    int LD;
    int volume;
    string color;
    int aim;
    string name;
    string country;
    cout << "Enter the data in this order: PlaceFofLaptop Color Volume Aim Name Country\n";
    in >> LD;
    in >> color;
    in >> volume;
    in >> aim;
    in >> name;
    in >> country;

    stringstream buffer;
    buffer << LD << " " << color << " " << volume << " " << aim << " " << name << " " << country;
    regex reg("^[0-1] [A-Z][a-z]* [0-9]{1,3} [0-2] [a-zA-Z.&]* [A-Z][a-zA-Z]*");

    if(regex_match(buffer.str(), reg)) {
        backpack.setlaptop_department(LD);
        backpack.setcolor(color);
        backpack.setvolume(volume);
        switch (aim) {
            case 0:
                backpack.setpurpose(URBAN);
                break;
            case 1:
                backpack.setpurpose(TACTICAL);
                break;
            case 2:
                backpack.setpurpose(TOURIST);
                break;
            default:
                break;
        }
        Firm firm(name, country);
        backpack.setfirm(&firm);
        return in;
    }else {
        cout << "ERROR: invalid text" << endl;
        in.clear();
        return in;
    }
}

//|------------------------Наследний 1---------------------|\\

LeatherBackpack::LeatherBackpack(): Backpack(), lining(false), Leather(VELOUR) {}

LeatherBackpack::LeatherBackpack(int laptop_department,  string color, int volume, const Firm& firm, enum Purpose purpose,
                                         bool  lining, Type leather) : Backpack(laptop_department, color, volume, firm, purpose),
                                         lining(lining), Leather(leather) {}

LeatherBackpack::LeatherBackpack(LeatherBackpack& copy): Backpack(copy.getlaptop_department(), copy.getcolor(), copy.getvolume(),
                                                                  copy.getfirm(), copy.getpurpose()),
                                                                  lining(copy.lining), Leather(copy.Leather){}

LeatherBackpack:: ~LeatherBackpack() = default;

bool LeatherBackpack::getlining() const {
    return this->lining;
}

Type LeatherBackpack::getLeather() const{
    return this->Leather;
}

void LeatherBackpack::setlining(const bool lining){
    this->lining = lining;
}

void LeatherBackpack::setLeather(const Type Leather){
    this->Leather = Leather;
}

void LeatherBackpack::Print(){
    Backpack::Print();
    cout.width(16);
    cout << lining;
    cout.width(16);
    cout << Leather;
}

//|------------------------Наследний 2---------------------|\\

FabricBackpack::FabricBackpack() : Backpack(), waterproof(false), fabric(SYNTHETICS){}

FabricBackpack::FabricBackpack(int laptop_department,  string color, int volume, const Firm& firm,
               enum Purpose purpose,bool waterproof, Fabric fabric) : Backpack(laptop_department, color, volume, firm, purpose),
                                                                      waterproof(waterproof), fabric(fabric) {};

FabricBackpack::FabricBackpack(FabricBackpack& copy) : Backpack(copy.getlaptop_department(), copy.getcolor(), copy.getvolume(),
                                                                copy.getfirm(), copy.getpurpose()),
                                                       waterproof(copy.waterproof), fabric(copy.fabric){}

FabricBackpack:: ~FabricBackpack() = default;

bool FabricBackpack:: getwaterproof() const{
    return this->waterproof;
}

Fabric FabricBackpack:: getFabric() const{
    return this->fabric;
}

void FabricBackpack:: setwaterproof(const bool waterproof){
    this->waterproof = waterproof;
}

void FabricBackpack:: setfabric(const Fabric fabric){
    this->fabric = fabric;
}
void FabricBackpack::Print() {
    Backpack::Print();
    cout.width(16);
    cout << waterproof;
    cout.width(16);
    cout << fabric;
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
    cout << " Country:";
}

void PrintForm1(){
    PrintForm();
    cout.width(16);
    cout << "Lining:";
    cout.width(16);
    cout << "Leather:";
}

void PrintForm2(){
    PrintForm();
    cout.width(16);
    cout << "Waterproof:";
    cout.width(16);
    cout << "Fabric:";
}