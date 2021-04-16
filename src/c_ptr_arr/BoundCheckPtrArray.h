#ifndef BOUND_CHECK_PTR_ARRAY_H
#define BOUND_CHECK_PTR_ARRAY_H
template <class T> 
class BoundCheckPtrArray
{
	private: 
		T* arr; 
		int len; 
		BoundCheckPtrArray& operator=(const BoundCheckPtrArray & opnd) {}; 
		BoundCheckPtrArray(const BoundCheckPtrArray & copy) {}; 
	
	public: 
		BoundCheckPtrArray(int n); 
		~BoundCheckPtrArray(); 
		T & operator[](int idx);
		T & operator[](int idx) const;
		void showAllVal() const; 
};
#endif
