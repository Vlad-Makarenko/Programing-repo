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
    bool laptop_department; // 1 - yes; 0 - no.
    string color;
    int volume;
    Firm firm;
    Purpose enumPurpose;
public:
    Backpack();
    Backpack(int laptop_department,  string color, int volume, const Firm& firm, enum Purpose purpose);
    Backpack(const Backpack &copy);
    virtual ~Backpack();
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
    void Print();
    string toString() const;
    Backpack& SplitLineToObject(const string &object) const;
    Backpack& operator=(const Backpack& backpack) ;
};

bool operator==(const Backpack& A, const Backpack& B);

bool operator!=(const Backpack& A, const Backpack& B);

ostream & operator<<(ostream &out ,const Backpack& backpack);

istream & operator>>(istream &in, Backpack& backpack);

void PrintForm();



#endif //LAB23_BACKPACK_H
