#ifndef HIGHCREDITACCOUNT_H
#define HIGHCREDITACCOUNT_H
#include "NormalAccount.h" 

class HighCreditAccount: public NormalAccount {
	private: 
		int creditLevel; 
	public: 
		HighCreditAccount(int uID, int uBal, 
			const char* uOwner, int uRate, int uType, int uCredit); 
		
		HighCreditAccount(int uID, int uBal, 
			const char* uOwner, int uRate, int uCredit); 
		virtual ~HighCreditAccount(); 
		int getCredit() const; 
		int setCredit(int uCredit); 
		virtual int deposit(int amount); 
		virtual void showAccountInfo() const;
};

#endif