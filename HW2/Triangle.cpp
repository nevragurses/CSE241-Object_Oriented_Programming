/*
    Triangle.cpp
 *
 *  Created on: 24,10,2018
 *      Author: Nevra Gürses
 */
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "Triangle.h"
using namespace std;

// Tests the side lenght is negative or zero.If it is,then program is stopped.
void Triangle::test(){
	if(side <=0){
		cout << "Side can not be negative number or zero." << endl;
		exit(1); //Stops the program.
	}
}
// Writes side of Triangle on screen,if it is necessary.
void Triangle::output() const{
	cout << "Side of Triangle is:" << side << endl;
}
// Determines the position of container Triangle.
void Triangle::setBigTriangle(double a1, double a2,double b1,double b2,double c1,double c2){
	big_a1=a1,a2=a2;
	big_b1=b1,b2=b2;
	big_c1=c1,big_c2=c2;
}
void Triangle::setTriangle(double new_a1, double new_a2,double new_b1,double new_b2,double new_c1,double new_c2){
	pos_a1=new_a1,pos_a2=new_a2;
	pos_b1=new_b1,pos_b2=new_b2;
	pos_c1=new_c1,pos_c2=new_c2;
}
// Determines which coordinates to rotate.This is necessary to Triangle in Circle.
void Triangle::setRotate(double x,double y){
		rotateX=x;
		rotateY=y;
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

