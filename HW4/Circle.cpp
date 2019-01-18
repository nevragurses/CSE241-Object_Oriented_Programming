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
Circle::Circle(double radiusValue) // Initilates the radius of container Circle.
	:radius(radiusValue)
{
	sumArea=sumArea + areaBig(); //adding area to calculate total area of all circles.
	sumPerimeter= sumPerimeter + perimeterBig(); //adding perimeter lenght to calculate total area of all circles.
	test(); // Calling test function to whether value is appopriate or not.
}	
Circle::Circle(double radiusValue,double x,double y,int degree) //Initilizes small  circles according to positions and rotation degree.
	:s_radius(radiusValue),pos_x(x),pos_y(y),degree(degree)
{ 
	sumArea=sumArea + areaSmall(); //adding area to calculate total area of all circles.
	sumPerimeter= sumPerimeter + perimeterSmall();  //adding perimeter lenght to calculate total area of all circles.
}

//Initilizes positions of circle.
Circle::Circle(double bigX,double bigY,double smallX,double smallY)
	:bigpos_x(bigX),bigpos_y(bigY),pos_x(smallX),pos_y(smallY)
{ 
	sumArea=sumArea + areaBig();  //adding area to calculate total area of all circles.
	sumPerimeter= sumPerimeter + perimeterBig();//adding perimeter lenght to calculate total area of all circles.
}

void Circle::set_smallRadius(double value){ // Initilates the radius of small Circle according to entered value.
	s_radius=value;
	sumArea=sumArea + areaSmall();//adding area to calculate total area of all circles.
	sumPerimeter= sumPerimeter + perimeterSmall(); //adding perimeter lenght to calculate total area of all circles.
}

//overloading << operator to drawing circles in svg file.
ostream& operator << (ostream& SvgFile,const Circle& object){
	if(object.color == 'r' && object.degree ==0){ //Draws container circle.
		SvgFile << "<svg version=\"1.1\" baseProfile=\"full\" width=\"100%\" height=\"100%\" xmlns=\"http://www.w3.org/2000/svg\"> " 
			<< " <circle cx=\"" <<  object.radius<< "\"" << " cy=\"" << object.radius
			<< "\"" <<" r=\"" << object.radius << "\" "<< "fill=\"red\" /> " << endl;
	}
	else if(object.s_color == 'g' && object.degree==0){ //Draws small circle.
		SvgFile << " <circle cx=\"" <<  object.pos_x<< "\"" << " cy=\"" << object.pos_y
			<< "\"" <<" r=\"" << object.s_radius << "\" "<< "fill=\"green\" /> " << endl;
	}
	else if(object.degree !=0){ //Draws container and rotating circle.
		SvgFile << " <circle cx=\"" <<  object.pos_x << "\"" << " cy=\"" << object.pos_y
			<< "\"" <<" r=\"" << object.s_radius << "\" "<< "fill=\"green\" " 
			<<"transform=\"rotate(" << object.degree <<","<< object.coordX << ","  << object.coordY << ")\"/> " << endl;
	} 
	return SvgFile;
}
//Overloading + and - operators to create new circle.
const Circle Circle:: operator + (const double number) const{
	double new_radius= radius + number;
	return Circle(new_radius);
}
const Circle Circle:: operator - (const double number) const {
	double new_radius= radius - number;
	return Circle(new_radius);
}
//Overloading unary operators to increment or decrement positions.
const Circle Circle::operator ++(){
	bigpos_x ++;
	bigpos_y ++;
	pos_x ++;
	pos_y ++;
	return Circle(bigpos_x,bigpos_y,pos_x,pos_y);
}
const Circle Circle::operator ++(int ignore){
	return Circle(bigpos_x ++,bigpos_y ++ ,pos_x ++ ,pos_y ++);
}
const Circle Circle::operator --(){
	bigpos_x --;
	bigpos_y --;
	pos_x --;
	pos_y--;
	return Circle(bigpos_x,bigpos_y,pos_x,pos_y);
}
const Circle Circle::operator --(int ignore){
	return Circle(bigpos_x --,bigpos_y --,pos_x --,pos_y --);
}
//Overloading operators to compare two circle.
bool Circle::operator == (const Circle& second) const{
	return ( areaBig() == second.areaBig());
}
bool Circle :: operator != (const Circle& second) const{
	return ( areaBig() != second.areaBig());
}
bool Circle :: operator < (const Circle& second) const{
	return ( areaBig() < second.areaBig());
}
bool Circle::operator > (const Circle& second) const{
	return ( areaBig() > second.areaBig());
}
//Calculated area and perimeter of all triangles by using static member functions.
double Circle :: sumArea =0;
double Circle :: sumPerimeter =0;
double Circle :: totalArea()
{
	return sumArea;
}
double Circle::totalPerimeter()
{
	return sumPerimeter;
}
//Prints the screen positions of container and small circle.	
void Circle::outputUploaded() const{
	cout << "Position x of big:" << bigpos_x << endl << "Position y of big:" << bigpos_y << endl
	     << "Position x of small:" << pos_x << endl << "Position y of small:" << pos_y << endl;
} 
// Tests radius is negative or zero.If it is,then program is stopped.
void Circle::test(){
	if(radius<=0){
		cout << "Radius can not be negative number or zero."<< endl;
		exit(1);
	}
}
//Returns perimeter of small circle.
double Circle::perimeterSmall() const{ return (2*PI*s_radius); }

//Returns perimeter of big circle.
double Circle::perimeterBig() const{ return (2*PI*radius); }

//Returns area of small circle.
double Circle::areaSmall() const{ return (PI*s_radius*s_radius); }

//Returns area of big circle.
double Circle::areaBig() const{ return (PI*radius*radius); }	
// Writes radius of Circle on screen,if it is necessary.
void Circle::output() const{ 
	cout << "Radius of Circle is:" << radius << endl; 
}
// Determines the positions of container Circle.
void Circle::setBigCircle(double x,double y){
	bigpos_x=x;
	bigpos_y=y;
}
// Determines the new positions of small Circles in container shape.
void Circle::setCircle(double uploaded_x,double uploaded_y){
	pos_x=uploaded_x;
	pos_y=uploaded_y;
}
// Determines which coordinates to rotate.
void Circle::setRotate(double x,double y){
		coordX=x;
		coordY=y;
}
//initilizing small and big color.
void Circle::setBigColor(){
	color='r';
}
void Circle::setSmallColor(){
	s_color='g';
}
void Circle::setDegree(int valueDegree){ //Determining rotating degree.
		degree=valueDegree;

}
// Draws the container and small Circles in Svg File.
void Circle::draw(int degree,ofstream &SvgFile){
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
char Circle::getbigColor() const { return color; } // Return container circle color.
char Circle::getsmallColor() const {return s_color; } // Return circle color.
double Circle::getRadius() const{ return radius; } // Returns radius of container Circle.
double Circle::getSmallRadius() const{ return s_radius; } // Return radius of small Circle.
int Circle::getDegree() const { return degree; }

// Returns positions of small and container Circles.
double Circle::getPos_x() const{ return bigpos_x; }
double Circle::getPos_y() const{ return bigpos_y; }
double Circle::getSmallPosx() const{ return pos_x; }
double Circle::getSmallPosy() const{ return pos_y; }
double Circle::getRotateX() const { return coordX; }
double Circle::getRotateY() const { return coordY; }


