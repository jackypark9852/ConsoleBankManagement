#include "TypeCheckInput.h" 
#include "TypeCheckInput.cpp" 
#include "TypeCheckInputException.h"

#include <iostream> 

using namespace std; 

int main()
{
	try
	{
		TypeCheckInput<int> test(100); 
		test.getInput(); 
	}
	catch (TypeCheckInputException &expn)
	{
		expn.showExceptionMessage();
		exit(1); 
	}
	cout << "End of main" << endl; 
	return 0; 
}