/*
 * Rectangle.h
 *
 *  
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
	double smallPerimeter() const;

 	//Returns perimeter of container rectangle.
	double bigPerimeter() const;

	//Returns area of small rectangle.
	double smallArea() const;

	//Returns area of big rectangle.
	double bigArea() const;


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
	
	// Assigns values for small width and height.	
	void setNewSmall(double value1,double value2);
	
	void draw(ofstream& SvgFile); // Draw the container and small Rectangle in Svg File.
	void test(); // Tests the height or width value are  negative or zero.If it is,then program is stopped.
	
	void output() const; // Writes width and height value of Rectangle on screen,if it is necessary.

	//Returning private members.
	char getbigColor() const; 
	char getsmallColor() const;	
	double getHeight() const; 
	double getWidth() const;
	double getSmallHeight() const; 
	double getSmallWidth() const ; 
	// Return positions of container and small Rectangles.
	double getPos_x() const;
	double getPos_y() const;
	double getSmallPos_x() const;
	double getSmallPos_y() const ;
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


#endif

