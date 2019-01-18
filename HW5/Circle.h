/*
 * Circle.h
 *
 *  
 *      Author: Nevra Gürses
 */
#ifndef CIRCLE_H_
#define CIRCLE_H_
#include <fstream>
#include <stdexcept> //for invalid_argument exception.
#include "Shape.h"
#define PI 3.14

using namespace std;
namespace ShapeOfGurses
{
	class Circle : public Shape
	{
	public:
		Circle(double radiusValue,char color,int degree)throw(invalid_argument) ;// Initializes  container Circle.
		Circle(double radiusSmall,char colorSmall) throw(invalid_argument); //	Initializes small circle.
		Circle() throw(); // No parameter constructor.
		Circle(double radiusValue,double x,double y,char color) throw(invalid_argument); // Initializes radius,positions and rotating degree of small circle.
		Circle(double bigX,double bigY,double smallX,double smallY,int degree) throw(invalid_argument); //Initializes positions of container and small circles.

		
		double Perimeter() const throw(); //Returns perimeter of circle.
		double Area() const throw(); //Returns area of circle.
	

		void draw(ostream& SvgFile) const throw(); // Draws the container and small Circles in Svg File.

		//Overloading unary operators to increment and decrement positions.
		const Circle& operator++() throw();
		const Circle& operator++(int) throw();
		const Circle& operator--() throw(invalid_argument);
		const Circle& operator --(int) throw(invalid_argument);

		//Overloading + and - operators to create new circle.
		const Circle& operator +(const double number) const throw(invalid_argument);
		const Circle& operator -(const double number) const throw(invalid_argument);

 
		void outputUploaded() const throw(); //Prints positions of small and container circle on screen.

		
		//Setter functions of circle.
		void setBigCircle(double x,double y) throw(invalid_argument); 
		void setCircle(double uploaded_x,double uploaded_y) throw(invalid_argument); 
		void setRotate(double x,double y) throw(invalid_argument);

		
		//Getter functions of circle.
		double getRadius() const throw();
		double getSmallRadius() const throw(); 
		double getPos_x() const throw();
		double getPos_y() const throw();
		double getSmallPosx() const throw();
		double getSmallPosy() const throw();
		double getRotateX() const throw();
		double getRotateY() const throw();

	protected:
		double radius,s_radius; // Radius of container and small Circle.
		// Positions of container and small circles.
		double bigpos_x;
		double bigpos_y;
		double pos_x;
		double pos_y;
		// Rotate coordinates.
		double coordX;
		double coordY;

	};
	
}

#endif
