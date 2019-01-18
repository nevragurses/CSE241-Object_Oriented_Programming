/*
 * Rectangle.cpp
 *
 *  
 *      Author: Nevra Gürses
 */
#include <iostream>
#include <cstdlib>
#include <fstream>
#include "Rectangle.h"
using namespace std;
Rectangle::Rectangle(int widthValue,int heightValue,double x,double y) // Initilates the heigt,width  value and coordinate  of container Rectangle.
	:width(widthValue),height(heightValue),pos_x(x),pos_y(y)
{
	sumArea=sumArea + bigArea();//Increasing area to calculate total area.
	sumPerimeter=sumPerimeter + bigPerimeter(); //Increasing perimeter to calculate total perimeter.
	test(); // Calling test function to whether values are appopriate or not.
}
Rectangle::Rectangle(double bigX,double bigY,double smallX,double smallY) //Initilizes positions of small and container rectangle.
	:pos_x(bigX),pos_y(bigY),s_posX(smallX),s_posY(smallY)
{  }
Rectangle::Rectangle (double widthValue,double heightValue) // Initilates the heigt,width  of container Rectangle.
	:width(widthValue),height(heightValue)
{
	sumArea=sumArea + bigArea(); //Increasing area to calculate total area.
	sumPerimeter=sumPerimeter + bigPerimeter(); //Increasing perimeter to calculate total perimeter.
}
void Rectangle :: setSmall(double sWidth,double sHeight){  // Initilates the widht and height value of small Rectangle according to entered value.
	s_width=sWidth;
	s_height=sHeight;
	sumArea=sumArea + smallArea();
	sumPerimeter=sumPerimeter + smallPerimeter();
}
//Overloaded << operator to draw shape in svg file.
ostream& operator <<(ostream& SvgFile,const Rectangle& object){
	if( object.color == 'r'){
		SvgFile << "<svg version=\"1.1\" baseProfile=\"full\" width=\"100%\" height=\"100%\" xmlns=\"http://www.w3.org/2000/svg\"> " << endl
			<< " <rect width=\""<< object.width  << "\" height=\"" << object.height  << "\"" << " fill=\"red\" /> " << endl;
	}
	else if(object.s_color == 'g'){
		SvgFile << " <rect x=\"" << object.s_posX << "\"" << " y=\""<< object.s_posY
			<< "\"" << " width=\"" <<  object.s_width << "\"" << " height=\"" << object.s_height
			<< "\"" << " fill=\"green\" " << "/>" << endl;
	}
	return SvgFile;
}
//Overloaded binary + and - operator to creating new object.
const Rectangle Rectangle :: operator +(const double number) const{
	double new_height=height + number;
	double new_width=width +number;
	return Rectangle(new_width,new_height);
}
const Rectangle Rectangle :: operator -(const double number) const{
	double new_height=height - number;
	double new_width=width  - number;
	return Rectangle(new_width,new_height);
}
//Overloaded binary operators to incrementing and decrementing positions.
const Rectangle Rectangle::operator ++(){
	pos_x ++;
	pos_y ++;
	s_posX ++;
	s_posY ++;
	return Rectangle(pos_x,pos_y,s_posX,s_posY);
}
const Rectangle Rectangle::operator ++(int ignore){
	return Rectangle(pos_x ++,pos_y ++ ,s_posX ++ ,s_posY ++);
}
const Rectangle Rectangle::operator --(){
	pos_x --;
	pos_y --;
	s_posX --;
	s_posY --;
	return Rectangle(pos_x,pos_y,s_posX,s_posY);
}
const Rectangle Rectangle::operator --(int ignore){
	return Rectangle(pos_x --,pos_y -- ,s_posX -- ,s_posY --);
}
//Overloaded operators to compare two rectangle.
bool Rectangle::operator == (const Rectangle& second) const{
	return ( bigArea() == second.bigArea());
}
bool Rectangle :: operator != (const Rectangle& second) const{
	return ( bigArea() != second.bigArea());
}
bool Rectangle::operator < (const Rectangle& second) const{
	return ( bigArea() < second.bigArea());
}
bool Rectangle :: operator > (const Rectangle& second) const{
	return ( bigArea() > second.bigArea());
}
//Static functions to calculate total area and total perimeter.
double Rectangle :: sumArea = 0;
double Rectangle :: sumPerimeter =0;	
double Rectangle :: totalArea(){
	return sumArea;
}
double Rectangle :: totalPerimeter(){
	return sumPerimeter;
}

// Tests the height or width value are  negative or zero.If it is,then program is stopped.
void Rectangle::test(){
	if(height<=0 || width <=0){
		cout << "Height or width can not be negative number or zero." << endl;
		exit(1);
	}
}
//Prints on  screen positions of container and small rectangle.
void Rectangle::outputUploaded() const{
	cout << "Position x of big:" << pos_x << endl << "Position y of big:" << pos_y << endl
	     << "Position x of small:" << s_posX << endl << "Position y of small:" << s_posY << endl;
} 	

// Writes width and height value of Rectangle on screen,if it is necessary.
void Rectangle::output() const{
	cout << "Height of New Rectange is:" << height << endl
	     <<"Width of New Rectangle is:"  << width << endl;
}

// Determines the new positions of small Rectangles in container shape.
void Rectangle::setRectangle(double widthValue,double heightValue,double uploaded_x,double uploaded_y ){
	s_width=widthValue;
	s_height=heightValue;
	s_posX=uploaded_x;
	s_posY=uploaded_y;
}
// Determines the new positions of small Rectangles in container shape if small rectangles be placed vertically in container shape.
void Rectangle::setRectangle2(double widthValue,double heightValue,double uploaded_x,double uploaded_y ){
	s_posX=uploaded_x;
	s_posY=uploaded_y;
	s_width=heightValue;
	s_height=widthValue;
}
void Rectangle::setNewSmall(double value1,double value2){ 
	s_width=value1;
	s_height=value2;
}
//Returns perimeter of small rectangle.
double Rectangle::smallPerimeter() const { return ((2*s_width)+(2*s_height)); }

//Returns perimeter of container rectangle.
double Rectangle::bigPerimeter() const { return ((2*width)+(2*height)); }

//Returns area of small rectangle.
double Rectangle::smallArea() const { return (s_width*s_height); }

//Returns area of big rectangle.
double Rectangle::bigArea() const { return (width*height); }

//Initilazing colors.
void Rectangle::setBigColor(){
	color='r';
}
void Rectangle::setSmallColor(){
	s_color='g';
}

// Draw the container and small Rectangle in Svg File.
void Rectangle::draw(ofstream &SvgFile){
	//Prints container rectangle in Svg file.Color is determinant.
	if( color == 'r'){
		SvgFile << "<svg version=\"1.1\" baseProfile=\"full\" width=\"100%\" height=\"100%\" xmlns=\"http://www.w3.org/2000/svg\"> " << endl
			<< " <rect width=\""<< width  << "\" height=\"" << height  << "\"" << " fill=\"red\" /> " << endl;
	}
	//Prints small rectangle in Svg file.Color is determinant.
	else if(s_color == 'g'){
		SvgFile << " <rect x=\"" << s_posX << "\"" << " y=\""<< s_posY
			<< "\"" << " width=\"" <<  s_width << "\"" << " height=\"" << s_height
			<< "\"" << " fill=\"green\" " << "/>" << endl;
	}
	
	
		
}
void Rectangle::output() const; // Writes width and height value of Rectangle on screen,if it is necessary.
char Rectangle::getbigColor() const { return color; } //Returns container rectangle color.
char Rectangle::getsmallColor() const { return s_color ;} 	//Returns small rectangle color.
double Rectangle::getHeight() const { return height; } // Returns height value of container Rectangle.
double Rectangle::getWidth() const { return width; } // Returns width value of container Rectangle.
double Rectangle::getSmallHeight() const { return s_height; } // Returns height value of small Rectangle.
double Rectangle::getSmallWidth() const { return s_width; } // Returns width value of small Rectangle.
// Return positions of container and small Rectangles.
double Rectangle::getPos_x() const { return pos_x; }
double Rectangle::getPos_y() const { return pos_y; }
double Rectangle::getSmallPos_x() const { return s_posX; }
double Rectangle::getSmallPos_y() const { return s_posY; }


