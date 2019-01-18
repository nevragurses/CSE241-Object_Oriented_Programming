/*
 * 161044071_main.cpp
 *
 *  
 *      Author: Nevra Gürses
 */
#include <iostream>
#include <vector>
#include "ComposedShape.h"
#include "Polygon.h"
#include "Polyline.h"
using std::cout;
using std::endl;
using namespace PolylineOfGurses;
using namespace ComposedOfGurses;
using  namespace PolygonOfGurses;
int main(){
	ofstream SvgFile;
	Rectangle rect[4]={{},{120,300,0,0},{560,345,0,0},{}}; //Rectangle array to use in ComposedShape,Polygon and Polyline Class.
	//Initilizing some features of container and small rectangle.
	rect[0].setSmall(180,76);
	rect[0].setSmallColor();
	rect[1].setBigColor();
	rect[2].setBigColor();
	rect[3].setSmall(20,15);
	rect[3].setSmallColor(); 
	
	Triangle tri[4]={{},{290,145,0,0,251.14,290,251.14},{256,128,0,0,221.70,256,221.70},{}}; //Triangle array to use in ComposedShape,Polygon and Polyline Class. 
	//Initilizing some features of container and small triangle.
	tri[0].set_smallTriangle(15);
	tri[0].setSmallColor();
	tri[0].setDegree(0);
	tri[1].setBigColor();
	tri[1].setDegree(0);
	tri[2].setBigColor();
	tri[2].setDegree(0);
	tri[3].set_smallTriangle(10);
	tri[3].setSmallColor(); 
	tri[3].setDegree(0);


	Circle circ[4]={{},{200},{300},{}}; //Circle array to use in ComposedShape,Polygon and Polyline Class.
	//Initilizing some features of container and small circle.
	circ[0].set_smallRadius(10);
	circ[0].setSmallColor();
	circ[0].setDegree(0);
	circ[1].setBigColor();
	circ[1].setDegree(0);
	circ[2].setBigColor();
	circ[2].setDegree(0);
	circ[3].set_smallRadius(12);
	circ[3].setSmallColor();
	circ[3].setDegree(0);

	//TESTING OPERATIONS OF POLYGON CLASS.

	
	cout << "------------------TESTING POLYGON CLASS ----------------" << endl;

	//Vector of inner class Point2D type to use in Polygon class. 
	vector<Polygon::Point2D>(polygonPoints);
	Polygon::Point2D point(0,0);
	polygonPoints.push_back(point);
	point.setPositions(400,0);
	polygonPoints.push_back(point);
	point.setPositions(400,100);
	polygonPoints.push_back(point);
	point.setPositions(0,100);
	polygonPoints.push_back(point);
	
	vector<Polygon::Point2D>(polygonPoints2);
	Polygon::Point2D point2(0,0);
	polygonPoints2.push_back(point2);
	point2.setPositions(200,0);
	polygonPoints2.push_back(point2);
	point2.setPositions(200,350);
	polygonPoints2.push_back(point2);
	point2.setPositions(0,350);
	polygonPoints2.push_back(point2);

	vector<Polygon::Point2D>(polygonPoints3);
	Polygon::Point2D point3(145,0);
	polygonPoints3.push_back(point3);
	point3.setPositions(0,251.14);
	polygonPoints3.push_back(point3);
	point3.setPositions(290,251.14);
	polygonPoints3.push_back(point3);

	

	//Polygon array.
	Polygon arrPoly[6]={ { polygonPoints } , { polygonPoints2 } , { polygonPoints3 }, 
		           { rect[2] },{tri[1] }, {circ[2] } };

	//Testing overloaded == operator.
	if(arrPoly[0] == arrPoly[1])
		cout << "This two polygon are equal."<< endl;

	else 
		cout << "This two polygon are not equal."<< endl;
	//Testing overloaded != operator.
	if(arrPoly[0] != arrPoly[2])
		cout << "This two polygon are not equal."<< endl;

	else 
		cout << "This two polygon are equal."<< endl;

	//Testing overloaded + operator.
	cout << "Points of first element of polygon array :" << endl;
	arrPoly[0].printArray();
	cout << "Points of second element of polygon array : " << endl;
	arrPoly[2].printArray();
	cout << "Points of new polygon that created adding of two polygon:" << endl;
	Polygon end=arrPoly[0]+arrPoly[1];
	end.printArray();

	//Testing overloaded << operator
	SvgFile.open("overloaded.svg");
	SvgFile << arrPoly[1];
	SvgFile << " </svg> " << endl;
	SvgFile.close(); 
	 

	//Testing drawing vector of point2d innner class in polygon class.
	SvgFile.open("VectorofPoint2DType.svg");
	SvgFile << arrPoly[0];    //Container rectangle is drawing svg file by overloading << operator.
	SvgFile << " </svg> " << endl;
	SvgFile.close(); 

	
	//TESTING OPERATIONS FOR POLYLINE CLASS 

	cout << "------------------TESTING POLYLINE CLASS ----------------" << endl;
	//Array of Polyline class.
	Polyline arrPolyline[6]={ { polygonPoints } , { polygonPoints2 } , { polygonPoints3 }, 
		           { rect[1] },{tri[2] }, {circ[1] } };

	//Testing overloaded == operator.
	if(arrPolyline[1] == arrPolyline[2])
		cout << "This two polygon are equal."<< endl;

	else 
		cout << "This two polyline are not equal."<< endl;

	//Testing overloaded != operator.
	if(arrPolyline[3] != arrPolyline[1])
		cout << "This two polyline are not equal."<< endl;

	else 
		cout << "This two polyline are equal."<< endl;

	//Testing overloaded + operator.
	cout << "Points of first element of polyline array :" << endl;
	arrPolyline[0].print();
	cout << endl << "Points of second element of polyline array : " << endl;
	arrPolyline[2].print();
	cout << endl<< "Points of new polyline that created adding of two polyline:" << endl;
	Polyline another=arrPolyline[1]+arrPolyline[2];
	another.print();

	//Testing overloaded << operator.
	SvgFile.open("Polyline1.svg");
	SvgFile << arrPolyline[3];  
	SvgFile << " </svg> " << endl;
	SvgFile.close();  

	SvgFile.open("Polyline2.svg");
	SvgFile << arrPolyline[4];  
	SvgFile << " </svg> " << endl;
	SvgFile.close(); 

	SvgFile.open("Polyline3.svg");
	SvgFile << arrPolyline[5];  
	SvgFile << " </svg> " << endl;
	SvgFile.close();



	//TESTING OPERATIONS FOR COMPOSEDSHAPE CLASS 

	cout << "------------------TESTING COMPOSEDSHAPE CLASS ----------------" << endl;
	//Array of ComposedShape class.
	ComposedShape compose[10] = { { rect[2],rect[0] },{ rect[1],circ[0] },{ rect[1],tri[0] },
				     { circ[1],circ[0] },{ circ[1],rect[3] },{ circ[1],tri[3] },
				     { tri[1],rect[3] }, { tri[2],circ[3] }, { tri[2],tri[0] } };

	//Calculating max number of small shapes in container shapes by using vector of Polygon class object.
	cout << "Max rectangle number in container rectangle is: " << compose[0].OptimalFit(rect[2],rect[0]) << endl << endl;
	SvgFile.open("output1.svg");
	compose[0].draw(SvgFile); //drawing shape by using vector of Polygon class  object in ComposedShape Class.

	cout << "Max circle number in container rectangle is: " << compose[1].OptimalFit(rect[1],circ[0]) << endl << endl;
	SvgFile.open("output2.svg"); //opening new svgfile to drawing all shapes at the same time.
	compose[1].draw(SvgFile); 

	cout << "Max triangle number in container rectangle is: " << compose[2].OptimalFit(rect[1],tri[0]) << endl << endl;
	SvgFile.open("output3.svg");
	compose[2].draw(SvgFile); 

	cout << "Max circle number in container circle is: " << compose[3].OptimalFit(circ[1],circ[0]) << endl << endl;
	SvgFile.open("output4.svg");
	compose[3].draw(SvgFile); 

	cout << "Max rectangle number in container circle is: " << compose[4].OptimalFit(circ[1],rect[3]) << endl << endl;
	SvgFile.open("output5.svg");
	compose[4].draw(SvgFile); 

	cout << "Max triangle number in container circle is: " << compose[5].OptimalFit(circ[1],tri[3]) << endl << endl;
	SvgFile.open("output6.svg");
	compose[5].draw(SvgFile); 

	cout << "Max rectangle number in container triangle is: " << compose[6].OptimalFit(tri[1],rect[3]) << endl << endl;
	SvgFile.open("output7.svg");
	compose[6].draw(SvgFile); 

	cout << "Max circle number in container triangle is: " << compose[7].OptimalFit(tri[2],circ[3]) << endl << endl;
	SvgFile.open("output8.svg");
	compose[7].draw(SvgFile); 

	cout << "Max triangle number in container triangle is: " << compose[8].OptimalFit(tri[2],tri[0]) << endl << endl;
	SvgFile.open("output9.svg");	
	compose[8].draw(SvgFile); 

	return 0;
 

}	



























