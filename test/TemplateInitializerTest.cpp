#include <iostream> 
#include <cstring> 

using namespace std; 

class stringWrap{
	private: 
		char* val; 
	
	public: 
		stringWrap(const char* ini){
			val = new char[strlen(ini) + 1]; 
			strcpy(val, ini); 
		}
		
		stringWrap() {
			cout << "stringWrap()" << endl; 
			val = new char[1]; 
		}
		~stringWrap(){
			delete []val; 
		}
	
		stringWrap& operator= (const char* txt) {
			delete []val; 
			val = new char[strlen(txt) + 1]; 
			strcpy(val, txt); 
			return *this; 
		}
		stringWrap& operator+=(const stringWrap& opnd) {
			char* temp = new char[strlen(val) + 1]; 
			strcpy(temp, val); 
			delete []val; 
			val = new char(strlen(temp) + strlen(opnd.val) + 1); 
			strcpy(val, temp);
			strcat(val, opnd.val); 
			return *this;
		}
	
		void showVal(){
			cout << val << endl; 
			return; 
		}
}; 
 
template <typename T> 
T sumArray(T arr[], int len){
	T sum = 0; 
	for (int i = 0; i < len; ++i) {
		sum += arr[i]; 
	}
	return sum; 
}

int main()
{
	stringWrap* arr; 
	arr = new stringWrap[3]; 
	arr[0] = "one ";
	arr[1] = "two "; 
	arr[2] = "three."; 
	sumArray(arr, 3).showVal(); 
	return 0; 
}

/*
stringWrap(int n = 0)
stringWrap(int n = 0)
stringWrap(int n = 0)
stringWrap(int n = 0)
one two three. 
*/