#include "TypeCheckInput.h" 
#include "ConstructorException.h" 
#include "ConstructorException.cpp" 
#include "InputTypeException.h" 
#include "InputTypeException.cpp" 

#include <iostream> 

using namespace std; 

//SHOULD THROW ERROR WHEN CONSTRUCTED
template<class T> 
TypeCheckInput<T>::TypeCheckInput(size_t len) {//throw(TypeCheckInputException)
	throw ConstructorException(); 
}

template<class T> 
TypeCheckInput<T>::~TypeCheckInput(){
	delete []inBuff; 
}

template<class T> 
bool TypeCheckInput<T>::checkValid(char* buff) const {
	return false; 
}

template<class T> 
T TypeCheckInput<T>::getInput() {//throw (TypeCheckInputException) 
	throw InputTypeException(); 
	return T(); 
}

/*
//<int> template class 
template<class T> 
bool TypeCheckInput<T>::checkValid(char* buff) const {
	return false; 
}

template<class T> 
T TypeCheckInput<T>::getInput() throw (TypeCheckInputException) {
	throw "Exception: Class cannot handle datatype";
}
*/
