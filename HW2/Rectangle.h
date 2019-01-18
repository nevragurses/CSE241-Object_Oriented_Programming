/*
 * Rectangle.h
 *
 *  Created on: Oct 24, 2018
 *      Author: Nevra Gürses
 */
#ifndef RECTANGLE_H_
#define RECTANGLE_H_
#include <fstream>
using namespace std;
class Rectangle
{
public:
	Rectangle(int widthValue,int heightValue,int x,int y) // Initilates the heigt,width  value and coordinate  of container Rectangle according to entered value.
		:width(widthValue),height(heightValue),pos_x(x),pos_y(y)
	{
		test(); // Calling test function to whether values are appopriate or not.
	}
	Rectangle(){ } // No parameter constructor.
	
	void setSmall(int sWidth,int sHeight){  // Initilates the widht and height value of small Rectangle according to entered value.
		s_width=sWidth;
		s_height=sHeight;
	}
	void setBigColor(); // Assigns color red to container Rectangle.
	void setSmallColor();// Assigns color green to small Rectangle.

	
	void setRectangle(int widthValue,int heightValue,int uploaded_x,int uploaded_y ); // Determines the new positions of small Rectangles in container shape.
	// Determines the new positions of small Rectangles in container shape if small rectangles be placed vertically in container shape.
	void setRectangle2(int widthValue,int heightValue,int uploaded_x,int uploaded_y); 
	
	// Assigns values for small width and height.This is necessary if width smaller than height they  commutative to calculate number of small Rectangle to my algorithm.	
	void setNewSmall(int value1,int value2){ 
		s_width=value1;
		s_height=value2;
	}
	void draw(ofstream& SvgFile); // Draw the container and small Rectangle in Svg File.
	void test(); // Tests the height or width value are  negative or zero.If it is,then program is stopped.
	
	void output() const; // Writes width and height value of Rectangle on screen,if it is necessary.
	char getbigColor() const { return color; } //Returns container rectangle color.
	char getsmallColor() const { return s_color ;} 	//Return small rectangle color.
	int getHeight() const { return height; } // Returns height value of container Rectangle.
	int getWidth() const { return width; } // Returns width value of container Rectangle.
	int getSmallHeight() const { return s_height; } // Returns height value of small Rectangle.
	int getSmallWidth() const { return s_width; } // Returns width value of small Rectangle.
	// Return positions of container and small Rectangles.
	int getPos_x() const { return pos_x; }
	int getPos_y() const { return pos_y; }
	int getSmallPos_x() const { return s_posX; }
	int getSmallPos_y() const { return s_posY; }
private:	
	int width,s_width; // Width for container and small Rectangle.
	int height,s_height; // Height for container and small Rectangle.
	// Positions of container and small Rectangles.
	int pos_x,pos_y;
	int s_posX,s_posY;
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

