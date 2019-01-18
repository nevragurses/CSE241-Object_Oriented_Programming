/*
 * Shape.h
 *
 *
 *      Author: Nevra Gürses
 */
#ifndef SHAPE_H
#define SHAPE_H
#include <fstream>
#include <stdexcept> //for invalid_argument exception.
#include <cstdlib>
using namespace std;
namespace ShapeOfGurses
{
	class Shape
	{
	public:
		Shape() throw(); //no parameter constructor.
		Shape(char bigColor,int degreeVal) throw(invalid_argument); //Initializing big color and degree.
		Shape(int degree) throw(); //Initializing rotating degree.
		Shape(char color) throw(invalid_argument);  //Initializing small color.

		//Pure virtual functions and overloaded operators that will use in derived classes.
		virtual double Area() const =0 ;
		virtual double Perimeter() const =0;
		virtual void draw(ostream& SvgFile)const=0;
		virtual const Shape& operator++() = 0;
		virtual const Shape& operator++(int) = 0;
		virtual const Shape& operator--() = 0;
		virtual const Shape& operator --(int) = 0;

		virtual const Shape& operator +(const double number) const = 0;
		virtual const Shape& operator -(const double number) const = 0;

		//Overloaded operators that compare 2 area.
		bool  operator == (const Shape& secondArea) const throw();
		bool  operator != (const Shape& secondArea) const throw();
		bool  operator < (const Shape& secondArea) const throw();
		bool  operator > (const Shape& secondArea) const throw();

		//Getter and setter functions.
		int getDegree() const throw();
		void setDegree(int degreeVal)throw();
		void setBigColor()throw() ;
		void setSmallColor() throw();
		char getBigColor() const throw();
		char getSmallColor() const throw();

	protected:
		char color,s_color;
		int degree;
	};
	

}
#endif
