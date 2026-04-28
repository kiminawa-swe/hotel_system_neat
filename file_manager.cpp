#include "file_manager.h"
#include "guest.h"
#include <fstream>


void SaveFile(const vector<guest> &user_data)
{
     // use ofstream ---> ouput file stream
     ofstream outFile("KLG_db.txt"); // saved the file name tool:outFile

     // for a good practice.. use outFile.is_open()
     if (outFile.is_open())
     {
          for (int i = 0; i < user_data.size(); i++)
          {
               outFile << user_data[i].getName() << "|" << user_data[i].getDay() << "|" << user_data[i].getRoom()<<"|"<<user_data[i].getDate()<<"|"<<user_data[i].getRoomType() << endl;
          }

          outFile.close(); // close the tool after used
     }
}

void loadFile(vector<guest> &user_data)
{

     // use ifstream ,input file stream
     ifstream inFile("KLG_db.txt"); // read the txt,or aka database

     if (!inFile)
     {
          cout << "no record found" << endl;
          return;
     }
     // 1.creating a temporary variable ,because c++ cant read whole user_data[i] at once
     string tempName, tempRoom,tempDate;
     // int tempDay;
     string tempDayStr;
     string tempTypeRoom;

     // 2.catch the pieces from the file(txt)

     // while(inFile >>tempName>>tempDay>>tempRoom){
     while (getline(inFile, tempName, '|'))
     { // remember getline only search char as delimiter, not string
          getline(inFile, tempDayStr, '|');
          getline(inFile, tempRoom,'|');
          getline(inFile,tempDate,'|');
          getline(inFile,tempTypeRoom);
          // 3.assemble the pieces into a guest object
          // its to call the constructor with the variable in it

          // check whether tempDayStr is empty or not, if empty, stoi will not work

          if (tempDayStr.empty())
          {
               continue; // continue will return back to the first loop ,
          }
          // convert back string to int
          int tempDay = stoi(tempDayStr);
          int tempRoomType=stoi(tempTypeRoom);
          guest newguest_file(tempName, tempDay, tempRoom,tempDate,tempRoomType);

          // 4.put the finished object into the vector

          user_data.push_back(newguest_file);
     }
}
