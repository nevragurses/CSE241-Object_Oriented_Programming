/*
 * Circle.h
 *
 *  
 *      Author: Nevra Gürses
 */
#ifndef CIRCLE_H_
#define CIRCLE_H_
#include <fstream>
#define PI 3.14
using namespace std;
class Circle
{
public:
	Circle(double radiusValue) ;// Initilates the radius of container Circle.	
	Circle() { } // No parameter constructor.
	Circle(double radiusValue,double x,double y,int degree); // Initilates raidus,positions and rotating degree of circle.
	Circle(double bigX,double bigY,double smallX,double smallY); //Initilizes positions of container and small circles.

	friend ostream& operator <<(ostream& SvgFile,const Circle& object); //overloading << operator to drawing circle in svg file.

	
	//Returns perimeter of small circle.
	double perimeterSmall() const;

	//Returns perimeter of big circle.
	double perimeterBig() const;

	//Returns area of small circle.
	double areaSmall() const;

	//Returns area of big circle.
	double areaBig() const; 	

	//Overloading unary operators to increment or decrement positions.
	const Circle operator++();
	const Circle operator++(int);
	const Circle operator--();
	const Circle operator --(int);

	//Overloading + and - operators to create new circle.
	const Circle operator +(const double number) const;
	const Circle operator -(const double number) const;

	//Overloading operators to compare two circle.
	bool  operator == (const Circle& second) const;
	bool  operator != (const Circle& second) const;
	bool  operator < (const Circle& second) const;
	bool  operator > (const Circle& second) const;

	//Static  functions to calculate total area and perimeter lenght of all circles.
	static double totalArea() ;
	static double totalPerimeter() ;

	void outputUploaded() const;

	void set_smallRadius(double value); // Initilates the radius of small Circle according to entered value.
	void setBigColor();// Assigns color red to container Circle.
	void setSmallColor();// Assigns color green to small Circle.

	void setDegree(int valueDegree); //Determining rotating degree.
	

	void setBigCircle(double x,double y); // Determines the position of container Circle.
	void setCircle(double uploaded_x,double uploaded_y); // Determines the new positions of small Circles in container shape.
	void setRotate(double x,double y); // Determines which coordinates to rotate.

	void draw(int degree,ofstream &SvgFile); // Draws the container and small Circles in Svg File.
		
	void test(); // Tests radius is negative or zero.If it is,then program is stopped.
	void output() const; // Writes radius of Circle on screen,if it is necessary.

	
	char getbigColor() const; // Return container circle color.
	char getsmallColor() const ; // Return circle color.
	double getRadius() const ;// Returns radius of container Circle.
	double getSmallRadius() const; // Return radius of small Circle.
	int getDegree() const ;

	// Returns positions of small and container Circles.
	double getPos_x() const;
	double getPos_y() const ;
	double getSmallPosx() const ;
	double getSmallPosy() const ;
	double getRotateX() const ;
	double getRotateY() const ;

private:
	static double sumArea;
	static double sumPerimeter;
	double radius,s_radius; // Radius of container and small Circle.
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

#endif
