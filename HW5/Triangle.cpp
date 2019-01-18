/*
    Triangle.cpp
 *
 *  
 *      Author: Nevra Gürses
 */
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "Triangle.h"
using namespace std;
namespace ShapeOfGurses{
	Triangle::Triangle(double sideValue,char color,int degree) throw(invalid_argument)// Initializes  container Triangle.
		:Shape(color,degree),side(sideValue)
	{
		if(side<=0) //If side is not positive,throw exception.
			throw invalid_argument("Side lenght can't be negative or zero! -27");
	}
	Triangle::Triangle(double sideSmall,char color) throw(invalid_argument) // Initializes  small Triangle.
		:Shape(color),s_side(sideSmall)
	{
		if(s_side<=0) //If side is not positive,throw exception.
			throw invalid_argument("Side lenght can't be negative or zero! -28");
	}
	//Initializes small ang big triangle according to positions and degree.
	Triangle::Triangle(double sideLenght,double X1,double Y1,double X2,double Y2,double X3,double Y3,double x1,double y1,double x2,double y2,double x3,double y3,int degree) throw(invalid_argument)
		:Shape(degree),side(sideLenght),big_a1(X1),big_a2(Y1),big_b1(X2),big_b2(Y2),big_c1(X3),big_c2(Y3),pos_a1(x1),pos_a2(y1),pos_b1(x2),pos_b2(y2),pos_c1(x3),pos_c2(y3)
	{
		if(side<0 || big_a1<0 ||big_a2<0 || big_b1<0 || big_b2<0 || big_c1<0 || big_c2<0 || pos_a1<0 ||pos_a2<0 || pos_b1<0 || pos_b2<0 || pos_c1<0 || pos_c2<0 )
			throw invalid_argument("Side lenght or positions can't be negative ! -29-");

	}
	Triangle::Triangle(double sideValue,double X1,double Y1,double X2,double Y2,double X3,double Y3,int degree) throw(invalid_argument) //Initializes container triangle.
		:Shape(degree),side(sideValue),big_a1(X1),big_a2(Y1),big_b1(X2),big_b2(Y2),big_c1(X3),big_c2(Y3)
	{
		if(side<=0 || big_a1<0 ||big_a2<0 || big_b1<0 || big_b2<0 || big_c1<0 || big_c2<0 ) //If side or positions are not positive,throw exception.
			throw invalid_argument("Side lenght or positions can't be negative ! -30");  

	}
	Triangle::Triangle(double smallSide,double x1,double x2,double y1,double y2,double z1,double z2,char color) throw(invalid_argument) //Initializes small triangle.
		:Shape(color),s_side(smallSide),pos_a1(x1),pos_a2(x2),pos_b1(y1),pos_b2(y2),pos_c1(z1),pos_c2(z2)
	{
		if(s_side<=0 || pos_a1<0 ||pos_a2<0 || pos_b1<0 || pos_b2<0 || pos_c1<0 || pos_c2<0 )  //If side or positions are not positive,throw exception.
			throw invalid_argument("Side lenght or positions can't be negative ! -31");	 

	}
	Triangle::Triangle()  throw()//No parameter constructor.
		:Shape()
	{ }

	//Returns perimeter of  triangle.
	double Triangle::Perimeter() const  throw()
	{
		if(getBigColor()=='r')
			return (3*side);
		else
			return (3*s_side);
	}
	//Returns area of triangle.  
	double Triangle::Area() const  throw()
	{
		double area;
		if(getBigColor()=='r'){
			area=((side*side)*sqrt(3.0))/4.0;
			return (area);
		}
		else{
			area=((s_side*s_side)*sqrt(3.0))/4.0;
			return (area);
		}
			
	}
	
	//Overloading + and - operators to create new triangle.
	const Triangle& Triangle::operator +(const double number) const throw(invalid_argument){ 
		double new_side=side +number;
		if(new_side<=0) //If new side is not positive,throw exception.
			throw invalid_argument("Side lenght can't negative or zero! -32");
		Triangle tri(new_side,'r',0);
		Triangle& tempTri=tri;
		return tempTri;
	}
	const Triangle& Triangle::operator - (const double number) const throw(invalid_argument){
		double new_side=side - number;
		if(new_side<=0) //If new side is not positive,throw exception.
			throw invalid_argument("Side lenght can't negative or zero! -33");
		Triangle tri(new_side,'r',0);
		Triangle& tempTri=tri;
		return tempTri;
		
	}
	//Overloading unary operators to increment or decrement positions.
	const Triangle& Triangle::operator ++()  throw(){ //pre incrementing.
		Triangle tri(side,++ big_a1,++big_a2,++big_b1,++ big_b2,++big_c1,++big_c2,++ pos_a1,++pos_a2,++pos_b1,++ pos_b2,++pos_c1,++pos_c2,0);
		Triangle& tempTri=tri;
		return tempTri;
	}
	const Triangle& Triangle::operator ++(int ignore)  throw(){ //post incrementing.
		Triangle tri(side,big_a1++,big_a2++,big_b1++,big_b2++,big_c1++,big_c2++,pos_a1 ++,pos_a2 ++,pos_b1 ++,pos_b2 ++, pos_c1 ++, pos_c2 ++,0);
		Triangle& tempTri=tri;
		return tempTri;
	}
	const Triangle& Triangle::operator --() throw(){ //pre decrementing.
		Triangle tri(side,-- big_a1, --big_a2,--big_b1,-- big_b2,--big_c1,--big_c2,-- pos_a1, --pos_a2, --pos_b1, --pos_b2, --pos_c1, --pos_c2,0);
		Triangle& tempTri=tri;
		return tempTri;
	}
	const Triangle& Triangle::operator --(int ignore) throw(){ //post decrementing.
		Triangle tri(side,big_a1--,big_a2--,big_b1--,big_b2--,big_c1--,big_c2--,pos_a1 --,pos_a2 --,pos_b1 --,pos_b2 --, pos_c1 --, pos_c2 --,0);
		Triangle& tempTri=tri;
		return tempTri;
	}

	
	//Prints the screen positions of container and small triangle.
	void Triangle::outputUploaded() const  throw(){
		cout << "Position x of big:"  << endl << "1. edge: x="<< big_a1 <<", y =" <<big_a2 <<endl
		     << "2. edge: x ="<< big_b1 <<", y = " <<big_b2 <<endl << "3. edge x= : "<< big_c1 <<", y=" << big_c2 <<endl
		     << "Position x of small: "  << endl << "1. edge: x= "<< pos_a1 <<", y = " <<pos_a2 <<endl
		     << "2. edge: x="<< pos_b1 <<", y = " <<pos_b2 <<endl << "3. edge: x= "<< pos_c1 <<", y = " <<pos_c2 <<endl;
	}	
	// Determines which coordinates to rotate.This is necessary to Triangle in Circle.
	void Triangle::setRotate(double x,double y) throw(invalid_argument){
		rotateX=x;
		rotateY=y;
		if(rotateX<0 ||rotateY<0) //If positions of rotate are not positive,throw exception.
			throw invalid_argument("Positions can't be negative! -34");
			
	}
	void Triangle::set_smallTriangle(int smallSide) throw(invalid_argument){ // Sets the side lenght of small Triangle.
		s_side=smallSide;
		if(s_side<=0) //If side is not positive,throw exception.
			throw invalid_argument("Side lenght can't be negative or zero! -35");
	}
	// Determines the position of container Triangle.
	void Triangle::setBigTriangle(double a1, double a2,double b1,double b2,double c1,double c2) throw(invalid_argument){
		big_a1=a1,a2=a2;
		big_b1=b1,b2=b2;
		big_c1=c1,big_c2=c2;
		if(big_a1<0 ||big_a2<0 || big_b1<0 || big_b2<0 || big_c1<0 || big_c2<0 ) //If positions  are not positive,throw exception.
			throw invalid_argument("Positions can't be negative ! -36");
	}
	// Determines the position of small Triangle.
	void Triangle::setTriangle(double new_a1, double new_a2,double new_b1,double new_b2,double new_c1,double new_c2) throw(invalid_argument){
		pos_a1=new_a1,pos_a2=new_a2;
		pos_b1=new_b1,pos_b2=new_b2;
		pos_c1=new_c1,pos_c2=new_c2;
		if(pos_a1<0 ||pos_a2<0 || pos_b1<0 || pos_b2<0 || pos_c1<0 || pos_c2<0 ) //If positions are not positive,throw exception.
			throw invalid_argument("Positions can't be negative ! -37");
	}
	// Draws the container and small Triangle in Svg File.
	void Triangle::draw(ostream& SvgFile) const  throw(){
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

	double Triangle::getSide() const throw() { return side; } // Returns side lenght of container Triangle.
	double Triangle::getSmallSide() const  throw(){ return s_side; } // Returns side lenght of small Triangle.
	int Triangle::getDegree() const  throw(){return degree; }
	//Returns coordinates of Triangle corner of small and container triangle.
	double Triangle::getPos_a1()  const  throw() {  return pos_a1; }
	double Triangle::getPos_a2()  const  throw() {  return pos_a2; }
	double Triangle::getPos_b1()  const  throw(){  return pos_b1; }
	double Triangle::getPos_b2()  const  throw() {  return pos_b2; }
	double Triangle::getPos_c1()  const  throw(){  return pos_c1; }
	double Triangle::getPos_c2()  const  throw(){  return pos_c2; }
	double Triangle::getBig_a1()  const  throw(){  return big_a1; }
	double Triangle::getBig_a2()  const  throw(){  return big_a2; }
	double Triangle::getBig_b1()  const  throw(){  return big_b1; }
	double Triangle::getBig_b2()  const  throw(){  return big_b2; }
	double Triangle::getBig_c1()  const  throw(){  return big_c1; }
	double Triangle::getBig_c2()  const  throw(){  return big_c2; }
	//Returns rotate coordinates.
	double Triangle::getRotateX() const  throw(){ return rotateX; } 
	double Triangle::getRotateY() const  throw(){ return rotateY; } 
}
	




































