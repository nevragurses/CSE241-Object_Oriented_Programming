/*
 * Collection.h
 *
 *
 *      Author: Nevra Gürses
 */
#ifndef COLLECTION_H_
#define COLLECTION_H_
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
namespace CollectionOfGurses{
template < class E, class C=vector<E> >
	class Collection //Abstract templated base class with all pure virtual functions.
	{
	public:
		Collection(){ }
		virtual void add(const E& e)  =0; //Ensures,collection contains specified element.
		virtual void addAll(Collection<E,C>& c)=0; //Adds elements that are in specified collection.
		virtual void clear()=0; //Removes all elements.
		virtual bool contains(const E& e) const=0; //Returns true if collection contains specified element.
		virtual bool containsAll(Collection<E,C>& c)=0; //Returns true if collection contains all elements in specified collection.
		virtual bool isEmpty() const=0; //Returns true if collection empty.
		virtual void remove(E e)=0;  //Removes a single instance of the specified element.
		virtual void removeAll(Collection<E, C>& c)=0; // Removes all of this collection's elements that are also in the specified collection.
		virtual void retainAll(Collection<E, C>& c)=0; //Retain all of elements that are also in specified collection.
		virtual int size() const =0; //Returns number of elements.
	};
}
#endif 
