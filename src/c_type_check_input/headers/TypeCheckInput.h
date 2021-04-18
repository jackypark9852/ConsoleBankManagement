#ifndef TYPE_CHECK_INPUT_H
#define TYPE_CHECK_INPUT_H

#include "ConstructorException.h"
#include "ConstructorException.cpp"
#include "InputTypeException.h"
#include "InputTypeException.cpp" 

#include <iostream> 
#include <string> 
#include <sstream>

using namespace std; 

template <class T> 
class TypeCheckInput{
	private: 
		string inBuff; 
		int len; 
		bool isValidDataType() const; 
	
	public: 
		TypeCheckInput();//throw (TypeCheckInputException);
		T getInput();//throw (TypeCheckInputException); 
};
//SHOULD THROW ERROR WHEN CONSTRUCTED

template<class T> 
TypeCheckInput<T>::TypeCheckInput(){//throw(TypeCheckInputException)
	if (!isValidDataType())
		throw ConstructorException(); 
	else
		inBuff = ""; 
}

template<class T> 
T TypeCheckInput<T>::getInput() 
{
	T myNum = 0; 
	
	inBuff.clear(); 
	while(inBuff.empty()){
		getline(cin, inBuff);
	}
	
	stringstream myStream(inBuff);
	
	if (myStream >> myNum) 
	{

		return myNum; 
	}
	else 
	{
		throw InputTypeException(); 
	} 
	
	return 0; 
}

template <class T> 
bool TypeCheckInput<T>::isValidDataType() const 
{
	return false; 
}

template <>
bool TypeCheckInput<int>::isValidDataType() const 
{
	return true; 
}

template <>
bool TypeCheckInput<float>::isValidDataType() const 
{
	return true; 
}


#endif 