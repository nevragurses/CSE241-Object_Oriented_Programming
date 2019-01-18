/*
 * Polygon.cpp
 *
 *
 *      Author: Nevra Gürses
 */
#include "Polygon.h"
using std::istream;
using std::ostream;
using std::cout;
using std::cin;

namespace ShapeOfGurses{ //My namespace.
	

	Polygon::Point2D::Point2D(double x,double y) throw(invalid_argument) //Initializing coordinates of a point in Point2D class.
		:coordX(x),coordY(y)
	{ 
		if(coordX<0 || coordY<0)
			throw invalid_argument("2D points can't be negative! -38");

	}
	Polygon::Point2D::Point2D() throw() //Defaulted constructor of Point2D class.
		:coordX(0),coordY(0)
	{ }
	void Polygon::Point2D::setPositions(double x,double y)  throw(invalid_argument){ //Setting new coordinates in Point2D class.
		coordX=x;
		coordY=y;
		if(coordX<0 || coordY<0)
			throw invalid_argument("2D points can't be negative! -39");
	}
	//Returning Point2D members.
	double Polygon::Point2D::get_x() const throw() {
		return coordX;
	}
	double Polygon::Point2D::get_y() const throw(){
		return coordY;
	}
	Polygon::Polygon() throw() //No parameter constructor.
		:Shape(),size(0),colorPoly('r'),rotateX(0),rotateY(0)
	{ }
	//Getter functions.
	double Polygon::getRotateX() const throw(){return rotateX;}
	int Polygon::getSize() const throw(){ return size; }
	char Polygon::getColorPoly() const throw(){ return colorPoly; }
	double Polygon::getRotateY() const throw(){ return rotateY;}
	double Polygon::Area() const throw(){ }
	double Polygon::Perimeter() const throw(){ }
	//Thise overloaded operators came shape class,and that are not doing anything in this class.
	const Polygon& Polygon :: operator++() throw() { }
	const Polygon& Polygon :: operator++(int) throw(){ }
	const Polygon& Polygon ::  operator--() throw(){}
	const Polygon& Polygon ::operator --(int)throw() { }
	const Polygon& Polygon ::operator +(const double number) const throw(){}
	const Polygon& Polygon :: operator -(const double number) const throw() {}

}
