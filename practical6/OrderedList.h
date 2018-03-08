/*
* OrderedList.h
*
* Generic Ordered List based on a List implementation
*
* @author  Aiden McCaughey
* @email   a.mccaughey@ulster.ac.uk
* @version 1.0
*
*/

#ifndef ORDEREDLIST_H
#define ORDEREDLIST_H

#include "ArrayList.h"

template <class T>
class OrderedList : public ArrayList<T>
{
public:
	OrderedList(int size=10) : ArrayList(size) {};
	OrderedList(const OrderedList<T> & data);
	OrderedList(const ArrayList<T> & data);

	void add(const T & e);
	int find(const T& e) const; 
	T first() const;
	T last() const;
	bool operator==(const OrderedList<T> & other) const;

	// override invalid operations
	void add(int pos, const T & e);
	void set(int pos, const T & e);

};

// PostCondition: OrderedList constructed from elements in supplied OrderedList
template <class T>
OrderedList<T>::OrderedList(const OrderedList<T> & data) : ArrayList(data) { }

// PostCondition: OrderedList constructed from elements in supplied ArrayList
template <class T>
OrderedList<T>::OrderedList(const ArrayList<T> & data) : ArrayList(data.size()) {
	// add each element from arraylist using orderedlist add function to
	// ensure they are added in order
	for(int i=0; i<data.size(); i++) {
		add(data.get(i));
	}
}

// PreCondition: isEmpty() == false
template <class T>
T OrderedList<T>::first() const
{
	return get(0);
}

// PreCondition: isEmpty() == false
template <class T>
T OrderedList<T>::last() const
{
	return get(size()-1); 
}

/**
* add element to Collection
* PreCondition:: none
* PostCondition: element added to Collection
*/
template <class T>
void OrderedList<T>::add(const T & e)
{        
	// locate correct position to insert
	int pos;
	for(pos=0; pos<size() && e > get(pos); pos++);

	// add element at ordered position using ArrayList add function
	ArrayList::add(pos,e);   
}

/**
 * return postion of element in List or -1 if not found
 * PreCondition:: elements in list are ordered
 */
template <class T>
int OrderedList<T>::find(const T & e) const {
   int left = 0;				// set left boundary
   int right = size()-1;		// set right boundary	
   while (left <= right) {		// continue search?
      int pivot = (left + right) / 2;
      if (e == get(pivot)) {	
         return pivot;			// found
      } else if (e > get(pivot)) { 
         left = pivot + 1;		// search to right
      } else {
         right = pivot - 1;		// search to left
      }
   }
   return -1;
}

// PostCondition: returns true if other Collection contains exact same elements, otherwise false
template <class T>
bool OrderedList<T>::operator==(const OrderedList<T> & other) const 
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

template <class T>
void OrderedList<T>::set(int pos, const T & e)
{        
	throw std::exception("invalid operation on an Ordered List");
}

template <class T>
void OrderedList<T>::add(int pos, const T & e)
{
	throw std::exception("invalid operation on an Ordered List");
}

#endif /* ORDEREDLIST_H */
