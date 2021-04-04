#include "NormalAccount.h" 
#include "BANKSYS.h"
#include <iostream> 

using namespace std; 

NormalAccount::NormalAccount(int uID, int uBal, const char* uOwner, int uRate, int uType) :
	Account(uID, uBal, uOwner, uType), accountRate(uRate) {};

NormalAccount::NormalAccount(int uID, int uBal, const char* uOwner, int uRate) : 
	Account(uID, uBal, uOwner, NORMAL), accountRate(uRate) {};


NormalAccount::~NormalAccount() {}; 

int NormalAccount::deposit(int amount)
{
	int weightedAmount = amount + amount*accountRate/100; 
	Account::deposit(weightedAmount); 
	return getAccountBalance(); 
}

void NormalAccount::showAccountInfo() const
{
	cout << "Normal Account Info" << endl; 
	cout << LINE << endl; 
	cout << "> Account ID: " << getAccountID() << endl;
	cout << "> Account Type: " << ACC_TYPE_NAMES[getType()] << endl; 
	cout << "> Account Owner: " << getAccountOwner() << endl; 
	cout << "> Interest Rate: " << accountRate << "%" << endl; 
	cout << "> Remaining Balance: $" << getAccountBalance() << endl; 
	cout << LINE << endl; 
	return; 
}

int NormalAccount::getRate() const 
{
	return accountRate; 
}

