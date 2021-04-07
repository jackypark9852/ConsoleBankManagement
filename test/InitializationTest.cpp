#include <iostream>

using namespace std; 

class Value
{
	private: 
		int num; 
	public: 
		Value(): num(0){
			cout << "Value()" << endl; 
		}
	
		Value(int n): num(n) {
			cout <<"Value(int n)" << endl; 
		}
	
		// Value& operator=(int n) {
		// 	num = n; 
		// 	cout << "operator=(int n)" << endl; 
		// 	return *this; 
		// }
	
		Value& operator=(const Value& opnd) {
			num = opnd.num; 
			cout << "operator=(const Value & opnd)" << endl; 
			return *this; 
		}
};

int main(){
	Value one; 
	one = 30; 
	
	Value two = 60; 
	return 0; 
}

/*
Value () 
Value(int n)
operator=(const Value & opnd)
Value(int n)
*/
