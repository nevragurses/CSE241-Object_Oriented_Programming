/*
 * HashSet.cpp
 *
 *
 *      Author: Nevra Gürses
 */
#include "HashSet.h"
namespace CollectionOfGurses{
	template < class E, class C >
	void HashSet<E,C>::add(const E& e) throw(){ //Ensures ,this HashSet contains the specified element.
		int counter=0;
		for(auto it=containerClass.begin();it!=containerClass.end();++it){ //checks all elements of HashSet.
			if(*it==e) //If there is an element that is equal specified element, counter increases.
				++counter;
		}
		if(counter==0){ //If counter doesn't increase,so this element is not in HashSet and it is added.
			containerClass.insert(containerClass.end(),e);
		}
	}
	template < class E, class C >
	void HashSet<E,C>::addAll(Collection<E,C>& c) throw(){  //Adds all elements in specified collection for this HashSet. 
		HashSet& collect=dynamic_cast < HashSet& > (c); //Collection is casting as HashSet.
		int counter=0; 
		for(auto p:collect.containerClass){
			for(auto it=containerClass.begin();it!=containerClass.end();++it){
				if(*it==p)  //If there are an element that is equal  element of specified collection, counter increases.
					++counter;
			}
			if(counter==0){//If counter doesn't increase,so this element is not in HashSet and it is added.
				containerClass.insert(containerClass.end(),p);
			}
			counter=0;
		}
		
	}

	template < class E, class C >
	void HashSet<E,C>::clear() throw(){  //Removes all elements.
		containerClass.clear();

	}

	template < class E, class C >
	bool HashSet<E,C>::contains(const E& e) const{ //Returns true, if HashSet contains specified element.
		int i=0;
		for(auto p:containerClass){ //Checks all elements in HashSet.
			if(p==e)
				return true;
		}
		return false;	
	}
	template < class E, class C >
	bool HashSet<E,C>::containsAll(Collection<E,C>& c) { //Returns true if HashSet contains all elements of specified collection.
		HashSet& collect=dynamic_cast < HashSet& > (c);
		int i=0;
		int j=0;
		int keep=0;
		class C ::iterator it1; //iterator for this container.
		class C ::iterator it2; //iterator for container of specified collection.
		for(it1=collect.containerClass.begin();it1!=collect.containerClass.end();it1 ++){
			for(it2=containerClass.begin();it2!=containerClass.end();it2 ++){
				if(*it1==*it2) //if elements of specified collection also in this HashSet.
					++keep; //counter increasing.
			}
			if(keep==0){  //if counter is not increase, so element is not in this HashSet.
				return false;
			}
			keep=0;
			it2=collect.containerClass.begin();
		}
		return true;
	}

	template < class E, class C >
	bool HashSet<E,C>::isEmpty() const throw(){  //Returns true, if HashSet is empty.
		return containerClass.empty();


	}
	template < class E, class C >
	void HashSet<E,C>::remove(E e){ //Removes an instance of specified element.
		int count =0,flag=0;
		auto it = containerClass.begin();  //iterator for container.
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
			cout <<"This element is not in this HashSet! " << endl;

	}
	template < class E, class C >
	void HashSet<E,C>::removeAll(Collection<E, C>& c){  //Removes all elements that are also in specified collection.
		HashSet& collect=dynamic_cast < HashSet& > (c);//Collection casting as HashSet.
		auto it1 = containerClass.begin();
		auto it2 = collect.containerClass.begin();
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
	void HashSet<E,C>::retainAll(Collection<E, C>& c){ //Retains all elements that are also in specified collection.
		HashSet& collect=dynamic_cast < HashSet& > (c);
		int j;
		auto it1 = containerClass.begin(); //iterator for this container.
		auto it2 = collect.containerClass.begin();  //Iterator for container of specified collection.
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
	int HashSet<E,C>::size() const throw() {  //Returns size of elements.
		return containerClass.size();

	}

	template < class E, class C >
	HashSet<E,C>::HashSet() throw() { } //No parameter constructor.

	template < class E, class C >
	void HashSet<E,C>::print() const throw(){ //Prints elements on screen.
		for(auto p:containerClass)
			cout << p << "  " ;

	}
}




















	
	
