#ifndef BANKSYS_H
#define BANKSYS_H

#include <string>
using namespace std; 

const int DB_SIZE = 100;
const char* const LINE = "-------------------------------";

//System menus 
enum {MAIN = 0, LOGGEDIN};

//Main menu choices 
enum {CREATEACC = 1, LOGIN, MAIN_EXIT}; 

//Logged-in menu choices
enum {INFO = 1, CURRENTBAL, DEPOSIT, WITHDRAW, LOGOUT, LOGGEDIN_EXIT}; 

//HighCreditAccount 
enum {CHOICE_A = 1, CHOICE_B, CHOICE_C} ;
const string CREDIT_LEVEL[3] = {"A", "B", "C"}; 
const int CREDIT_INTER_RATES[3] = {7, 4, 2}; 

//Account types
enum {GENERIC = 0, NORMAL = 1, HIGH_CREDIT = 2}; 

const string ACC_TYPE_NAMES[] = {"Generic Account", "Normal Account", "High Credit Account"}; 

#endif 