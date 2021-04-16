#include "BoundCheckPtrArray.h" 

#include <iostream> 

using namespace std; 

template <class T> 
BoundCheckPtrArray<T>::BoundCheckPtrArray(int n): len(n)
{
	arr = new T[len]; 
}

template <class T> 
BoundCheckPtrArray<T>::~BoundCheckPtrArray()
{
	delete []arr; 
}

template <class T> 
T & BoundCheckPtrArray<T>::operator[](int idx)
{
	if (idx < 0 || idx >= len) {
		cout << "Array index out of bound exception." << endl; 
		exit(1); 
	}
	
	return arr[idx]; 
}

template <class T> 
T & BoundCheckPtrArray<T>::operator[](int idx) const
{
	if (idx < 0 || idx >= len) {
		cout << "Array index out of bound exception." << endl; 
		exit(1); 
	}
	
	return arr[idx]; 
}

template <class T> 
void BoundCheckPtrArray<T>::showAllVal() const
{
	for(int i = 0; i < len; ++i)
		cout << "[" << i << "]: " << arr[i] << endl;
	return; 
}