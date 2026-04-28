#include "guest.h"

guest::guest(string n, int d, string r,string dt,int ty) : name(n), days(d), room(r), date(dt),roomType(ty){}

int guest::getDay() const {
     return days; }

string guest::getName() const {
     return name; }

int guest::getPrice() const {
     if(getRoomType()==1){
     return days * PRICE;     
     }
     else if(getRoomType()==2){
     return days * PRICE *1.5;     
     }
     else if(getRoomType()==3){
     return days * PRICE*2;
     }

     return days* PRICE;

      }
 
string guest::getRoom() const {
     return room; }

string guest::getDate() const{
    return date;
}

int guest::getRoomType()const{
     return roomType;
}

void guest::display_info() const {
    cout << setfill('-') << setw(40) << "-" << setfill(' ') << endl;
    cout << "Guest name: " << name << endl;
    cout << "Room: " << room << endl;
    cout << "Total: RM" << getPrice() << endl;
    cout <<"Date check in: "<<getDate()<<endl;
    cout << setfill('-') << setw(40) << "-" << setfill(' ') << endl;
}

