/*
 * Triangle.h
 *
 *  
 *      Author: Nevra Gürses
 */
#ifndef TRIANGLE_H_
#define TRIANGLE_H_
/*
 * Triangle.h
 *
 *  
 *      Author: Nevra Gürses
 */

#include <fstream>
#include <stdexcept> //for invalid_argument exeption.
#include "Shape.h"
using namespace std;
namespace ShapeOfGurses{
	class Triangle : public Shape
	{
	public:
		Triangle(double sideValue,char color,int degree) throw(invalid_argument);// Initializes the container triangle.
		Triangle()  throw(); //No parameter constructor.
		Triangle(double sideValue,double X1,double Y1,double X2,double Y2,double X3,double Y3,double x1,double y1,double x2,double y2,double x3,double y3,int degree) throw(invalid_argument);
		Triangle(double sideValue,double X1,double Y1,double X2,double Y2,double X3,double Y3,int degree) throw(invalid_argument); //Initializes container triangle.
		Triangle(double smallRadius,char color) throw(invalid_argument); //Initializes small triangle.
		Triangle(double smallSide,double x1,double x2,double y1,double y2,double z1,double z2,char color) throw(invalid_argument); //Inilializes small triangle.
		



		//Overloading + and - operators to create new triangle.
		const Triangle& operator +(const double number) const throw(invalid_argument);
		const Triangle& operator -(const double number) const throw(invalid_argument);
	
		//Overloading unary operators to increment or decrement positions.
		const Triangle& operator++()  throw();
		const Triangle& operator++(int)  throw();
		const Triangle& operator--()  throw();
		const Triangle& operator --(int)  throw();

		
		double Perimeter() const  throw(); //Returns perimeter of triangle.
		double Area() const  throw();   //Returns area of  triangle.
		

		void outputUploaded() const  throw(); //Write screen positions of small and container triangles .



		//Setter funtions of triangle.
		void set_smallTriangle(int smallSide) throw(invalid_argument); 
		void setRotate(double x,double y) throw(invalid_argument); 
		void setBigTriangle(double a1, double a2,double b1,double b2,double c1,double c2) throw(invalid_argument); 
		void setTriangle(double new_a1, double new_a2,double new_b1,double new_b2,double new_c1,double new_c2) throw(invalid_argument); 

		
		void draw(ostream& SvgFile) const throw(); // Draws the container and small Triangle in Svg File.
		

		//Getter functions of triangle.
		double getSide() const  throw();
		double getSmallSide() const  throw();
		int getDegree() const  throw();
		double getPos_a1()  const  throw() ;
		double getPos_a2()  const  throw();
		double getPos_b1()  const  throw();
		double getPos_b2()  const  throw();
		double getPos_c1()  const  throw();
		double getPos_c2()  const  throw();
		double getBig_a1()  const  throw();
		double getBig_a2()  const  throw();
		double getBig_b1()  const  throw();
		double getBig_b2()  const  throw();
		double getBig_c1()  const  throw();
		double getBig_c2()  const  throw();
		double getRotateX() const  throw();
		double getRotateY() const  throw();

	protected:
		double side,s_side; // Side for container and small Triangles.
		//Positions.
		double big_a1,big_a2; 
		double big_b1,big_b2;
		double big_c1,big_c2;
		double pos_a1,pos_a2; 
		double pos_b1,pos_b2;
		double pos_c1,pos_c2;

		// Rotate coordinates.
		double rotateX;
		double rotateY;
	};
	
}

#endif
