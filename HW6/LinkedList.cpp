/*
 * LinkedList.cpp
 *
 *
 *      Author: Nevra Gürses
 */
#include "LinkedList.h"
namespace CollectionOfGurses{
	template < class E, class C >
	void LinkedList<E,C>::add(const E& e) throw(){ //Ensures ,this LinkedList contains the specified element.
		containerClass.insert(containerClass.end(),e); //Inserts element in LinkedList.
	}
	template < class E, class C >
	void LinkedList<E,C>::addAll(Collection<E,C>& c)throw() { //Adds all elements in specified collection for this LinkedList. 
		LinkedList& collect=dynamic_cast < LinkedList& > (c); //Collection is casting as LinkedList.
		int size2=collect.containerClass.size();
		for(auto p:collect.containerClass)
			containerClass.insert(containerClass.end(),p); //All elements is adding for this LinkedList.
	}

	template < class E, class C >
	void LinkedList<E,C>::clear()throw() {  //Removes all elements.
		containerClass.clear();

	}
	template < class E, class C >
	bool LinkedList<E,C>::contains(const E& e) const throw(){ //Returns true, if LinkedList contains specified element.
		int i=0;
		for(auto p:containerClass){ //Checks all elements in LinkedList.
			if(p==e)
				return true;
		}
		return false;	
	}
	template < class E, class C >
	bool LinkedList<E,C>::containsAll(Collection<E,C>& c)throw() { //Returns true if LinkedList contains all elements of specified collection.
		LinkedList& collect=dynamic_cast < LinkedList& > (c);
		int i=0;
		int j=0;
		int keep=0;
		class C ::iterator it1; //iterator for this container.
		class C ::iterator it2; //iterator for container of specified collection.
		for(it1=collect.containerClass.begin();it1!=collect.containerClass.end();it1 ++){
			for(it2=containerClass.begin();it2!=containerClass.end();it2 ++){
				if(*it1==*it2) //if elements of specified collection also in this LinkedList.
					++keep; //counter increasing.
			}
			if(keep==0){ //if counter is not increase, so element is not in this LinkedList.
				return false;
			}
			keep=0;
			it2=collect.containerClass.begin();
		}
		return true;
	}

	template < class E, class C >
	bool LinkedList<E,C>::isEmpty() const throw() { //Return true if LinkedList is empty.
		return containerClass.empty();
	}
	template < class E, class C >
	void LinkedList<E,C>::remove(E e) throw(){ //Removes an instance of specified element.
		int count =0,flag=0;
		auto it = containerClass.begin(); //iterator for container.
		while(it != containerClass.end() && flag==0){
	      		if(*it==e){  //if element is found,it is removed.
		    		it = containerClass.erase(it);
				count ++;
				flag=1; //flag is changing because element is found and 1 instance of element is removed.
			}
	       		else
		  		++it;
		}
		if(count ==0)
			cout <<"This element is not in this LinkedList! " << endl;

	}
	template < class E, class C >
	void LinkedList<E,C>::removeAll(Collection<E, C>& c) throw(){   //Removes all elements that are also in specified collection.
		LinkedList& collect=dynamic_cast < LinkedList& > (c); //Collection casting as LinkedList.
		auto it1 = containerClass.begin(); //iterator for this container.
		auto it2 = collect.containerClass.begin(); //Iterator for container of specified collection.
		while( it2 != collect.containerClass.end()){
			while(it1 != containerClass.end()){
				if(*it1==*it2){ //If there are equal element,this element  is removed.
					it1 = containerClass.erase(it1);
			
				}
				else{
					++it1;
				}
			
			}
			it1=containerClass.begin();
			++it2;
		}
	}

	template < class E, class C >
	void LinkedList<E,C>::retainAll(Collection<E, C>& c)throw(){ //Retains all elements that are also in specified collection.
		LinkedList& collect=dynamic_cast < LinkedList& > (c); //Collection casting as LinkedList.
		int j;
		auto it1 = containerClass.begin(); //iterator for this container.
		auto it2 = collect.containerClass.begin(); //Iterator for container of specified collection.
		vector<E> keepRetain; //templated vector to keep equal elements.
		while( it2 != collect.containerClass.end()){
			while(it1 != containerClass.end()){
				if(*it1==*it2){
					keepRetain.push_back(*it1); //If elements are equal,this element is kept templated vector as retained element.
				}
				++it1;
			}
			it1=containerClass.begin();
			++it2;
		}
		int counter=0;
		for(it1=containerClass.begin();it1!=containerClass.end();){
			for(j=0;j<keepRetain.size();++j){
				if(*it1==keepRetain[j]){ //If element of container is equal templated vector element,counter increases.
					++counter;
				}
			}
			if(counter==0){ //If elements is not equal retained element,so counter is not increases and that element is removed. 
				it1=containerClass.erase(it1);
			
			}
			else{
				counter=0;
				++it1;
			}
		}
	
	}
	template < class E, class C >
	E LinkedList<E,C>::element() throw(exception){ //Retrieves, but does not remove, the head of this LinkedList.
		if(containerClass.empty()==true){ //If LinkedList is empty,throw exception.
			throw exception();
		}
		auto first=containerClass.begin();   //Head of LinkedList.
		E keep=*first;	 //Head is keeping an variable.
		return keep; //returning variable that keeps head.
	
	}
	template < class E, class C >
	E LinkedList<E,C>::poll() throw(exception){ //Retrieves and removes the head of this LinkedList.
		if(containerClass.empty()==true){ //If LinkedList empty,throw exception.
			throw exception();
		}
		auto first=containerClass.begin(); //Head of LinkedList.
		E keep=*first; //Head is keeping an variable.
		auto iter=containerClass.begin();
		iter=containerClass.erase(iter); //head is removing.
		return keep; //returning variable that keeps head.
	
	}
	template < class E, class C >
	void LinkedList<E,C>::offer(const E& e)throw(){ //Inserts specified element.
		containerClass.insert(containerClass.end(),e);
	}

	template < class E, class C >
	int LinkedList<E,C>::size() const throw(){  //Returns size of elements of LinkedList.
		return containerClass.size();

	}
	template < class E, class C >
	LinkedList<E,C>::LinkedList() throw() { } //No parameter constructor.	

	template < class E, class C >
	void LinkedList<E,C>::print() const throw(){ //Prints elements on screen.
		for(auto p:containerClass)
			cout << p << "  ";

	}
}




















	
	
