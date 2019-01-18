target : 161044071_main.o LinkedList.o HashSet.o ArrayList.o
	g++ -o target  161044071_main.o LinkedList.o HashSet.o ArrayList.o

161044071_main.o : 161044071_main.cpp
	g++ -c 161044071_main.cpp -std=c++11

LinkedList.o : LinkedList.cpp
	g++ -c LinkedList.cpp -std=c++11

HashSet.o : HashSet.cpp
	g++ -c HashSet.cpp -std=c++11

ArrayList.o : ArrayList.cpp
	g++ -c ArrayList.cpp -std=c++11

clean:
	rm *.o target


