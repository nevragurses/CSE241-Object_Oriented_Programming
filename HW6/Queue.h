/*
 * Queue.h
 *
 *
 *      Author: Nevra Gürses
 */
#ifndef QUEUE_H_
#define QUEUE_H_
#include <iostream>
#include "Collection.h"
using std::cout;
using std::endl;
namespace CollectionOfGurses{
	template < class E, class C=vector<E> >
	class Queue :virtual public Collection<E, C >//Abstract templated derived class with all pure virtual functions.
	{
	public:
		Queue(){ }
		//Pure virtual functions they are also in base class collection.
		virtual void addAll(Collection<E,C>& c)=0;
		virtual void clear()=0;
		virtual bool contains(const E& e) const=0;
		virtual bool containsAll(Collection<E,C>& c)=0;
		virtual bool isEmpty() const=0;
		virtual void remove(E e)=0;
		virtual void removeAll(Collection<E, C>& c)=0;
		virtual void retainAll(Collection<E, C>& c)=0;
		virtual int size() const =0;

		virtual void add(const E& e)=0; //Inserts the specified element.
		virtual E element()=0;  //Retrieves, but does not remove, the head of this queue.
		virtual void offer(const E& e)=0; //Inserts the specified element.
		virtual E poll()=0; //Retrieves and removes the head of this queue.
	};
}
#endif 
