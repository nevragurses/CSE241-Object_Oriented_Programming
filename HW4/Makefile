Shapes:161044071_main.o Rectangle.o Circle.o Triangle.o ComposedShape.o Polygon.o Polyline.o
	g++ -o Shapes 161044071_main.o Rectangle.o Circle.o Triangle.o ComposedShape.o  Polygon.o Polyline.o
Rectangle.o : Rectangle.cpp
	g++ -c -std=c++0x  Rectangle.cpp 

Circle.o : Circle.cpp
	g++ -c -std=c++0x  Circle.cpp
Polygon.o : Polygon.cpp
	g++ -c -std=c++0x  Polygon.cpp
Polyline.o : Polyline.cpp
	g++ -c -std=c++0x  Polyline.cpp

Triangle.o : Triangle.cpp
	g++ -c -std=c++0x  Triangle.cpp

ComposedShape.o : ComposedShape.cpp
	g++ -c -std=c++0x  ComposedShape.cpp


161044071_main.o : 161044071_main.cpp
	g++ -c -std=c++0x  161044071_main.cpp
clean:
	rm *.o Shapes

