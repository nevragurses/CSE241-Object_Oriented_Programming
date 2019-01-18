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
#include <cmath>
#include <vector>
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "Polygon.h"
#define PI 3.14
using  namespace PolygonOfGurses;
using namespace std;
enum Shape { rectangle,circle,triangle };
namespace ComposedOfGurses{
	class ComposedShape
	{
	public:
		//These are overloaded constructors.
		ComposedShape(Rectangle container,Rectangle small)  // Initilates container rectangle and small rectangle in it.
			:bigRect(container),smallRect(small)
		{ }
		ComposedShape(Rectangle container,Circle small)  // Initilates container rectangle and small circle in it.
			:bigRect(container),smallCircle(small)
		{ }
		ComposedShape(Rectangle container,Triangle small)  // Initilates container rectangle and small triangle in it.
			:bigRect(container),smallTriangle(small)
		{ }
		ComposedShape(Circle container,Rectangle small)  // Initilates container circle and small rectangle in it.
			:bigCircle(container),smallRect(small)
		{ }
		ComposedShape(Circle container,Circle small)  // Initilates container circle and small circle in it.
			:bigCircle(container),smallCircle(small)
		{ }
		ComposedShape(Circle container,Triangle small)  // Initilates container circle and small triangle in it.
			:bigCircle(container),smallTriangle(small)
		{ }
		ComposedShape(Triangle container,Triangle small)   // Initilates container triangle and small triangle in it.
			:bigTriangle(container),smallTriangle(small)
		{ }
		ComposedShape(Triangle container,Rectangle small)  // Initilates container triangle and small rectangle in it.
			:bigTriangle(container),smallRect(small)
		{ }
		ComposedShape(Triangle container,Circle small)  //Initilates container triangle and small circle in it.
			:bigTriangle(container),smallCircle(small)
		{ }
		ComposedShape(){ } //No parameter constructor.
		//Inner ShapeElem class
		class ShapeElem 
		{
		public:
			ShapeElem(Rectangle rect); //Inıtilizes a rectangle shape.
	
			ShapeElem(Circle circ) ; //Initilizes a circle shape.
		
			ShapeElem(Triangle tri) ; //Initilizes a triangle shape.
			ShapeElem();
			
			friend ostream& operator <<(ostream& SvgFile,Shape& Selection); //Overloading operator to drawing shapes in SvgFile;
				
		
			double area(Shape Selection,void *ptr); //Calculates area of shapes.
		
		
			double perimeter(Shape Selection,void *ptr); //Calculates perimeter of shapes.
	
		private:
			void *ptr;
			Shape select;
	
		};

		void draw(ofstream &SvgFile); //drawing inner and container shape together by using vector of Polygon class object.
	
	
		const vector < Polygon > getPolygonObject() const; //Returning vector of Polygon class object.

		
		//These are overloaded OptimalFit function to fit small shapes in container shape.
		int OptimalFit(Rectangle,Rectangle);  
		int OptimalFit(Rectangle,Circle);    
		int OptimalFit(Rectangle,Triangle);   
		int OptimalFit(Circle,Triangle);     
		int OptimalFit(Circle,Circle);     
		int OptimalFit(Circle,Rectangle);    
		int OptimalFit(Triangle,Rectangle);   
		int OptimalFit(Triangle,Circle);    
		int OptimalFit(Triangle,Triangle);  
	   


		//Returns objects of ComposedShape class.
		const Rectangle getBigRect() const;
		const Rectangle getSmallRect() const;
		const Circle getBigCircle() const;
		const Circle getSmallCircle() const;
		const Triangle getBigTriangle() const;
		const Triangle getSmallTriangle() const;
	

	private:
		vector <Polygon>  object; //Vector of polygon class object to holding shapes.
	
		Rectangle bigRect,smallRect;     // Rectangle types for small and container rectangle.
		Circle bigCircle,smallCircle;      // Circle types for small and container circle.
		Triangle bigTriangle,smallTriangle;   // Triangle types for small and container triangle.

	

	};
}
#endif



















	
