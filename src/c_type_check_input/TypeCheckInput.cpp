#include "headers/TypeCheckInput.h" 
#include "headers/ConstructorException.h" 
#include "ConstructorException.cpp" 
#include "headers/InputTypeException.h" 
#include "InputTypeException.cpp" 

#include <iostream> 
#include <string> 
#include <sstream> 
#include <limits> 
using namespace std; 

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
