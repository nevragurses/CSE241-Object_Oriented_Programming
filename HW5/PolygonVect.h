/*
 * PolygonVect.h
 *
 *  
 *      Author: Nevra Gürses
 */
#include <iostream>
#include "Polygon.h"
#include <vector>
#include <stdexcept> //for invalid_argument exception.
namespace ShapeOfGurses{
	class PolygonVect : public Polygon
	{
	public:
		PolygonVect() throw(); //No parameter constructor.
		PolygonVect(Rectangle rectangle) throw(); //Keeps rectangle points in STL vector.
		PolygonVect(Circle circle) throw(); //Keeps circle points in STL vector.
		PolygonVect(Triangle triangle) throw();	 //Keeps triangle points in STL vector.
		PolygonVect(vector<Polygon::Point2D> polygonPoints) throw(invalid_argument); //Takes point2d vectors as parameter and records elements in own STL vector.

		void draw(ostream& SvgFile) const throw(); //draws polygons.
	

	private:
		vector<Polygon::Point2D> pointsOfPolygon; //STL vector.
	};
}
		
		
