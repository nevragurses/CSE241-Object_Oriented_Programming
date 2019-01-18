/*
 * HashSet.h
 *
 *
 *      Author: Nevra Gürses
 */
#ifndef HASHSET_H_
#define HASHSET_H_
#include <iostream>
#include "Set.h"
#include <exception> //for exception.
using namespace std;
namespace CollectionOfGurses{
	template < class E, class C=vector<E > >
	class HashSet :public Set<E,C > //Derived class that derives Set.
	{
	public:
		HashSet() throw();  //No parameter constructor.
		//Functions that are also in base class.
		void add(const E& e) throw(); 
		void addAll(Collection<E,C>& c)throw(); 
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
