#ifndef GUEST_H    // "If Not Defined GUEST_H"
#define GUEST_H    // "Then Define GUEST_H"


//#pragma once
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class guest {
protected:
    string name;
    int days;
    string room;
    string date;
    int roomType;
    static const int PRICE = 100;

public:
    guest(string n, int d, string r,string dt,int ty);

    int getDay() const;

    string getName() const;

    int getPrice() const;

    string getRoom() const;

    string getDate() const;

    int getRoomType() const;
    
    void display_info() const;
};



#endif