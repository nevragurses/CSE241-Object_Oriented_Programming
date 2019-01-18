/*
 * ArrayList.cpp
 *
 *
 *      Author: Nevra Gürses
 */
#include "ArrayList.h"
namespace CollectionOfGurses{
	template < class E, class C >
	void ArrayList<E,C>::add(const E& e) throw(){ //Ensures ,this ArrayList contains the specified element.
		containerClass.insert(containerClass.end(),e); //Inserts element in ArrayList.
	}
	template < class E, class C >
	void ArrayList<E,C>::addAll(Collection<E,C>& c)throw() { //Adds all elements in specified collection for this ArrayList. 
		ArrayList& collect=dynamic_cast < ArrayList& > (c); //Collection is casting as ArrayList.
		int size2=collect.containerClass.size();
		for(auto p:collect.containerClass)
			containerClass.insert(containerClass.end(),p); //All elements is adding for this ArrayList.
	}

	template < class E, class C >
	void ArrayList<E,C>::clear()throw() {  //Removes all elements.
		containerClass.clear();

	}

	template < class E, class C >
	bool ArrayList<E,C>::contains(const E& e) const{ //Returns true, if ArrayList contains specified element.
		int i=0;
		for(auto p:containerClass){ //Checks all elements in ArrayList.
			if(p==e)
				return true;
		}
		return false;	
	}
	template < class E, class C >
	bool ArrayList<E,C>::containsAll(Collection<E,C>& c) { //Returns true if ArrayList contains all elements of specified collection.
		ArrayList& collect=dynamic_cast < ArrayList& > (c); //Casting collection for ArrayList.
		int i=0;
		int j=0;
		int keep=0;
		class C ::iterator it1; //iterator for this container.
		class C ::iterator it2; //iterator for container of specified class.
		for(it1=collect.containerClass.begin();it1!=collect.containerClass.end();it1 ++){
			for(it2=containerClass.begin();it2!=containerClass.end();it2 ++){
				if(*it1==*it2) //if elements of specified collection also in this ArrayList.
					++keep; //counter increasing.
			}
			if(keep==0){ //if counter is not increase, so element is not in this ArrayList.
				return false;
			}
			keep=0;
			it2=collect.containerClass.begin();
		}
		return true;
	}

	template < class E, class C >
	bool ArrayList<E,C>::isEmpty() const throw(){  //Return true if ArrayList is empty.
		return containerClass.empty();


	}

	template < class E, class C >
	void ArrayList<E,C>::remove(E e){ //Removes an instance of specified element.
		int count =0,flag=0;
		auto it = containerClass.begin(); //iterator for container.
		while(it != containerClass.end() && flag==0){
	      		if(*it==e){ //if element is found,it is removed.
		    		it = containerClass.erase(it);
				count ++;
				flag=1; //flag is changing because element is found and 1 instance of element is removed.
			}
	       		else
		  		++it;
		}
		if(count ==0)
			cout <<"This element is not in this ArrayList! " << endl;

	}
	template < class E, class C >
	void ArrayList<E,C>::removeAll(Collection<E, C>& c){  //Removes all elements that are also in specified collection.
		ArrayList& collect=dynamic_cast < ArrayList& > (c); //Collection casting as ArrayList.
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
	void ArrayList<E,C>::retainAll(Collection<E, C>& c){ //Retains all elements that are also in specified collection.
		ArrayList& collect=dynamic_cast < ArrayList& > (c); //Collection casting as ArrayList.
		int j;
		auto it1 = containerClass.begin(); //iterator for this container.
		auto it2 = collect.containerClass.begin(); //Iterator for container of specified collection.
		vector<E> keepRetain; //templated vector to keep equal elements.
		while( it2 != collect.containerClass.end()){
			while(it1 != containerClass.end()){
				if(*it1==*it2){ //If elements are equal,this element is kept templated vector as retained element.
					keepRetain.push_back(*it1);
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
	int ArrayList<E,C>::size() const throw(){  //Returns size of elements.
		return containerClass.size();

	}

	template < class E, class C >
	ArrayList<E,C>::ArrayList() throw(){ } //No parameter constructor.

	template < class E, class C >
	void ArrayList<E,C>::print() const throw(){ //Prints all elements on screen.
		for(auto p:containerClass)
			cout << p  << "  " ;

	}
}




















	
	
