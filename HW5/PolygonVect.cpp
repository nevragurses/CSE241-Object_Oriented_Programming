/*
 * PolygonVect.cpp
 *
 *
 *      Author: Nevra Gürses
 */

#include "Polygon.h"
#include "PolygonVect.h"
#include <cmath>
using namespace std;
//Unnamed namespace
namespace{
	 // returns x coordinate  of one point of  circle.
	double findPosX(double radius,double degree) {   
		double x=radius*cos(degree*PI/180);
		return (x+radius);
	}
	 // returns y coordinate  of one point of  circle.
	double findPosY(double radius,double degree){
		double y=radius*sin(degree*PI/180);
		return (y+radius);
	}
}
namespace ShapeOfGurses{

	PolygonVect::PolygonVect(Rectangle rectangle) throw()//Conversion constuctor from rectangle.
	{
		size=4;
		if(rectangle.getBigColor()=='r'){  //If container rectangle.
			colorPoly='r'; //initializing container color.

			//Assigning rectangle points in STL vector.
			pointsOfPolygon.push_back(Polygon::Point2D(rectangle.getPos_x(),rectangle.getPos_y()));
			pointsOfPolygon.push_back(Polygon::Point2D(rectangle.getPos_x(),rectangle.getPos_y()+rectangle.getHeight()));
			pointsOfPolygon.push_back(Polygon::Point2D(rectangle.getPos_x()+rectangle.getWidth(),rectangle.getPos_y()+rectangle.getHeight()));
			pointsOfPolygon.push_back(Polygon::Point2D(rectangle.getPos_x()+rectangle.getWidth(),rectangle.getPos_y()));
			
		}
		if(rectangle.getSmallColor()=='g'){ //If inner rectangle.
			colorPoly='g'; //initializing small color.

			//Assigning rectangle points in STL vector.
			pointsOfPolygon.push_back(Polygon::Point2D(rectangle.getSmallPos_x(),rectangle.getSmallPos_y()));
			pointsOfPolygon.push_back(Polygon::Point2D(rectangle.getSmallPos_x(),rectangle.getSmallPos_y()+rectangle.getSmallHeight()));
			pointsOfPolygon.push_back(Polygon::Point2D(rectangle.getSmallPos_x()+rectangle.getSmallWidth(),rectangle.getSmallPos_y()+rectangle.getSmallHeight()));
			pointsOfPolygon.push_back(Polygon::Point2D(rectangle.getSmallPos_x()+rectangle.getSmallWidth(),rectangle.getSmallPos_y()));
			
		}
	}
	PolygonVect::PolygonVect(Circle circle) throw()//Conversion constuctor from circle.
	{
		size=100;
		if(circle.getBigColor()=='r' && circle.getDegree()==0 ){ //If container circle.
			double radius=circle.getRadius();
			colorPoly='r'; //initializing container color.
			degree=0; //initializing container degree.
			int i=0;
			double j=0; 

			//Assigning circle points in STL vector.
			while(j <=360){
				 //finding coordinates of 100 points of container circle and assigning dynamic array.
				pointsOfPolygon.push_back(Polygon::Point2D((findPosX(radius,j)),(findPosY(radius,j))));
				++i;
				j=j+3.60;
			}
		}
		else if(circle.getSmallColor()=='g' && circle.getDegree()==0 ){  //If inner circle and does not rotating.
			colorPoly='g'; //initializing inner color.
			degree=0; //initiliazing inner degree.
			double j=0;
			int i=0;

			//Assigning circle points in STL vector.
			while(j<=360){
				//finding coordinates of 100 points of small circle and assigning dynamic array.
				pointsOfPolygon.push_back(Polygon::Point2D(circle.getSmallPosx()+(findPosX(circle.getSmallRadius(),j)),(circle.getSmallPosy()+findPosY(circle.getSmallRadius(),j))));
				++i;
				j=j+3.60;
			}
		}
		else if(circle.getSmallColor()=='g' && circle.getDegree()!=0 ){ //If inner circle and rotating.
			colorPoly='g';
			rotateX=circle.getRotateX(); //initializing rotating x coorcinate.
			rotateY=circle.getRotateY(); //initializing rotating y coordinate.
			degree=circle.getDegree(); //initializing rotating degree.
			double j=0;
			int i=0;

			//Assigning circle points in STL vector.
			while(j<=360){
				//finding coordinates of 100 points of small rotating circle and assigning dynamic array.
				pointsOfPolygon.push_back(Polygon::Point2D((circle.getSmallPosx()+findPosX(circle.getSmallRadius(),j)),(circle.getSmallPosy()+findPosY(circle.getSmallRadius(),j))));
				++i;
				j=j+3.60;
			}
		}
	}
			
	PolygonVect::PolygonVect(Triangle triangle) throw()//Conversion from triangle.
	{
		size=3;
		if(triangle.getBigColor()=='r' && triangle.getDegree()==0 ){ //If container triangle.
			colorPoly='r'; //initializing container color.
			degree=0;//initializing container degree.

			//Assigning triangle points in STL vector.
			pointsOfPolygon.push_back(Polygon::Point2D(triangle.getBig_a1(),triangle.getBig_a2()));
			pointsOfPolygon.push_back(Polygon::Point2D(triangle.getBig_b1(),triangle.getBig_b2()));
			pointsOfPolygon.push_back(Polygon::Point2D(triangle.getBig_c1(),triangle.getBig_c2()));
		}
		if(triangle.getSmallColor()=='g' && triangle.getDegree()==0){ //If small triangle.
			colorPoly='g'; //initializing small color.
			degree=0; //initializing small degree.

			//Assigning triangle points in STL vector.
			pointsOfPolygon.push_back(Polygon::Point2D(triangle.getPos_a1(),triangle.getPos_a2()));
			pointsOfPolygon.push_back(Polygon::Point2D(triangle.getPos_b1(),triangle.getPos_b2()));
			pointsOfPolygon.push_back(Polygon::Point2D(triangle.getPos_c1(),triangle.getPos_c2()));
			
		
			
		}
		if(triangle.getSmallColor()=='g' && triangle.getDegree()!=0){ //If small rotating triangle.
			rotateX=triangle.getRotateX(); //initializing rotating x coordinate.
			rotateY=triangle.getRotateY(); //initializing rotating y coordinate.
			colorPoly='g'; 
			degree=triangle.getDegree(); //initializing rotate degree.

			//Assigning triangle points in STL vector.
			pointsOfPolygon.push_back(Polygon::Point2D(triangle.getPos_a1(),triangle.getPos_a2()));
			pointsOfPolygon.push_back(Polygon::Point2D(triangle.getPos_b1(),triangle.getPos_b2()));
			pointsOfPolygon.push_back(Polygon::Point2D(triangle.getPos_c1(),triangle.getPos_c2()));
			
			
		}
	}
	PolygonVect::PolygonVect(vector<Polygon::Point2D> polygonPoints)throw(invalid_argument){ // constructor that takes an STL vector of Point2D objects to represent the Polygon points.
		size=polygonPoints.size();
		if(size<=0) //If size is not positive,throw an exception.
			throw invalid_argument("Vector size can't be negative!-46");

		for(int i=0;i<size;++i){  
			pointsOfPolygon.push_back(polygonPoints[i]); //assignment vector members in own vector.
		}
		
	}
	PolygonVect::PolygonVect() throw() //No parameter constructor.
		:Polygon()
	{ }
	//Drawing polygon.
	void PolygonVect::draw(ostream& SvgFile) const throw(){
		
		if(colorPoly=='r' || colorPoly !='g'){ //drawing container shape.
			SvgFile << "<svg version=\"1.1\" baseProfile=\"full\" width=\"100%\" height=\"100%\" xmlns=\"http://www.w3.org/2000/svg\"> "
				<< "<polygon  points=\"";
			int i=0;
			//This loop provides printing coordinates of all vector elements in svg.
			while(i < size){
				SvgFile  << pointsOfPolygon[i].get_x() << " " << pointsOfPolygon[i].get_y() << endl;			
				++i;
			}
			SvgFile<< "\" fill=\"red\"/> "<< endl;
			
		}
		else if(colorPoly=='g'){ //drawing small shape .
			if(degree!=0 && size !=4){ //drawing small shape that is rotating.
				SvgFile <<"<polygon transform=\"rotate(" << degree << " " << rotateX << " "  << rotateY
				<< ")\" points=\"";
				int i=0;
				//This loop provides printing coordinates of all vector elements in svg.
				while(i< size){ 
					SvgFile  << pointsOfPolygon[i].get_x() << " " << pointsOfPolygon[i].get_y() << " "  ;			
					++i;
				}
				SvgFile<< "\" fill=\"green\"/> "<< endl;
					
		
			}
			else{ //drawing small shape that is not rotating.
				SvgFile<< "<polygon  points=\"";
				int i=0;
				//This loop provides printing coordinates of all vector elements in svg.
				while(i<size){
					SvgFile  << pointsOfPolygon[i].get_x() << " " << pointsOfPolygon[i].get_y() << endl;			
					++i;
				}
				SvgFile<< "\" fill=\"green\"/> "<< endl;
			}

			
		}
		
	}
			
}
	
