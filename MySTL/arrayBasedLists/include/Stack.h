/*
 * Stack.h
 *
 */

#ifndef STACK_H_
#define STACK_H_
#include "Vector.h"

namespace mySTL {

template<class T>
class Stack {
protected:
	Vector<T> vec;
	
public:
	// exception class for pop() and top() with empty stack
	class ReadEmptyStack : public std::exception {
		public:
			virtual const char* what() const throw() {
				return "Read empty stack.";
			}
	};

	Stack(): vec(1) { }	               	
	Stack(int len, T x): vec(len, x) {  } 	               	
	~Stack() {} 
	
	// Assign Operator Overloading
	/*
	Stack<T>& operator=(Stack<T> &b) { 
		if (a != NULL) delete[] a; a = b.a;
		b.a = NULL;
		m_size = b.m_size;
		m_max_size = b.m_max_size;
		return *this;
	}
	*/
	Stack<T>& operator=(Stack<T> &b) {
		vec = b.vec;
	}

	bool empty() 	{ return vec.empty(); }
	int size() 		{ return vec.size(); }	// Add size() function

	void reverse() 	{ vec.reverse(); }
	// basic operations
	T& top();
	void push(T x) 	{ vec.push_back(x); }
	void pop()	   	{ vec.pop_back(); }
	void pop2()     { vec.pop_back2(); }	// pop_back with resize
	void clear()    { vec.clear(); }

};

template<class T>
T& Stack<T>::top() {	
	// assert(vec.length()>0);  
    if(vec.length()==0)
		throw ReadEmptyStack();	// throw an exception
	return vec[vec.length()-1];		// return the last element (reference)
}

} /* namespace ods */
#endif /* STACK_H_ */
