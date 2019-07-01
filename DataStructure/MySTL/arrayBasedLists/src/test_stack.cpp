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

#include "Stack.h"
using namespace mySTL;

int main(int argc, char **argv)
{
	int n = 20, i;


	srand(0);

	cout << endl << "Stack<int>:" << endl;

	cout << "Test Stack::push() and pop()";
	Stack<int> as;
	for(i=0; i<n; i++)
		as.push(i);
	for(i=0; i<n; i++) {
		assert(as.top()==n-1-i);
		as.pop();
	}
	cout << "-> PASS" << endl;
	
	cout << "Test Stack::reverse() ";
	for(i=0; i<n; i++)
		as.push(i);
	as.reverse();
	for(i=0; i<n; i++) {
		assert(as.top()==i);
		as.pop();
	}
	cout << "-> PASS" << endl;
}

