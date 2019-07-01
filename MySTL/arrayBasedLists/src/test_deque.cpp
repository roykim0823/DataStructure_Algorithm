/*
 * main.cpp
 *
 *  Created on: 2011-11-23
 *      Author: morin
 */
#include <cmath>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

#include "Deque.h"
using namespace mySTL;

template <typename T>
void print(T& x) 
{
	for(int i=0; i<x.size(); i++)
		cout << x[i] << " ";
	cout << endl;
}

int main(int argc, char **argv)
{
	size_t n = 1000000, i;


	srand(0);

	cout << endl << "Deque<int>:" << endl;

	Deque<int> as;
	//as.clear();

	for(i=0; i<n; i++) {
		as.push_back(i);
		assert(as.front()==0);
		assert(as.back()==(int)i);
	}
	cout << "Test Dequq::push_back() ->\t";

	for(i=0; i<n; i++)     {
		assert(as.front()==(int)i);
		as.pop_front();
		assert(as.size()==(int)n-1-i);
	}
	cout << "pop_front() " << endl;
	as.clear();

	for(i=0; i<n; i++) {
		as.push_front(i);
	    assert(as.front()==(int)i);
	    assert(as.back()==0);
	}
	cout << "Test Dequq::push_front() ->\t";

	for(i=0; i<n; i++)     {
		assert(as.front()==(int)(n-1-i));
		as.pop_front();
		assert(as.size()==n-1-i);
	}
	cout << "pop_front() " << endl;

	as.clear();
	for(i=0; i<n; i++)  {
		as.push_back(i);
	}
	cout << "Test Dequq::push_back() ->\t";

	for(i=0; i<n; i++) {
		assert(as.back()==(int)(n-1-i));
		as.pop_back();
		assert(as.size()==(int)n-1-i);
	}
	cout << "pop_back()" << endl;

	as.clear();	//---------------------------------------
	for(i=0; i<n; i++)  {
		as.push_front(i);
	}
	cout << "Test Dequq::push_front() ->\t";

	for(i=0; i<n; i++) {
		assert(as.back()==(int)(i));
		as.pop_back();
		assert(as.size()==(int)n-1-i);
	}
	cout << "pop_back()" << endl;
	
	as.clear();	//---------------------------------------
	for(i=0; i<n; i++)  {
		as.push_front(i);
		as.push_back(i);
	}
	cout << "Test Dequq::push_*() ->\t";

	for(i=0; i<n; i++) {
		assert(as.front()==(int)(n-1-i));
		assert(as.back()==(int)(n-1-i));
		as.pop_front();
		as.pop_back();
		assert(as.size()==(2*(n-1-i)));
	}
	cout << "pop_*()" << endl;

}

