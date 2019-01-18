/*
 * Polygon.h
 *
 *  Created on: 19,11,2018
 *      Author: Nevra Gürses
 */
#ifndef POLYGON_H_
#define POLYGON_H_
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
using std::istream;
using std::ostream;
using std::find;
using std::vector; 

namespace PolygonOfGurses
{
	class Polygon 
	{
	public:
		class Point2D //Inner Point2D class.
		{
			public:
				Point2D(double x,double y);
				void setPositions(double x,double y); //sets new positions.
				Point2D();
				double get_x() const;
				double get_y() const;

			private:
				double coordX;
				double coordY;
		};
		Polygon(vector<Point2D>polygonPoints); // constructor that takes an STL vector of Point2D objects to represent the Polygon points.
		Polygon();
		Polygon(const Polygon& object); //Copy constructor.
	
		//Conversion constructors.
		Polygon(Rectangle rectangle);
		Polygon(Circle circle);
		Polygon(Triangle triangle);

		~Polygon(); //Destructor.

		Polygon& operator=(const Polygon& second); //Overloaded assignment operator.
		Point2D& operator[](const int index) const; //overloaded [] operator.
		//overloded comparision operators.
		bool operator == (const Polygon& secondPolygon) const;
		bool operator != (const Polygon& secondPolygon) const;

		const Polygon operator +(const Polygon& secondPolygon) const; //overloading adding operator.
		friend ostream& operator <<(ostream& SvgFile,const Polygon& object); //overloading << operator to draw shape.
		

		//Returning members.
		int getSize() const ;
		int getDegree() const ;
		char getColor() const ;
		double getrotateX() const ;
		double getrotateY () const;
		void printArray() const; //Printing coordinates.
	private:
		Point2D *pointsOfPolygon; //dynamic array of Point2D class type. 
		//members that is used in drawing of calculating.
		int size,degree; 
		char color;
		double rotateX,rotateY;
	};
}
#endif
