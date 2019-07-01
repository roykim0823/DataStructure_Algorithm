/*
 * test_vector.cpp
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

//#include "Vector.h"
#include "Vector_unique_ptr.h"
using namespace mySTL;

int main(int argc, char **argv)
{
	size_t n = 100000, i;

	srand(0);

	cout << endl << "Vector<int>:" << endl;
	Vector<int> as;
	
	cout << "Test Vector::push_back() " << endl;;
	for(i=0; i<n; i++) {
		as.push_back(i);
		assert(as.length()==i+1);
	}
	for(i=0; i<n; i++)
		assert(as[i]==(int)i);
	
	cout << "Test Vector::reverse() " << endl;
	as.reverse();
	for(i=0; i<n; i++)
		assert(as[i]==(int)(n-1-i));
	
	cout << "Test Vector::pop_back() " << endl;
	for(i=0; i<n; i++)     {
		as.pop_back();
		assert(as.length()==n-1-i);
	}
	
	cout << "Test Vector::insert() " << endl;;
	for(i=0; i<n; i++) {
		as.insert(0,i);
		assert(as.length()==i+1);
	}
	as.reverse();
	for(i=0; i<n; i++)
		assert(as[i]==(int)i);
	
	cout << "Test Vector::remove() " << endl;
	for(i=0; i<n; i++)     {
		as.remove(0);
		assert(as.length()==n-1-i);
	}
	
	cout << "Test Vector::insert() at the end" << endl;;
	for(i=0; i<n; i++) {
		as.insert(i,i);
		assert(as.length()==i+1);
	}
	for(i=0; i<n; i++)
		assert(as[i]==(int)i);
    return 0;
}

