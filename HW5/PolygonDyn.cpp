/*
 * PolygonDyn.cpp
 *
 *
 *      Author: Nevra Gürses
 */

#include "PolygonDyn.h"
#include <cmath>
namespace{
	 // returns x coordinate  of one point of  circle.
	double findPosX(double radius,double degree) throw(invalid_argument){
		if(radius<=0) //If radius is not positive,throw an exception. 
			throw invalid_argument("Radius can't be negative and zero!-40");  
		double x=radius*cos(degree*PI/180);
		return (x+radius);
	}
	 // returns y coordinate  of one point of  circle.
	double findPosY(double radius,double degree) throw(invalid_argument){
		if(radius<=0) //If radius is not positive,throw an exception.
			throw invalid_argument("Radius can't be negative and zero!-41");  
		double y=radius*sin(degree*PI/180);
		return (y+radius);
	}
}
namespace ShapeOfGurses{
	
	PolygonDyn::PolygonDyn(const PolygonDyn& object) throw(invalid_argument) //Copy constructor.
	{
		degree=object.getDegree();	
		size=object.getSize();
		colorPoly=object.getColorPoly();
		rotateX=object.getRotateX();
		rotateY=object.getRotateY();
		if(size<=0 || rotateX<0 || rotateY <0) //If size and positions is not positive,throw an exception.
			throw invalid_argument("Polygon size and positions can't be negative!-43");
		pointsOfPolygon=new Polygon::Point2D[size];
		for(int i=0;i<size;++i)
			pointsOfPolygon[i]=object.pointsOfPolygon[i]; //copying.
				
	}
	PolygonDyn::~PolygonDyn() throw(){ //Destructor.
		delete [] pointsOfPolygon;
	}
	//Overloaded assignment operator.
	PolygonDyn& PolygonDyn::operator = (const PolygonDyn& second) throw(invalid_argument){
		if(size !=second.size){ 
			delete [] pointsOfPolygon;
			pointsOfPolygon=new Polygon::Point2D[second.size]; //creating new dynamic array.
		}
		size=second.size;
		if( size<=0 || second.size <= 0) //If size  is not positive,throw an exception.
			throw invalid_argument("Polygon size can't be negative and zero!-44");
		//Assignment
		for(int i=0;i<size;i++)
			pointsOfPolygon[i]=second.pointsOfPolygon[i];
			
		return *this;
	}
	PolygonDyn::PolygonDyn(Rectangle rectangle) throw()//Conversion constuctor from rectangle.
	{
		size=4; 
		pointsOfPolygon=new Polygon::Point2D[size]; 

		if(rectangle.getBigColor()=='r'){  //If container rectangle.
			colorPoly='r'; //initializing container color.

			//Assigning rectangle points in dynamic array.
			pointsOfPolygon[0]=Polygon::Point2D(rectangle.getPos_x(),rectangle.getPos_y());
			pointsOfPolygon[1]=Polygon::Point2D(rectangle.getPos_x(),rectangle.getPos_y()+rectangle.getHeight());
			pointsOfPolygon[2]=Polygon::Point2D(rectangle.getPos_x()+rectangle.getWidth(),rectangle.getPos_y()+rectangle.getHeight());
			pointsOfPolygon[3]=Polygon::Point2D(rectangle.getPos_x()+rectangle.getWidth(),rectangle.getPos_y());
			
		}
		if(rectangle.getSmallColor()=='g'){ //If inner rectangle.
			colorPoly='g'; //initializing small color.

			//Assigning rectangle points in dynamic array.
			pointsOfPolygon[0]=Polygon::Point2D(rectangle.getSmallPos_x(),rectangle.getSmallPos_y());
			pointsOfPolygon[1]=Polygon::Point2D(rectangle.getSmallPos_x(),rectangle.getSmallPos_y()+rectangle.getSmallHeight());
			pointsOfPolygon[2]=Polygon::Point2D(rectangle.getSmallPos_x()+rectangle.getSmallWidth(),rectangle.getSmallPos_y()+rectangle.getSmallHeight());
			pointsOfPolygon[3]=Polygon::Point2D(rectangle.getSmallPos_x()+rectangle.getSmallWidth(),rectangle.getSmallPos_y());
			
		}
	}
	PolygonDyn::PolygonDyn(Circle circle) throw() //Conversion constuctor from circle.
	{
		size=100;
		pointsOfPolygon=new Polygon::Point2D[size];
		if(circle.getBigColor()=='r' && circle.getDegree()==0 ){ //If container circle.
			double radius=circle.getRadius();
			colorPoly='r'; //initializing container color.
			degree=0; //initiliazing container degree.
			int i=0;
			double j=0; 

			//Assigning circle points in dynamic array.
			while(j <=360){
				pointsOfPolygon[i]=Polygon::Point2D((findPosX(radius,j)),(findPosY(radius,j))); //finding coordinates of 100 points of container circle and assigning dynamic array.
				++i;
				j=j+3.60;
			}
		}
		else if(circle.getSmallColor()=='g' && circle.getDegree()==0 ){  //If inner circle and does not rotating.
			colorPoly='g'; //initializing inner color.
			degree=0; //initiliazing inner degree.
			double j=0;
			int i=0;

			//Assigning circle points in dynamic array.
			while(j<=360){
				//finding coordinates of 100 points of small circle and assigning dynamic array.
				pointsOfPolygon[i]=Polygon::Point2D(circle.getSmallPosx()+(findPosX(circle.getSmallRadius(),j)),(circle.getSmallPosy()+findPosY(circle.getSmallRadius(),j)));
				++i;
				j=j+3.60;
			}
		}
		else if(circle.getSmallColor()=='g' && circle.getDegree()!=0 ){ //If inner circle and rotating.
			colorPoly='g';
			rotateX=circle.getRotateX(); //initializing rotating x coorcinate.
			rotateY=circle.getRotateY(); //initializing rotating y coordinate.
			degree=circle.getDegree(); //initiliazing rotating degree.
			double j=0;
			int i=0;

			//Assigning circle points in dynamic array.
			while(j<=360){
				//finding coordinates of 100 points of small rotating circle and assigning dynamic array.
				pointsOfPolygon[i]=Polygon::Point2D((circle.getSmallPosx()+findPosX(circle.getSmallRadius(),j)),(circle.getSmallPosy()+findPosY(circle.getSmallRadius(),j)));
				++i;
				j=j+3.60;
			}
		}
	}
			
	PolygonDyn::PolygonDyn(Triangle triangle) throw()//Conversion from triangle.
	{
		size=3;
		pointsOfPolygon=new Polygon::Point2D[size];
		if(triangle.getBigColor()=='r' && triangle.getDegree()==0 ){ //If container triangle.
			colorPoly='r'; //initializing container color.
			degree=0;//initializing container degree.

			//Assigning triangle points in dynamic array.
			pointsOfPolygon[0]=Polygon::Point2D(triangle.getBig_a1(),triangle.getBig_a2());
			pointsOfPolygon[1]=Polygon::Point2D(triangle.getBig_b1(),triangle.getBig_b2());
			pointsOfPolygon[2]=Polygon::Point2D(triangle.getBig_c1(),triangle.getBig_c2());
		}
		if(triangle.getSmallColor()=='g' && triangle.getDegree()==0){ //If small triangle.
			colorPoly='g'; //initializing small color.
			degree=0; //initializing small degree.

			//Assigning triangle points in dynamic array.
			pointsOfPolygon[0]=Polygon::Point2D(triangle.getPos_a1(),triangle.getPos_a2());
			pointsOfPolygon[1]=Polygon::Point2D(triangle.getPos_b1(),triangle.getPos_b2());
			pointsOfPolygon[2]=Polygon::Point2D(triangle.getPos_c1(),triangle.getPos_c2());
			
		
			
		}
		if(triangle.getSmallColor()=='g' && triangle.getDegree()!=0){ //If small rotating triangle.
			rotateX=triangle.getRotateX(); //initializing rotating x coordinate.
			rotateY=triangle.getRotateY(); //initializing rotating y coordinate.
			colorPoly='g'; 
			degree=triangle.getDegree(); //initializing rotate degree.

			//Assigning triangle points in dynamic array.
			pointsOfPolygon[0]=Polygon::Point2D(triangle.getPos_a1(),triangle.getPos_a2());
			pointsOfPolygon[1]=Polygon::Point2D(triangle.getPos_b1(),triangle.getPos_b2());
			pointsOfPolygon[2]=Polygon::Point2D(triangle.getPos_c1(),triangle.getPos_c2());
			
			
		}
	}
	PolygonDyn::PolygonDyn(vector<Polygon::Point2D> polygonPoints) throw(invalid_argument){ // constructor that takes an STL vector of Point2D objects to represent the Polygon points.
		size=polygonPoints.size();
		if(size <0)
			throw invalid_argument("Polygon size can't be negative or zero!-45");
		pointsOfPolygon=new Polygon::Point2D[size];
		for(int i=0;i<size;++i){  
			pointsOfPolygon[i]=polygonPoints[i]; //assignment vector members in dynamic memory.
		}
		
	}
	PolygonDyn::PolygonDyn() throw() //No parameter constructor.
		:Polygon()
	{ }
	//Draws polygons.
	void PolygonDyn::draw(ostream& SvgFile)const throw(){
		
		if(colorPoly=='r' || colorPoly !='g'){ //drawing container shape.
			SvgFile << "<svg version=\"1.1\" baseProfile=\"full\" width=\"100%\" height=\"100%\" xmlns=\"http://www.w3.org/2000/svg\"> "
				<< "<polygon  points=\"";
			int i=0;
			//This loop provides printing coordinates of all dynamic memory elements in svg.
			while(i < size){
				SvgFile  << pointsOfPolygon[i].get_x() << " " << pointsOfPolygon[i].get_y() << endl;			
				++i;
			}
			SvgFile<< "\" fill=\"red\"/> "<< endl;
			
		}
		else if(colorPoly=='g'){ //drawing small shape .
			if(degree!=0 && size !=4){ //drawing small shape that is rotating.
				SvgFile <<"<polygon transform=\"rotate(" <<degree << " " <<  rotateX << " "  << rotateY
				<< ")\" points=\"";
				int i=0;
				//This loop provides printing coordinates of all dynamic memory elements in svg.
				while(i< size){ 
					SvgFile  << pointsOfPolygon[i].get_x() << " " << pointsOfPolygon[i].get_y() << " "  ;			
					++i;
				}
				SvgFile<< "\" fill=\"green\"/> "<< endl;
					
		
			}
			else{ //drawing small shape that is not rotating.
				SvgFile<< "<polygon  points=\"";
				int i=0;
				//This loop provides printing coordinates of all dynamic memory elements in svg.
				while(i<size){
					SvgFile  << pointsOfPolygon[i].get_x() << " " << pointsOfPolygon[i].get_y() << endl;			
					++i;
				}
				SvgFile<< "\" fill=\"green\"/> "<< endl;
			}

			
		}
		
	}
			
}
