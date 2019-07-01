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

//#include "DLList.h"
#include "DLList_shared_ptr.h"
using namespace mySTL;

int main(int argc, char **argv)
{
	size_t n = 100000, i;

	srand(0);

	cout << endl << "DLList<int>:" << endl;

	DLList<int> as;
	as.clear();
	for(i=0; i<n; i++) {
		as.push_back(i);
	}
	for(i=0; i<n; i++) {
		assert(as[i]==(int)i);
		//as[i]+=1;
		//assert(as[i]==(int)(i+1));
	}
	cout << "Test DLList::push_back() ->\t";
    
	for(i=0; i<n; i++)     {
		assert(as[0]==(int)i);
		as.pop_front();
		assert(as.size()==(int)n-1-i);
	}
	cout << "pop_front() " << endl;
    
	as.clear();
	for(i=0; i<n; i++) {
		as.push_front(i);
	    assert(as[0]==(int)i);
	    assert(as[as.size()-1]==0);
	}
	cout << "Test SLList::push_front() ->\t";

	for(i=0; i<n; i++)     {
		assert(as[0]==(int)(n-1-i));
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
		assert(as[0]==(int)(n-1-i));
		assert(as[as.size()-1]==(int)(n-1));
		as.pop_front();
	}
	for(i=0; i<n; i++) {
		assert(as[0]==(int)(i));
		assert(as[as.size()-1]==(int)(n-1));
		as.pop_front();
		assert(as.size()==n-1-i);
	}
	cout << "pop_*()" << endl;
}

