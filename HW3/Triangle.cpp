/*
    Triangle.cpp
 *
 *  Created on: 07,11,2018
 *      Author: Nevra Gürses
 */
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "Triangle.h"
using namespace std;
Triangle::Triangle(double sideValue) // Initilates the side lenght of container Triangle.
	:side(sideValue)
{
	test();	 // Calling test function to whether value is  appopriate or not.
	area= area + bigArea(); //adding area to calculate total area of all triangles.
	perimeter = perimeter + bigPerimeter(); //adding perimeter to calculate total perimeter of all triangles.
}
//Initilize small ang big triangle according to positions.
Triangle::Triangle(double sideLenght,double X1,double Y1,double X2,double Y2,double X3,double Y3,double x1,double y1,double x2,double y2,double x3,double y3)
	:side(sideLenght),big_a1(X1),big_a2(Y1),big_b1(X2),big_b2(Y2),big_c1(X3),big_c2(Y3),pos_a1(x1),pos_a2(y1),pos_b1(x2),pos_b2(y2),pos_c1(x3),pos_c2(y3)
{ }
void Triangle::set_smallTriangle(int smallSide){ // Initilates the side lenght of small Triangle.
	s_side=smallSide;
	area = area + smallArea(); //adding area to calculate total area of all triangles.
	perimeter= perimeter + smallPerimeter(); //adding perimeter to calculate total perimeter of all triangles.
}

//Returns perimeter of small triangle.
double Triangle::smallPerimeter() const
{
	return (3*s_side);
}
//Returns perimeter of container triangle.
double Triangle::bigPerimeter() const
{
	return(3*side);
}
//Returns area of small triangle.
double Triangle::smallArea() const
{
	double area=((s_side*s_side)*sqrt(3.0))/4.0;
	return (area);
}
//Returns area of big triangle.  
double Triangle::bigArea() const
{
	double area=((side*side)*sqrt(3.0))/4.0;
	return (area); 
}
//overloading << operator to drawing triangle in svg file.
ostream& operator <<(ostream& SvgFile,const Triangle& object){
	//Prints container Triangle in svg file that is not rotating.Color is determinant.
	if(object.color == 'r' && object.degree ==0){
		SvgFile << "<svg version=\"1.1\" baseProfile=\"full\" width=\"100%\" height=\"100%\" xmlns=\"http://www.w3.org/2000/svg\"> " 
			<< "<polygon  points=\"" << object.side/2.0 << " " << 0 << " " << 0 << " " 
			<< (object.side/2.0)*sqrt(3.0) << " "<<object.side <<" "<< (object.side/2.0)*sqrt(3.0)  << "\" fill=\"red\"/> "<< endl;
	}
	//Prints small Triangles in svg file that is not rotating.Color is determinant.
	else if(object.s_color == 'g' && object.degree == 0){
		SvgFile << "<polygon  points=\"" << object.pos_a1 << " " << object.pos_a2 << " " << object.pos_b1 << " " 
			<< object.pos_b2 << " "<< object.pos_c1 << " " << object.pos_c2  << "\" fill=\"green\"/> "<< endl; 
	}
	//If rotating necessary for small Triangle,shape according to entered degree is rotated and prints Svg file.
	else if(object.degree!=0){ 
		SvgFile <<"<polygon transform=\"rotate(" << object.degree << " " <<  object.rotateX << " "  << object.rotateY
			<< ")\" points=\"" << object.pos_a1 << " " << object.pos_a2 
			<< " " << object.pos_b1<< " "  << object.pos_b2 << " "  << object.pos_c1 << " "  << object.pos_c2 << "\" fill=\"green\"/> " << endl;
	}
}
//Overloading + and - operators to create new triangle.
const Triangle Triangle::operator +(const double number) const {
	double new_side=side +number;
	return Triangle(new_side);
}
const Triangle Triangle::operator - (const double number) const {
	double new_side=side - number;
	return Triangle(new_side);
}
//Overloading unary operators to increment or decrement positions.
const Triangle Triangle::operator ++(){
	return Triangle(side,++ big_a1,++big_a2,++big_b1,++ big_b2,++big_c1,++big_c2,++ pos_a1,++pos_a2,++pos_b1,++ pos_b2,++pos_c1,++pos_c2);
}
const Triangle Triangle::operator ++(int ignore){
	return Triangle(side,big_a1++,big_a2++,big_b1++,big_b2++,big_c1++,big_c2++,pos_a1 ++,pos_a2 ++,pos_b1 ++,pos_b2 ++, pos_c1 ++, pos_c2 ++);
}
const Triangle Triangle::operator --(){
	return Triangle(side,-- big_a1, --big_a2,--big_b1,-- big_b2,--big_c1,--big_c2,-- pos_a1, --pos_a2, --pos_b1, --pos_b2, --pos_c1, --pos_c2);
}
const Triangle Triangle::operator --(int ignore){
	return Triangle(side,big_a1--,big_a2--,big_b1--,big_b2--,big_c1--,big_c2--,pos_a1 --,pos_a2 --,pos_b1 --,pos_b2 --, pos_c1 --, pos_c2 --);
}

//Overloading operators to compare two triangle.
bool Triangle::operator == (const Triangle& second) const{
	return ( bigArea() == second.bigArea());
}
bool Triangle :: operator != (const Triangle& second) const{
	return ( bigArea() != second.bigArea());
}
bool Triangle::operator < (const Triangle& second) const{
	return ( bigArea() < second.bigArea());
}
bool Triangle :: operator > (const Triangle& second) const{
	return ( bigArea() > second.bigArea());
}
//Calculated area and perimeter of all triangles by using static member functions.
double Triangle::area=0;
double Triangle :: perimeter=0;
double Triangle :: getTotalArea(){
	return area;
}
double Triangle :: getTotalPerimeter(){
	return perimeter;
}
//Prints the screen positions of container and small triangle.
void Triangle::outputUploaded() const{
	cout << "Position x of big:"  << endl << "1. edge: x="<< big_a1 <<", y =" <<big_a2 <<endl
	     << "2. edge: x ="<< big_b1 <<", y = " <<big_b2 <<endl << "3. edge x= : "<< big_c1 <<", y=" << big_c2 <<endl
	     << "Position x of small: "  << endl << "1. edge: x= "<< pos_a1 <<", y = " <<pos_a2 <<endl
	     << "2. edge: x="<< pos_b1 <<", y = " <<pos_b2 <<endl << "3. edge: x= "<< pos_c1 <<", y = " <<pos_c2 <<endl;
}	
// Tests the side lenght is negative or zero.If it is,then program is stopped.
void Triangle::test(){
	if(side <=0){
		cout << "Side can not be negative number or zero." << endl;
		exit(1); //Stops the program.
	}
}
// Writes side of Triangle on screen.
void Triangle::output() const{
	cout << "Side of Triangle is:" << side << endl;
}
// Determines which coordinates to rotate.This is necessary to Triangle in Circle.
void Triangle::setRotate(double x,double y){
		rotateX=x;
		rotateY=y;
}
// Determines the position of container Triangle.
void Triangle::setBigTriangle(double a1, double a2,double b1,double b2,double c1,double c2){
	big_a1=a1,a2=a2;
	big_b1=b1,b2=b2;
	big_c1=c1,big_c2=c2;
}
// Determines the position of small Triangle.
void Triangle::setTriangle(double new_a1, double new_a2,double new_b1,double new_b2,double new_c1,double new_c2){
	pos_a1=new_a1,pos_a2=new_a2;
	pos_b1=new_b1,pos_b2=new_b2;
	pos_c1=new_c1,pos_c2=new_c2;
}
// Draws the container and small Triangle in Svg File.
void Triangle::draw(int degree,ofstream &SvgFile){
	//Prints container Triangle in svg file.Color is determinant.
	if(color == 'r' && degree ==0){
		SvgFile << "<svg version=\"1.1\" baseProfile=\"full\" width=\"100%\" height=\"100%\" xmlns=\"http://www.w3.org/2000/svg\"> " 
			<< "<polygon  points=\"" << side/2.0 << " " << 0 << " " << 0 << " " 
			<< (side/2.0)*sqrt(3.0) << " "<<side <<" "<< (side/2.0)*sqrt(3.0)  << "\" fill=\"red\"/> "<< endl;
	}
	//Prints small Triangles in svg file that is not rotating.Color is determinant.
	else if(s_color == 'g' && degree == 0){
		SvgFile << "<polygon  points=\"" << pos_a1 << " " << pos_a2 << " " << pos_b1 << " " 
			<< pos_b2 << " "<< pos_c1 << " " << pos_c2  << "\" fill=\"green\"/> "<< endl; 
	}
	//If rotating necessary for small Triangle,shape according to entered degree is rotated and prints Svg file.
	else if(degree!=0){ 
		SvgFile <<"<polygon transform=\"rotate(" << degree << " " <<  rotateX << " "  << rotateY
			<< ")\" points=\"" << pos_a1 << " " << pos_a2 
			<< " " << pos_b1<< " "  << pos_b2 << " "  << pos_c1 << " "  << pos_c2 << "\" fill=\"green\"/> " << endl;
	}
	
}

