/*
 * ComposedShape.h
 *
 * 
 *      Author: Nevra Gürses
 */
#ifndef COMPOSEDSHAPE_H_
#define COMPOSEDSHAPE_H_
#include <iostream>
#include <fstream>
#include <cstdlib>
/*
 * ComposedShape.h
 *
 *  
 *      Author: Nevra Gürses
 */

#include <cmath>
#include <vector>
#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#define PI 3.14
using namespace std;
namespace ShapeOfGurses{
	class ComposedShape : public Shape
	{
	public:
		//These are overloaded constructors.
		ComposedShape(Rectangle container,Rectangle small) throw();  // Initilates container rectangle and small rectangle in it.
		ComposedShape(Rectangle container,Circle small) throw();  // Initilates container rectangle and small circle in it.
		ComposedShape(Rectangle container,Triangle small) throw();  // Initilates container rectangle and small triangle in it.
		ComposedShape(Circle container,Rectangle small) throw();  // Initilates container circle and small rectangle in it.
		ComposedShape(Circle container,Circle small) throw();  // Initilates container circle and small circle in it.
		ComposedShape(Circle container,Triangle small) throw();  // Initilates container circle and small triangle in it.
		ComposedShape(Triangle container,Triangle small) throw();  // Initilates container triangle and small triangle in it.
		ComposedShape(Triangle container,Rectangle small) throw();  // Initilates container triangle and small rectangle in it.
		ComposedShape(Triangle container,Circle small) throw();  //Initilates container triangle and small circle in it.
		ComposedShape() throw(); //No parameter constructor.
		
	
		const vector < Shape* > &getShapeVect() const throw() { return shapeVect; } //Returning shape pointer vector.

		
		//These are overloaded OptimalFit function to fit small shapes in container shape.
		void OptimalFit(Rectangle,Rectangle) throw();  
		void OptimalFit(Rectangle,Circle) throw();    
		void OptimalFit(Rectangle,Triangle) throw();   
		void OptimalFit(Circle,Triangle) throw();     
		void OptimalFit(Circle,Circle) throw();     
		void OptimalFit(Circle,Rectangle) throw();    
		void OptimalFit(Triangle,Rectangle) throw();   
		void OptimalFit(Triangle,Circle) throw();    
		void OptimalFit(Triangle,Triangle) throw(); 
 
	   	void draw(ostream& SvgFile) const throw(); //Draws container and inner shapes.


		
		double Area() const throw();  //Area of inner and container shapes.
		double Perimeter() const throw(); //Perimeter of inner and container shapes.

		//These overloaded operators came shape class,they are not using in this class.
		const ComposedShape& operator++() throw();
		const ComposedShape& operator++(int) throw();
		const ComposedShape& operator--() throw();
		const ComposedShape& operator --(int) throw();
		const ComposedShape& operator +(const double number) const throw();
		const ComposedShape& operator -(const double number) const throw();
	

		//Returns objects of ComposedShape class.
		const Rectangle getBigRect() const throw();
		const Rectangle getSmallRect() const throw();
		const Circle getBigCircle() const throw();
		const Circle getSmallCircle() const throw();
		const Triangle getBigTriangle() const throw();
		const Triangle getSmallTriangle() const throw();
		

	private:
		vector <Shape*>  shapeVect; //Vector of polygon class object to holding shapes.

		Rectangle bigRect,smallRect;     // Rectangle types for small and container rectangle.
		Circle bigCircle,smallCircle;      // Circle types for small and container circle.
		Triangle bigTriangle,smallTriangle;   // Triangle types for small and container triangle.
	
	};
}
#endif



















	
