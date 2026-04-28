#pragma once
#include <vector>
#include "guest.h"

bool validRoom(string room);
bool isTaken(const vector<guest>& user_data, string room);
string addguestRoom(const vector<guest>& user_data);
//room type
int roomType();
