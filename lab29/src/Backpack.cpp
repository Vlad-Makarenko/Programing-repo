//
// Created by Vlad on 20.04.2021.
//

#include "Backpack.h"

//|------------------------FIRM------------------------|\\

Firm::Firm() : Name(), Country() {}

Firm::Firm(string Name,  string Country): Name(Name), Country(Country){}

Firm::Firm(const Firm &copy) : Name(copy.Name), Country(copy.Country) {}

Firm::~Firm() = default;

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

Backpack::Backpack() : laptop_department(false), color(), volume(0), firm(), enumPurpose(URBAN) {}

Backpack::Backpack(int laptop_department,  string color, int volume, const Firm& firm, enum Purpose purpose) :
        laptop_department(laptop_department), color(color), volume(volume), firm(firm), enumPurpose(purpose){}

Backpack::Backpack(const Backpack &copy) : laptop_department(copy.laptop_department), color(copy.color),
                                           volume(copy.volume), firm(copy.firm), enumPurpose(copy.enumPurpose) {}

Backpack:: ~Backpack()  = default;

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

ostream & operator<<(ostream &out ,const Backpack& backpack) {
    out.width(17);
    out  << backpack.getlaptop_department();
    out.width(15);
    out << backpack.getcolor();
    out.width(17);
    out << backpack.getvolume();
    out.width(18);
    out << backpack.getpurpose();
    out.width(15);
    out << backpack.getfirm().getName();
    out.width(18);
    out << backpack.getfirm().getCountry();
    return out;
}

bool operator>(const Backpack& A, const Backpack& B){
    bool result;
    if (A.getvolume() > B.getvolume() )
        result = true;
    else
        result = false;
    return result;
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

ostream & operator<<(ostream &out ,const LeatherBackpack& backpack){
    out.width(17);
    out  << backpack.getlaptop_department();
    out.width(15);
    out << backpack.getcolor();
    out.width(17);
    out << backpack.getvolume();
    out.width(18);
    out << backpack.getpurpose();
    out.width(15);
    out << backpack.getfirm().getName();
    out.width(18);
    out << backpack.getfirm().getCountry();
    out.width(16);
    out << backpack.getlining();
    out.width(16);
    out << backpack.getLeather();
    return out;
}

bool operator>(const LeatherBackpack& A, const LeatherBackpack& B){
    bool result;
    if (A.getvolume() > B.getvolume() )
        result = true;
    else
        result = false;
    return result;
}

bool operator==(const LeatherBackpack& A, const LeatherBackpack& B){
    bool  result = true;
    if (A.getlaptop_department() == B.getlaptop_department()
        && A.getcolor() == B.getcolor()
        && A.getvolume() == B.getvolume()
        && A.getpurpose() == B.getpurpose()
        && A.getfirm().getName() == B.getfirm().getName()
        && A.getfirm().getCountry() == B.getfirm().getCountry()
        && A.getlining() == B.getlining()
        && A.getLeather() == B.getLeather()){
        result &= true;
    }else{
        result &= false;
    }
    return result;
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



ostream & operator<<(ostream &out ,const FabricBackpack& backpack){
    out.width(17);
    out  << backpack.getlaptop_department();
    out.width(15);
    out << backpack.getcolor();
    out.width(17);
    out << backpack.getvolume();
    out.width(18);
    out << backpack.getpurpose();
    out.width(15);
    out << backpack.getfirm().getName();
    out.width(18);
    out << backpack.getfirm().getCountry();
    out.width(16);
    out << backpack.getwaterproof();
    out.width(16);
    out << backpack.getFabric();
    return out;
}

bool operator>(const FabricBackpack& A, const FabricBackpack& B){
    bool result = true;
    if (A.getvolume() > B.getvolume() )
        result = true;
    else
        result = false;
    return result;
}

bool operator==(const FabricBackpack& A, const FabricBackpack& B){
    bool  result = true;
    if (A.getlaptop_department() == B.getlaptop_department()
        && A.getcolor() == B.getcolor()
        && A.getvolume() == B.getvolume()
        && A.getpurpose() == B.getpurpose()
        && A.getfirm().getName() == B.getfirm().getName()
        && A.getfirm().getCountry() == B.getfirm().getCountry()
        && A.getwaterproof() == B.getwaterproof()
        && A.getFabric() == B.getFabric()){
        result &= true;
    }else{
        result &= false;
    }
    return result;
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

void PrintForm3(){
    PrintForm();
    cout.width(16);
    cout << "WP/Lining:";
    cout.width(16);
    cout << "Fabric/Leather:";
}