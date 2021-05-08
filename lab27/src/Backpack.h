//
// Created by Vlad on 20.04.2021.
//

#ifndef LAB23_BACKPACK_H
#define LAB23_BACKPACK_H

#include <string>
#include <sstream>
#include <cstring>
#include <iostream>
#include <fstream>
#include <regex>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::stringstream;
using std::ifstream;
using std::ofstream;
using std::ostream;
using std::istream;
using std::regex_match;
using std::regex;
using std::stoi;

#define ARRAY_SIZE 255

enum Purpose{
    URBAN,
    TACTICAL,
    TOURIST
};

class Firm{
    string Name;
    string Country;
public:
    Firm();
    Firm(string Name,  string Country);
    Firm(const Firm &copy);
    virtual ~Firm();
    string getName() const;
    string getCountry() const;
    void setName(const string &name);
    void setCountry(const string &country);
    void Print();
};

class Backpack{
public:
    virtual void Print() = 0;
    virtual Backpack* clone() = 0;
    virtual ~Backpack() {}
    virtual char GetType() = 0;
};


//|--------------------Наследник 1--------------------|\\

enum Type {
    ANILINE, VELOUR, SUEDE
};

class LeatherBackpack : public Backpack {
    bool laptop_department; // 1 - yes; 0 - no.
    string color;
    int volume;
    Firm firm;
    Purpose enumPurpose;
    bool lining;
    Type Leather;
public:
    LeatherBackpack();
    LeatherBackpack(int laptop_department,  string color, int volume, const Firm& firm, enum Purpose purpose, bool  lining, Type leather);


    int getlaptop_department() const;
    string getcolor() const;
    int getvolume() const;
    Firm getfirm() const;
    Purpose getpurpose() const;
    void setlaptop_department(const int laptop_department);
    void setcolor(const string color);
    void setvolume( const int volume);
    void setfirm(Firm *firm1);
    void setpurpose(const Purpose purpose);
    virtual ~LeatherBackpack();
    bool getlining() const;
    Type getLeather() const;
    void setlining(const bool lining);
    void setLeather(const Type Leather);
    void Print() override;
    Backpack *clone() override;
    char GetType() override;

};

//|--------------------Наследник 2--------------------|\\

enum Fabric {
    SYNTHETICS, COTTON, TARP
};

class FabricBackpack : public Backpack {
    bool laptop_department; // 1 - yes; 0 - no.
    string color;
    int volume;
    Firm firm;
    Purpose enumPurpose;
    bool waterproof;
    Fabric fabric;
public:
    FabricBackpack();
    FabricBackpack(int laptop_department,  string color, int volume, const Firm& firm, enum Purpose purpose, bool waterproof, Fabric fabric);

    virtual ~FabricBackpack();

    int getlaptop_department() const;
    string getcolor() const;
    int getvolume() const;
    Firm getfirm() const;
    Purpose getpurpose() const;
    void setlaptop_department(const int laptop_department);
    void setcolor(const string color);
    void setvolume( const int volume);
    void setfirm(Firm *firm1);
    void setpurpose(const Purpose purpose);
    bool getwaterproof() const;
    Fabric getFabric() const;
    void setwaterproof(const bool waterproof);
    void setfabric(const Fabric fabric);
    void Print() override;
    Backpack *clone() override;
    char GetType() override;

};


void PrintForm();

void PrintForm1();

void PrintForm2();

void PrintForm3();

#endif //LAB23_BACKPACK_H
