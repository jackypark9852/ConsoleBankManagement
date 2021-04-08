#include <iostream> 

using namespace std; 

template <typename T> 
class SimpClass {
	private: 
		T val; 
	
	public: 
		SimpClass(T input = 0): val(input) {}; 
			
		void showType(); 
};

template <typename T> 
void SimpClass<T>::showType(){
	cout << "type T" << endl; 
	return; 
}

template <> 
void SimpClass<int>::showType(){
	cout << "type: int" << endl;
	return; 
}

int main()
{
	SimpClass<char> cSimp('A'); 
	cSimp.showType(); 
	
	SimpClass<int> iSimp(10);
	iSimp.showType(); 
	
	return 0; 
}