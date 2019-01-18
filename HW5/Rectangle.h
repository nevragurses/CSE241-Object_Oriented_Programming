/*
 * Rectangle.h
 *
 *
 *      Author: Nevra Gürses
 */
#ifndef RECTANGLE_H_
#define RECTANGLE_H_
#include "Shape.h"
#include <string>
#include <stdexcept> //for invalid_argument exception.
using namespace std;
namespace ShapeOfGurses
{
	class Rectangle : public Shape
	{
	public:
		Rectangle(int widthValue,int heightValue,double x,double y,char bigColor,int degree) throw (invalid_argument); // Initializes  container Rectangle.
		Rectangle(double bigX,double bigY,double smallX,double smallY,int degree) throw (invalid_argument); //Initializes the positions of container and small rectangle.
		Rectangle (double widthValue,double heightValue,char color) throw (invalid_argument); //Initializes small rectangle.
		Rectangle(double widthVal,double heightVl,int degree) throw (invalid_argument); //Initializes container rectangle.
		Rectangle (int smallHeight,int smallWidth,double posX,double posY,char color) throw (invalid_argument); //Initializes small rectangle with positions.
		Rectangle() throw();// No parameter constructor.
		

	 	
		double Perimeter() const throw(); //Returns perimeter of rectangle.
		double Area() const throw(); //Returns area of rectangle.


		//overloded + and - operators to create new rectangle.
		const Rectangle& operator +(const double number) const throw (invalid_argument);
		const Rectangle& operator -(const double number) const throw (invalid_argument);

		//overloaded unary operators to incrementing and recrementing positions.
		const Rectangle& operator++() throw ();
		const Rectangle& operator++(int) throw ();
		const Rectangle& operator--() throw (invalid_argument);
		const Rectangle& operator --(int) throw (invalid_argument);
		
		void outputUploaded() const throw(); //prints on screen positions of container and small rectangles.
		void output() const throw(); //Prints features of rectangle.

		//Setter functions of rectangle.
		void setRectangle(double widthValue,double heightValue,double uploaded_x,double uploaded_y ) throw (invalid_argument); 
		void setSmall(double sWidth,double sHeight) throw (invalid_argument); 
		void setRectangle2(double widthValue,double heightValue,double uploaded_x,double uploaded_y) throw (invalid_argument);
		void setNewSmall(double value1,double value2) throw (invalid_argument);

		void draw(ostream& SvgFile) const throw(); // Draws the container and small Rectangle in Svg File.

		//Getter functions of rectangle.
		double getHeight() const  throw();
		double getWidth() const  throw();
		double getSmallHeight() const  throw();
		double getSmallWidth() const  throw();
		double getPos_x() const  throw();
		double getPos_y() const  throw();
		double getSmallPos_x() const  throw();
		double getSmallPos_y() const  throw();
	protected:
		double width,s_width; // Width for container and small Rectangle.
		double height,s_height; // Height for container and small Rectangle.
		// Positions of container and small Rectangles.
		double pos_x,pos_y;
		double s_posX,s_posY;


	};


}
#endif
