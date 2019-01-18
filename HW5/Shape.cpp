/*
 * Shape.cpp
 *
 *
 *      Author: Nevra Gürses
 */
#include "Shape.h"
using namespace std;
namespace ShapeOfGurses{

	Shape::Shape() throw() //No parameter constructor.
		:color('r'),s_color('g'),degree(0)
	{ }
	Shape::Shape(char bigColor,int degreeVal) throw(invalid_argument)  //Initializing big color and degree.
		:color(bigColor),degree(degreeVal)
	{ 
		if(color!='r' ) //If big color is not equal red,throw an exception.
			throw invalid_argument("Container shape color must be red!-14");
	}
	Shape::Shape(int degreeVal) throw() //Initializing rotating degree.
		:degree(degreeVal)
	{ }
	Shape::Shape(char colorSmall) throw(invalid_argument) //Initializing small color.
		:s_color(colorSmall)
	{  
		if(s_color!='g') //If small color is not equal green,throw an exception.
			throw invalid_argument("Small shape color must be green!-15");
	}
	//Overloaded operators that compare 2 area.
	bool Shape::operator == (const Shape& secondArea) const throw(){
		return ( Area() == secondArea.Area());
	}
	bool Shape::operator != (const Shape& secondArea)const throw(){
		return ( Area() != secondArea.Area());
	}
	bool Shape::operator < (const Shape& secondArea) const throw(){
		return (Area() < secondArea.Area());
	}
	bool Shape::operator > (const Shape& secondArea) const throw(){
		return ( Area() > secondArea.Area());
	}
	void Shape::setDegree(int degreeVal) throw() {  
		degree=degreeVal;
	}
	//Setter functions.
	void Shape::setBigColor() throw() { color = 'r' ; }
	void Shape::setSmallColor() throw() { s_color = 'g'; }
	
	//Getter functions.
	char Shape::getBigColor() const throw() { return color; }
	char Shape::getSmallColor() const throw (){ return s_color;}
	int Shape::getDegree() const throw(){ return degree; }
}


















