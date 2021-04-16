#ifndef INPUT_TYPE_EXCEPTION_H
#define INPUT_TYPE_EXCEPTION_H

#include "TypeCheckInputException.h"

class InputTypeException: public TypeCheckInputException
{
	public: 
		InputTypeException(); 
		void showExceptionMessage(); 
}; 

#endif 