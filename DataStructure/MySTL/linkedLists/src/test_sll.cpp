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

//#include "SLList.h"
#include "SLList_shared_ptr.h"
using namespace mySTL;

int main(int argc, char **argv)
{
	size_t n = 1000000, i;

	srand(0);

	cout << endl << "SSList<int>:" << endl;

	SLList<int> as;
	//as.clear();

	for(i=0; i<n; i++) {
		as.push_back(i);
		assert(as.front()==0);
		assert(as.back()==(int)i);
	}
	cout << "Test SLList::push_back() ->\t";

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
	cout << "Test SLList::push_front() ->\t";

	for(i=0; i<n; i++)     {
		assert(as.front()==(int)(n-1-i));
		as.pop_front();
		assert(as.size()==n-1-i);
	}
	cout << "pop_front() " << endl;

	as.clear();	//---------------------------------------
	for(i=0; i<n; i++)  {
		as.push_front(i);
		as.push_back(i);
	}
	cout << "Test SLList::push_*() ->\t";

	for(i=0; i<n; i++) {
		assert(as.front()==(int)(n-1-i));
		assert(as.back()==(int)(n-1));
		as.pop_front();
	}
	for(i=0; i<n; i++) {
		assert(as.front()==(int)(i));
		assert(as.back()==(int)(n-1));
		as.pop_front();
		assert(as.size()==n-1-i);
	}
	cout << "pop_*()" << endl;

}

