#include <iostream> 

using namespace std; 
enum {DATATYPE = 0};

template <class T> 
class TypeCheckInput{
	private: 
		char* inBuff; 
		bool checkValid(char* buff) const; 
	
	public: 
		TypeCheckInput(size_t len);
		~TypeCheckInput(); 
		T getInput() throw (const char*); 
};

//SHOULD PRODUCE ERROR IF TRY TO DO ANYTHING WITH THIS
template<class T> 
TypeCheckInput<T>::TypeCheckInput(size_t len) throw(const char*{
	inBuff = new char[len]; 
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
T TypeCheckInput<T>::getInput() throw (const char*) {
	throw "Exception: Class cannot handle datatype";
}
//-------------------------------------------------------\

//<int> template class 
template<class T> 
bool TypeCheckInput<T>::checkValid(char* buff) const {
	return false; 
}

template<class T> 
T TypeCheckInput<T>::getInput() throw (const char*) {
	throw "Exception: Class cannot handle datatype";
}
//-------------------------------------------------------

int main()
{
	TypeCheckInput<int> test(100); 
	try
	{
		test.getInput();
	}
	catch (const char* expn)
	{
		cout << expn; 
		exit(1); 
	}
	cout << "End of main" << endl; 
	return 0; 
}