#include "Array.h"

#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <assert.h>
#include <new>

namespace HKSTL {
 
template <typename T>
Array<T>::Array() {
  m_length=1;
	m_size=0;
	m_ptr = new T[m_length];
}

template <typename T>
Array<T>::Array(size_t length) {
  assert(length > 0);
  m_length=length;
	m_size=0;
	m_ptr = new T[m_length];
}

// Constructor with a length and initial value
template <typename T>
Array<T>::Array(size_t size, T value) {
	m_length = size*2;
	m_size = size;
	m_ptr = new T[m_length];
	for (int i = 0; i < m_size; ++i)
		m_ptr[i] = value;
}

template <typename T>
Array<T>::~Array() {
	if (m_ptr != nullptr) delete[] m_ptr;
}

template <typename T>
void Array<T>::reserve(size_t n) {
	if(m_length > n)  // no-op if n is less than the current capacity
		return ;	
	if(m_ptr == nullptr) { // empty vector
   		m_length = n;
   		m_size = 0;
   		m_ptr = new T[n];
   	} else {        	// if a has content 
		  T *tmp_ptr = new T[n];
      std::copy(&m_ptr[0], &m_ptr[m_size], tmp_ptr);
		  delete[] m_ptr;
      m_ptr = tmp_ptr;
   	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& arr) { 
	if (m_ptr != nullptr) 
		delete[] m_ptr; 
	m_ptr = arr.m_ptr;
 	arr.m_ptr = nullptr;
 	m_length 	= arr.m_length;
 	m_size 		= arr.m_size;
 	return *this;
}

template<typename T>
void Array<T>::reverse() {
	for (size_t i = 0; i < m_size/2; ++i) {
		swap(i, (m_size-1)-i);
	}
}

template<typename T>
void Array<T>::fill(T value) {
	std::fill(m_ptr, m_ptr+m_size, value);
}

template<typename T>
void Array<T>::push_back(T value) {	// add an item at the last index+1
	if(m_size+1 > m_length) reallocate();   // the array is full, then reallocate(): x2 length 
	m_ptr[m_size] = value;					// a[size] is the next index of the last one
	m_size++;
}
	
template<typename T>
void Array<T>::pop_back() {	// remove an item at the last index
	m_size--;             		// just reduce the size value
	assert(m_size >= 0);
  if (m_length >= m_size*4) reallocate();
}

template<typename T>
void Array<T>::insert(size_t i, T value) {
	if(m_size+1 > m_length) reallocate();
	std::copy_backward(m_ptr+i, m_ptr+m_size, m_ptr+m_size+1);	// faster than below for-loop
	m_ptr[i]=value;
	m_size++;
}

template<typename T>
void Array<T>::erase(size_t i) {
	assert(i >= 0 && i < m_size);  	
	std::copy(m_ptr+i+1, m_ptr+m_size, m_ptr+i);
	m_size--;
	if(m_length >= m_size*4) reallocate();	// resize if the size is too big for the length
}

template<typename T>
void Array<T>::clear() {	// remove all items
	m_length=1;
	m_size=0;
	T *temp_ptr = new T[1];
	delete[] m_ptr;
	m_ptr=temp_ptr;
}

// Dynamically manage the length of Array 
template<typename T>
void Array<T>::reallocate() {
  size_t new_length = m_size * 2;
	if (new_length == 0)
    new_length = 1;

	T *temp_ptr = new T[new_length];
	// Faster array copy
	std::copy(&m_ptr[0], &m_ptr[m_size], &temp_ptr[0]);
	m_length=new_length;
  m_ptr = temp_ptr;
  delete[] temp_ptr;
}
		
}  // namespace HKSTL