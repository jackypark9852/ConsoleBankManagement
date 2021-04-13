#include "TypeCheckInput.h" 
#include "ConstructorException.h" 
#include "ConstructorException.cpp" 
#include "InputTypeException.h" 
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

template <class T> 
bool TypeCheckInput<T>::isValidDataType() const 
{
	return false; 
}

template<class T> 
T TypeCheckInput<T>::getInput() 
{
	return T(); 
}

template <>
bool TypeCheckInput<int>::isValidDataType() const 
{
	return true; 
}

//http://www.cplusplus.com/forum/articles/6046/
template <>
int TypeCheckInput<int>::getInput() //throw InputTypeException
{
	int myNum = 0; 
	
	getline(cin, inBuff);
	
	stringstream myStream(inBuff);
	
	//Input buffer cleaning NEEDS FIXING
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
	
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