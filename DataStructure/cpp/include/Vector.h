// Vector.h
// Created on: 2019-07-03
// Author: Hyunjin Kim

#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>
#include <algorithm>

#include <stdlib.h>
#include <assert.h>
#include <memory>

namespace HKSTL {

// A simple array class that simulates Java's arrays implementation
// with a unique_pointer
template<typename T>
class Vector {
public:
  Vector(size_t length=8);
  Vector(size_t size, T value);
  virtual ~Vector() {}  // no need to deleate the memory

  void reserve(size_t n)
  bool empty() { return m_size==0; }
  size_t size() { return m_size; }
  void fill(T x);
	virtual void reverse();
  
  Vector<T>& operator=(const Vector<T> &vec);  // copy assignment
  Vector<T>& operator=(Vector<T> &&vec);  // move assignment

  T& operator[] (size_t i) {
    assert( i >= 0 && i < m_size );
    return m_uniptr[i];
  }
  // operator overloading for the addrss addition 
	T* operator+(size_t i) { return &m_uniptr[i]; }
  

  // basic operations
  void push_back(const T& value);
  void pop_back();
  void insert(size_t i, const T& value);
  void erase(size_t i);  // remove i-th element
  void clear();  // remove all

protected:
  std::unique_ptr <T []> m_uniptr;
  std::size_t m_length;  // the length of allocated memory
  std::size_t m_size;  // the size of Vector
  void reallocate();
  void swap(size_t i, size_t j) {
    // std::swap(m_uniptr[i], m_uniptr[j]);
    T temp = m_uniptr[i];
    m_uniptr[i] = m_uniptr[j];
    m_uniptr[j] = temp;
  }
};

}  // namespace HKSTL
#endif  // VECTOR_H_
