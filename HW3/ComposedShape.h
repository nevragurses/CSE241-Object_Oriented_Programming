/*
 * ComposedShape.h
 *
 *  Created on: 07,11,2018
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
#define PI 3.14
using namespace std;
enum Shape { rectangle,circle,triangle };
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
		ShapeElem(Rectangle rect) { //Inıtilizes a rectangle shape.
			ptr=&rect;
			Rectangle *pntr1 = (Rectangle*)(ptr); //Created an rectangle pointer by the pointing adress of void pointer.
			select=rectangle; //defines the type of shape as rectangle.
		}
		ShapeElem(Circle circ) { //Initilizes a circle shape.
			ptr=&circ;
			Circle *pntr2 = (Circle*)(ptr); //Created an circle pointer by the pointing adress of void pointer.
			select=circle;  //defines the type of shape as circle.
		}
		ShapeElem(Triangle tri) { //Initilizes a triangle shape.
			ptr=&tri;
			Triangle *pntr3=(Triangle*)(ptr); //Created an triangle pointer by the pointing adress of void pointer.
			select=triangle;  //defines the type of shape as triangle.
		}

		friend ostream& operator <<(ostream& SvgFile,Shape& Selection); //Overloading operator to drawing shapes in SvgFile;
				
		//Calculates area of shapes.
		double area(Shape Selection,void *ptr){
			if(Selection==rectangle){
				Rectangle *pntr1 = (Rectangle*)(ptr); //adress of rectangle is assigning a pointer rectangle by void pointer.
				return (pntr1->bigArea());
			}
			else if(Selection==triangle){
				Triangle *pntr2 = (Triangle*)(ptr); //adress of triangle is assigning a pointer triangle by void pointer.
				return (pntr2->bigArea());
			}
			else if(Selection==circle){
				Circle *pntr3 = (Circle*)(ptr); //adress of circle is assigning a pointer circle by void pointer.
				return (pntr3->areaBig());
			}
		}
		//Calculates perimeter of shapes.
		double perimeter(Shape Selection,void *ptr){
			if(Selection==rectangle){
				Rectangle *pntr1 = (Rectangle*)(ptr); //adress of rectangle is assigning a pointer rectangle by void .
				return (pntr1->bigPerimeter());
			}
			else if(Selection==triangle){
				Triangle *pntr2 = (Triangle*)(ptr);  //adress of triangle is assigning a pointer triangle by void pointer.
				return (pntr2->bigPerimeter());
			}
			else if(Selection==circle){
				Circle *pntr3 = (Circle*)(ptr);  //adress of circle is assigning a pointer circle by void pointer.
				return (pntr3->perimeterBig());
			}
		}
	private:
		void *ptr;
		Shape select;
	
	};
		

	//These are overloaded draw function.
	void draw(ofstream &SvgFile,Rectangle,Rectangle);   // Draws rectangles in rectangle.
	void draw(ofstream &SvgFile,Rectangle,Circle);      // Draws circles in rectangle.
	void draw(ofstream &SvgFil,Rectangle,Triangle);    // Draws triangles in rectangle.
	void draw(ofstream &SvgFile,Triangle,Rectangle);   // Draws rectangles in triangle.
	void draw(ofstream &SvgFile,Triangle,Circle);     // Draws circles in triangle.
	void draw(ofstream &SvgFile,Triangle,Triangle);   // Draws triangles in triangle.
	void draw(ofstream &SvgFile,Circle,Circle);      // Draws circles in circle.
	void draw(ofstream &SvgFile,Circle,Rectangle);   // Draws rectangles in circle.
	void draw(ofstream &SvgFile,Circle,Triangle);   // Draws triangles in circle.
	
	//These are overloaded OptimalFit function.
	int OptimalFit(Rectangle,Rectangle);   // Fits small Rectangles in Container Rectangle.
	int OptimalFit(Rectangle,Circle);    // Fits small Circles in Container Rectangle.
	int OptimalFit(Rectangle,Triangle);   // Fits small Triangles in Container Rectangle.
	int OptimalFit(Circle,Triangle);     // Fits small Triangles in Container Circle.
	int OptimalFit(Circle,Circle);     // Fits small Circles in Container Circle.
	int OptimalFit(Circle,Rectangle);    // Fits small Rectangles in Container Circle.
	int OptimalFit(Triangle,Rectangle);   // Fits small Rectangles in Container Triangle.
	int OptimalFit(Triangle,Circle);    // Fits small Circles in Container Triangle.
	int OptimalFit(Triangle,Triangle);   // Fits small Triangles in Container Rectangle.
   


	//Returns vectors that are  occured in optimalFit function.
	 const vector < Rectangle > getRectRect() const { return Rect_rect; }
	 const vector < Rectangle > getTRiRect() const { return Triangle_rect; }
	 const vector < Rectangle > getCircleRect() const { return Circle_rect; }
	 const vector < Triangle > getRectTri() const { return Rect_triangle; }
	 const vector < Triangle > getTriTri() const { return Triangle_triangle; }
	 const vector < Triangle > getCircleTri() const { return  Circle_triangle; }
	 const vector < Circle > getRectCirc()const { return  Rect_circle; }
	 const vector < Circle > getTriCirc() const { return Triangle_circle; }
	 const vector < Circle > getCircCirc() const { return Circle_circle; }
	 


	//Returns objects of ComposedShape class.
	const Rectangle getBigRect() const { return bigRect; }
	const Rectangle getSmallRect() const { return smallRect; }
	const Circle getBigCircle() const { return bigCircle; }
	const Circle getSmallCircle() const { return smallCircle; }
	const Triangle getBigTriangle() const { return bigTriangle; }
	const Triangle getSmallTriangle() const { return smallTriangle; }
	

private:
	Rectangle bigRect,smallRect;     // Rectangle types for small and container rectangle.
	Circle bigCircle,smallCircle;      // Circle types for small and container circle.
	Triangle bigTriangle,smallTriangle;   // Triangle types for small and container triangle.

	vector<Rectangle> Rect_rect;   // Vector that is Rectangle type to keep small rectangles in container rectangle.
	vector<Circle>Rect_circle;     // Vector that is Circle type to keep small circles in container rectangle.
	vector<Triangle>Rect_triangle;  // Vector that is Triangle type to keep small triangles in container rectangle.
	vector<Rectangle>Triangle_rect;   // Vector that is Rectangle type to keep small rectangles in container triangle.
	vector<Triangle>Triangle_triangle;  // Vector that is Triangle type to keep small triangles in container triangle.
	vector<Circle>Triangle_circle;   // Vector that is Circle type to keep small circles in container triangle.
	vector<Circle>Circle_circle;   // Vector that is Circle type to keep small circles in container circle.
	vector<Triangle>Circle_triangle;   // Vector that is Triangle type to keep small triangles in container circle.
	vector<Rectangle>Circle_rect;   // Vector that is Rectangle type to keep small rectangles in container circles.

};
#endif



















	
