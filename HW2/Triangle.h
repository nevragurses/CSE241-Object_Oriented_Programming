/*
 * Triangle.h
 *
 *  Created on: Oct 24,2018
 *      Author: Nevra Gürses
 */
#ifndef TRIANGLE_H_
#define TRIANGLE_H_
#include <fstream>

using namespace std;
class Triangle
{
public:
	Triangle(int sideValue) // Initilates the side lenght of container Triangle according to entered value.
		:side(sideValue)
	{
		test();	 // Calling test function to whether value is  appopriate or not.
	}
	Triangle(){ } //No parameter constructor.

	void set_smallTriangle(int smallSide){ // Initilates the side lenght of small Triangle according to entered value.
		s_side=smallSide;
		
	}
	void setBigColor();// Assigns color red to container Triangle.
	void setSmallColor(); // Assigns color green to small Triangle.

	void setRotate(double x,double y); // Determines which coordinates to rotate.This is necessary to Triangle in Circle.
	void setBigTriangle(double a1, double a2,double b1,double b2,double c1,double c2); // // Determines position of container Triangle.
	void setTriangle(double new_a1, double new_a2,double new_b1,double new_b2,double new_c1,double new_c2); // Determines the new positions of small Triangles in container shape.


	void test(); // Tests the side lenght is negative or zero.If it is,then program is stopped.
	
	void draw(int degree,ofstream &SvgFile); // Draws the container and small Triangle in Svg File.


	void output() const; // Writes side of Triangle on screen,if it is necessary.
	int getSide() const{ return side; } // Returns side lenght of container Triangle.
	int getSmallSide() const{ return s_side; } // Returns side lenght of small Triangle.
	char getbigColor() const { return color; }
	char getsmallColor() const { return s_color; }  
 	//Returns coordinates of Triangle corner of small and container triangle.
	double getPos_a1()  const {  return pos_a1; }
	double getPos_a2()  const {  return pos_a2; }
	double getPos_b1()  const {  return pos_b1; }
	double getPos_b2()  const {  return pos_b2; }
	double getPos_c1()  const {  return pos_c1; }
	double getPos_c2()  const {  return pos_c2; }
	double getBig_a1()  const {  return big_a1; }
	double getBig_a2()  const {  return big_a2; }
	double getBig_b1()  const {  return big_b1; }
	double getBig_b2()  const {  return big_b2; }
	double getBig_c1()  const {  return big_c1; }
	double getBig_c2()  const {  return big_c2; }
	//Returns rotate coordinates.
	double getRotateX() const { return rotateX; } 
	double getRotateY() const { return rotateY; } 

	
	
private:
	int side,s_side; // Side for container and small Triangles.
	//Positions.
	double big_a1,big_a2; 
	double big_b1,big_b2;
	double big_c1,big_c2;
	double pos_a1,pos_a2; 
	double pos_b1,pos_b2;
	double pos_c1,pos_c2;
	char color,s_color; // Color to container or small Triangle.
	int degree; // The degree of rotate.
	// Rotate coordinates.
	double rotateX;
	double rotateY;
};
//Inline functions with inline keyword.
inline void Triangle::setBigColor(){
	color='r';
}
inline void Triangle::setSmallColor(){
	s_color='g';
}
#endif
