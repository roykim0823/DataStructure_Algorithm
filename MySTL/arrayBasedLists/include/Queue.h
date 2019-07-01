/*
 * Queue.h
 *
 *      Author: morin
 */

#ifndef QUEUE_H_
#define QUEUE_H_
#include "Vector.h"

namespace mySTL {

template<typename T>
class Queue {	
protected:
	Vector<T> vec; 	// vector for circular array
	size_t j;		// starting index of circular array
    size_t n;		// The length of circular array
	void resize();
	T max(T a, T b) { return ((a)>(b) ? (a) : (b)); }

public:
	Queue() : vec(1) { j=n=0; }	// vec(1), vec's size is 1
	~Queue() {}
	void push(T x);  	// push_back
	void pop();        	// pop_front
	T front()	{ return vec[j]; }
	T back()    { return vec[j+n-1]; }
	size_t size() { return n; }
};

template<typename T>
void Queue<T>::resize() {
	Vector<T> tmp(max(1, 2*n));
	// Copy vec to tmp
	for(size_t k=0; k<n; k++) 
		tmp.push_back(vec[(j+k)%vec.size()]);
	vec=tmp;	// Vector support assignment operator
	j=0;
}

template<typename T>
void Queue<T>::push(T x) {
	if(n+1 > vec.size()) resize();
//	cout << j << " " << n << " " << vec.size() << endl; 
	vec[(j+n) % vec.size()] = x;
	n++;
}

template<typename T>
void Queue<T>::pop() {
	j = (j+1) % vec.size();	// increasing the starting index
	n--;
	if(vec.size() >= 3*n) resize();
}

} /* namespace ods */
#endif /* QUEUE_H_ */
