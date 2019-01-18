/*
 * PolygonDyn.h
 *
 *  
 *      Author: Nevra Gürses
 */
#ifndef POLYGONDYN_H_
#define POLYGONDYN_H_
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "Polygon.h"
#include "Shape.h"
#include <stdexcept> //for invalid_argument exception.
namespace ShapeOfGurses
{
	class PolygonDyn : public Polygon
	{
	public:
		PolygonDyn() throw(); //no parameter constructor.
		PolygonDyn(vector<Polygon::Point2D> (polygonPoints)) throw(invalid_argument);  //Takes point2d vectors as parameter and records elements in own  dynamic memory.
		PolygonDyn(Rectangle rectangle) throw();  //Keeps rectangle points in dynamic memory.
		PolygonDyn(Circle circle) throw();  //Keeps circle points in dynamic memory.
		PolygonDyn(Triangle triangle) throw();	  //Keeps triangle points in dynamic memory.

		
		void draw(ostream& SvgFile) const throw(); //draws polygons.
	

		PolygonDyn& operator=(const PolygonDyn& second) throw(invalid_argument); //Overloaded assignment operator.
		~PolygonDyn() throw(); //Destructor.
		PolygonDyn(const PolygonDyn& object) throw(invalid_argument); //Copy constructor.
	private:
		Polygon::Point2D* pointsOfPolygon;
	};
	
}






#endif
