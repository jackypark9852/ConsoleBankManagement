#include "Bank.h" 
#include "BANKSYS.h"
#include "NormalAccount.h" 
#include "HighCreditAccount.h" 

#include <cstring> 
#include <string> 
#include <iostream> 
#include <limits>



using namespace std;
Account* Bank::findAccount(int uAccountID)
{
	for(int i = 0; i < accCount; i++) 
	{
		if (accountDb[i] -> getAccountID() == uAccountID) return accountDb[i];
	}
	return NULL; 
}

Bank::Bank(): curAccountPtr(NULL), accCount(0)
{
	for(int i = 0; i < DB_SIZE; i++)
            {
                accountDb[i] = NULL; 
            }
	bankName = new char[strlen("Good Bank") + 1]; 
    strcpy(bankName, "Good Bank"); 
	cout << bankName << "'s Initialization Successful!" << endl; 
}

Bank::Bank(const char* uBankName):	 curAccountPtr(NULL), accCount(0)
{
	for(int i = 0; i < DB_SIZE; i++)
    {
        accountDb[i] = NULL; 
    }
    bankName = new char[strlen(uBankName) + 1]; 
    strcpy(bankName, uBankName); 
    cout << bankName << "'s Initialization Successful!" << endl; 
}

Bank::~Bank() {
	for (int i = 0; i < accCount; i++) 
	{
		delete accountDb[i]; 
	}
	// cout << bankName << " deleted!" << endl; 	
	delete []bankName; 
}

char* Bank::getBankName() const 
{
	return bankName; 
}

char* Bank::setBankName(const char* uNewName)
{
	delete []bankName; 
	bankName = new char[strlen(uNewName) + 1]; 
	strcpy(bankName, uNewName); 
	return bankName; 
}

int Bank::getAccCount() const
{
	return accCount; 
}

int Bank::setAccCount(const int uNewCount)
{
	if (uNewCount > DB_SIZE || uNewCount < 0)
	{
		cout << "**" << uNewCount << "is not a valid accCount value.**" << endl; 
		return accCount; 
	}
	accCount = uNewCount; 
	return accCount; 
}
	

bool Bank::login()
{
	if (curAccountPtr != NULL)
	{
		cout << "**Already logged in! Please log off first.**" << endl;  
		return false; 
	}
	
	int uAccountID; 
	Account* foundAccountPtr; 
	cout << "Login" << endl; 
	cout << LINE << endl; 
	cout << "Enter your account ID: "; 
	cin >> uAccountID; 
	foundAccountPtr = findAccount(uAccountID);
	
	if(foundAccountPtr == NULL) 
	{
		cout << "**Account not found. Please try again.**" << endl; 
		return false; 
	}
	else
	{
		curAccountPtr = foundAccountPtr; 
		cout << LINE << endl; 
		cout << "Log in successful." << endl << endl; 
		return true; 
	}
}

void Bank::logout()
{
	curAccountPtr = NULL; 
	cout << "Log out successful!" << endl; 
	return; 
}

// Account* Bank::createAccount()
// {
// 	int uAccountID; 
// 	int uAccountBalance = -1; 
// 	char uAccountOwner[1000]; 
// 	int uAccountRate; 
// 	Account* newAccount = NULL; 
	
// 	cout << "Creating a new account:" << endl; 
// 	cout << LINE << endl; 
// 	cout << "Account ID (numbers only): "; 
// 	cin >> uAccountID; 
// 	cout << "Name: "; 
// 	cin >> uAccountOwner; 
// 	while(uAccountBalance < 0)
// 	{
// 		cout << "Starting balance: $";
// 		cin >> uAccountBalance; 
// 		if (uAccountBalance < 0) cout << "**Please enter a positive value**" << endl; 
// 	}
// 	cout << "Interest Rate: " << endl; 
// 	cin >> uAccountRate;
// 	cout << LINE << endl << endl; 
// 	newAccount = new NormalAccount(uAccountID, uAccountBalance, uAccountOwner, uAccountRate); 
// 	accountDb[accCount++] = newAccount; 
// 	curAccountPtr = newAccount; 
// 	return newAccount; 
// }

Account* Bank::createAccount()
{
	int choice; 
	bool madeChoice = false; 

	while(!madeChoice)
	{
		cout << "Account Type Selection" << endl; 
		cout << LINE << endl; 
		cout << "1. Normal Account" << endl; 
		cout << "2. High Credit Account" << endl; 
		cout << LINE << endl; 
		cout << "Choice: "; 
		cin >> choice ; 
		cout << endl; 

		switch(choice)
		{
			case NORMAL:
				madeChoice = true; 
				return createNormalAccount(); 

			case HIGH_CREDIT: 
				madeChoice = true; 
				return createHighCreditAccount(); 

			default: 
				cout << "Invalid choice! Try again." << endl;
				showContinue();
				
		}
	}
	
	return NULL; 
		
}

NormalAccount* Bank::createNormalAccount()
{
	int uAccountID; 
	int uAccountBalance = -1; 
	char uAccountOwner[1000]; 
	int uAccountRate; 
	NormalAccount* newAccount = NULL; 

	cout << "Normal Account Registration" << endl; 
	cout << LINE << endl; 
	cout << "Account ID (numbers only): "; 
	cin >> uAccountID; 
	cout << "Name: "; 
	cin >> uAccountOwner; 
	while(uAccountBalance < 0)
	{
		cout << "Starting balance: $";
		cin >> uAccountBalance; 
		if (uAccountBalance < 0) cout << "**Please enter a positive value**" << 	endl; 
	}
	cout << "Interest Rate (%): "; 
	cin >> uAccountRate;
	cout << LINE << endl << endl; 


	newAccount = new NormalAccount(uAccountID, uAccountBalance, uAccountOwner,	uAccountRate); 
	accountDb[accCount++] = newAccount; 
	curAccountPtr = newAccount; 
	return newAccount; 
}

HighCreditAccount* Bank::createHighCreditAccount()
{
	int uAccountID; 
	int uAccountBalance = -1; 
	char uAccountOwner[1000]; 
	int uAccountRate; 
	int uCredit;
	HighCreditAccount* newAccount = NULL; 

	cout << "High Credit Account Registration" << endl; 
	cout << LINE << endl; 
	cout << "Account ID (numbers only): "; 
	cin >> uAccountID; 
	cout << "Name: "; 
	cin >> uAccountOwner; 
	while(uAccountBalance < 0)
	{
		cout << "Starting balance: $";
		cin >> uAccountBalance; 
		if (uAccountBalance < 0) cout << "**Please enter a positive value**" << 	endl; 
	}
	cout << "Interest Rate (%): "; 
	cin >> uAccountRate;
	cout << "Credit Level (1)A (2)B (3)C : "; 
	cin >> uCredit; 
	cout << LINE << endl << endl; 


	newAccount = new HighCreditAccount(uAccountID, uAccountBalance, uAccountOwner,	uAccountRate, uCredit); 
	accountDb[accCount++] = newAccount; 
	curAccountPtr = newAccount; 
	return newAccount; 
}



Account* Bank::getCurAccountPtr()
{
	return curAccountPtr; 
}

void Bank::showAllAccount() const
{
	if(accCount == 0) 
	{
		cout << "**No accounts created yet.**" << endl; 
		return;  
	}
	cout << bankName << " Account Summary: " << endl; 
	// cout << "------------------------------" << endl; 
	for(int i = 0; i < accCount; i++)
	{
		cout << "Account " << i << ": " << endl; 
		accountDb[i] -> showAccountInfo();
	}
	return; 
}

int Bank::showMainMenu(){
	int uChoice; 
	
	cout << "Welcome to " << bankName << endl; 
	cout << LINE << endl; 
	cout << "1. Make a new account" << endl; 
	cout << "2. Log in" << endl; 
	cout << LINE << endl; 
	cout << "Choice: "; 
	cin >> uChoice; 
	cout << endl;  
	
	return uChoice; 
}

int Bank::showLoggedInMenu(){
	int uChoice; 
	
	cout << "Welcome " << curAccountPtr -> getAccountOwner() << "! | "; 
	cout << "Account " << curAccountPtr -> getAccountID() << endl; 
	cout << LINE << endl; 
	cout << "1. Check account info" << endl; 
	cout << "2. Check current balance" << endl; 
	cout << "3. Deposit" << endl; 
	cout << "4. Withdraw" << endl; 
	cout << "5. Log out" << endl; 
	cout << LINE << endl; 
	cout << "Choice: "; 
	cin >> uChoice; 
	cout << endl; 
	
	return uChoice; 
}

void Bank::showCurAccountInfo() const
{
	curAccountPtr -> showAccountInfo(); 
	showContinue(); 
	return; 
}

void Bank::showCurrentBalance() const 
{
	
	cout << "Current balance: $";
	cout << curAccountPtr -> getAccountBalance() << endl; 
	showContinue(); 
	return; 
}

void Bank::showDeposit()
{
	int amount = -1; 
	cout <<"Deposit" << endl; 
	cout << LINE << endl;
	
	while(amount <= 0)
	{
		cout << "Enter deposit amount: $";
		cin >> amount; 
	
		if (amount < 0) {
			cout << "Invalid amount. Enter a positive value." << endl; 
			continue;  
		}
		else if (amount == 0) 
		{
			cout << "**Transaction cancelled**" << endl; 
			return; 
		}
	}
	cout << LINE << endl; 
	cout << "Deposit successful." << endl;
	cout << "> Current balance: $" << curAccountPtr -> deposit(amount) << endl; 
	showContinue();
	return; 
}

void Bank::showWithdraw() 
{
	int amount = -1;
	
	cout << "Withdraw" << endl; 
	cout << LINE << endl; 
	
	while (amount <= 0)
	{
		cout << "Enter withdrawal amount: $"; 
		cin >> amount; 

		if (amount < 0) {
			cout << "Invalid amount! " << endl; 
			continue; 
		}
		else if (amount > curAccountPtr -> getAccountBalance()) {
			cout << "Insufficient funds!" << endl; 
			cout << "> Current account balance: $" << curAccountPtr -> getAccountBalance() << endl; 
			amount = -1;
			continue;  
		}
		else if (amount == 0) 
		{
			cout << "Transaction cancelled." << endl; 
			return; 
		}
	}
	cout << LINE << endl; 
	cout <<"Withdrawal successful" << endl; 
	cout << "> Current balance: $" << curAccountPtr -> withdraw(amount) << endl; 
	showContinue(); 
	return;  
}

void Bank::showContinue() const
{
	string input = "";  
	cout << "Enter any key to continue: "; 
	cin >> input; 
	cout << endl; 
	return; 
}