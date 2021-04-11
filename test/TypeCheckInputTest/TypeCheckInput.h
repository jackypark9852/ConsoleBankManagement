#ifndef TYPE_CHECK_INPUT_H
#define TYPE_CHECK_INPUT_H

#include <iostream> 

using namespace std; 

template <class T> 
class TypeCheckInput{
	private: 
		char* inBuff; 
		bool checkValid(char* buff) const; 
	
	public: 
		TypeCheckInput(size_t len);//throw (TypeCheckInputException);
		~TypeCheckInput(); 
		T getInput();//throw (TypeCheckInputException); 
};

#endif 