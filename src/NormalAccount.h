- Inf#ifndef NORMALACCOUNT_H
#define NORMALACCOUNT_H
#include "Account.h" 

class NormalAccount: public Account {
	private: 
		const int accountRate;  
	public: 
		NormalAccount(int uID, int uBal, const char* uOwner, int uRate, int uType); 
		NormalAccount(int uID, int uBal, const char* uOwner, int uRate); 
		virtual ~NormalAccount(); 
		virtual int deposit(int amount); 
		virtual void showAccountInfo() const;
		int getRate() const; 
};
#endif 