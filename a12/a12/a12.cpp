//***************************************************************************//
/*
Assignment 11

Benjamin Hough
CS11 sect: 0445
Nov 8, 2015
Dave Harden
a11.cpp

*/
//***************************************************************************//




#include <iostream>
#include "LL.h"


using namespace std;
using namespace cs11_linkedlist;



int main()
{

	LL<int> list1, list2, list3;

	for ( LL<int>::size_type i = 0; i < 5; i++ )
	{
		list1.push_front( i );
		list2.push_front( i + 5 );
	}


	for ( LL<int>::size_type i = 0; i < 5; i++ )
	{
		list3.push_front( list2.front() );
		list2.pop_front();
	}

	for ( LL<int>::size_type i = 0; i < 5; i++ )
	{
		list1.push_front( list3.front() );
		list3.pop_front();
	}

	list2 = list1;
	LL<int> list4( list1 );

	LL<int>::size_type size = list1.size();
	cout << "List 1: ";

	for ( LL<int>::size_type i = 0; i < size; i++ )
	{
		cout << list1.front() << ", ";
		list1.pop_front();
	}

	cout << endl;

	if ( list2.empty() )
	{
		cout << "list2 is empty" << endl;
	}
	else
	{
		cout << "list2 is not empty" << endl;
	}


	size = list2.size();
	cout << "List 2 size: " << size << endl;
	cout << "List 2: ";

	for ( LL<int>::size_type i = 0; i < size; i++ )
	{
		cout << list2.front() << ", ";
		list2.pop_front();
	}

	cout << endl;




	if ( list2.empty() )
	{
		cout << "list2 is empty" << endl;
	}
	else
	{
		cout << "list2 is not empty" << endl;
	}

	cout << "List 2 size: " << list2.size() << endl;

	size = list4.size();
	cout << "List 4: ";

	LL<int> list5;

	for ( LL<int>::iterator i = list4.begin() ; i != list4.end(); ++i )
	{
		cout << i->data << ", ";
	}

	cout << endl;

	//list5 = list4;

	cout << "List 5 size: " << list5.size() << endl;

	cout << "List 5: pop front" << endl;

	try
	{
		list5.pop_front();
	}
	catch ( LL<int>::Empty_List_Error e )
	{
		cout << "OHHH NOOESS" << endl;
	}

	return 0;
}






/* output

List 1: 9, 8, 7, 6, 5, 4, 3, 2, 1, 0,
list2 is not empty
List 2 size: 10
List 2: 9, 8, 7, 6, 5, 4, 3, 2, 1, 0,
list2 is empty
List 2 size: 0
List 4: 9, 8, 7, 6, 5, 4, 3, 2, 1, 0,
List 5 size: 0
Press any key to continue . . .


*/