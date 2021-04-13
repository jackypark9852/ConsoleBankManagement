#include "TypeCheckInput.h" 
#include "TypeCheckInput.cpp" 
#include "TypeCheckInputException.h"

#include <iostream> 

using namespace std; 

int main()
{
	int input = 0; 
	while(1) {
		try
		{
			TypeCheckInput<int> test;
			cout << "Please input an int: "; 
			input = test.getInput();
		}
		catch (TypeCheckInputException &expn)
		{
			expn.showExceptionMessage();
			cout << "Please try again." << endl; 
			continue; 
		}
		break; 
	}
	
	cout << "You input is: " << input << endl; 
	return 0; 
}