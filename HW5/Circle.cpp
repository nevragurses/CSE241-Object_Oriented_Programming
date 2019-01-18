/*
 * Circle.cpp
 *
 *  
 *      Author: Nevra Gürses
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Circle.h"
using namespace std;
namespace ShapeOfGurses{
	Circle::Circle(double radiusValue,char color,int degree) throw(invalid_argument) // Initializes  container Circle.
		:Shape(color,degree),radius(radiusValue)
	{
		if(radius<=0) //If radius is not positive,throw exception.
			throw invalid_argument("Radius can't be zero or negative!-16");
	}
	Circle::Circle(double radiusSmall,char colorSmall) throw(invalid_argument) //Initializes small circle.
		:Shape(colorSmall),s_radius(radiusSmall)	
	{
		if(s_radius<=0) //If radius is not positive,throw exception.
			throw invalid_argument("Radius can't be zero or negative!-17");
  	}	
	Circle::Circle(double radiusValue,double x,double y,char color) throw(invalid_argument) //Initializes small  circles with positions.
		:Shape(color),s_radius(radiusValue),pos_x(x),pos_y(y)
	{ 
		if(s_radius<=0 || pos_x <0 || pos_y<0) //If radius or positions are not positive,throw exception.
			throw invalid_argument("Radius or positions can't be negative !-18");
	}
	Circle::Circle(double bigX,double bigY,double smallX,double smallY,int degree) throw(invalid_argument) //Initializes positions of small and container circle.
		:Shape(degree),bigpos_x(bigX),bigpos_y(bigY),pos_x(smallX),pos_y(smallY)
	{
		if(bigpos_x <0 || bigpos_y<0 || pos_x <0 || pos_y<0) //If positions are not positive,throw exception.
			throw invalid_argument(" Positions can't be negative !-19");
	}
	Circle::Circle() throw() //No parameter constructor.
		:Shape()
	{
	}

	//Overloading + and - operators to create new circle.
	const Circle& Circle:: operator + (const double number) const throw(invalid_argument){
		double new_radius= radius + number;
		if(new_radius<=0) //If new radius  is not positive,throw exception.
			throw invalid_argument("Radius can't be zero or negative!-20");
		Circle circ(new_radius,'r',0);
		Circle& tempCircle=circ;
		return tempCircle;
	}
	const Circle& Circle:: operator - (const double number) const throw(invalid_argument) {
		double new_radius= radius - number;
		if(new_radius<=0) //If new radius  is not positive,throw exception.
			throw invalid_argument("Radius can't be zero or negative!-21");
		Circle circ(new_radius,'r',0);
		Circle& tempCircle=circ;
		return tempCircle;
	}
	//Overloading unary operators to increment or decrement positions.
	const Circle& Circle::operator ++() throw(){ //pre incerementing.
		bigpos_x ++;
		bigpos_y ++;
		pos_x ++;
		pos_y ++;
		Circle circ(bigpos_x,bigpos_y,pos_x,pos_y,0);
		Circle& tempCircle=circ;
		return tempCircle;
	}
	const Circle& Circle::operator ++(int ignore) throw(){ //post incrementing.
		Circle circ(bigpos_x ++,bigpos_y ++ ,pos_x ++ ,pos_y ++,0);
		Circle& tempCircle=circ;
		return tempCircle;
	}
	const Circle& Circle::operator --() throw(invalid_argument){ //pre decrementing.
		bigpos_x --;
		bigpos_y --;
		pos_x --;
		pos_y--;
		if( bigpos_x <0 || bigpos_y<0 || pos_x <0 || pos_y<0) //If new positions  are not positive,throw exception.
			throw invalid_argument("Positions can't be  negative! -22");
		Circle circ(bigpos_x,bigpos_y,pos_x,pos_y,0);
		Circle& tempCircle=circ;
		return tempCircle;

	}
	const Circle& Circle::operator --(int ignore) throw(invalid_argument){ //post decrementing.
		Circle circ(bigpos_x --,bigpos_y --,pos_x --,pos_y --,0);
		if(bigpos_x <0 || bigpos_y<0 || pos_x <0 || pos_y< 0) //If new positions  are not positive,throw exception.
			throw invalid_argument("Positions can't be negative! -23");
		Circle& tempCircle=circ;
		return tempCircle;
	}
	
	//Prints the screen positions of container and small circle.	
	void Circle::outputUploaded() const throw(){
		cout << "Position x of big:" << bigpos_x << endl << "Position y of big:" << bigpos_y << endl
		     << "Position x of small:" << pos_x << endl << "Position y of small:" << pos_y << endl;
	} 
	
	

	// Perimeter of  a circle.
	double Circle::Perimeter() const throw(){ 
		if(getBigColor()=='r')
			return (2*PI*radius); 
		else
			return (2*PI*s_radius);
	}

	//Area of a circle.
	double Circle::Area() const throw(){
		if(getBigColor()=='r')
			return (PI*radius*radius); 
		else
			return (PI*s_radius*s_radius);
	}
	//Sets positons of big circle.	
	void Circle::setBigCircle(double x,double y) throw(invalid_argument){
		bigpos_x=x;
		bigpos_y=y;
		if(bigpos_x <0 || bigpos_y<0 ) //If  positions are not positive,throw exception.
			throw invalid_argument("Positions can't be negative -24");
		
	}
	// Determines the new positions of small Circles in container shape.
	void Circle::setCircle(double uploaded_x,double uploaded_y)  throw(invalid_argument){
		pos_x=uploaded_x;
		pos_y=uploaded_y;
		if(pos_x <0 || pos_y<0) //If  positions are not positive,throw exception.
			throw invalid_argument("Positions can't be negative -25");
	}
	// Determines which coordinates to rotate.
	void Circle::setRotate(double x,double y) throw(invalid_argument){
		coordX=x;
		coordY=y;
		if(coordX <0 || coordY<0) //If  positions for rotate are not positive,throw exception.
			throw invalid_argument("Positions can't be negative -26");
			
	}
	
	// Draws the container and small Circles in Svg File.
	void Circle::draw(ostream& SvgFile) const throw(){
		//Prints container Circle in svg file.Color is determinant.
		if(color == 'r' && degree ==0){
			SvgFile << "<svg version=\"1.1\" baseProfile=\"full\" width=\"100%\" height=\"100%\" xmlns=\"http://www.w3.org/2000/svg\"> " 
				<< " <circle cx=\"" <<  radius<< "\"" << " cy=\"" << radius
				<< "\"" <<" r=\"" << radius << "\" "<< "fill=\"red\" /> " << endl;
		}
		//Prints small Circles in svg file that is not rotating.Color is determinant.
		else if(s_color == 'g' && degree==0){
			SvgFile << " <circle cx=\"" <<  pos_x<< "\"" << " cy=\"" << pos_y
				<< "\"" <<" r=\"" << s_radius << "\" "<< "fill=\"green\" /> " << endl;
		}
		//If rotating necessary for small Circle,shape according to entered degree is rotated and prints Svg file.
		else if(degree !=0){
			SvgFile << " <circle cx=\"" <<  pos_x << "\"" << " cy=\"" << pos_y
				<< "\"" <<" r=\"" << s_radius << "\" "<< "fill=\"green\" " 
				<<"transform=\"rotate(" << degree <<","<< coordX << ","  << coordY << ")\"/> " << endl;
		} 
	}
	double Circle::getRadius() const throw(){ return radius; } // Returns radius of container Circle.
	double Circle::getSmallRadius() const throw(){ return s_radius; } // Return radius of small Circle.

	// Returns positions of small and container Circles.
	double Circle::getPos_x() const  throw(){ return bigpos_x; }
	double Circle::getPos_y() const  throw(){ return bigpos_y; }
	double Circle::getSmallPosx() const  throw(){ return pos_x; }
	double Circle::getSmallPosy() const  throw(){ return pos_y; }
	double Circle::getRotateX() const  throw(){ return coordX; }
	double Circle::getRotateY() const  throw(){ return coordY; }

	
}
