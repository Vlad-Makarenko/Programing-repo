//
// Created by Vlad on 20.04.2021.
//

#ifndef LAB23_BACKPACK_H
#define LAB23_BACKPACK_H

#include <string>
#include <cstring>
#include <iostream>
using std::string;
using std::cin;
using std::cout;
using std::endl;

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
};

void PrintForm();



#endif //LAB23_BACKPACK_H
