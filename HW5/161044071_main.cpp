/*
 * 161044071_main.cpp
 *
 *  
 *      Author: Nevra Gürses
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <stdexcept>
#include "Shape.h"
#include "PolygonDyn.h"
#include "PolygonVect.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "ComposedShape.h"
using namespace std;
using namespace ShapeOfGurses;
ostream& operator << (ostream& SvgFile,const Shape& object){ // Overloaded global operator <<  for printing the shapes to SVG files.
	object.draw(SvgFile); //calling draw function of shapes.
	return SvgFile;
}
void printAll(const vector<Shape*>&all,ostream& SvgFile){ // Global function that takes a vector of Shape pointers and prints all shapes to an SVG file.
	for(Shape* shapePtr:all){
		SvgFile << *shapePtr; //Shape is printing by overloaded << operator.
	}
}
void printPoly(const vector<Shape*>&all,ostream& SvgFile){ //Global function that takes a vector of Shape pointers and prints all Polygons to an SVG file.
	for(Shape* shapePtr:all){
		Polygon* pPtr=dynamic_cast < Polygon* > (shapePtr); //Shapes is casting as polygon.
		if(pPtr != nullptr) //If shape is polygon;
			SvgFile << *shapePtr;  // printing by overloaded << operator.
	}
}
const vector <Shape*> convertAll(const vector<Shape*>&all){  // Global function that converts all shapes to Polygons and returns a new vector.
	vector< Shape* > newVect;
	for(Shape* shapePtr:all){
		//Shapes is casting as rectangle,circle,triangle.
		Rectangle* rPtr=dynamic_cast < Rectangle* > (shapePtr);
		Circle* cPtr=dynamic_cast < Circle* > (shapePtr);
		Triangle* tPtr=dynamic_cast < Triangle* > (shapePtr);
		if(rPtr != nullptr){ //If shape is rectangle;
			Shape *sPtr=new PolygonVect;
			PolygonVect* pvPtr = dynamic_cast < PolygonVect* > (sPtr); //casting as polygon
			PolygonVect poly(*rPtr);
			*pvPtr=poly;
			newVect.push_back(pvPtr); //rectangle is recording in vector as polygon.
		}
		if(cPtr != nullptr){ // If shape is circle;
			Shape *sPtr=new PolygonVect;
			PolygonVect* cvPtr = dynamic_cast < PolygonVect* > (sPtr); //Casting as polygon
			PolygonVect poly(*cPtr);
			*cvPtr=poly;
			newVect.push_back(cvPtr); //circle is recording in vector as polygon.
		}
		if(tPtr != nullptr){ //If shape is triangle;
			Shape *sPtr=new PolygonVect;
			PolygonVect* tvPtr = dynamic_cast < PolygonVect* > (sPtr); //Casting as polygon
			PolygonVect poly(*tPtr);
			*tvPtr=poly;
			newVect.push_back(tvPtr); //triangle is recording in vector as polygon.
		}
		
	}
	return newVect;
	
}
	
void sortShapes( vector<Shape*>&all){ //Global functions that sortes shapes with respect to areas.
	Shape* temp; //temperature shape pointer.
	int size=all.size();
	//Sorting shapes.
	for(int i=0; i < size-1 ; i++){
        	for(int j=i+1; j < size; j++){
  			if(all[i]->Area() > all[j]->Area()){
				temp=all[i];
				all[i]=all[j];
				all[j]=temp;
			}
		}
	}
}
int main(){

	try //For throw exception and catch control.
	{


	ofstream SvgFile;  

	Rectangle rect[4]={{180,76,'g'},{120,300,0,0,'r',0},{560,345,0,0,'r',0},{20,15,'g'}}; //Rectangle array for using operations.
	Triangle tri[4]={{15,'g'},{290,145,0,0,251.14,290,251.14,0},{256,128,0,0,221.70,256,221.70,0},{10,'g'}}; //Triangle array for using operations.
	tri[1].setBigColor();
	tri[2].setBigColor();
	Circle circ[4]={{10,'g'},{200,'r',0},{300,'r',0},{12,'g'}}; //Circle array for using operations.


	//Test functions of Rectangle class objects.
	cout << endl << "-----TESTING RECTANGLE CLASS -----" << endl << endl;
	cout << "Area of rectangle that is lenghts(300,120)=" << rect[1].Area() << endl;
	cout << "Perimeter of rectangle that is lenghts(300,120)=" << rect[1].Perimeter() << endl<< endl;
	Rectangle newRect = rect[1] - 10.75; //New rectangle that created by using an rectangle object and double by overloading - operator.
	cout << "After second rectangle that is lenghts(300,120)  overloaded  - operator to create new rectangle : " << endl ;
	newRect.output();
	Rectangle newRect2 = rect[1] + 200.175; //New rectangle that created by using an rectangle object and double by overloading + operator.
	cout << "After second rectangle that is lenghts(300,120)  overloaded  + operator to create new rectangle : " << endl;
	newRect2.output();
	cout << endl ;
	//comparision two rectangle by overloading operators.
	if(rect[2] == rect[3]) 
		cout << "Area of third and fourth rectangle is equal." << endl;
	else if(rect[2] != rect [3])
		cout << "Area of third and fourth rectangle is not equal." << endl;
	if(rect[2] < rect [3])
		cout << "Area of third rectangle smaller than fourth rectangle. " << endl;
	else if(rect[2] > rect [3])
		cout << "Area of third rectangle bigger than fourth rectangle." << endl << endl;
	cout << "TO TESTING POSITIONS OF SMALL AND BİG RECTANGLES THAT INCEREASED AND DECREASED BY 1.0 :" << endl;
	Rectangle z(50.9,30.5,10.5,12.4,0); ++z; //Small and container Rectangle positions after pre incrementing to testing member fuction. 
	cout << "New positions of small and big rectangles after pre incrementing to positions(50.9,30.5,10.5,12.4):" << endl;
	z.outputUploaded() ; cout << endl;
	Rectangle r(50.9,30.5,10.5,12.4,0); --r; //Small and container Rectangle positions after pre decrementing to testing member fuction.
	cout << "New positions of small and big rectangles after pre decrementing to positions(50.9,30.5,10.5,12.4):"  << endl;
	r.outputUploaded() ; cout << endl;
	cout << "RECTANGLE IS DRAWİNG SVG FILE BY OVERLOAD << OPERATOR" <<endl  << endl;  
	SvgFile.open("RECTANGLE.svg");
	SvgFile << rect[1];    //Container rectangle is drawing svg file by overloading << operator.
	SvgFile << " </svg> " << endl;
	SvgFile.close(); 

	//Test functions of Triangle class objects.
	cout << endl << "-----TESTING TRINGLE CLASS -----" << endl << endl;
	cout << "Area of triangle that is side(15)=" << tri[0].Area() << endl;
	cout << "Perimeter of triangle that is side(15)=" << tri[0].Perimeter() << endl<<endl;
	Triangle newTri = tri[2] - 5.7; //New triangle object that created by using an triangle object and double number by overloading - operator.
	cout << "After third triangle that is side(256)  overloaded  - operator to create new triangle : " << endl ;
	cout << "Side of new triangle is: " << newTri.getSide() << endl;
	Triangle newTri2 = tri[2] + 100.45; //New triangle object that created by using an triangle object and double number by overloading + operator.
	cout << "After third triangle that is side(256)  overloaded  + operator to create new triangle : " << endl;
	cout << "Side of new triangle is: " << newTri2.getSide() << endl;
	cout << endl ;
	if(tri[2] == tri[3])
		cout << "Area of third and fourth triangle is equal." << endl;
	else if(tri[2] != tri [3])
		cout << "Area of third and fourth triangle is not equal." << endl;
	if(tri[2] < tri [3])
		cout << "Area of third triangle smaller than fourth triangle. " << endl;
	else if(tri[2] > tri [3])
		cout << "Area of third triangle bigger than fourth triangle." << endl << endl;
	cout << "TO TESTING POSITIONS OF SMALL AND BİG TRIANGLES THAT INCEREASED AND DECREASED BY 1.0 :" << endl;
	Triangle y(5,100.0,0,0,300.4,200,300.4,12.0,0,5.0,14.0,15.0,14.0,0); ++y; //pre ıncreasing positions to testing member function.
	cout << "New positions of small and big triangles after pre incrementing to positions(100.0,0,0,300.4,200,300.4,12.0,0,5.0,14.0,15.0,14.0):"  << endl;
	y.outputUploaded() ; cout << endl;
	Triangle m(5,100.0,1,1,300.4,200,300.4,12.0,1,5.0,14.0,15.0,14.0,0); --m; //pre decreasing positions to testing member function.
	cout << "New positions of small and big triangles after pre decrementing to positions(100.0,1,1,300.4,200,300.4,12.0,1,5.0,14.0,15.0,14.0):"  << endl;
	m.outputUploaded() ; cout << endl;
	cout << "TRIANGLE IS DRAWING SVG FILE BY OVERLOAD << OPERATOR" <<endl  << endl; 
	SvgFile.open("TRIANGLE.svg");
	SvgFile << tri[2]; //container triangle drawing svg file by overloading << operator.
	SvgFile << " </svg> " << endl;
	SvgFile.close(); 

	//Test functions of Circle class objects.
	cout << endl << "-----TESTING CIRCLE CLASS -----" << endl << endl;
	cout << "Area of circle that is radius(10)=" << circ[0].Area() << endl;
	cout << "Perimeter of circle that is radius(15)=" << circ[0].Perimeter() << endl<< endl;
	
	cout << "After third circle that is radius(300)  overloaded  + operator to create new circle : " << endl ;
	Circle newCircle2 = circ[2] + 50.45;//new circle object that created by using circle object and double number by overloading + operator.
	cout << "Radius of new circle is: " << newCircle2.getRadius() << endl;
	cout << "After third circle that is radius(300)  overloaded  - operator to create new circle : " << endl ;
	newCircle2 = circ[2] - 50.45;//new circle object that created by using circle object and double number by overloading - operator.
	cout << "Radius of new circle is: " << newCircle2.getRadius() << endl<< endl;
	//comparision two circle by overloading operators.
	if(circ[2] == circ[3])
		cout << "Area of third and fourth circle is equal." << endl;
	else if(circ[2] != circ [3])
		cout << "Area of third and fourth circle is not equal." << endl;
	if(circ[2] < circ [3])
		cout << "Area of third circle smaller than fourth circle. " << endl;
	else if(circ[2] > circ [3])
		cout << "Area of third circle bigger than fourth circle." << endl << endl;
	Circle x(20.5,20.5,10.6,10.6,0); ++x; //uploaded positions after pre incrementing by overloading ++ operator.
	cout << "NEW POSITIONS OF SMALL AND BIG CIRCLES AFTER PRE INCREMENTING TO POSITIONS(20.5,20,5,10.6,10.6):"  << endl;
	x.outputUploaded(); cout << endl;
	Circle l(20.5,20.5,10.6,10.6,0); l++; 
	cout << "RETURNED POSITIONS OF SMALL AND BIG CIRCLES AFTER POST INCREMENTING TO POSITIONS(20.5,20,5,10.6,10.6):"  << endl;
	l.outputUploaded(); cout << endl;
	Circle t(20.5,20.5,10.6,10.6,0); --t; //returned positions after pre decrementing by using overloading -- operator.
	cout << "NEW POSITIONS OF SMALL AND BIG CIRCLES AFTER PRE DECREMENTING TO POSITIONS(20.5,20,5,10.6,10.6):"  << endl;
	t.outputUploaded(); cout << endl;
	Circle s(20.5,20.5,10.6,10.6,0); s--;
	cout << "RETURNED POSITIONS OF SMALL AND BIG CIRCLES AFTER POST DECREMENTING TO POSITIONS(20.5,20,5,10.6,10.6):"  << endl;
	s.outputUploaded(); cout << endl;
	cout << "CIRCLE IS DRAWING SVG FILE BY OVERLOAD << OPERATOR" <<endl  << endl; 
	SvgFile.open("CIRCLE.svg");
	SvgFile << circ[2]; //container circle drawing svg file by overloading << operator.
	SvgFile << " </svg> " << endl;
	SvgFile.close(); 


	//ComposedShape class objects as array.
	cout << endl << "-----TESTING COMPOSEDSHAPE CLASS -----" << endl;
	ComposedShape compose[10] = { { rect[2],rect[0] },{ rect[1],circ[0] },{ rect[1],tri[0] },
				     { circ[1],circ[0] },{ circ[1],rect[3] },{ circ[1],tri[3] },
				     { tri[1],rect[3] }, { tri[2],circ[3] }, { tri[2],tri[0] } };
	
	compose[0].OptimalFit(rect[2],rect[0]);
	cout<< "Area of Rectangle in rectangle :" << compose[0].Area() << endl;
	cout<< "Perimeter of Rectangle in rectangle :" << compose[0].Perimeter() << endl;
	cout << "Rectangle in rectangle is drawing svg file.. " << endl<< endl ;
	SvgFile.open("RectInRect.svg");
	SvgFile << compose[0]; //composed shape drawing svg file by overloading << operator.
	SvgFile << " </svg> " << endl;
	SvgFile.close(); 
	
	
	compose[1].OptimalFit(rect[1],circ[0]);
	cout<< "Area of Circle in rectangle is:" << compose[1].Area() << endl;
	cout<< "Perimeter of Circle in rectangle is:" << compose[0].Perimeter() << endl;
	cout << "Circle in rectangle is drawing svg file.. " << endl<< endl;
	SvgFile.open("CircInRect.svg");
	SvgFile << compose[1]; //composed shape drawing svg file by overloading << operator.
	SvgFile << " </svg> " << endl;
	SvgFile.close(); 

	
	compose[2].OptimalFit(rect[1],tri[0]);
	cout<< "Area of Triangle in rectangle is:" << compose[2].Area() << endl;
	cout<< "Perimeter of Triangle in rectangle is:" << compose[2].Perimeter() << endl;
	cout << "Triangle in rectangle is drawing svg file.. " <<endl << endl;
	SvgFile.open("TriInRect.svg");
	SvgFile << compose[2]; //composed shape drawing svg file by overloading << operator.
	SvgFile << " </svg> " << endl;
	SvgFile.close(); 
	
	
	compose[3].OptimalFit(circ[1],circ[0]);
	cout<< "Area of Circle in circle is:" << compose[3].Area() << endl;
	cout<< "Perimeter of Circle in circle is:" << compose[3].Perimeter() << endl;
	cout << "Circle in circle is drawing svg file.. " << endl << endl; 
	SvgFile.open("CircInCirc.svg");
	SvgFile << compose[3]; //composed shape drawing svg file by overloading << operator.
	SvgFile << " </svg> " << endl;
	SvgFile.close(); 
	

	
	compose[4].OptimalFit(circ[1],rect[3]);
	cout<< "Area of Rectangle in circle is:" << compose[4].Area() << endl;
	cout<< "Perimeter of Rectangle in circle  is: " << compose[4].Perimeter() << endl;
	cout << "Rectangle in circle is drawing svg file.. " << endl << endl;
	SvgFile.open("RectInCirc.svg");
	SvgFile << compose[4]; //composed shape drawing svg file by overloading << operator.
	SvgFile << " </svg> " << endl;
	SvgFile.close(); 

	
	compose[5].OptimalFit(circ[1],tri[3]);
	cout<< "Area of Triangle in circle is:" << compose[5].Area() << endl;
	cout<< "Perimeter of Triangle in circle  is:" << compose[5].Perimeter() << endl;
	cout << "Triangle in circle is drawing svg file.. " << endl << endl;
	SvgFile.open("TriInCirc.svg");
	SvgFile << compose[5]; //composed shape drawing svg file by overloading << operator.
	SvgFile << " </svg> " << endl;
	SvgFile.close(); 

	
	compose[6].OptimalFit(tri[1],rect[3]);
	cout<< "Area of Rectangle in triangle is:" << compose[6].Area() << endl;
	cout<< "Perimeter of Rectangle in triangle  is:" << compose[6].Perimeter() << endl;
	cout << "Rectangle in triangle is drawing svg file.. " << endl<< endl;
	SvgFile.open("RectInTri.svg");
	SvgFile << compose[6]; //composed shape drawing svg file by overloading << operator.
	SvgFile << " </svg> " << endl;
	SvgFile.close(); 

	
	
	compose[7].OptimalFit(tri[2],circ[3]);
	cout<< "Area of Circle in triangle:" << compose[7].Area() << endl;
	cout<< "Perimeter of Circle in triangle:" << compose[7].Area() << endl;
	cout << "Circle in triangle is drawing svg file.." << endl<< endl;
	SvgFile.open("CircInTri.svg");
	SvgFile << compose[7]; //composed shape drawing svg file by overloading << operator.
	SvgFile << " </svg> " << endl;
	SvgFile.close(); 

	
	compose[8].OptimalFit(tri[2],tri[0]);
	cout<< "Area of Triangle in triangle:" << compose[8].Area() << endl;
	cout<< "Perimeter of Triangle in triangle:" << compose[8].Area() << endl;
	cout << "Triangle in triangle is drawing svg file.. " <<endl << endl; 
	SvgFile.open("TriInTri.svg");
	SvgFile << compose[8]; //composed shape drawing svg file by overloading << operator.
	SvgFile << " </svg> " << endl;
	SvgFile.close(); 


	cout << endl;
	
	
	//Testing polygon class
	cout << endl << "-----TESTING POLYGON CLASS -----" << endl;
	
	cout << "Rectangle as PolygonVect is drawing svg file.." << endl<<endl;
	PolygonVect vectPoly(rect[1]); //Creating rectangle as polygon vector class.
	SvgFile.open("RectAsPolygonVect.svg");
	SvgFile << vectPoly;
	SvgFile << " </svg> " << endl;
	SvgFile.close();
	
	cout << "Circle as PolygonVect is drawing svg file.." << endl<<endl;
	PolygonVect vectPoly2(circ[1]); //Creating circle as polygon vector class.
	SvgFile.open("CircAsPolygonVect.svg");
	SvgFile << vectPoly2;
	SvgFile << " </svg> " << endl;
	SvgFile.close();

	cout << "Triangle as PolygonVect is drawing svg file.." << endl <<endl;
	PolygonVect vectPoly3(tri[1]); //Creating triangle as polygon vector class.
	SvgFile.open("TriAsPolygonVect.svg"); 
	SvgFile << vectPoly3;
	SvgFile << " </svg> " << endl;
	SvgFile.close();

	cout << "Rectangle as PolygonDyn is drawing svg file.." << endl<<endl;
	PolygonDyn dynPoly(rect[1]); //Creating rectangle as polygon dynamic class.
	SvgFile.open("RectAsPolygonDyn.svg");
	SvgFile << dynPoly;
	SvgFile << " </svg> " << endl;
	SvgFile.close();
	
	cout << "Circle as PolygonDyn is drawing svg file.." << endl<<endl;
	PolygonDyn dynPoly2(circ[1]); //Creating circle as polygon dynamic class.
	SvgFile.open("CircAsPolygonDyn.svg");
	SvgFile << vectPoly2;
	SvgFile << " </svg> " << endl;
	SvgFile.close();

	cout << "Triangle as PolygonDyn is drawing svg file.." << endl <<endl;
	PolygonDyn dynPoly3(tri[1]); //Creating triangle as polygon dynamic class.
	SvgFile.open("TriAsPolygonDyn.svg");
	SvgFile << dynPoly3;
	SvgFile << " </svg> " << endl;
	SvgFile.close(); 

	//2D points is holding in vector.
	vector<Polygon::Point2D>(polygonPoints);
	Polygon::Point2D point(100,10);
	polygonPoints.push_back(point);
	point.setPositions(40,198);
	polygonPoints.push_back(point);
	point.setPositions(190,78);
	polygonPoints.push_back(point);
	point.setPositions(10,78);
	polygonPoints.push_back(point);
	point.setPositions(160,198);
	polygonPoints.push_back(point);     
	
	
	PolygonVect polyVect(polygonPoints); //Creating polygon vector that is parameter stl vector.
	SvgFile.open("StarAsPolyVect.svg");
	SvgFile << polyVect;
	SvgFile << " </svg> " << endl;
	SvgFile.close();

	PolygonDyn polyDyn(polygonPoints);  //Creating polygon dynamic that is parameter stl vector.
	SvgFile.open("StarAsPolyDyn.svg");
	SvgFile << polyDyn;
	SvgFile << " </svg> " << endl;
	SvgFile.close();  

	cout << endl << "-----TESTING GLOBAL PRINTALL FUNCTION -----" << endl << endl;
	

	vector<Shape*> (shape); //shape pointer vector.
	SvgFile.open("PrintAll.svg");
	cout << "An example of printAll function( with a composed shape and a rectangle) is drawing svg file.."<< endl;
	shape.push_back(&compose[3]);
	shape.push_back(&rect[0]);
	printAll(shape,SvgFile); //All shapes printing in svg file.
	SvgFile << " </svg> " << endl;
	SvgFile.close();
	

	cout << endl << "-----TESTING GLOBAL PRINTPOLY FUNCTION -----" << endl << endl;
	PolygonVect rectAsPoly(rect[0]);
	vector<Shape*> (shape2); //shape pointer vector.
	SvgFile.open("PrintPoly.svg");
	cout << "An example of printPoly function( with a composed shape and a star and a rectangle(that as polyon) is drawing svg file.."<< endl;
	cout << "After function we see that composed shape was not drawed,because it is not polyon type." << endl;
	shape2.push_back(&polyDyn);
	shape2.push_back(&rectAsPoly);
	shape2.push_back(&compose[3]);
	printPoly(shape2,SvgFile); //Polyon shapes printing in svg file.
	SvgFile << " </svg> " << endl;
	SvgFile.close();
	
	cout << endl << "-----TESTING GLOBAL CONVERTALL FUNCTION -----" << endl << endl;
	cout << "A rectangle and a circle in convertAll function.." << endl;
	cout << "After converting they recorded as polygon in svg file." << endl;  
	vector<Shape*> (shape4);
	SvgFile.open("ConvertAll.svg");
	shape4.push_back(&circ[2]);
	shape4.push_back(&rect[0]);
	convertAll(shape4);
	printAll(convertAll(shape4),SvgFile); //Shapes in printing svg file as polygon shape.
	SvgFile << " </svg> " << endl;
	SvgFile.close();
	

	cout << endl << "-----TESTING GLOBAL SORTSHAPES FUNCTION -----" << endl << endl;
	vector<Shape*> (shape3); //shape pointer vector.
	shape3.push_back(&rect[0]);
	shape3.push_back(&circ[0]);
	shape3.push_back(&tri[0]);
	cout << "BEFORE SORTING , AREAS ARE:  " ;
	for(int i=0;i<shape3.size();++i) 
		cout << shape3[i]->Area() << " --- " ; //Area of shapes that is unsorted.

	cout << endl << "AFTER SORTING,AREAS ARE:  ";
	sortShapes(shape3);
	for(int i=0;i<shape3.size();++i)
		cout << shape3[i]->Area() << " --- " ; //Area of shapes that is sorted.

	cout << endl << endl;
	
	}
	catch(invalid_argument& invalid){
		cout << invalid.what() << endl; //Catch exception and prints why it is occured.
	}

}
