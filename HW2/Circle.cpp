/*
 * Circle.cpp
 *
 *  Created on: 24,10,2018
 *      Author: Nevra Gürses
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Circle.h"
using namespace std;
// Tests radius is negative or zero.If it is,then program is stopped.
void Circle::test(){
	if(radius<=0){
		cout << "Radius can not be negative number or zero."<< endl;
		exit(1);
	}
}
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


