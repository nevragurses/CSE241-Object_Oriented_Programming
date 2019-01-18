/*
 * List.h
 *
 *
 *      Author: Nevra Gürses
 */
#ifndef LIST_H_
#define LIST_H_
#include <iostream>
#include "Collection.h"
using std::cout;
using std::endl;
namespace CollectionOfGurses{
	template < class E, class C=vector<E > >
	class List :virtual public Collection<E,C> //Abstract templated derived class with all pure virtual functions.
	{
	public:
		List() { };
		//Pure virtual functions they are also in base class collection.
		virtual void add(const E& e)=0;
		virtual void addAll(Collection<E,C>& c)=0;
		virtual void clear()=0;
		virtual bool contains(const E& e) const=0;
		virtual bool containsAll(Collection<E,C>& c)=0;
		virtual bool isEmpty() const=0;
		virtual void remove(E e)=0;
		virtual void removeAll(Collection<E, C>& c)=0;
		virtual void retainAll(Collection<E, C>& c)=0;
		virtual int size() const =0;
	};
}


#endif 
