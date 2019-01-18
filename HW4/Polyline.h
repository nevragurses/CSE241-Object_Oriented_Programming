/*
 * Polyline.h
 *
 *  Created on: 19,11,2018
 *      Author: Nevra Gürses
 */
#ifndef POLYLINE_H_
#define POLYLINE_H_
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "Polygon.h"
using std::istream;
using std::ostream;
using std::find;
using std::vector; //for vector
using namespace PolygonOfGurses;

namespace PolylineOfGurses
{
	class Polyline
	{
	public:
		
		Polyline(vector<Polygon::Point2D>polinePoints); //constructor that takes stl vector.
		Polyline();

		//Conversion constructors.
		Polyline(Rectangle rectangle);
		Polyline(Circle circle);
		Polyline(Triangle triangle);
		Polygon::Point2D& operator[](const int index) const;
		//Overloaded comparision operators.
		bool operator == (const Polyline& another) const;
		bool operator != (const Polyline& another) const;

		const Polyline operator +(const Polyline& another) const; //overloaded adding operator.
		friend ostream& operator <<(ostream& SvgFile,const Polyline& x); //overloaded << operator to drawing.
		void print() const ;

		
	private:
		Polygon object; //Polygon object to using members of polygon class.
		
	};
}
#endif
