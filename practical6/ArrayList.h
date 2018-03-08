/**
 * ArrayList.h
 *
 * Generic Dynamic ArrayList based on array
 *
 * @author  Aiden McCaughey
 * @email   a.mccaughey@ulster.ac.uk
 * @version 1.0
 */

#ifndef _ARRAYLIST_H
#define _ARRAYLIST_H

#include "Array.h"
#include <exception>
#include <iostream>

template <class T>
class ArrayList {
public:
    ArrayList(int size=10);
    bool operator==(const ArrayList<T> &) const;

    void clear();
	void add(const T & e);
    void add(int, const T &);
    void remove(int);
    void set(int, const T &);
    T    get(int) const;
    int  find(T &) const;

    int  size() const;
    bool isEmpty() const;
    void print(std::ostream & os) const;
   
private:
    Array<T> data;
    int used;
};

// --------------- ArrayList Implementation -----------------------

// Default Constructor
template <class T>
ArrayList<T>::ArrayList(int size): data(size), used(0) {}

// PostCondition: returns true if Lists are identical, false otherwise
template <class T>
bool ArrayList<T>::operator==(const ArrayList<T> & other) const 
{
    bool same=true;
    if (size() != other.size()) {
        same = false;
    }
    for(int i=0; same && i<size(); i++) {
        if (get(i) != other.get(i)) {
            same = false;
        }
    } 
    return same;
}


// PostCondition: return length of list
template<class T>
int ArrayList<T>::size() const {
    return used;
}

// PreCondition: pos is a valid list position and list is not full
// PostCondition: inserts element value at specified position in list
template<class T>
void ArrayList<T>::add(int pos, const T & value) {
	// complete this function
}

// PreCondition: the list is not full
// PostCondition: inserts element value at end of list
template<class T>
void ArrayList<T>::add(const T & value) {
    // complete this function
}


// PreCondition: pos is a valid list position
// PostCondition: remove element at specified position in  list
template<class T>
void ArrayList<T>::remove(int pos) {
	// complete this function
}

// PreCondition: pos is a valid list position
// PostCondition: retrieves element at specified position in list
template<class T>
T ArrayList<T>::get(int pos) const  {
    if (pos < 0 || pos >= size()) 
		throw std::out_of_range("invalid list postion: " + std::to_string(pos));

    return data[pos]; 
}

// PreCondition: pos is a valid list position
// PostCondition: updates element at specified position in list
template<class T>
void ArrayList<T>::set(int pos, const T & value) {
	if (pos < 0 || pos >= size()) 
		throw std::out_of_range("invalid list postion: " + std::to_string(pos));
    
	data[pos] = value;
}


// PostCondition: returns postion of e in list or -1 if not found
template<class T>
int ArrayList<T>::find(T & e) const {
	// complete this function
}


// PostCondition: prints contents of list to standard output
template<class T>
void ArrayList<T>::print(std::ostream & os) const {
    os << "[ ";
    for(int i=0; i<size(); i++) {
        os << get(i) << " ";
    }
    os << "]";
}

// PostCondition: list is emptied len == 0;
template<class T>
void ArrayList<T>::clear() {
    used = 0;				// reset length to zero
}

//PostCondition: returns length of list
template<class T>
bool ArrayList<T>::isEmpty() const {
    return (used == 0);
}

// PreCondition: None
// PostCondition: overload << operator to output list on ostream
template <class T>
std::ostream& operator <<(std::ostream& output, const ArrayList<T>& l) {
    l.print(output);
    return output;  // for multiple << operators.
}

#endif /*_ARRAYLIST_H*/