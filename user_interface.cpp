//this is from new branch , branch
#include "user_interface.h"
#include "room.h"
#include "file_manager.h"
#include <conio.h>
#include "guest.h"
#include <ctime>

void displayMenu(int choice)
{
     system("cls"); // to clear the screen to redraw menu
     system("color 0B");
     time_t today=time(0);

     cout << endl;
     cout << endl;
     cout << endl;
     cout << endl;
     cout<<"today's date: "<<ctime(&today)<<endl;
     
     cout << setw(20) << "KLG management System" << setw(20) << endl;
     cout << setfill('-') << setw(40) << "-" << setfill(' ') << endl;
     cout << (choice == 1 ? ">" : " ") << "1.guest info " << endl;
     cout << (choice == 2 ? ">" : " ") << "2.display guest list" << endl;
     cout << (choice == 3 ? ">" : " ") << "3.Guest check out" << endl;
     cout << (choice == 4 ? ">" : " ") << "4.search user: " << endl;
     cout << (choice == 5 ? ">" : " ") << "exit(press 5): " << endl;
     cout << setfill('-') << setw(40) << "-" << setfill(' ') << endl;
}

string getName()
{
     string name; // declared locally
     bool valid = false;
     cout << "Enter your name: " << endl;
     

     while (!valid)
     {

          getline(cin, name);
          valid = true;

          if(name.empty()){
               cout<<"there's no name being entered "<<endl;
               valid=false;
               
          }

          for (int i = 0; i < name.size(); i++)
          {
               if (isdigit(name[i]))
               {
                    cout << "incorrect input!" << endl;
                    valid = false;
                    break; // stop the loop
               }
          }
     }
     return name;
}



void checkoutGuest(vector<guest> &user_data)
{

     int selector = 0;
     bool run = true;
     char kunci;

     while (run)
     {
          system("cls");
          cout << "GUEST CHECKOUT" << endl;
          cout << "press ESC to exit" << endl;

          // display
          for (int i = 0; i < user_data.size(); i++)
          {
               cout << (selector == i ? ">" : " ") << "NAME:" << user_data[i].getName() << " " << "ROOM:" << user_data[i].getRoom() << endl;
          }
          kunci = _getch(); // wait any kunci to be press

          if (kunci == -32 || kunci == 0)
          {
               kunci = getch(); // scrolling begun

               if (kunci == 72)
               {
                    if (selector > 0)
                         selector--;
               }
               else if (kunci == 80)
               {
                    if (selector < (user_data.size() - 1))
                         selector++;
               }
          }

          else if (kunci == 13)
          {
               if (user_data.empty())
               {
                    break;
               }
               char proceed;
               cout << "proceed?(Y/N)";
               cin >> proceed;
               if (towupper(proceed) == 'Y')
               {
                    cout << "checkout :" << user_data[selector].getName() << endl;
                    user_data.erase(user_data.begin() + selector);
                    SaveFile(user_data);
                    system("pause");
               }
               else if (towupper(proceed) == 'N')
               {
                    return;
               }
          }
          else if (kunci == 27)
          {
               run = false; // key=24 is ESC key
          }
     }

}


     /*for(int i=0;i<user_data.size();i++){
          user_data[i].display_info();
     }

     string room;
     cout<<"Enter room to checkout: "<<endl;
     cin>>room;
     for(int i=0;i<user_data.size();i++){
          //user_data[i].display_info(); //
          if(user_data[i].getRoom()==room){
               user_data.erase(user_data.begin()+i);

               SaveFile(user_data);
               cout<<"check out done!.."<<endl;
               system("pause");
               return;

          }

     }
     cout<<"room not found!"<<endl;

     system("pause");

     */

     void searchGuest(const vector<guest> &user_data){


     for (int i = 0; i < user_data.size(); i++)
     {
          user_data[i].display_info();
     }

     string room;

     bool found = false;
     while (!found)
     {
          cout << "enter room to find" << endl;
          cin >> room;

          for (int i = 0; i < user_data.size(); i++)
          {
               if (user_data[i].getRoom() == room)
               {
                    cout << "found the room!" << endl;
                    user_data[i].display_info();
                    // cout<<"name: "<<user_data[i].getName()<<endl;
                    // cout<<"Day stay: "<<user_data[i].getDay()<<endl;
                    // cout<<"price to pay:"<<user_data[i].getPrice()<<endl;

                    found = true;
                    //break;
               }
          }

          if (!found)
          {
               cout << "room not found..." << endl;
               break;
          }
     }

     system("pause");
     }


string getDate(){

     time_t start=time(0);

     return ctime(&start);

}