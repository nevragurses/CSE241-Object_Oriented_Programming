/*
 * Polygon.h
 *
 *  
 *      Author: Nevra Gürses
 */
#ifndef POLYGON_H_
#define POLYGON_H_
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
using std::istream;
using std::ostream;
using std::find;
using std::vector; 

namespace ShapeOfGurses
{
	class Polygon : public Shape
	{
	public:
		class Point2D //Inner class for holdind 2d points.
		{
		public:
			Point2D() throw(); //No parameter constructor.
			Point2D(double x,double y) throw(invalid_argument); //Initilizing positions of 2d points.
			void setPositions(double x,double y)  throw(invalid_argument); //setter function.
			
			//Getter functions.
			double get_x() const throw();
			double get_y() const throw();
		protected:
			double coordX;
			double coordY;
		};
		Polygon()  throw();

		virtual void draw(ostream& SvgFile) const =0; //Pure virtual draw function.

		//Getter functions.
		double getRotateX() const throw();
		int getSize() const throw();
		char getColorPoly() const throw();
		double getRotateY() const throw();

		

		//Thise overloaded operators and functions came shape class,and they are not doing anything in this class.
		 double Area() const throw();
		 double Perimeter() const throw();
		 const Polygon& operator++()  throw();
		 const Polygon& operator++(int) throw();
		 const Polygon& operator--() throw();
		 const Polygon& operator --(int)throw() ;
		 const Polygon& operator +(const double number) const throw();
		 const Polygon& operator -(const double number) const throw() ;


	protected:
		double rotateX,rotateY;
		int size;
		char colorPoly;
	};
}
#endif
