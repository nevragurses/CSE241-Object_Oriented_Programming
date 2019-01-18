/*
 * Rectangle.h
 *
 *  Created on: 07,11,2018
 *      Author: Nevra Gürses
 */
#ifndef RECTANGLE_H_
#define RECTANGLE_H_
#include <fstream>
using namespace std;
class Rectangle
{
public:
	Rectangle(int widthValue,int heightValue,double x,double y); // Initilates the heigt,width  value and coordinate  of container Rectangle.
	Rectangle(double bigX,double bigY,double smallX,double smallY); //Initilizes the positions of container and small rectangle.
	Rectangle (double widthValue,double heightValue); //Initilizes the height and width a rectangle.
	Rectangle(){ } // No parameter constructor.
	void setSmall(double sWidth,double sHeight);  // Initilates the width and height value of small Rectangle.

	//Overloaded << operator to draw shape in svg file.
	friend ostream& operator <<(ostream& SvgFile,const Rectangle& object);

	//Returns perimeter of small rectangle.
	double smallPerimeter() const { return ((2*s_width)+(2*s_height)); }

 	//Returns perimeter of container rectangle.
	double bigPerimeter() const { return ((2*width)+(2*height)); }

	//Returns area of small rectangle.
	double smallArea() const { return (s_width*s_height); }

	//Returns area of big rectangle.
	double bigArea() const { return (width*height); }


	//overloded + and - operators to create new rectangle.
	const Rectangle operator +(const double number) const;
	const Rectangle operator -(const double number) const;

	//overloaded unary operators to incrementing and recrementing positions.
	const Rectangle operator++();
	const Rectangle operator++(int);
	const Rectangle operator--();
	const Rectangle operator --(int);
	
	//overloaded operators to compare two rectangle.
	bool  operator == (const Rectangle& second) const;
	bool  operator != (const Rectangle& second) const;
	bool  operator < (const Rectangle& second) const;
	bool  operator > (const Rectangle& second) const;
	
	//static functions to calculate area and perimeter of all rectangles.
	static double totalArea();
	static double totalPerimeter();

	void outputUploaded() const ; //prints screen positions of container and small rectangles.
	void setBigColor(); // Assigns color red to container Rectangle.
	void setSmallColor();// Assigns color green to small Rectangle.

	void setRectangle(double widthValue,double heightValue,double uploaded_x,double uploaded_y ); // Determines the new positions of small Rectangles in container shape.
	// Determines the new positions of small Rectangles in container shape if small rectangles be placed vertically in container shape.
	void setRectangle2(double widthValue,double heightValue,double uploaded_x,double uploaded_y); 
	
	// Assigns values for small width and height.This is necessary if width smaller than height they  commutative to calculate number of small Rectangle to my algorithm.	
	void setNewSmall(double value1,double value2){ 
		s_width=value1;
		s_height=value2;
	}
	void draw(ofstream& SvgFile); // Draw the container and small Rectangle in Svg File.
	void test(); // Tests the height or width value are  negative or zero.If it is,then program is stopped.
	
	void output() const; // Writes width and height value of Rectangle on screen,if it is necessary.
	char getbigColor() const { return color; } //Returns container rectangle color.
	char getsmallColor() const { return s_color ;} 	//Returns small rectangle color.
	double getHeight() const { return height; } // Returns height value of container Rectangle.
	double getWidth() const { return width; } // Returns width value of container Rectangle.
	double getSmallHeight() const { return s_height; } // Returns height value of small Rectangle.
	double getSmallWidth() const { return s_width; } // Returns width value of small Rectangle.
	// Return positions of container and small Rectangles.
	double getPos_x() const { return pos_x; }
	double getPos_y() const { return pos_y; }
	double getSmallPos_x() const { return s_posX; }
	double getSmallPos_y() const { return s_posY; }
private:
	static double sumArea;
	static double sumPerimeter;	
	double width,s_width; // Width for container and small Rectangle.
	double height,s_height; // Height for container and small Rectangle.
	// Positions of container and small Rectangles.
	double pos_x,pos_y;
	double s_posX,s_posY;
	char color,s_color; // Color for container and small Rectangle.

};
//Inline functions with inline keyword.
inline void Rectangle::setBigColor(){
	color='r';
}
inline void Rectangle::setSmallColor(){
	s_color='g';
}

#endif

