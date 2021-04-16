#ifndef TYPE_CHECK_INPUT_H
#define TYPE_CHECK_INPUT_H

#include <iostream> 
#include <string> 

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

#endif 