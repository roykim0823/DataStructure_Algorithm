/*
 * Deque.h
 *
 *      Author: morin
 */

#ifndef DEQUE_H_
#define DEQUE_H_
#include "Vector.h"

namespace mySTL {

template<typename T>
class Deque {	
protected:
	Vector<T> vec; 	// vector for circular array
	size_t j;		// starting index of circular array
    size_t n;		// The length of circular array
	void resize();
	T max(T a, T b) { return ((a)>(b) ? (a) : (b)); }

public:
	Deque() : vec(1) { j=n=0; }	// vec(1), vec's size is 1
	~Deque() {}
	void push_front(T x);  		// push_front
	void push_back(T x);  		// push_back
	void pop_front();        	// pop_front
	void pop_back();        	// pop_back
	T front()	{ return vec[j]; }
	T back()    { return vec[(j+n-1)%vec.size()]; }
	size_t size() { return n; }
	void clear() { vec.clear(); j=n=0;}
};

template<typename T>
void Deque<T>::resize() {
	Vector<T> tmp(max(1, 2*n));
	// Copy vec to tmp
	for(size_t k=0; k<n; k++) 
		tmp.push_back(vec[(j+k)%vec.size()]);
	vec=tmp;	// Vector support assignment operator
	j=0;
}

template<typename T>
void Deque<T>::push_front(T x) {
	if(n+1 > vec.size()) resize();
//	cout << j << " " << n << " " << vec.size() << endl; 
	if(j+n==0) j=0;	// if the vector is empty
	else if(j==0) j=vec.size()-1;	// if j=0 but the n>0
	else j=j-1;
	vec[j] = x;
	n++;
}

template<typename T>
void Deque<T>::push_back(T x) {
	if(n+1 > vec.size()) resize();
//	cout << j << " " << n << " " << vec.size() << endl; 
	vec[(j+n) % vec.size()] = x;
	n++;
}

template<typename T>
void Deque<T>::pop_front() {
	j = (j+1) % vec.size();	// increasing the starting index
	n--;
	if(vec.size() >= 3*n) resize();
}

template<typename T>
void Deque<T>::pop_back() {
	//j = (j+1) % vec.size();	// increasing the starting index
	n--;                        // decreasing the ending index
	if(vec.size() >= 3*n) resize();
}

} /* namespace ods */
#endif /* DEQUE_H_ */
