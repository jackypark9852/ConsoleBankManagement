#include "Account.h" 
#include "NormalAccount.h" 
#include "HighCreditAccount.h" 
#include "Bank.h" 
#include "BoundCheckPtrArray.h" 
#include "BoundCheckPtrArray.cpp"
#include <iostream>
#include <cstring> 

using namespace std;
int main()
{
	Bank b("Hello Bank");
	bool loggedIn = false; 
	bool Exit = false;
	int mode = MAIN; 
	
	while(!Exit)
	{
		switch(mode)
		{
			case MAIN:
				switch(b.showMainMenu()) 
				{
					case -1:
						b.showAllAccount(); 
						break; 
						
					case CREATEACC: 
						if(b.createAccount() != NULL) 
						{
							mode = LOGGEDIN; 
						}
						break; 
				
					case LOGIN: 
						if(b.login())
						{
							mode = LOGGEDIN;  
						}
						break; 
				
					case MAIN_EXIT: 
						Exit = true; 
						break; 
						
					default:
						cout << "**invalid choice**" << endl; 
						break; 
				}
				break; 
				
			case LOGGEDIN:
				switch(b.showLoggedInMenu())
				{
					case INFO: 
						b.showCurAccountInfo(); 
						break; 
					case CURRENTBAL:
						b.showCurrentBalance(); 
						break; 
					
					case DEPOSIT: 
						b.showDeposit(); 
						break; 
					
					case WITHDRAW: 
						b.showWithdraw(); 
						break; 
					
					case LOGOUT: 
						b.logout(); 
						mode = MAIN; 
						break; 
						
					case LOGGEDIN_EXIT: 
						Exit = true; 
						break; 
					
					default:
						cout << "**invalid choice**" << endl; 
						break; 
				}
				break; 
		}
	}
	return 0; 
}

