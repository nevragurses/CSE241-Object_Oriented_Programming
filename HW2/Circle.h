/*
 * Circle.h
 *
 *  Created on: Oct 24, 2018
 *      Author: Nevra Gürses
 */
#ifndef CIRCLE_H_
#define CIRCLE_H_
#include <fstream>
using namespace std;
class Circle
{
public:
	Circle(int radiusValue) // Initilates the radius of container Circle according to entered value.
		:radius(radiusValue)
	{ 
		test(); // Calling test function to whether value is appopriate or not.
	}
	Circle() { } // No parameter constructor.

	void set_smallRadius(int value){ // Initilates the radius of small Circle according to entered value.
		s_radius=value;
	}
	void setBigColor();// Assigns color red to container Circle.
	void setSmallColor();// Assigns color green to small Circle.
	
	void setBigCircle(double x,double y); // Determines the position of container Circle.
	void setCircle(double uploaded_x,double uploaded_y); // Determines the new positions of small Circles in container shape.
	void setRotate(double x,double y); // Determines which coordinates to rotate.

	void draw(int degree,ofstream &SvgFile); // Draws the container and small Circles in Svg File.
		
	void test(); // Tests radius is negative or zero.If it is,then program is stopped.
	void output() const; // Writes radius of Circle on screen,if it is necessary.
	
	char getbigColor() const { return color; } // Return container circle color.
	char getsmallColor() const {return s_color; } // Return circle color.
	int getRadius() const{ return radius; } // Returns radius of container Circle.
	int getSmallRadius() const{ return s_radius; } // Return radius of small Circle.
	// Returns positions of small and container Circles.
	double getPos_x() const{ return bigpos_x; }
	double getPos_y() const{ return bigpos_y; }
	double getSmallPosx() const{ return pos_x; }
	double getSmallPosy() const{ return pos_y; }
	double getRotateX() const { return coordX; }
	double getRotateY() const { return coordY; }

private:
	int radius,s_radius; // Radius of container and small Circle.
	// Positions.
	double bigpos_x;
	double bigpos_y;
	double pos_x;
	double pos_y;
	char color,s_color; // Color to container and small Circle.
	int degree; // Rotate degree.
	// Rotate coordinates.
	double coordX;
	double coordY;

};
//Inline functions with inline keyword.
inline void Circle::setBigColor(){
	color='r';
}
inline void Circle::setSmallColor(){
	s_color='g';
}
#endif
