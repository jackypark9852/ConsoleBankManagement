#ifndef TYPE_CHECK_INPUT_EXCEPTION_H
#define TYPE_CHECK_INPUT_EXCEPTION_H

#include <iostream> 

using namespace std; 

class TypeCheckInputException
{
	public: 
		virtual void showExceptionMessage() = 0; 
};

#endif 