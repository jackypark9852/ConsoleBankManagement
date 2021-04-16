#ifndef BANK_H 
#define BANK_H 

#include "c_acnt/Account.h"
#include "c_acnt/NormalAccount.h"
#include "c_acnt/HighCreditAccount.h"
#include "BANKSYS.h"

class Bank {
    private: 
        Account* accountDb[DB_SIZE]; 
        Account* curAccountPtr; 
        char* bankName; 
        int accCount;
	
		Account* findAccount(int uAccountID); 
    public: 
        Bank();
        Bank(const char* uBankName);
		~Bank(); 
	
		char* getBankName() const; 
		char* setBankName(const char* uNewName); 
		int getAccCount() const; 
		int setAccCount(const int uNewCount);  
		Account* getCurAccountPtr(); 
		
		bool login();
		void logout(); 
		Account* createAccount();  
		NormalAccount* createNormalAccount(); 
		HighCreditAccount* createHighCreditAccount();

		void showAllAccount() const; 
		int showMainMenu(); 
		int showLoggedInMenu(); 
		void showCurAccountInfo() const; 
		void showCurrentBalance() const; 
		void showDeposit(); 
		void showWithdraw(); 
		void showContinue() const;
		
}; 
#endif