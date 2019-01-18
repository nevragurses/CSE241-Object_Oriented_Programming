#include <iostream>
#include <string>
#include <list>
#include <set>
#include <vector>
#include "Collection.h"
#include "Set.h"
#include "Queue.h"
#include "List.h"
#include "ArrayList.cpp"
#include "HashSet.cpp"
#include "LinkedList.cpp"
using std::vector;
using std::list;
using std::set;
using namespace CollectionOfGurses; //my namespace.
int main(){

	try{ //for throw and exception.

		//Test for arraylist collection that is container int vector.
		cout << "-----------TEST OF ARRAYLIST CLASS WITH CONTAINER INT VECTOR------------" << endl;
		ArrayList<int,vector<int> > arr;
		arr.add(2);
		arr.add(3);
		arr.add(4);
		arr.add(5);
		arr.add(6);
		cout << "First ArrayList elements:" ;
		arr.print();
		cout << endl;
		cout << "Size of first ArrayList :" << arr.size() << endl << endl;

		cout << "Second ArrayList elements:" ;
		ArrayList<int,vector<int> > arr2;
		arr2.add(4);
		arr2.add(5);
		arr2.add(8);
		arr2.print();
		cout << endl;
		cout << "Size of second ArrayList :" << arr2.size() << endl << endl;
	
		cout << "After 6 is removed in first  ArrayList: ";
		arr.remove(6);
		arr.print();
		cout << endl;
		cout << "After removing of 6,size of first ArrayList :" << arr.size() << endl << endl;
		 

		cout << "Testing first ArrayList whether contains 3 or not:" << endl;
		if(arr.contains(3)==1)
			cout <<"ArrayList contains 3." << endl << endl;
		else 		
			cout << "ArrayList does not contain 3." << endl << endl;

		cout << "Testing first ArrayList whether contains all element second ArrayList or not :" << endl;
		if(arr.containsAll(arr2)==1)
			cout <<"Every elements of second ArrayList is in first ArrayList." << endl << endl;
		else 		
			cout << "Every elements of second ArrayList is not in first ArrayList." << endl << endl;

		cout << "Testing RemoveAll function:" << endl;
		arr.removeAll(arr2);
		cout << "After removing of elements in first ArrayList that is also contained second ArrayList: ";
		arr.print();
		cout << endl;
		cout << "After RemoveAll function ,size of first ArrayList :" << arr.size() << endl << endl;

		cout <<"After second ArrayList added first ArrayList,so uploaded first ArrayList: ";
		arr.addAll(arr2);
		arr.print();
		cout << endl;
		cout << "After addAll function ,size of first ArrayList :" << arr.size() << endl << endl;
	

		cout << "Testing RetainAll function:" << endl;
		cout << "After retains elements of first ArrayList that is also in second ArrayList: " ;
		arr.retainAll(arr2);
		arr.print();
		cout << endl <<"After retainAll fuction,size of first ArrayList :" << arr.size() << endl << endl;

		cout << "Testing first ArrayList empty or not:" << endl;
		if(arr.isEmpty()==1)
			cout <<"ArrayList is empty." << endl << endl;
		else 		
			cout << "ArrayList is not empty." << endl << endl;

	
		arr.clear();
		cout << "Testing clear function : " ;
		arr.print();
		cout << endl <<"After clear fuction,size of first ArrayList :" << arr.size() << endl << endl;

		
		//Test for arraylist collection that is container string vector.
		cout << "-----------TEST OF ARRAYLIST CLASS WITH CONTAINER STRING VECTOR------------" << endl;
		ArrayList<string,vector<string> > str;
		str.add("com");
		str.add("pu");
		str.add("ter");
		str.add("sci");
		str.add("ence");
		str.add("temp");
		str.add("la");
		str.add("tes");
		cout << "First ArrayList elements:" ;
		str.print();
		cout << endl;
		cout << "Size of first ArrayList :" << str.size() << endl << endl;

		cout << "Second ArrayList elements:" ;
		ArrayList<string,vector<string> > str2;
		str2.add("temp");
		str2.add("la");
		str2.add("tes");
		str2.print();
		cout << endl;
		cout << "Size of second ArrayList :" << str2.size() << endl << endl;
	
		cout << "After -ence- is removed in first  ArrayList: ";
		str.remove("ence");
		str.print();
		cout << endl;
		cout << "After removing of -ence-,size of first ArrayList :" << str.size() << endl << endl;
		 

		cout << "Testing first ArrayList whether contains -sci- or not:" << endl;
		if(str.contains("sci")==1)
			cout <<"ArrayList contains -sci-." << endl << endl;
		else 		
			cout << "ArrayList does not contain -sci-." << endl << endl;

		cout << "Testing first ArrayList whether contains all element second ArrayList or not :" << endl;
		if(str.containsAll(str2)==1)
			cout <<"Every elements of second ArrayList is in first ArrayList." << endl << endl;
		else 		
			cout << "Every elements of second ArrayList is not in first ArrayList." << endl << endl;

		cout << "Testing RemoveAll function:" << endl;
		str.removeAll(str2);
		cout << "After removing of elements in first ArrayList that is also contained second ArrayList : "; 
		str.print();
		cout << endl;
		cout << "After RemoveAll function ,size of first ArrayList :" << str.size() << endl << endl;

		cout <<"After second ArrayList added first ArrayList,so uploaded first ArrayList: ";
		str.addAll(str2);
		str.print();
		cout << endl;
		cout << "After addAll function ,size of first ArrayList :" << str.size() << endl << endl;
	

		cout << "Testing RetainAll function:" << endl;
		cout << "After retains elements of first ArrayList that is also in second ArrayList: " ;
		str.retainAll(str2);
		str.print();
		cout << endl <<"After retainAll fuction,size of first ArrayList :" << str.size() << endl << endl;

		cout << "Testing first ArrayList empty or not:" << endl;
		if(str.isEmpty()==1)
			cout <<"ArrayList is empty." << endl << endl;
		else 		
			cout << "ArrayList is not empty." << endl << endl;

	
		str.clear();
		cout << "Testing clear function : " ;
		str.print();
		cout << endl <<"After clear fuction,size of first ArrayList :" << str.size() << endl << endl;

	
		//Test for arraylist collection that is container int set.
		cout << "-----------TEST OF ARRAYLIST CLASS WITH CONTAINER INT SET------------" << endl;
		ArrayList<int,set<int> > arr5;
		arr5.add(2);
		arr5.add(3);
		arr5.add(4);
		arr5.add(5);
		arr5.add(6);
		cout << "First ArrayList elements:" ;
		arr5.print();
		cout << endl;
		cout << "Size of first ArrayList :" << arr5.size() << endl << endl;

		cout << "Second ArrayList elements:" ;
		ArrayList<int,set<int> > arr6;
		arr6.add(4);
		arr6.add(5);
		arr6.add(8);
		arr6.print();
		cout << endl;
		cout << "Size of second ArrayList :" << arr6.size() << endl << endl;
	
		cout << "After 6 is removed in first  ArrayList: ";
		arr5.remove(6);
		arr5.print();
		cout << endl;
		cout << "After removing of 6,size of first ArrayList :" << arr5.size() << endl << endl;
		 

		cout << "Testing first ArrayList whether contains 3 or not:" << endl;
		if(arr5.contains(3)==1)
			cout <<"ArrayList contains 3." << endl << endl;
		else 		
			cout << "ArrayList does not contain 3." << endl << endl;

		cout << "Testing first ArrayList whether contains all element second ArrayList or not :" << endl;
		if(arr5.containsAll(arr6)==1)
			cout <<"Every elements of second ArrayList is in first ArrayList." << endl << endl;
		else 		
			cout << "Every elements of second ArrayList is not in first ArrayList." << endl << endl;

		cout << "Testing RemoveAll function:" << endl;
		arr5.removeAll(arr6);
		cout << "After removing of elements in first ArrayList that is also contained second ArrayList: ";
		arr5.print();
		cout << endl;
		cout << "After RemoveAll function ,size of first ArrayList :" << arr5.size() << endl << endl;

		cout <<"After second ArrayList added first ArrayList,so uploaded first ArrayList: ";
		arr5.addAll(arr6);
		arr5.print();
		cout << endl;
		cout << "After addAll function ,size of first ArrayList :" << arr5.size() << endl << endl;
	

		cout << "Testing RetainAll function:" << endl;
		cout << "After retains elements of first ArrayList that is also in second ArrayList: " ;
		arr5.retainAll(arr6);
		arr5.print();
		cout << endl <<"After retainAll fuction,size of first ArrayList :" << arr5.size() << endl << endl;

		cout << "Testing first ArrayList empty or not:" << endl;
		if(arr5.isEmpty()==1)
			cout <<"ArrayList is empty." << endl << endl;
		else 		
			cout << "ArrayList is not empty." << endl << endl;

	
		arr5.clear();
		cout << "Testing clear function : " ;
		arr5.print();
		cout << endl <<"After clear fuction,size of first ArrayList :" << arr5.size() << endl << endl;


		//Test for arraylist collection that is container string set.
		cout << "-----------TEST OF ARRAYLIST CLASS WITH CONTAINER STRING SET------------" << endl;
		ArrayList<string,set<string> > str5;
		str5.add("com");
		str5.add("pu");
		str5.add("ter");
		str5.add("sci");
		str5.add("ence");
		str5.add("temp");
		str5.add("la");
		str5.add("tes");
		cout << "First ArrayList elements:" ;
		str5.print();
		cout << endl;
		cout << "Size of first ArrayList :" << str5.size() << endl << endl;

		cout << "Second ArrayList elements:" ;
		ArrayList<string,set<string> > str6;
		str6.add("temp");
		str6.add("la");
		str6.add("tes");
		str6.print();
		cout << endl;
		cout << "Size of second ArrayList :" << str6.size() << endl << endl;
	
		cout << "After -ence- is removed in first  ArrayList: ";
		str5.remove("ence");
		str5.print();
		cout << endl;
		cout << "After removing of -ence-,size of first ArrayList :" << str5.size() << endl << endl;
		 

		cout << "Testing first ArrayList whether contains -sci- or not:" << endl;
		if(str5.contains("sci")==1)
			cout <<"ArrayList contains -sci-." << endl << endl;
		else 		
			cout << "ArrayList does not contain -sci-." << endl << endl;

		cout << "Testing first ArrayList whether contains all element second ArrayList or not :" << endl;
		if(str5.containsAll(str6)==1)
			cout <<"Every elements of second ArrayList is in first ArrayList." << endl << endl;
		else 		
			cout << "Every elements of second ArrayList is not in first ArrayList." << endl << endl;

		cout << "Testing RemoveAll function:" << endl;
		str5.removeAll(str6);
		cout << "After removing of elements in first ArrayList that is also contained second ArrayList : "; 
		str5.print();
		cout << endl;
		cout << "After RemoveAll function ,size of first ArrayList :" << str5.size() << endl << endl;

		cout <<"After second ArrayList added first ArrayList,so uploaded first ArrayList: ";
		str5.addAll(str6);
		str5.print();
		cout << endl;
		cout << "After addAll function ,size of first ArrayList :" << str5.size() << endl << endl;
	

		cout << "Testing RetainAll function:" << endl;
		cout << "After retains elements of first ArrayList that is also in second ArrayList: " ;
		str5.retainAll(str6);
		str5.print();
		cout << endl <<"After retainAll fuction,size of first ArrayList :" << str5.size() << endl << endl;

		cout << "Testing first ArrayList empty or not:" << endl;
		if(str5.isEmpty()==1)
			cout <<"ArrayList is empty." << endl << endl;
		else 		
			cout << "ArrayList is not empty." << endl << endl;

	
		str5.clear();
		cout << "Testing clear function : " ;
		str5.print();
		cout << endl <<"After clear fuction,size of first ArrayList :" << str5.size() << endl << endl;
	
	

		//Test for arraylist collection that is container int list.
		cout << "-----------TEST OF ARRAYLIST CLASS WITH CONTAINER INT LIST------------" << endl;
		ArrayList<int,list<int> > arr3;
		arr3.add(2);
		arr3.add(3);
		arr3.add(4);
		arr3.add(5);
		arr3.add(6);
		cout << "First ArrayList elements:" ;
		arr3.print();
		cout << endl;
		cout << "Size of first ArrayList :" << arr3.size() << endl << endl;

		cout << "Second ArrayList elements:" ;
		ArrayList<int,list<int> > arr4;
		arr4.add(4);
		arr4.add(5);
		arr4.add(8);
		arr4.print();
		cout << endl;
		cout << "Size of second ArrayList :" << arr4.size() << endl << endl;
	
		cout << "After 6 is removed in first  ArrayList: ";
		arr3.remove(6);
		arr3.print();
		cout << endl;
		cout << "After removing of 6,size of first ArrayList :" << arr3.size() << endl << endl;
		 

		cout << "Testing first ArrayList whether contains 3 or not:" << endl;
		if(arr3.contains(3)==1)
			cout <<"ArrayList contains 3." << endl << endl;
		else 		
			cout << "ArrayList does not contain 3." << endl << endl;

		cout << "Testing first ArrayList whether contains all element second ArrayList or not :" << endl;
		if(arr3.containsAll(arr4)==1)
			cout <<"Every elements of second ArrayList is in first ArrayList." << endl << endl;
		else 		
			cout << "Every elements of second ArrayList is not in first ArrayList." << endl << endl;

		cout << "Testing RemoveAll function:" << endl;
		arr3.removeAll(arr4);
		cout << "After removing of elements in first ArrayList that is also contained second ArrayList: ";
		arr3.print();
		cout << endl;
		cout << "After RemoveAll function ,size of first ArrayList :" << arr3.size() << endl << endl;

		cout <<"After second ArrayList added first ArrayList,so uploaded first ArrayList: ";
		arr3.addAll(arr4);
		arr3.print();
		cout << endl;
		cout << "After addAll function ,size of first ArrayList :" << arr3.size() << endl << endl;
	

		cout << "Testing RetainAll function:" << endl;
		cout << "After retains elements of first ArrayList that is also in second ArrayList: " ;
		arr3.retainAll(arr4);
		arr3.print();
		cout << endl <<"After retainAll fuction,size of first ArrayList :" << arr3.size() << endl << endl;

		cout << "Testing first ArrayList empty or not:" << endl;
		if(arr3.isEmpty()==1)
			cout <<"ArrayList is empty." << endl << endl;
		else 		
			cout << "ArrayList is not empty." << endl << endl;

	
		arr3.clear();
		cout << "Testing clear function : " ;
		arr3.print();
		cout << endl <<"After clear fuction,size of first ArrayList :" << arr3.size() << endl << endl;


		//Test for arraylist collection that is container string list.
		cout << "-----------TEST OF ARRAYLIST CLASS WITH CONTAINER STRING LIST------------" << endl;
		ArrayList<string,list<string> > str3;
		str3.add("com");
		str3.add("pu");
		str3.add("ter");
		str3.add("sci");
		str3.add("ence");
		str3.add("temp");
		str3.add("la");
		str3.add("tes");
		cout << "First ArrayList elements:" ;
		str3.print();
		cout << endl;
		cout << "Size of first ArrayList :" << str3.size() << endl << endl;

		cout << "Second ArrayList elements:" ;
		ArrayList<string,list<string> > str4;
		str4.add("temp");
		str4.add("la");
		str4.add("tes");
		str4.print();
		cout << endl;
		cout << "Size of second ArrayList :" << str4.size() << endl << endl;
	
		cout << "After -ence- is removed in first  ArrayList: ";
		str3.remove("ence");
		str3.print();
		cout << endl;
		cout << "After removing of -ence-,size of first ArrayList :" << str3.size() << endl << endl;
		 

		cout << "Testing first ArrayList whether contains -sci- or not:" << endl;
		if(str3.contains("sci")==1)
			cout <<"ArrayList contains -sci-." << endl << endl;
		else 		
			cout << "ArrayList does not contain -sci-." << endl << endl;

		cout << "Testing first ArrayList whether contains all element second ArrayList or not :" << endl;
		if(str3.containsAll(str4)==1)
			cout <<"Every elements of second ArrayList is in first ArrayList." << endl << endl;
		else 		
			cout << "Every elements of second ArrayList is not in first ArrayList." << endl << endl;

		cout << "Testing RemoveAll function:" << endl;
		str3.removeAll(str4);
		cout << "After removing of elements in first ArrayList that is also contained second ArrayList : "; 
		str3.print();
		cout << endl;
		cout << "After RemoveAll function ,size of first ArrayList :" << str3.size() << endl << endl;

		cout <<"After second ArrayList added first ArrayList,so uploaded first ArrayList: ";
		str3.addAll(str4);
		str3.print();
		cout << endl;
		cout << "After addAll function ,size of first ArrayList :" << str3.size() << endl << endl;
	

		cout << "Testing RetainAll function:" << endl;
		cout << "After retains elements of first ArrayList that is also in second ArrayList: " ;
		str3.retainAll(str4);
		str3.print();
		cout << endl <<"After retainAll fuction,size of first ArrayList :" << str3.size() << endl << endl;

		cout << "Testing first ArrayList empty or not:" << endl;
		if(str3.isEmpty()==1)
			cout <<"ArrayList is empty." << endl << endl;
		else 		
			cout << "ArrayList is not empty." << endl << endl;

	
		str3.clear();
		cout << "Testing clear function : " ;
		str3.print();
		cout << endl <<"After clear fuction,size of first ArrayList :" << str3.size() << endl << endl;


		//Test for hashset collection that is container int vector.
		cout << "-----------TEST OF HASHSET CLASS WITH CONTAINER INT VECTOR------------" << endl;
		HashSet<int,vector<int> > hs;
		hs.add(2);
		hs.add(3);
		hs.add(4);
		hs.add(5);
		hs.add(6);
		cout << "First HashSet elements:" ;
		hs.print();
		cout << endl;
		cout << "Size of first HashSet :" << hs.size() << endl << endl;

		cout << "Second HashSet elements:" ;
		HashSet<int,vector<int> > hs2;
		hs2.add(4);
		hs2.add(5);
		hs2.add(8);
		hs2.print();
		cout << endl;
		cout << "Size of second HashSet :" << hs2.size() << endl << endl;
	
		cout << "After 6 is removed in first  HashSet: ";
		hs.remove(6);
		hs.print();
		cout << endl;
		cout << "After removing of 6,size of first HashSet :" << hs.size() << endl << endl;
		 

		cout << "Testing first HashSet whether contains 3 or not:" << endl;
		if(hs.contains(3)==1)
			cout <<"HashSet contains 3." << endl << endl;
		else 		
			cout << "HashSet does not contain 3." << endl << endl;

		cout << "Testing first HashSet whether contains all element second HashSet or not :" << endl;
		if(hs.containsAll(hs2)==1)
			cout <<"Every elements of second HashSet is in first HashSet." << endl << endl;
		else 		
			cout << "Every elements of second HashSet is not in first HashSet." << endl << endl;

		cout << "Testing RemoveAll function:" << endl;
		hs.removeAll(hs2);
		cout << "After removing of elements in first HashSet that is also contained second HashSet: ";
		hs.print();
		cout << endl;
		cout << "After RemoveAll function ,size of first HashSet :" << hs.size() << endl << endl;

		cout <<"After second HashSet added first HashSet,so uploaded first HashSet: ";
		hs.addAll(hs2);
		hs.print();
		cout << endl;
		cout << "After addAll function ,size of first HashSet :" << hs.size() << endl << endl;
	

		cout << "Testing RetainAll function:" << endl;
		cout << "After retains elements of first HashSet that is also in second ArrayList: " ;
		hs.retainAll(hs2);
		hs.print();
		cout << endl <<"After retainAll fuction,size of first HashSet :" << hs.size() << endl << endl;

		cout << "Testing first HashSet empty or not:" << endl;
		if(hs.isEmpty()==1)
			cout <<"HashSet is empty." << endl << endl;
		else 		
			cout << "HashSet is not empty." << endl << endl;

	
		hs.clear();
		cout << "Testing clear function : " ;
		hs.print();
		cout << endl <<"After clear fuction,size of first HashSet :" << hs.size() << endl << endl;

		
		//Test for hashset collection that is container string vector.
		cout << "-----------TEST OF HASHSET CLASS WITH CONTAINER STRING VECTOR------------" << endl;
		HashSet<string,vector<string> > hs_str;
		hs_str.add("com");
		hs_str.add("pu");
		hs_str.add("ter");
		hs_str.add("sci");
		hs_str.add("ence");
		hs_str.add("temp");
		hs_str.add("la");
		hs_str.add("tes");
		cout << "First HashSet elements:" ;
		hs_str.print();
		cout << endl;
		cout << "Size of first HashSet :" << hs_str.size() << endl << endl;

		cout << "Second HashSet elements:" ;
		HashSet<string,vector<string> > hs_str2;
		hs_str2.add("temp");
		hs_str2.add("la");
		hs_str2.add("tes");
		hs_str2.print();
		cout << endl;
		cout << "Size of second HashSet :" << hs_str2.size() << endl << endl;
	
		cout << "After -ence- is removed in first  HashSet: ";
		hs_str.remove("ence");
		hs_str.print();
		cout << endl;
		cout << "After removing of -ence-,size of first HashSet :" << hs_str.size() << endl << endl;
		 

		cout << "Testing first HashSet whether contains -sci- or not:" << endl;
		if(hs_str.contains("sci")==1)
			cout <<"HashSet contains -sci-." << endl << endl;
		else 		
			cout << "HashSet does not contain -sci-." << endl << endl;

		cout << "Testing first HashSet whether contains all element second HashSet or not :" << endl;
		if(hs_str.containsAll(hs_str2)==1)
			cout <<"Every elements of second HashSet is in first HashSet." << endl << endl;
		else 		
			cout << "Every elements of second HashSet is not in first HashSet." << endl << endl;

		cout << "Testing RemoveAll function:" << endl;
		hs_str.removeAll(hs_str2);
		cout << "After removing of elements in first HashSet that is also contained second HashSet : "; 
		hs_str.print();
		cout << endl;
		cout << "After RemoveAll function ,size of first HashSet :" << hs_str.size() << endl << endl;

		cout <<"After second HashSet added first HashSet,so uploaded first HashSet: ";
		hs_str.addAll(hs_str2);
		hs_str.print();
		cout << endl;
		cout << "After addAll function ,size of first HashSet :" << hs_str.size() << endl << endl;
	

		cout << "Testing RetainAll function:" << endl;
		cout << "After retains elements of first HashSet that is also in second HashSet: " ;
		hs_str.retainAll(hs_str2);
		hs_str.print();
		cout << endl <<"After retainAll fuction,size of first HashSet :" << hs_str.size() << endl << endl;

		cout << "Testing first HashSet empty or not:" << endl;
		if(hs_str.isEmpty()==1)
			cout <<"HashSet is empty." << endl << endl;
		else 		
			cout << "HashSet is not empty." << endl << endl;

	
		hs_str.clear();
		cout << "Testing clear function : " ;
		hs_str.print();
		cout << endl <<"After clear fuction,size of first HashSet :" << hs_str.size() << endl << endl;

		//Test for hashset collection that is container int set.
		cout << "-----------TEST OF HASHSET CLASS WITH CONTAINER INT SET------------" << endl;
		HashSet<int,set<int> > hs3;
		hs3.add(2);
		hs3.add(3);
		hs3.add(4);
		hs3.add(5);
		hs3.add(6);
		cout << "First HashSet elements:" ;
		hs3.print();
		cout << endl;
		cout << "Size of first HashSet :" << hs3.size() << endl << endl;

		cout << "Second HashSet elements:" ;
		HashSet<int,set<int> > hs4;
		hs4.add(4);
		hs4.add(5);
		hs4.add(8);
		hs4.print();
		cout << endl;
		cout << "Size of second HashSet :" << hs4.size() << endl << endl;
	
		cout << "After 6 is removed in first  HashSet: ";
		hs3.remove(6);
		hs3.print();
		cout << endl;
		cout << "After removing of 6,size of first HashSet :" << hs3.size() << endl << endl;
		 

		cout << "Testing first HashSet whether contains 3 or not:" << endl;
		if(hs3.contains(3)==1)
			cout <<"HashSet contains 3." << endl << endl;
		else 		
			cout << "HashSet does not contain 3." << endl << endl;

		cout << "Testing first HashSet whether contains all element second HashSet or not :" << endl;
		if(hs3.containsAll(hs4)==1)
			cout <<"Every elements of second HashSet is in first HashSet." << endl << endl;
		else 		
			cout << "Every elements of second HashSet is not in first HashSet." << endl << endl;

		cout << "Testing RemoveAll function:" << endl;
		hs3.removeAll(hs4);
		cout << "After removing of elements in first HashSet that is also contained second HashSet: ";
		hs3.print();
		cout << endl;
		cout << "After RemoveAll function ,size of first HashSet :" << hs3.size() << endl << endl;

		cout <<"After second HashSet added first HashSet,so uploaded first HashSet: ";
		hs3.addAll(hs4);
		hs3.print();
		cout << endl;
		cout << "After addAll function ,size of first HashSet :" << hs3.size() << endl << endl;
	

		cout << "Testing RetainAll function:" << endl;
		cout << "After retains elements of first HashSet that is also in second ArrayList: " ;
		hs3.retainAll(hs4);
		hs3.print();
		cout << endl <<"After retainAll fuction,size of first HashSet :" << hs3.size() << endl << endl;

		cout << "Testing first HashSet empty or not:" << endl;
		if(hs3.isEmpty()==1)
			cout <<"HashSet is empty." << endl << endl;
		else 		
			cout << "HashSet is not empty." << endl << endl;

	
		hs3.clear();
		cout << "Testing clear function : " ;
		hs3.print();
		cout << endl <<"After clear fuction,size of first HashSet :" << hs3.size() << endl << endl;


		//Test for hashset collection that is container string set.
		cout << "-----------TEST OF HASHSET CLASS WITH CONTAINER STRING SET------------" << endl;
		HashSet<string,set<string> > hs3_str;
		hs3_str.add("com");
		hs3_str.add("pu");
		hs3_str.add("ter");
		hs3_str.add("sci");
		hs3_str.add("ence");
		hs3_str.add("temp");
		hs3_str.add("la");
		hs3_str.add("tes");
		cout << "First HashSet elements:" ;
		hs3_str.print();
		cout << endl;
		cout << "Size of first HashSet :" << hs3_str.size() << endl << endl;

		cout << "Second HashSet elements:" ;
		HashSet<string,set<string> > hs_str4;
		hs_str4.add("temp");
		hs_str4.add("la");
		hs_str4.add("tes");
		hs_str4.print();
		cout << endl;
		cout << "Size of second HashSet :" << hs_str4.size() << endl << endl;
	
		cout << "After -ence- is removed in first  HashSet: ";
		hs3_str.remove("ence");
		hs3_str.print();
		cout << endl;
		cout << "After removing of -ence-,size of first HashSet :" << hs3_str.size() << endl << endl;
		 

		cout << "Testing first HashSet whether contains -sci- or not:" << endl;
		if(hs3_str.contains("sci")==1)
			cout <<"HashSet contains -sci-." << endl << endl;
		else 		
			cout << "HashSet does not contain -sci-." << endl << endl;

		cout << "Testing first HashSet whether contains all element second HashSet or not :" << endl;
		if(hs3_str.containsAll(hs_str4)==1)
			cout <<"Every elements of second HashSet is in first HashSet." << endl << endl;
		else 		
			cout << "Every elements of second HashSet is not in first HashSet." << endl << endl;

		cout << "Testing RemoveAll function:" << endl;
		hs3_str.removeAll(hs_str4);
		cout << "After removing of elements in first HashSet that is also contained second HashSet : "; 
		hs3_str.print();
		cout << endl;
		cout << "After RemoveAll function ,size of first HashSet :" << hs3_str.size() << endl << endl;

		cout <<"After second HashSet added first HashSet,so uploaded first HashSet: ";
		hs3_str.addAll(hs_str4);
		hs3_str.print();
		cout << endl;
		cout << "After addAll function ,size of first HashSet :" << hs3_str.size() << endl << endl;
	

		cout << "Testing RetainAll function:" << endl;
		cout << "After retains elements of first HashSet that is also in second HashSet: " ;
		hs3_str.retainAll(hs_str4);
		hs3_str.print();
		cout << endl <<"After retainAll fuction,size of first HashSet :" << hs3_str.size() << endl << endl;

		cout << "Testing first HashSet empty or not:" << endl;
		if(hs3_str.isEmpty()==1)
			cout <<"HashSet is empty." << endl << endl;
		else 		
			cout << "HashSet is not empty." << endl << endl;

	
		hs3_str.clear();
		cout << "Testing clear function : " ;
		hs3_str.print();
		cout << endl <<"After clear fuction,size of first HashSet :" << hs3_str.size() << endl << endl;

		//Test for hashset collection that is container int list.
		cout << "-----------TEST OF HASHSET CLASS WITH CONTAINER INT LIST------------" << endl;
		HashSet<int,list<int> > hs5;
		hs5.add(2);
		hs5.add(3);
		hs5.add(4);
		hs5.add(5);
		hs5.add(6);
		cout << "First HashSet elements:" ;
		hs5.print();
		cout << endl;
		cout << "Size of first HashSet :" << hs5.size() << endl << endl;

		cout << "Second HashSet elements:" ;
		HashSet<int,list<int> > hs6;
		hs6.add(4);
		hs6.add(5);
		hs6.add(8);
		hs6.print();
		cout << endl;
		cout << "Size of second HashSet :" << hs6.size() << endl << endl;
	
		cout << "After 6 is removed in first  HashSet: ";
		hs5.remove(6);
		hs5.print();
		cout << endl;
		cout << "After removing of 6,size of first HashSet :" << hs5.size() << endl << endl;
		 

		cout << "Testing first HashSet whether contains 3 or not:" << endl;
		if(hs5.contains(3)==1)
			cout <<"HashSet contains 3." << endl << endl;
		else 		
			cout << "HashSet does not contain 3." << endl << endl;

		cout << "Testing first HashSet whether contains all element second HashSet or not :" << endl;
		if(hs5.containsAll(hs6)==1)
			cout <<"Every elements of second HashSet is in first HashSet." << endl << endl;
		else 		
			cout << "Every elements of second HashSet is not in first HashSet." << endl << endl;

		cout << "Testing RemoveAll function:" << endl;
		hs5.removeAll(hs6);
		cout << "After removing of elements in first HashSet that is also contained second HashSet: ";
		hs5.print();
		cout << endl;
		cout << "After RemoveAll function ,size of first HashSet :" << hs5.size() << endl << endl;

		cout <<"After second HashSet added first HashSet,so uploaded first HashSet: ";
		hs5.addAll(hs6);
		hs5.print();
		cout << endl;
		cout << "After addAll function ,size of first HashSet :" << hs5.size() << endl << endl;
	

		cout << "Testing RetainAll function:" << endl;
		cout << "After retains elements of first HashSet that is also in second HashSet: " ;
		hs5.retainAll(hs6);
		hs5.print();
		cout << endl <<"After retainAll fuction,size of first HashSet :" << hs5.size() << endl << endl;

		cout << "Testing first HashSet empty or not:" << endl;
		if(hs5.isEmpty()==1)
			cout <<"HashSet is empty." << endl << endl;
		else 		
			cout << "HashSet is not empty." << endl << endl;

	
		hs5.clear();
		cout << "Testing clear function : " ;
		hs5.print();
		cout << endl <<"After clear fuction,size of first HashSet :" << hs5.size() << endl << endl;


		//Test for hashset collection that is container string list.
		cout << "-----------TEST OF HASHSET CLASS WITH CONTAINER STRING LIST------------" << endl;
		HashSet<string,list<string> > hs4_str;
		hs4_str.add("com");
		hs4_str.add("pu");
		hs4_str.add("ter");
		hs4_str.add("sci");
		hs4_str.add("ence");
		hs4_str.add("temp");
		hs4_str.add("la");
		hs4_str.add("tes");	
		cout << "First HashSet elements:" ;
		hs4_str.print();
		cout << endl;
		cout << "Size of first HashSet :" << hs4_str.size() << endl << endl;

		cout << "Second HashSet elements:" ;
		HashSet<string,list<string> > hs_str5;
		hs_str5.add("temp");
		hs_str5.add("la");
		hs_str5.add("tes");
		hs_str5.print();
		cout << endl;
		cout << "Size of second HashSet :" << hs_str5.size() << endl << endl;
	
		cout << "After -ence- is removed in first  HashSet: ";
		hs4_str.remove("ence");
		hs4_str.print();
		cout << endl;
		cout << "After removing of -ence-,size of first HashSet :" << hs4_str.size() << endl << endl;
		 

		cout << "Testing first HashSet whether contains -sci- or not:" << endl;
		if(hs4_str.contains("sci")==1)
			cout <<"HashSet contains -sci-." << endl << endl;
		else 		
			cout << "HashSet does not contain -sci-." << endl << endl;

		cout << "Testing first HashSet whether contains all element second HashSet or not :" << endl;
		if(hs4_str.containsAll(hs_str5)==1)
			cout <<"Every elements of second HashSet is in first HashSet." << endl << endl;
		else 		
			cout << "Every elements of second HashSet is not in first HashSet." << endl << endl;

		cout << "Testing RemoveAll function:" << endl;
		hs4_str.removeAll(hs_str5);
		cout << "After removing of elements in first HashSet that is also contained second HashSet : "; 
		hs4_str.print();
		cout << endl;
		cout << "After RemoveAll function ,size of first HashSet :" << hs4_str.size() << endl << endl;

		cout <<"After second HashSet added first HashSet,so uploaded first HashSet: ";
		hs4_str.addAll(hs_str5);
		hs4_str.print();
		cout << endl;
		cout << "After addAll function ,size of first HashSet :" << hs4_str.size() << endl << endl;
	

		cout << "Testing RetainAll function:" << endl;
		cout << "After retains elements of first HashSet that is also in second HashSet: " ;
		hs4_str.retainAll(hs_str5);
		hs4_str.print();
		cout << endl <<"After retainAll fuction,size of first HashSet :" << hs4_str.size() << endl << endl;

		cout << "Testing first HashSet empty or not:" << endl;
		if(hs4_str.isEmpty()==1)
			cout <<"HashSet is empty." << endl << endl;
		else 		
			cout << "HashSet is not empty." << endl << endl;

	
		hs4_str.clear();
		cout << "Testing clear function : " ;
		hs4_str.print();
		cout << endl <<"After clear fuction,size of first HashSet :" << hs4_str.size() << endl << endl;

		//Test for linkedlist collection that is container int vector.
		cout << "-----------TEST OF LINKEDLIST CLASS WITH CONTAINER INT VECTOR------------" << endl;
		LinkedList<int,vector<int> > ll;
		ll.add(2);
		ll.add(3);
		ll.add(4);
		ll.add(5);
		ll.add(6);
		cout << "First LinkedList elements:" ;
		ll.print();
		cout << endl;
		cout << "Size of first LinkedList :" << ll.size() << endl << endl;

		cout << "Second LinkedList elements:" ;
		LinkedList<int,vector<int> > ll2;
		ll2.add(4);
		ll2.add(5);
		ll2.add(8);
		ll2.print();
		cout << endl;
		cout << "Size of second LinkedList :" << ll2.size() << endl << endl;
	
		cout << "After 6 is removed in first  LinkedList: ";
		ll.remove(6);
		ll.print();
		cout << endl;
		cout << "After removing of 6,size of first LinkedList :" << ll.size() << endl << endl;
		 

		cout << "Testing first LinkedList whether contains 3 or not:" << endl;
		if(ll.contains(3)==1)
			cout <<"LinkedList contains 3." << endl << endl;
		else 		
			cout << "LinkedList does not contain 3." << endl << endl;

		cout << "Testing first LinkedList whether contains all element second LinkedList or not :" << endl;
		if(ll.containsAll(ll2)==1)
			cout <<"Every elements of second LinkedList is in first LinkedList." << endl << endl;
		else 		
			cout << "Every elements of second LinkedList is not in first LinkedList." << endl << endl;

		cout << "Testing RemoveAll function:" << endl;
		ll.removeAll(ll2);
		cout << "After removing of elements in first LinkedList that is also contained second LinkedList: ";
		ll.print();
		cout << endl;
		cout << "After RemoveAll function ,size of first LinkedList :" << ll.size() << endl << endl;

		cout <<"After second LinkedList added first LinkedList,so uploaded first LinkedList: ";
		ll.addAll(ll2);
		ll.print();
		cout << endl;
		cout << "After addAll function ,size of first LinkedList :" << ll.size() << endl << endl;
	

		cout << "Testing RetainAll function:" << endl;
		cout << "After retains elements of first LinkedList that is also in second LinkedList: " ;
		ll.retainAll(ll2);
		ll.print();
		cout << endl <<"After retainAll fuction,size of first LinkedList :" << ll.size() << endl << endl;

		cout << "Testing first LinkedList empty or not:" << endl;
		if(ll.isEmpty()==1)
			cout <<"LinkedList is empty." << endl << endl;
		else 		
			cout << "LinkedList is not empty." << endl << endl;

		cout << "Testing offer function:" << endl;
		cout << "After inserting specified element: ";
		ll.offer(9);
		ll.print();
		cout << endl << endl;

		cout << "Testing element function:" << endl;
		cout << "After retrieved, but does not removed, the head of linkedlist." << endl;
		cout << "Returned value: " << ll.element() << endl << endl;

		cout << "Testing poll function:" << endl;
		cout << "After retrieved and removed, the head of linkedlist." << endl;
		cout << "Returned value: " << ll.poll() << endl ;
		cout << "Last version: " ;
		ll.print();
		cout << endl << endl;

	
		ll.clear();
		cout << "Testing clear function : " ;
		ll.print();
		cout << endl <<"After clear fuction,size of first LinkedList :" << ll.size() << endl << endl;


		//Test for linkedlist collection that is container string vector.
		cout << "-----------TEST OF LINKEDLIST CLASS WITH CONTAINER STRING VECTOR------------" << endl;
		LinkedList<string,vector<string> > ll_str;
		ll_str.add("com");
		ll_str.add("pu");
		ll_str.add("ter");
		ll_str.add("sci");
		ll_str.add("ence");
		ll_str.add("temp");
		ll_str.add("la");
		ll_str.add("tes");
		cout << "First LinkedList elements:" ;
		ll_str.print();
		cout << endl;
		cout << "Size of first LinkedList :" << ll_str.size() << endl << endl;

		cout << "Second LinkedList elements:" ;
		LinkedList<string,vector<string> > ll_str2;
		ll_str2.add("temp");
		ll_str2.add("la");
		ll_str2.add("tes");
		ll_str2.print();
		cout << endl;
		cout << "Size of second LinkedList :" << ll_str2.size() << endl << endl;
	
		cout << "After -ence- is removed in first  LinkedList: ";
		ll_str.remove("ence");
		ll_str.print();
		cout << endl;
		cout << "After removing of -ence-,size of first LinkedList :" << ll_str.size() << endl << endl;
		 

		cout << "Testing first LinkedList whether contains -sci- or not:" << endl;
		if(ll_str.contains("sci")==1)
			cout <<"LinkedList contains -sci-." << endl << endl;
		else 		
			cout << "LinkedList does not contain -sci-." << endl << endl;

		cout << "Testing first LinkedList whether contains all element second LinkedList or not :" << endl;
		if(ll_str.containsAll(ll_str2)==1)
			cout <<"Every elements of second LinkedList is in first LinkedList." << endl << endl;
		else 		
			cout << "Every elements of second LinkedList is not in first LinkedList." << endl << endl;

		cout << "Testing RemoveAll function:" << endl;
		ll_str.removeAll(ll_str2);
		cout << "After removing of elements in first LinkedList that is also contained second LinkedList : "; 
		ll_str.print();
		cout << endl;
		cout << "After RemoveAll function ,size of first LinkedList :" << ll_str.size() << endl << endl;

		cout <<"After second LinkedList added first LinkedList,so uploaded first LinkedList: ";
		ll_str.addAll(ll_str2);
		ll_str.print();
		cout << endl;
		cout << "After addAll function ,size of first LinkedList :" << ll_str.size() << endl << endl;
	

		cout << "Testing RetainAll function:" << endl;
		cout << "After retains elements of first LinkedList that is also in second LinkedList: " ;
		ll_str.retainAll(ll_str2);
		ll_str.print();
		cout << endl <<"After retainAll fuction,size of first LinkedList :" << ll_str.size() << endl << endl;

		cout << "Testing first LinkedList empty or not:" << endl;
		if(ll_str.isEmpty()==1)
			cout <<"LinkedList is empty." << endl << endl;
		else 				
			cout << "LinkedList is not empty." << endl << endl;

		cout << "Testing offer function:" << endl;
		cout << "After inserting specified element: ";
		ll_str.offer("CSE");
		ll_str.print();
		cout << endl << endl;

		cout << "Testing element function:" << endl;
		cout << "After retrieved, but does not removed, the head of linkedlist." << endl;
		cout << "Returned value: " << ll_str.element() << endl << endl;

		cout << "Testing poll function:" << endl;
		cout << "After retrieved and removed, the head of linkedlist." << endl;
		cout << "Returned value: " << ll_str.poll() << endl ;
		cout << "Last version: " ;
		ll_str.print();
		cout << endl << endl;


	
		ll_str.clear();
		cout << "Testing clear function : " ;
		ll_str.print();
		cout << endl <<"After clear fuction,size of first LinkedList :" << ll_str.size() << endl << endl;


		//Test for linkedlist collection that is container int set.
		cout << "-----------TEST OF LINKEDLIST CLASS WITH CONTAINER INT SET------------" << endl;
		LinkedList<int,set<int> > ll3;
		ll3.add(2);
		ll3.add(3);
		ll3.add(4);
		ll3.add(5);
		ll3.add(6);
		cout << "First LinkedList elements:" ;
		ll3.print();
		cout << endl;
		cout << "Size of first LinkedList :" << ll3.size() << endl << endl;

		cout << "Second LinkedList elements:" ;
		LinkedList<int,set<int> > ll4;
		ll4.add(4);
		ll4.add(5);
		ll4.add(8);
		ll4.print();
		cout << endl;
		cout << "Size of second LinkedList :" << ll4.size() << endl << endl;
	
		cout << "After 6 is removed in first  LinkedList: ";
		ll3.remove(6);
		ll3.print();
		cout << endl;
		cout << "After removing of 6,size of first LinkedList :" << ll3.size() << endl << endl;
		 

		cout << "Testing first LinkedList whether contains 3 or not:" << endl;
		if(ll3.contains(3)==1)
			cout <<"LinkedList contains 3." << endl << endl;
		else 		
			cout << "LinkedList does not contain 3." << endl << endl;

		cout << "Testing first LinkedList whether contains all element second LinkedList or not :" << endl;
		if(ll3.containsAll(ll4)==1)
			cout <<"Every elements of second LinkedList is in first LinkedList." << endl << endl;
		else 		
			cout << "Every elements of second LinkedList is not in first LinkedList." << endl << endl;

		cout << "Testing RemoveAll function:" << endl;
		ll3.removeAll(ll4);
		cout << "After removing of elements in first LinkedList that is also contained second LinkedList: ";
		ll3.print();
		cout << endl;
		cout << "After RemoveAll function ,size of first LinkedList :" << ll3.size() << endl << endl;

		cout <<"After second LinkedList added first LinkedList,so uploaded first LinkedList: ";
		ll3.addAll(ll4);
		ll3.print();
		cout << endl;
		cout << "After addAll function ,size of first LinkedList :" << ll3.size() << endl << endl;
	

		cout << "Testing RetainAll function:" << endl;
		cout << "After retains elements of first LinkedList that is also in second LinkedList: " ;
		ll3.retainAll(ll4);
		ll3.print();
		cout << endl <<"After retainAll fuction,size of first LinkedList :" << ll3.size() << endl << endl;

		cout << "Testing first LinkedList empty or not:" << endl;
		if(ll3.isEmpty()==1)
			cout <<"LinkedList is empty." << endl << endl;
		else 		
			cout << "LinkedList is not empty." << endl << endl;

	
		cout << "Testing offer function:" << endl;
		cout << "After inserting specified element: ";
		ll3.offer(9);
		ll3.print();
		cout << endl << endl;

		cout << "Testing element function:" << endl;
		cout << "After retrieved, but does not removed, the head of linkedlist." << endl;
		cout << "Returned value: " << ll3.element() << endl << endl;

		cout << "Testing poll function:" << endl;
		cout << "After retrieved and removed, the head of linkedlist." << endl;
		cout << "Returned value: " << ll3.poll() << endl ;
		cout << "Last version: " ;
		ll3.print();
		cout << endl << endl;

		ll3.clear();
		cout << "Testing clear function : " ;
		ll3.print();
		cout << endl <<"After clear fuction,size of first LinkedList :" << ll3.size() << endl << endl;


		//Test for linkedlist collection that is container string set.
		cout << "-----------TEST OF LINKEDLIST CLASS WITH CONTAINER STRING SET------------" << endl;
		LinkedList<string,set<string> > ll2_str;
		ll2_str.add("com");
		ll2_str.add("pu");
		ll2_str.add("ter");
		ll2_str.add("sci");
		ll2_str.add("ence");
		ll2_str.add("temp");
		ll2_str.add("la");
		ll2_str.add("tes");
		cout << "First LinkedList elements:" ;
		ll2_str.print();
		cout << endl;
		cout << "Size of first LinkedList :" << ll2_str.size() << endl << endl;

		cout << "Second LinkedList elements:" ;
		LinkedList<string,set<string> > ll_str3;
		ll_str3.add("temp");
		ll_str3.add("la");
		ll_str3.add("tes");
		ll_str3.print();
		cout << endl;
		cout << "Size of second LinkedList :" << ll_str3.size() << endl << endl;
	
		cout << "After -ence- is removed in first  LinkedList: ";
		ll2_str.remove("ence");	
		ll2_str.print();
		cout << endl;
		cout << "After removing of -ence-,size of first LinkedList :" << ll2_str.size() << endl << endl;
		 

		cout << "Testing first LinkedList whether contains -sci- or not:" << endl;
		if(ll2_str.contains("sci")==1)
			cout <<"LinkedList contains -sci-." << endl << endl;
		else 		
			cout << "LinkedList does not contain -sci-." << endl << endl;

		cout << "Testing first LinkedList whether contains all element second LinkedList or not :" << endl;
		if(ll2_str.containsAll(ll_str3)==1)
			cout <<"Every elements of second LinkedList is in first LinkedList." << endl << endl;
		else 		
			cout << "Every elements of second LinkedList is not in first LinkedList." << endl << endl;

		cout << "Testing RemoveAll function:" << endl;
		ll2_str.removeAll(ll_str3);
		cout << "After removing of elements in first LinkedList that is also contained second LinkedList : "; 
		ll2_str.print();
		cout << endl;
		cout << "After RemoveAll function ,size of first LinkedList :" << ll2_str.size() << endl << endl;

		cout <<"After second LinkedList added first LinkedList,so uploaded first LinkedList: ";
		ll2_str.addAll(ll_str3);
		ll2_str.print();
		cout << endl;
		cout << "After addAll function ,size of first LinkedList :" << ll2_str.size() << endl << endl;
	

		cout << "Testing RetainAll function:" << endl;
		cout << "After retains elements of first LinkedList that is also in second LinkedList: " ;
		ll2_str.retainAll(ll_str3);
		ll2_str.print();
		cout << endl <<"After retainAll fuction,size of first LinkedList :" << ll2_str.size() << endl << endl;

		cout << "Testing first LinkedList empty or not:" << endl;
		if(ll2_str.isEmpty()==1)
			cout <<"LinkedList is empty." << endl << endl;
		else 				
			cout << "LinkedList is not empty." << endl << endl;


		cout << "Testing offer function:" << endl;
		cout << "After inserting specified element: ";
		ll2_str.offer("CSE");
		ll2_str.print();
		cout << endl << endl;

		cout << "Testing element function:" << endl;
		cout << "After retrieved, but does not removed, the head of linkedlist." << endl;
		cout << "Returned value: " << ll2_str.element() << endl << endl;

		cout << "Testing poll function:" << endl;
		cout << "After retrieved and removed, the head of linkedlist." << endl;
		cout << "Returned value: " << ll2_str.poll() << endl ;
		cout << "Last version: " ;
		ll2_str.print();
		cout << endl << endl;


	
		ll2_str.clear();
		cout << "Testing clear function : " ;
		ll2_str.print();
		cout << endl <<"After clear fuction,size of first LinkedList :" << ll2_str.size() << endl << endl;

		//Test for linkedlist collection that is container int list.	
		cout << "-----------TEST OF LINKEDLIST CLASS WITH CONTAINER INT LIST------------" << endl;
		LinkedList<int,list<int> > ll5;
		ll5.add(2);
		ll5.add(3);
		ll5.add(4);
		ll5.add(5);
		ll5.add(6);
		cout << "First LinkedList elements:" ;
		ll5.print();
		cout << endl;
		cout << "Size of first LinkedList :" << ll5.size() << endl << endl;

		cout << "Second LinkedList elements:" ;
		LinkedList<int,list<int> > ll6;
		ll6.add(4);
		ll6.add(5);
		ll6.add(8);
		ll6.print();
		cout << endl;
		cout << "Size of second LinkedList :" << ll6.size() << endl << endl;
	
		cout << "After 6 is removed in first  LinkedList: ";
		ll5.remove(6);
		ll5.print();
		cout << endl;
		cout << "After removing of 6,size of first LinkedList :" << ll5.size() << endl << endl;
		 

		cout << "Testing first LinkedList whether contains 3 or not:" << endl;
		if(ll5.contains(3)==1)
			cout <<"LinkedList contains 3." << endl << endl;
		else 		
			cout << "LinkedList does not contain 3." << endl << endl;

		cout << "Testing first LinkedList whether contains all element second LinkedList or not :" << endl;
		if(ll5.containsAll(ll6)==1)
			cout <<"Every elements of second LinkedList is in first LinkedList." << endl << endl;
		else 		
			cout << "Every elements of second LinkedList is not in first LinkedList." << endl << endl;

		cout << "Testing RemoveAll function:" << endl;
		ll5.removeAll(ll6);
		cout << "After removing of elements in first LinkedList that is also contained second LinkedList: ";
		ll5.print();
		cout << endl;
		cout << "After RemoveAll function ,size of first LinkedList :" << ll5.size() << endl << endl;

		cout <<"After second LinkedList added first LinkedList,so uploaded first LinkedList: ";
		ll5.addAll(ll6);
		ll5.print();
		cout << endl;
		cout << "After addAll function ,size of first LinkedList :" << ll5.size() << endl << endl;
	

		cout << "Testing RetainAll function:" << endl;
		cout << "After retains elements of first LinkedList that is also in second LinkedList: " ;
		ll5.retainAll(ll6);
		ll5.print();
		cout << endl <<"After retainAll fuction,size of first LinkedList :" << ll6.size() << endl << endl;

		cout << "Testing first LinkedList empty or not:" << endl;
		if(ll5.isEmpty()==1)
			cout <<"LinkedList is empty." << endl << endl;
		else 		
			cout << "LinkedList is not empty." << endl << endl;

		
		cout << "Testing offer function:" << endl;
		cout << "After inserting specified element: ";
		ll5.offer(9);
		ll5.print();
		cout << endl << endl;

		cout << "Testing element function:" << endl;
		cout << "After retrieved, but does not removed, the head of linkedlist." << endl;
		cout << "Returned value: " << ll5.element() << endl << endl;

		cout << "Testing poll function:" << endl;
		cout << "After retrieved and removed, the head of linkedlist." << endl;
		cout << "Returned value: " << ll5.poll() << endl ;
		cout << "Last version: " ;
		ll5.print();
		cout << endl << endl;

	
	
		ll5.clear();
		cout << "Testing clear function : " ;
		ll5.print();
		cout << endl <<"After clear fuction,size of first LinkedList :" << ll5.size() << endl << endl;


		//Test for linkedlist collection that is container string list.
		cout << "-----------TEST OF LINKEDLIST CLASS WITH CONTAINER STRING LIST------------" << endl;
		LinkedList<string,list<string> > ll3_str;
		ll3_str.add("com");
		ll3_str.add("pu");
		ll3_str.add("ter");
		ll3_str.add("sci");
		ll3_str.add("ence");
		ll3_str.add("temp");
		ll3_str.add("la");
		ll3_str.add("tes");
		cout << "First LinkedList elements:" ;
		ll3_str.print();
		cout << endl;
		cout << "Size of first LinkedList :" << ll3_str.size() << endl << endl;

		cout << "Second LinkedList elements:" ;
		LinkedList<string,list<string> > ll_str5;
		ll_str5.add("temp");
		ll_str5.add("la");
		ll_str5.add("tes");
		ll_str5.print();
		cout << endl;
		cout << "Size of second LinkedList :" << ll_str5.size() << endl << endl;
	
		cout << "After -ence- is removed in first  LinkedList: ";
		ll3_str.remove("ence");
		ll3_str.print();
		cout << endl;
		cout << "After removing of -ence-,size of first LinkedList :" << ll3_str.size() << endl << endl;
		 

		cout << "Testing first LinkedList whether contains -sci- or not:" << endl;
		if(ll3_str.contains("sci")==1)
			cout <<"LinkedList contains -sci-." << endl << endl;
		else 		
			cout << "LinkedList does not contain -sci-." << endl << endl;

		cout << "Testing first LinkedList whether contains all element second LinkedList or not :" << endl;
		if(ll3_str.containsAll(ll_str5)==1)
			cout <<"Every elements of second LinkedList is in first LinkedList." << endl << endl;
		else 		
			cout << "Every elements of second LinkedList is not in first LinkedList." << endl << endl;

		cout << "Testing RemoveAll function:" << endl;
		ll3_str.removeAll(ll_str5);
		cout << "After removing of elements in first LinkedList that is also contained second LinkedList : "; 
		ll3_str.print();
		cout << endl;
		cout << "After RemoveAll function ,size of first LinkedList :" << ll3_str.size() << endl << endl;

		cout <<"After second LinkedList added first LinkedList,so uploaded first LinkedList: ";
		ll3_str.addAll(ll_str5);
		ll3_str.print();
		cout << endl;
		cout << "After addAll function ,size of first LinkedList :" << ll3_str.size() << endl << endl;
	

		cout << "Testing RetainAll function:" << endl;
		cout << "After retains elements of first LinkedList that is also in second LinkedList: " ;
		ll3_str.retainAll(ll_str5);
		ll3_str.print();
		cout << endl <<"After retainAll fuction,size of first LinkedList :" << ll3_str.size() << endl << endl;

		cout << "Testing first LinkedList empty or not:" << endl;
		if(ll3_str.isEmpty()==1)
			cout <<"LinkedList is empty." << endl << endl;
		else 				
			cout << "LinkedList is not empty." << endl << endl;


		cout << "Testing offer function:" << endl;
		cout << "After inserting specified element: ";
		ll3_str.offer("CSE");
		ll3_str.print();
		cout << endl << endl;

		cout << "Testing element function:" << endl;
		cout << "After retrieved, but does not removed, the head of linkedlist." << endl;
		cout << "Returned value: " << ll3_str.element() << endl << endl;

		cout << "Testing poll function:" << endl;
		cout << "After retrieved and removed, the head of linkedlist." << endl;
		cout << "Returned value: " << ll3_str.poll() << endl ;
		cout << "Last version: " ;
		ll3_str.print();
		cout << endl << endl;


	
		ll3_str.clear();
		cout << "Testing clear function : " ;
		ll3_str.print();
		cout << endl <<"After clear fuction,size of first LinkedList :" << ll3_str.size() << endl << endl;


	
	}
	catch(exception){ //catch exception.
		cout << "Error occured!!" << endl;
	}










	
}
