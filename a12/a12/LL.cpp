//***************************************************************************//
/*
Assignment 12

Benjamin Hough
CS11 sect: 0445
Nov 15, 2015
Dave Harden
LL.cpp

*/
//***************************************************************************//


#include <iostream>

namespace cs11_linkedlist
{



	// assignment operator overload (one of Big Four)
	template<class T>
	LL<T> LL<T>::operator=( const LL& listToAssign )
	{
		if ( this != &listToAssign )
		{
			clear();
			copyList( listToAssign );
		}

		return *this;
	}





	// makes the LL object empty. Watch for memory leaks!
	template<class T>
	void LL<T>::clear()
	{
		node * deleteMe;

		while ( list != nullptr )
		{
			deleteMe = list;
			list = list->next;
			delete deleteMe;
		}
	}




	template<class T>
	void LL<T>::copyList( const LL& listToCopy )
	{
		node* sourcePtr = listToCopy.list;

		if ( sourcePtr != nullptr )
		{
			list = new node;
			node* curptr = list;
			curptr->data = sourcePtr->data;
			sourcePtr = sourcePtr->next;

			while ( sourcePtr != nullptr )
			{
				curptr->next = new node;
				curptr = curptr->next;
				curptr->data = sourcePtr->data;
				sourcePtr = sourcePtr->next;
			}

			curptr->next = nullptr;
		}
		else
		{
			list = nullptr;
		}
	}






	// returns the number of items in the LL object.
	template<class T>
	typename LL<T>::size_type LL<T>::size() const
	{
		LL<T>::size_type numberOfItems = 0;
		node* currptr = list;

		while ( currptr != nullptr )
		{
			++numberOfItems;
			currptr = currptr->next;
		}

		return numberOfItems;
	}





	// returns true if the LL object is empty, false otherwise.
	template<class T>
	bool LL<T>::empty() const
	{
		return list == nullptr;
	}





	// void pop_front(): removes the first item in the list. Watch for memory leaks!
	template<class T>
	void LL<T>::pop_front()
	{
		if ( empty() )
		{
			throw Empty_List_Error();
		}

		node* deleteMe = list;
		list = list->next;

		delete deleteMe;
	}






	// insert x at the front of the LL object.
	template<class T>
	void LL<T>::push_front( const value_type & x )
	{
		node* newFirstPtr = list;
		list = new node;
		list->next = newFirstPtr;
		list->data = x;
	}





	// returns a reference to the front item in the LL object.
	template<class T>
	typename LL<T>::value_type & LL<T>::front()
	{
		if ( empty() )
		{
			throw Empty_List_Error();
		}

		return list->data;
	}





	// same, but for use by const LL objects.
	template<class T>
	typename const LL<T>::value_type & LL<T>::front() const
	{
		if ( empty() )
		{
			throw Empty_List_Error();
		}

		return list->data;
	}





	// Default constructor.  One of the Big Four.  Creates an empty LL object.
	template<class T>
	LL<T>::LL()
	{
		list = nullptr;
	}





	// copy constructor (one of the Big Four)
	template<class T>
	LL<T>::LL( const LL<T> & listToCopy )
	{
		copyList( listToCopy );
	}





	// destructor (one of Big Four)
	template<class T>
	LL<T>::~LL()
	{
		clear();
	}

}




/*

output


List 1: 9, 8, 7, 6, 5, 4, 3, 2, 1, 0,
list2 is not empty
List 2 size: 10
List 2: 9, 8, 7, 6, 5, 4, 3, 2, 1, 0,
list2 is empty
List 2 size: 0
List 4: 9, 8, 7, 6, 5, 4, 3, 2, 1, 0,
List 5 size: 0
List 5: pop front
OHHH NOOESS
Press any key to continue . . .

*/