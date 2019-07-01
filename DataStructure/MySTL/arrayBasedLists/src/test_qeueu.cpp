/*
 * test_queue.cpp
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

#include "Queue.h"
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
	size_t n = 100000;
	size_t i;


	srand(0);

	cout << endl << "Queue<int>:" << endl;

	Queue<int> as;
	cout << "Test Queue::push() " << endl;;
	for(i=0; i<n; i++) {
		as.push(i);
		assert(as.front()==0);
		assert(as.back()==(int)i);
	}
	
	cout << "Test Queue::pop() " << endl;;
	for(i=0; i<n; i++)     {
		assert(as.front()==(int)i);
		as.pop();
		assert(as.size()==n-1-i);
	}
	cout << "-> PASS" << endl;
}

