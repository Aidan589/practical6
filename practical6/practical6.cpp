
//================================================================================
// Name        : practical6.cpp
// Author      : a.mccaughey@ulster.ac.uk
// Version     : 1.0
// Description : practical 6 test program to utilise List classes
//================================================================================

#include <iostream>
#include <string>
#include <cctype>
#include "ArrayList.h"
#include "OrderedList.h"
#include "FluentList.h"
#include "SuperList.h"

using namespace std;


// PreCondition: n >=0 && n<l.size();
// PostCondition: nth largest element in list is returned
template <class T>
T findNth(const ArrayList<T> & l, int n)
{
	// complete function
}


void testFindNth()
{
	// write a test function for findNth(..)
}

void testList() {
	// write a set of axioms for an ArrayList by
	// using a FluentList. See examples in the notes
	// create as extensive a set of tests as you can

	// if (FluentList<int>().add(1).add(2).size() == 2)
	//	cout << "Passed List add function" << endl;
	// else
	//	cout << "FAILED List add function" << endl;

	// etc
}


void testSuperList()
{
	// create a superlist and test the functions you completed
}

// Main method.
int main() {

	//testList();
	//testSuperList();
	//testFindNth();
	
	// ---------------------------------------------------
	cout << endl << "Press enter to quit";
	cin.get();
	return 0;
}