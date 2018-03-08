/**
 * FluentList.h
 *
 * Generic Fluent Dynamic List based on ArrayList
 *
 * @author  Aiden McCaughey
 * @email   a.mccaughey@ulster.ac.uk
 * @version 1.0
 */

#ifndef FLUENTLIST_H
#define FLUENTLIST_H

#include "ArrayList.h"

template <class T>
class FluentList : public ArrayList<T> {
public:
	// default constructor simply calls underlying ArrayList constructor
	FluentList() : ArrayList() {};

	// copy constructor creates a fluentlist from an array list
	FluentList(const ArrayList<T> & l) : ArrayList(l) {}

	// ArrayList operations that can be made 'Fluent'
	FluentList & clear();
    FluentList & add(int, const T &);
	FluentList & add(const T &);
    FluentList & remove(int);
    FluentList & set(int, const T &);
       
};

// --------------- Fluent Implementation -----------------------


// PreCondition: pos is a valid list position and list is not full
// PostCondition: inserts element value at specified position in list
template<class T>
FluentList<T> & FluentList<T>::add(int pos, const T & value) {
	ArrayList::add(pos, value);
	return *this;
}

// PreCondition: pos is a valid list position and list is not full
// PostCondition: inserts element value at specified position in list
template<class T>
FluentList<T> & FluentList<T>::add(const T & value) {
	ArrayList::add(value);
	return *this;
}

// PreCondition: pos is a valid list position
// PostCondition: updates element at specified position in list with value
template<class T>
FluentList<T> & FluentList<T>::set(int pos, const T & value) {
	ArrayList::set(pos, value);
	return *this;
}


// PreCondition: pos is a valid list position
// PostCondition: remove element at specified position in  list
template<class T>
FluentList<T> & FluentList<T>::remove(int pos) {
	ArrayList::remove(pos);
	return *this;
}


// PostCondition: list is emptied len == 0;
template<class T>
FluentList<T> & FluentList<T>::clear() {
	ArrayList::clear();
	return *this;
}

#endif /* FLUENTLIST_H*/