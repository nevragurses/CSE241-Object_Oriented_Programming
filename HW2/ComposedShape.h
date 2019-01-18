/*
 * ComposedShape.h
 *
 *  Created on: Oct 24,2018
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
using namespace std;
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


	//Returns an eleman of vectors that are  occured in optimalFit function.
	Rectangle getVect_inRectofRect(int eleman)  { return Rect_rect[eleman]; }
	Rectangle getVect_inTriofRect(int eleman)  { return Triangle_rect[eleman]; }
	Rectangle getVect_inCircleofRect(int eleman)  { return Circle_rect[eleman]; }
	Triangle getVect_inRectofTri(int eleman)  { return Rect_triangle[eleman]; }
	Triangle getVect_inTriaofTri(int eleman)  { return Triangle_triangle[eleman]; }
	Triangle getVect_inCircleofTri(int eleman)  { return Circle_triangle[eleman]; }
	Circle getVect_inRectofCircle(int eleman)  { return Rect_circle[eleman]; }
	Circle getVect_inTriofCicle(int eleman)  { return Triangle_circle[eleman]; }
	Circle getVect_inCircleofCircle(int eleman)  { return Circle_circle[eleman]; }
	

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



















	
