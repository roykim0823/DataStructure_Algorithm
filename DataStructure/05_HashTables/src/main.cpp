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

#include "ChainedHashTable.h"
#include "LinearHashTable.h"

using namespace ods;

#ifndef CLOCKS_PER_SEC
#define CLOCKS_PER_SEC 1000
#endif


template <class USet>
void usetTests(USet &us, int n) {
	clock_t start, stop;
	cout << "Adding " << n << " elements...";
	cout.flush();
	start = clock();
	for (int i = 0; i < n; i++) {
		us.add(rand() % (2*n));
	}
	stop = clock();
	cout << "done (" << ((double)(stop-start))/CLOCKS_PER_SEC << "s)" << endl;

	cout << "Finding " << n << " elements...";
	cout.flush();
	start = clock();
	int success = 0;
	for (int i = 0; i < n; i++) {
		int z = rand() % (2*n);
		int y = us.find(z);
		if (y == z) success++;
		if (i % 300000 == 0) {
			cout << "[" << z << "=>" << y << "]";
		}
	}
	stop = clock();
	cout << "done [" << success << "/" << n << " (" << ((double)(stop-start))/CLOCKS_PER_SEC << "s)" << endl;

	cout << "Removing " << n << " elements...";
	cout.flush();
	start = clock();
	for (int i = 0; i < n; i++) {
		us.remove(rand() % (2*n));
	}
	stop = clock();
	cout << "done (" << ((double)(stop-start))/CLOCKS_PER_SEC << "s)" << endl;

	cout << "Final size is " << us.size() << endl;

	cout << "Clearing " << us.size() << " elements...";
	cout.flush();
	start = clock();
	us.clear();
	stop = clock();
	cout << "done (" << ((double)(stop-start))/CLOCKS_PER_SEC << "s)" << endl;
}


int main(int argc, char **argv)
{
	int n = 1000000;

	srand(0);

	{
		cout << endl << "ChainedHashTable<int>:" << endl;
		ChainedHashTable<int> t;
		usetTests(t, n);
	}

	{
		cout << endl << "LinearHashTable<int>:" << endl;
		LinearHashTable<int> t(INT_MIN, INT_MIN+1);
		usetTests(t, n);
	}
	return 0;
}
