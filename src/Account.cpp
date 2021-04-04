#include "Account.h" 
#include "BANKSYS.h"
#include <iostream> 
#include <cstring>
#include <algorithm>

using namespace std; 

Account::Account(int uID, int uBal, const char* uOwner, int uType) 
	: accountID(uID), accountBalance(uBal), accountType(uType)
{
	accountOwner = new char[strlen(uOwner) + 1]; 
	strcpy(accountOwner, uOwner); 
	// cout << accountOwner << "'s account created!" << endl;  
}

Account::~Account()
{
	//cout << accountOwner <<"'s account deleted!" << endl; 
	delete []accountOwner; 
}

char* Account::getAccountOwner() const
{ 
	return accountOwner; 
}

char* Account::setAccountOwner(const char* uNewName)  
{
	delete []accountOwner; 
	accountOwner = new char[strlen(uNewName) + 1]; 
	strcpy(accountOwner, uNewName); 
	// cout << "Account owner successfully changed to: "  << accountOwner << endl;
	// cout << "---------------------------------" << endl; 
	return accountOwner; 
}

int Account::getAccountID() const{
	return accountID;
}

int Account::setAccountID(const int uNewID) {
	accountID = uNewID; 
	return accountID; 
}

int Account::getAccountBalance() const{
	return accountBalance; 
}

int Account::setAccountBalance(const int uNewBalance) {
	accountBalance = uNewBalance; 
	return accountBalance; 
}

int Account::getType() const
{
	return accountType; 
}

int Account::deposit(int amount)
{
	accountBalance += amount; 
	return accountBalance; 
}

int Account::withdraw(int amount){
	max(0, accountBalance -= amount); 
	return accountBalance; 
}
