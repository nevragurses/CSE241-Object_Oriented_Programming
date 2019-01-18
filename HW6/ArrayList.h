/*
 * ArrayList.h
 *
 *
 *      Author: Nevra Gürses
 */
#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_
#include <iostream>
#include "List.h"
#include <exception> //for exception.
using std::cout;
using std::endl;
using std::exception;
namespace CollectionOfGurses{
	template < class E, class C=vector<E > >
	class ArrayList :public List<E,C > //Derived class that derives List.
	{
	public:
		ArrayList() throw();  //No parameter constructor.
		//Functions that are also in base class.
		void add(const E& e) throw(); 
		void addAll(Collection<E,C>& c) throw();
		void clear() throw(); 
		bool contains(const E& e)const; 
		bool containsAll(Collection<E,C>& c); 
		bool isEmpty() const throw();
		void remove(E e); 
		void removeAll(Collection<E, C>& c);
		void retainAll(Collection<E, C>& c);
		int size() const throw(); 
		void print() const throw();
	
	private:
		C containerClass; //for container.
	};
}
#endif
