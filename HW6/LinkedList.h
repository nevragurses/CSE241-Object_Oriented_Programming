/*
 * LinkedList.h
 *
 *
 *      Author: Nevra Gürses
 */
#ifndef LINKEDLIST_
#define LINKEDLIST_H_
#include <iostream>
#include "List.h"
#include "Queue.h"
#include <exception> //for exception.
using std::cout;
using std::endl;
using std::exception;
namespace CollectionOfGurses{
	template < class E, class C=vector<E> >
	class LinkedList :public List<E,C>,public Queue<E,C > //templated derived class that derives List and Queue.
	{
	public:
		LinkedList() throw(); //No parameter constructor.
		//Functions that are also in base classes.
		void add(const E& e) throw();
		void addAll(Collection<E,C>& c) throw();
		void clear() throw();
		bool contains(const E& e) const throw();
		bool containsAll(Collection<E,C>& c) throw();
		bool isEmpty() const throw();
		void remove(E e) throw();
		void removeAll(Collection<E, C>& c) throw();
		void retainAll(Collection<E, C>& c) throw();
		int size() const throw();
		void print() const throw(); //prints elements on screen.

		E element() throw(exception);
		void offer(const E& e) throw();
		E poll() throw(exception);
	private:
		C containerClass; //for container.
	};
}
#endif 
