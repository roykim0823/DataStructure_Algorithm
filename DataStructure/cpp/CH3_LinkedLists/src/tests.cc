#include <cmath>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

#include "SLList.h"
#include "SLList_SHARED.h"
#include "DLList.h"
#include "DLList_SHARED.h"
using namespace HKSTL;

template <typename T>
void Tests(T &as, size_t n=0)
{
  if (n==0)
    n = 1000000;

	for(int i=0; i<n; i++) {
		as.push_back(i);
		assert(as.front()==0);
		assert(as.back()==i);
	}
	cout << "Test SLList::push_back() ->\t";

	for(int i=0; i<n; i++)     {
		assert(as.front()==i);
		as.pop_front();
		assert(as.size()==n-1-i);
	}
	cout << "pop_front() " << endl;
	as.clear();

	for(int i=0; i<n; i++) {
		as.push_front(i);
	    assert(as.front()==i);
	    assert(as.back()==0);
	}
	cout << "Test SLList::push_front() ->\t";

	for(int i=0; i<n; i++)     {
		assert(as.front()==(n-1-i));
		as.pop_front();
		assert(as.size()==n-1-i);
	}
	cout << "pop_front() " << endl;

	as.clear();	//---------------------------------------
	for(int i=0; i<n; i++)  {
		as.push_front(i);
		as.push_back(i);
	}
	cout << "Test SLList::push_*() ->\t";

	for(int i=0; i<n; i++) {
		assert(as.front()==(n-1-i));
		assert(as.back()==(n-1));
		as.pop_front();
	}
	for(int i=0; i<n; i++) {
		assert(as.front()==(i));
		assert(as.back()==(n-1));
		as.pop_front();
		assert(as.size()==n-1-i);
	}
	cout << "pop_*()" << endl;
}

int main(int argc, char **argv)
{
	size_t n = 1000000;

	SLList<int> ssl;
	cout << endl << "SSList<int>:" << endl;
  Tests(ssl, n);

  SLList_SHARED<int> ssl_shared; 
	cout << endl << "SSList_SHARED<int>:" << endl;
  Tests(ssl_shared, n);
	
  DLList<int> dll;
	cout << endl << "DSList<int>:" << endl;
  Tests(dll, n);

  DLList_SHARED<int> dll_shared; 
	cout << endl << "DSList_SHARED<int>:" << endl;
  Tests(dll_shared, n);
}

