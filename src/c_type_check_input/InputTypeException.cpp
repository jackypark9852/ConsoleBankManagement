#include "headers/InputTypeException.h" 

#include <iostream>

using namespace std; 

InputTypeException::InputTypeException() {} 

void InputTypeException::showExceptionMessage()
{
	cout << "[Exception Message: Wrong input type]" << endl; 
	return; 
}