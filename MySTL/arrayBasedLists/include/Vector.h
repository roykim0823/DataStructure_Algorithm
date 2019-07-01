/*
 * array.h
 *
 *  Created on: 2011-11-24
 *      Author: morin
 */

#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <assert.h>
#include <new>

namespace mySTL {
/**
 * A simple array class that simulates Java's arrays implementation - kind of
 * TODO: Make a reference-counted version so that the = operator doesn't have
 * to destroy its right-hand side.
 */
template<typename T>
class Vector {
protected:
	T *a;  	// pointer to array
	
	size_t m_length; 	  	// the vector size
	size_t m_size;   		// the array size (available space size)
	void resize();
	void swap(int i, int j) {
		T x = a[i];
		a[i] = a[j];
		a[j] = x;
	}

public:
	Vector(); 	               	
	Vector(int len);         	// Init with a size
	Vector(int len, T init); 	// size with initial values
	virtual ~Vector(); 
	
	void reserve(int n);		// make the array size n

	void fill(T x);
	// Assign Operator Overloading
	Vector<T>& operator=(Vector<T> &b) { 
		if (a != NULL) 
			delete[] a; 
		a = b.a;
		b.a = NULL;
		m_length 	= b.m_length;
		m_size 		= b.m_size;
		return *this;
	}

	// Index Operator Overloading 
	T& operator[](size_t i) {
		assert(i >= 0 && i < m_size);  	// also in swap()
		/* Throwing an exception
		if(i<0 || i>=length) 
			throw std::out_of_range("Out of range in array at class array &operator []");
	    */
		return a[i];
	}

	T* operator+(int i) {
		return &a[i];
	}

    bool empty() { return m_length==0; }
	size_t length() { return m_length; }	
	size_t size() { return m_size; }		

	static void copyOfRange(Vector<T> &a0, Vector<T> &a, int i, int j);
	virtual void reverse();
	// basic operations
	void push_back(T x);
	void pop_back();
	void pop_back2(); 	// pop_back() with resize()
	void insert(size_t i, T x);	// insert at index i
	void remove(size_t i);			// delete at index i
	void clear();

};

// Constructor with a length
template<class T>
Vector<T>::Vector() {
	m_length=0;
	m_size=1;
	a = new T[1];
}

// Constructor with a length
template<class T>
Vector<T>::Vector(int len) {
    m_length=0;
	m_size=len;
	a = new T[m_size];
}

// Constructor with a length and initial value
template<class T>
Vector<T>::Vector(int len, T init) {
	m_length=len;
	m_size=len;
	a = new T[len];
	for (int i = 0; i < len; i++)
		a[i] = init;
}

// Default Destructor 
template<class T>
Vector<T>::~Vector() {
	if (a != NULL) delete[] a;
}

template<class T>
void Vector<T>::reserve(int n) {
	if(m_size>n)  // no-op if n is less than the current capacity
		return ;	
	if(a == NULL) { // empty vector
   		m_length=0;
   		m_size=n;
   		a = new T[n];
   	} else {        	// if a has content 
		T *b;
   		b=new T[n];
   		for(int i=0; i<n; i++)
   			b[i] = a[i];
		delete []a;
        a=b;
   	}
}

template<class T>
void Vector<T>::reverse() {
	for (size_t i = 0; i < m_length/2; i++) {
		swap(i, m_length-i-1);
	}
}

template<class T>
void Vector<T>::copyOfRange(Vector<T> &a0, Vector<T> &a, int i, int j) {
	Vector<T> b(j-i);
	std::copy(a.a+i, a.a+j, b.a);
	a0 = b;
}

template<class T>
void Vector<T>::fill(T x) {
	Vector::fill(a, a+m_length, x);
}

template<class T>
void Vector<T>::push_back(T x) {	// add an item at the last index+1
	if(m_length+1>m_size) resize();   // the array is full, then resize() -> increase 2x size
	a[m_length] = x;					// a[size] is the next index of the last one
	m_length++;
}
	
// Dynamically mange the size of array 
template<class T>
void Vector<T>::resize() {
    int resize=2*m_length;
	if(resize==0)	// if m_length==0, maybe not necessary since the min size of array is 1
		resize=1;

	//T *b = new T[resize];
	Vector<T>  b(resize);
	// Faster array copy
	std::copy(a+0, a+m_length, &b[0]);
	//for(int i=0; i<m_length; i++)
	//	b[i] = a[i];
	b.m_length=m_length;
	*this=b;
}
		
template<class T>
void Vector<T>::pop_back() {	// remove an item at the last index
	m_length--;             		// just reduce the size value
	assert(m_length>=0);
}

template<class T>
void Vector<T>::pop_back2() {	// remove an item at the last index and resize()
	m_length--;             		// just reduce the size value
	assert(m_length>=0);
	if(m_size>=3*m_length) resize();	// resize if the max_size is too big for the size
}

template<class T>
void Vector<T>::insert(size_t i, T x) {
	if(m_length+1 > m_size) resize();
	std::copy_backward(a+i, a+m_length, a+m_length+1);	// faster than below for-loop
	/*
	for (int j=n; j>i; j--) 
		a[j] = a[j-1];
	*/
	a[i]=x;
	m_length++;
}

template<class T>
void Vector<T>::remove(size_t i) {
	assert(i >= 0 && i < m_length);  	
	std::copy(a+i+1, a+m_length, a+i);
	/*
	for (int j=i; j<n-1; j++) 
		a[j] = a[j+1];
	*/
	m_length--;
	if(m_size>=3*m_length) resize();	// resize if the size is too big for the length
}

template<class T>
void Vector<T>::clear() {	// remove all items
	m_length=0;
	m_size=1;
	T *b = new T[1];
	delete []a;
	a=b;
}
} /* namespace ods */
#endif /* ARRAY_H_ */
