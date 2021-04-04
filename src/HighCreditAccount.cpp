#include "HighCreditAccount.h" 
#include "BANKSYS.h"

#include <iostream>

using namespace std; 

HighCreditAccount::HighCreditAccount(int uID, int uBal, 
	const char* uOwner, int uRate, int uType, int uCredit)
	: NormalAccount(uID, uBal, uOwner, uRate, uType), creditLevel(uCredit) {}; 

HighCreditAccount::HighCreditAccount(int uID, int uBal, 
	const char* uOwner, int uRate, int uCredit)
	: NormalAccount(uID, uBal, uOwner, uRate, HIGH_CREDIT), creditLevel(uCredit) {}; 

HighCreditAccount::~HighCreditAccount(){}; 

int HighCreditAccount::getCredit() const
{
	return creditLevel; 
}

int HighCreditAccount::setCredit(int uCredit) 
{
	creditLevel = uCredit; 
	return creditLevel; 
}

int HighCreditAccount::deposit(int amount)
{
	Account::deposit(amount + amount* (getRate() + CREDIT_INTER_RATES[creditLevel])/100); 
	return getAccountBalance(); 	
}

void HighCreditAccount::showAccountInfo() const
{
	cout << "High Credit Account Info" << endl; 
	cout << LINE << endl; 
	cout << "> Account ID: " << getAccountID() << endl;
	cout << "> Account Type: " << ACC_TYPE_NAMES[getType()] << endl; 
	cout << "> Account Owner: " << getAccountOwner() << endl; 
	cout << "> Interest Rate: " << getRate() << "%" << endl; 
	cout << "> Credit Level: " << CREDIT_LEVEL[creditLevel] << endl; 
	cout << "> Remaining Balance: $" << getAccountBalance() << endl; 
	cout << LINE << endl; 
	return; 
}