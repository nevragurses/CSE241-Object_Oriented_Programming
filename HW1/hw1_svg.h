/*
 * hw1_svg.h
 *
 *  Created on: Oct 18, 2018
 *      Author: Nevra
 */
#ifndef HW1_SVG_H_
#define HW1_SVG_H_
const double PI = 3.14; //Value of constant Pi.
//Enum class for shapes.
enum class Shape { Rectangle, Circle, Triangle };
//Improved structure type for features of a shape.
struct ShapeFeatures
{
	int width, height, radius, sideLenght;
	int s_width, s_height, s_radius, s_sideLenght;
	Shape container, s_shape;
};
//Function declerations that is used in program.
void SelectShape(ShapeFeatures& Selection);
void SelectionAns(ShapeFeatures& Selection,char ans);
void Small_rectangle(ShapeFeatures& Selection);
void Small_circle(ShapeFeatures& Selection);
void Small_triangle(ShapeFeatures& Selection);
void Rectangle_circle(ShapeFeatures& Selection);
void Rectangle_rectangle(ShapeFeatures& Selection);
double findRoot(double number);
void Rectangle_triangle(ShapeFeatures& Selection);
void Triangle_triangle(ShapeFeatures& Selection);
void Triangle_rectangle(ShapeFeatures& Selection);
void Triangle_circle(ShapeFeatures& Selection);
void Circle_triangle (ShapeFeatures& Selection);
void Circle_circle(ShapeFeatures& Selection);
void Circle_rectangle(ShapeFeatures& Selection);

#endif //ends _HW1_SVG_H_
