#include <vector>
#include "guest.h"
#include "file_manager.h"
#include "user_interface.h"
#include "room.h"

#include <conio.h> // to user _getkey()


    
    // ... your main loop here

    int main()
{
     string name;
     int days;
     string room;
     int type;
     // int choice=0;
     vector<guest> user_data; // store user data in vector

     // before the program start we should load the data first from the file

     loadFile(user_data);

     // implemeting the scrolling effect

     int choice = 1;
     bool running = true;
     char key;

     while (running)
     {
          
          // we use function to replace the menu
          displayMenu(choice);

          key = _getch(); // wait any key to be pressed

          // 224 refer to special key
          if (key == -32 || key == 0)
          {

               key = _getch();

               // scrolling logic //
               // if (key == 72 && choice > 1) choice--; // Up Arrow
               // else if (key == 80 && choice < 5) choice++; // Down Arrow

               if (key == 72)
               { // up
                    if (choice > 1)
                         choice--;
               }
               else if (key == 80)
               { // down
                    if (choice < 5)
                         choice++;
               }
          }
          else if (key >= '1' && key <= '5')
          {
               choice = key - '0'; // to convert from '1' to 1
          }
          else if (key == '1')
               choice = 1;
          else if (key == '2')
               choice = 2;
          else if (key == '3')
               choice = 3;
          else if (key == '4')
               choice = 4;
          else if (key == '5')
               choice = 5;

          // if user hit enter ,enter =13

          if (key == 13)
          {
               // remember to put one at here too
               system("cls"); // its to clear the display menu in order to show workspace only

               if (choice == 1)
               {
                    ///////////get name///////////////
                    
                    name = getName();

                    /// entering room number///////////

                    validRoom(room);

                    room = addguestRoom(user_data);
                    type=roomType();
                    isTaken(user_data, room);

                    ////////////get day/////////////

                    cout << "enter how many days to stay: \n";
                    while (!(cin >> days))
                    {
                         cin.clear();
                         cin.ignore(1000, '\n');
                         cout << "invalid input" << endl;

                         // break;
                    }
                    cin.clear();
                    cin.ignore(1000, '\n'); // clear the enter buffer

                    string date;
                    date=getDate();
                    // cin.ignore();

                    ///VIP/////
                    /* char VIP;
                    cout<<"VIP GUEST (Y/N): ?"<<endl;
                    cin>>VIP;
                    toupper(VIP);
                    if(VIP=='Y'){
                         VIP vipguest(name,days,room);
                         user_data.push_back(vipguest);
                         //SaveFile(user_data);

                    }
                    else if(VIP=='N'){
                         guest newguest(name, days, room);
                    // newguest.display_info();

                    user_data.push_back(newguest); // we stored name,days,room in vector
                    //SaveFile(user_data);
                    }*/
                   

                    //change the constructor (name,days,room,date)
                    guest newguest(name,days,room,date,type);
                    user_data.push_back(newguest);

                    ///////////////////
                    // saving the data in the data base
                    SaveFile(user_data);
               }
               else if (choice == 2) //guest list
               {
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
               
                    cout << right << setw(30) << "KLG management hotel List" << setw(10) << endl;
                    for (int i = 0; i < user_data.size(); i++)
                    {
                         user_data[i].display_info();
                    }

                    system("pause"); // to make the list pause
               }
               else if (choice == 3)
               {

                    checkoutGuest(user_data);
               
               }
               else if (choice == 4)
               {

                    searchGuest(user_data);
               }
               else if (choice == 5)
               {
                    running = false;
               }
          }
     }
     cout << "alright thank you for coming!";
}

