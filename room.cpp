//testing merge branch
#include "room.h"
#include <iostream>
#include "guest.h"


bool validRoom(string room)
{

     return room.size() == 4;
}

bool isTaken(const vector<guest> &user_data, string room)
{
     for (int i = 0; i < user_data.size(); i++)
     {
          if (user_data[i].getRoom() == room)
          {
               cout << "this room already occupied! " << endl;
               return true;
               // break;
          }
     }
     return false;
}

string addguestRoom(const vector<guest> &user_data)
{
     string room;
     do
     {
          cout << "enter room number: \n";
          cin >> room;
     } while (!validRoom(room) || isTaken(user_data, room));

     return room;
}

int roomType(){

     int roomType;
     cout<<"Room type: "<<endl;
     cout<<"1.Normal "<<endl;
     cout<<"2.Luxury "<<endl;
     cout<<"3.Deluxe "<<endl;
     cout<<"enter(1,2 or 3)"<<endl;
     cin>>roomType;

     return roomType;
}
