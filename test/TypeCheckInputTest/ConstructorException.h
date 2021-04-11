#ifndef CONSTRUCTOR_EXCEPTION_H
#define CONSTRUCTOR_EXCEPTION_H

#include "TypeCheckInputException.h" 

class ConstructorException: public TypeCheckInputException 
{
	public: 
		ConstructorException(); 
		void showExceptionMessage();
}; 

#endif