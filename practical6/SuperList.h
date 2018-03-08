/**
 * SuperList.h
 *
 * Generic Super List based on ArrayList
 *
 * @author  Aiden McCaughey
 * @email   a.mccaughey@ulster.ac.uk
 * @version 1.0
 */

#ifndef SUPERLIST_H
#define SUPERLIST_H

#include "ArrayList.h"

template <class T>
class SuperList : public ArrayList<T> {
public:
	SuperList() : ArrayList() {};
	void operator=(const SuperList<T> & data) { this = data; }
	SuperList(const ArrayList<T> & data) : ArrayList(data) {}

    SuperList<T> drop(int n);   
	SuperList<T> take(int n);   
	SuperList<T> reverse();
};

// --------------- SuperList Implementation -----------------------


// PostCondition: returns a new list in reverse order
template<class T>
SuperList<T> SuperList<T>::reverse() {
  // complete function
}


// PreCondition: list size() >= n
// PostCondition: returns a new list containing all but first n elements
template<class T>
SuperList<T> SuperList<T>::drop(int n) {
  // complete function
}

// PreCondition: list size() >= n
// PostCondition: returns a new list containing all but first n elements
template<class T>
SuperList<T> SuperList<T>::take(int n) {
  // complete function
}

#endif /* SUPERLIST_H*/