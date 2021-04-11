#include "ConstructorException.h" 

#include <iostream> 

using namespace std; 

ConstructorException::ConstructorException(){}

void ConstructorException::showExceptionMessage()
{
	cout << "[Exception Message: TypeCheckInput does not support this datatype.]" << endl; 
	return; 
}