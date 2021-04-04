#ifndef ACCOUNT_H 
#define ACCOUNT_H 

class Account {
    private: 
		char* accountOwner; 
        int accountID; 
		int accountBalance;
		const int accountType; 
		
    public:
        Account(int uID, int uBal, const char* uOwner, int uType);
		virtual ~Account(); 
		char* getAccountOwner() const; 
		char* setAccountOwner(const char* uNewName); 
		int getAccountID() const; 
		int setAccountID(const int uNewID); 
		int getAccountBalance() const; 
		int setAccountBalance(const int uNewBalance); 
		int getType() const; 
		virtual int deposit(int amount); 
		int withdraw(int amount); 
        virtual void showAccountInfo() const = 0;  
};
#endif