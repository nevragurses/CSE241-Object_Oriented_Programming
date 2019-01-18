/*
 * 161044071_main.cpp
 *
 *  Created on: Oct 18, 2018
 *      Author: Nevra
 */
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "ComposedShape.h"
#include <fstream>
using namespace std;


int main(){

	
	ofstream SvgFile;
	
	//Rectangle,Circle,Triangle  classes objects as array.
	Rectangle rect[4]={{},{120,300,0,0},{560,345,0,0},{}};
	Triangle tri[4]={{},{290},{256},{}};
	Circle circle[4]={{},{200},{300},{}};
	
	//Test functions of Rectangle class objects.
	cout << endl << "----- RECTANGLE OBJECTS -----" << endl; 
	rect[0].setSmall(180,76);   //to initilaze small rectangle.
	cout << "height of rectangle 1: " << rect[0].getSmallHeight() << endl
             << "width of rectangle 1: " << rect[0].getSmallWidth() << endl;
	rect[0].setSmallColor(); //to determine small rectangle color as green.
	cout << "color: " << rect[0].getsmallColor() << " ==>'g'means that green." << endl << endl;

	cout << "height of rectangle 2 : " << rect[1].getHeight() << endl
             << "width of rectangle 2: " << rect[1].getWidth() << endl
	     << "position on x coordinate: " << rect[1].getPos_x() << endl
       	     << "position on y coordinate: " << rect[1].getPos_y()<< endl;
        rect[1].setBigColor(); //to determine big rectangle color as red.
	cout << "color: " << rect[1].getbigColor() << " ==>'r'means that red." << endl << endl;
	
	
	cout << "height of rectangle 3: " << rect[2].getHeight() << endl
             << "width of rectangle 3: " << rect[2].getWidth() << endl
	     << "position on x coordinate: " << rect[2].getPos_x() << endl
       	     << "position on y coordinate: " << rect[2].getPos_y()<< endl;
        rect[2].setBigColor(); //to determine big rectangle color as red.
	cout << "color: " << rect[2].getbigColor() << " ==>'r'means that red." << endl << endl;

	rect[3].setSmall(20,15); //to initilaze small rectangle.
	cout << "height of rectangle 4: " << rect[3].getSmallHeight() << endl
             << "width of rectangle 4: " << rect[3].getSmallWidth() << endl;
	   
	rect[3].setSmallColor(); //to determine small rectangle color as green.
	cout << "color: " << rect[3].getsmallColor() << " ==>'g'means that green." << endl << endl;
 	
	//Test functions of Triangle class objects.

   	cout << endl << "----- TRIANGLE OBJECTS -----" << endl;
	tri[0].set_smallTriangle(15);//to initilaze small triangle.
	cout << "Side of triangle 1: " << tri[0].getSmallSide() << endl;
	tri[0].setSmallColor();  //to determine small triangle color as green.
	cout << "color: " << tri[0].getsmallColor() << " ==>'g'means that green." << endl << endl;

	cout << "Side of triangle 2: " << tri[1].getSide() << endl;;
	tri[1].setBigColor(); //to determine big triangle color as red.
	cout << "color: " << tri[1].getbigColor() << " ==>'r'means that red." << endl << endl;
	
	
	cout << "Side of triangle 3: " << tri[2].getSide() << endl;
        tri[2].setBigColor(); //to determine big triangle color as red.
	cout << "color: " << tri[2].getbigColor() << " ==>'r'means that red." << endl << endl;

          
	tri[3].set_smallTriangle(10);//to initilaze small triangle.
		cout <<  "Side of triangle 4: " << tri[3].getSmallSide() << endl ;
		tri[3].setSmallColor(); //to determine small triangle color as green.
	        cout  << "color: " << tri[3].getsmallColor() << " ==>'g'means that green." << endl << endl;

	//Test functions of Circle class objects.
	
	cout << endl << "----- CIRCLE OBJECTS -----" << endl;
	circle[0].set_smallRadius(10); //to initilaze small circle.
	cout << "Radius of circle 1: " << circle[0].getSmallRadius() << endl;
	circle[0].setSmallColor(); //to determine small circle color as green.
	cout << "color: " << circle[0].getsmallColor() << " ==>'g'means that green." << endl << endl;

	cout << "Radius of circle 2: " <<  circle[1].getRadius() << endl;;
	circle[1].setBigColor(); //to determine big circle color as red.
	cout << "color: " << circle[1].getbigColor() << " ==>'r'means that red." << endl << endl;
	
	
	cout << "Radius of circle 3: " << circle[2].getRadius() << endl;
        circle[2].setBigColor(); //to determine big circle color as red.
	cout << "color: " << circle[2].getbigColor() << " ==>'r'means that red." << endl << endl;

          
	circle[3].set_smallRadius(12); //to initilaze small circle.
		cout <<  "Radius of circle 4: " << circle[3].getSmallRadius() << endl;
		circle[3].setSmallColor(); //to determine small circle color as green.
	        cout  << "color: " << circle[3].getsmallColor() << " ==>'g'means that green." << endl;


	//ComposedShape class objects as array.

	ComposedShape compose[10] = { { rect[2],rect[0] },{ rect[1],circle[0] },{ rect[1],tri[0] },
				     { circle[1],circle[0] },{ circle[1],rect[3] },{ circle[1],tri[3] },
				     { tri[1],rect[3] }, { tri[2],circle[3] }, { tri[2],tri[0] } };

	cout << endl;
	
	//Calculating and drawing svg file  operations to max number of small shape.

	cout << "--------SHAPE OPERATIONS ----------" << endl;
	cout << "Max rectangle number in container rectangle is: " << compose[0].OptimalFit(rect[2],rect[0]) << endl << endl;
	compose[0].draw(SvgFile,rect[2],rect[0]);

	cout << "Max circle number in container rectangle is: " << compose[1].OptimalFit(rect[1],circle[0]) << endl << endl;
	compose[1].draw(SvgFile,rect[1],circle[0]);

	cout << "Max triangle number in container rectangle is: " << compose[2].OptimalFit(rect[1],tri[0]) << endl << endl;
	compose[2].draw(SvgFile,rect[1],tri[0]);

	cout << "Max circle number in container circle is: " << compose[3].OptimalFit(circle[1],circle[0]) << endl << endl;
	compose[3].draw(SvgFile,circle[1],circle[0]);

	cout << "Max rectangle number in container circle is: " << compose[4].OptimalFit(circle[1],rect[3]) << endl << endl;
	compose[4].draw(SvgFile,circle[1],rect[3]);

	cout << "Max triangle number in container circle is: " << compose[5].OptimalFit(circle[1],tri[3]) << endl << endl;
	compose[5].draw(SvgFile,circle[1],tri[3]);

	cout << "Max rectangle number in container triangle is: " << compose[6].OptimalFit(tri[1],rect[3]) << endl << endl;
	compose[6].draw(SvgFile,tri[1],rect[3]);

	cout << "Max circle number in container triangle is: " << compose[7].OptimalFit(tri[2],circle[3]) << endl << endl;
	compose[7].draw(SvgFile,tri[2],circle[3]);

	cout << "Max triangle number in container triangle is: " << compose[8].OptimalFit(tri[2],tri[0]) << endl << endl;
	compose[8].draw(SvgFile,tri[2],tri[0]);

	return 0;
}	



























