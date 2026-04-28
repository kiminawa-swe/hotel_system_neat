#pragma once
#include <vector>
#include <ctime>
#include "guest.h"

void displayMenu(int choice);
string getName();
void checkoutGuest(vector<guest>& user_data);
void searchGuest(const vector<guest> &user_data);
string getDate();

