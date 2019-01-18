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
namespace ShapeOfGurses{
	Rectangle::Rectangle() throw() //No parameter constructor.
		:Shape()
	{  }
	Rectangle::Rectangle(int widthValue,int heightValue,double x,double y,char bigColor,int degree) throw (invalid_argument) // Initializes container Rectangle.
		:Shape(bigColor,degree),width(widthValue),height(heightValue),pos_x(x),pos_y(y)
	{
		if(width <=0 || height <=0) //If  height or width are not positive number,throw an exception.
			throw invalid_argument("Height or width can't be negative and zero!-1");
	}
	
	Rectangle::Rectangle(double widthValue,double heightValue,int degree) throw(invalid_argument)// Initializes container Rectangle.
		:Shape(degree),width(widthValue),height(heightValue)
	{
		if(width <=0 || height <=0) //If  height or width are not positive number,throw an exception.
			throw invalid_argument("Height or width can't be negative and zero!-2"); 
	}
	Rectangle::Rectangle(double bigX,double bigY,double smallX,double smallY,int degree) throw (invalid_argument)//Initializes positions of small and container rectangle.
		:Shape(degree),pos_x(bigX),pos_y(bigY),s_posX(smallX),s_posY(smallY)
	{ 
		if(pos_x <0 || pos_y < 0 || s_posX < 0 || s_posY < 0 ) //If  height or width or positions are not positive number,throw an exception.
			throw invalid_argument("Positions can't be negative !-3");

	}
	Rectangle::Rectangle (double widthValue,double heightValue,char color) throw (invalid_argument)// Initializes small Rectangle.
		:Shape(color),s_width(widthValue),s_height(heightValue)
	{

		if(s_width <=0 || s_height <= 0) //If  height or width are not positive number,throw an exception.
			throw invalid_argument("Height or width can't be negative and zero!-4");
	}
	Rectangle::Rectangle (int smallHeight,int smallWidth,double posX,double posY,char color) throw(invalid_argument) //Initializes small rectangle with positions.
		:Shape(color),s_posX(posX),s_posY(posY),s_height(smallHeight),s_width(smallWidth)
	{ 
		if(s_posX <0 || s_posY < 0 || s_height <= 0 || s_width <= 0 )  //If  height or width or positions are not positive number,throw an exception.
			throw invalid_argument("Positions or height or width can't be negative!-5");
	}
	//Overloaded binary + and - operators for  creating new object.
	const Rectangle& Rectangle :: operator +(const double number) const throw(invalid_argument){
		double new_height=height + number;
		double new_width=width +number;
		if(new_height<=0 || new_width<=0){ //If new height or width are not positive number,throw an exception.
			throw invalid_argument("Height or width can't be negative and zero!-6");
		}
		Rectangle rect(new_width,new_height,0);
		Rectangle& tempRect=rect;
		return tempRect;
	}
	const Rectangle& Rectangle :: operator -(const double number) const throw(invalid_argument){
		double new_height=height - number;
		double new_width=width  - number;
		if(new_height<=0 || new_width<=0){ //If new height or width are not positive number,throw an exception.
			throw invalid_argument("Height or width can't be negative and zero!-7");
		}
		Rectangle rect(new_width,new_height,0);
		Rectangle& tempRect=rect;
		return tempRect;
	}
	//Overloaded binary operators to incrementing and decrementing positions.
	const Rectangle& Rectangle::operator ++() throw(){ //pre incrementing.
		pos_x ++;
		pos_y ++;
		s_posX ++;
		s_posY ++;

		Rectangle rect(pos_x,pos_y,s_posX,s_posY,0);
		Rectangle& tempRect=rect;
		return tempRect;

	}
	const Rectangle& Rectangle::operator ++(int ignore) throw(){ //post incrementing.
		Rectangle rect(pos_x ,pos_y  ,s_posX  ,s_posY ,0);
		pos_x ++;
		pos_y ++;
		s_posX ++;
		s_posY ++;
		
		Rectangle& tempRect=rect;
		return tempRect;
	}
	const Rectangle& Rectangle::operator --()  throw(invalid_argument){ //pre decrementing.
		pos_x --;
		pos_y --;
		s_posX --;
		s_posY --;
		if(pos_x <0 || pos_y < 0 || s_posX < 0 || s_posY < 0 )  { //If new positions are not positive,throw an exception.
			throw invalid_argument("Positions can't be negative!-8");
		}
		Rectangle rect(pos_x,pos_y,s_posX,s_posY,0);
		Rectangle& tempRect=rect;
		return tempRect;
	}
	const Rectangle& Rectangle::operator --(int ignore)  throw(invalid_argument){ //post decrementing.
		Rectangle rect(pos_x ,pos_y  ,s_posX  ,s_posY ,0);
		pos_x --;
		pos_y --;
		s_posX --;
		s_posY --;
		if(pos_x <0 || pos_y < 0 || s_posX < 0 || s_posY < 0 ){  //If new positions are not positive,throw an exception.
			throw invalid_argument("Positions can't be negative!-9");
		}
		Rectangle& tempRect=rect;
		return tempRect;
	}
	void Rectangle::output() const throw(){ //Prints features of rectangle.
		cout << "Height of New Rectange is:" << height << endl
	    	     <<"Width of New Rectangle is:"  << width << endl;
	}	
	
	//Prints on  screen positions of container and small rectangle.
	void Rectangle::outputUploaded() const throw(){
		cout << "Position x of big:" << pos_x << endl << "Position y of big:" << pos_y << endl
		     << "Position x of small:" << s_posX << endl << "Position y of small:" << s_posY << endl;
	}

	// Determines the new positions of small Rectangles in container shape.
	void Rectangle::setRectangle(double widthValue,double heightValue,double uploaded_x,double uploaded_y ) throw(invalid_argument){
		s_width=widthValue;
		s_height=heightValue;
		s_posX=uploaded_x;
		s_posY=uploaded_y;

		if(s_width <=0 || s_height <= 0 || s_posX < 0 || s_posY < 0 )  { //If positions or height or width is not positive,throw an exception.
			throw invalid_argument("Positions or height or width can't be negative !-10");
		}
	}
	// Sets the widht and height value of small Rectangle.
	void Rectangle :: setSmall(double sWidth,double sHeight) throw(invalid_argument){  
		s_width=sWidth;
		s_height=sHeight;
		if(s_width <=0 || s_height <=0) //If  height or width is not positive,throw an exception.
			throw invalid_argument("Height or width can't be negative and zero!-11");
	}
	// Determines the new positions of small Rectangles in container shape if small rectangles be placed vertically in container shape.
	void Rectangle::setRectangle2(double widthValue,double heightValue,double uploaded_x,double uploaded_y ) throw(invalid_argument){
		s_posX=uploaded_x;
		s_posY=uploaded_y;
		s_width=heightValue;
		s_height=widthValue;

		if(s_width <=0 || s_height <= 0 || s_posX < 0 || s_posY < 0 )  { //If positions or height or width is not positive,throw an exception.
			throw invalid_argument("Positions or height or width can't be negative !-12");
		}
	}
	// Uploades the widht and height value of small Rectangle.
	void Rectangle::setNewSmall(double value1,double value2) throw(invalid_argument){
		s_width=value1;
		s_height=value2;
		if(s_width <=0 || s_height <=0) //If  height or width is not positive,throw an exception.
			throw invalid_argument("Height or width can't be negative and zero !-13");
	}
	//Perimeter of a rectangle.
	double Rectangle::Perimeter() const throw(){
		if(getBigColor()=='r')
			return ((2*width)+(2*height));
		else
			return ((2*s_width)+(2*s_height));
	}

	// Area of a rectangle.
	double Rectangle::Area() const throw(){
		if(getBigColor()=='r')
		 	return (width*height);
		else
			return (s_width*s_height);


	}

	// Draw the container and small Rectangle in Svg File.
	void Rectangle::draw(ostream &SvgFile) const throw(){
		//Prints container rectangle in Svg file.Color is determinant.
		if( color == 'r'){
			SvgFile << "<svg version=\"1.1\" baseProfile=\"full\" width=\"100%\" height=\"100%\" xmlns=\"http://www.w3.org/2000/svg\"> " << endl
				<< " <rect width=\""<< width  << "\" height=\"" << height  << "\"" << " fill=\"red\" /> " << endl;
		}
		//Prints small rectangle in Svg file.Color is determinant.
		else if(s_color == 'g'){
			SvgFile << " <rect x=\"" << s_posX << "\"" << " y=\""<< s_posY
				<< "\"" << " width=\"" <<  s_width << "\"" << " height=\"" << s_height
				<< "\"" << " fill=\"green\"  stroke=\"black\"" << "/>" << endl;
		}



	}
	double Rectangle::getHeight() const throw()  { return height; } // Returns height value of container Rectangle.
	double Rectangle::getWidth() const throw()  { return width; } // Returns width value of container Rectangle.
	double Rectangle::getSmallHeight() const throw() { return s_height; }  // Returns height value of small Rectangle.
	double Rectangle::getSmallWidth() const throw() { return s_width; } // Returns width value of small Rectangle.
	// Return positions of container and small Rectangles.
	double Rectangle::getPos_x() const throw() { return pos_x; } 
	double Rectangle::getPos_y() const throw() { return pos_y; } 
	double Rectangle::getSmallPos_x() const throw() { return s_posX; } 
	double Rectangle::getSmallPos_y() const throw() { return s_posY; } 
}
