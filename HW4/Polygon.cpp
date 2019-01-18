/*
 * Polygon.cpp
 *
 *  
 *      Author: Nevra Gürses
 */
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <cmath>
using std::istream;
using std::ostream;
using std::cout;
using std::endl;
using std::cin;
#include "Polygon.h"
//Unnamed namespace
namespace{
	 // returns x coordinate  of one point of  circle.
	double findPosX(double radius,double degree){  
		double x=radius*cos(degree*PI/180);
		return (x+radius);
	}
	 // returns y coordinate  of one point of  circle.
	double findPosY(double radius,double degree){
		double y=radius*sin(degree*PI/180);
		return (y+radius);
	}
}
namespace PolygonOfGurses{ //My namespace.
	

	Polygon::Point2D::Point2D(double x,double y) //Initilizing coordinates of a point in Point2D class.
		:coordX(x),coordY(y)
	{ }
	void Polygon::Point2D::setPositions(double x,double y){ //Setting new coordinates in Point2D class.
		coordX=x;
		coordY=y;
	}
	Polygon::Point2D::Point2D() //Defaulted constructor of Point2D class.
		:coordX(0),coordY(0)
	{ }
	//Returning Point2D members.
	double Polygon::Point2D::get_x() const {
		return coordX;
	}
	double Polygon::Point2D::get_y() const {
		return coordY;
	}
	
	Polygon::Polygon() //no parameter constractor.
			:size(0)
	{ } 
	Polygon::Polygon(vector<Point2D> polygonPoints){ // constructor that takes an STL vector of Point2D objects to represent the Polygon points.
		size=polygonPoints.size();
		if(size < 0){ //testing size.
			cout << "It is not be a polygon"<< endl;
			exit(1);
		}
		pointsOfPolygon=new Point2D[size];
		for(int i=0;i<size;++i){  
			pointsOfPolygon[i]=polygonPoints[i]; //assignment vector members in dynamic array.
		}
		
	}
	Polygon::Polygon(const Polygon& object) //Copy constructor.
		:size(object.getSize()),color(object.getColor()),rotateX(object.getrotateX()),rotateY(object.getrotateY()),degree(object.getDegree())
	{
		if(size < 0){ //testing size.
			cout << "It is not be a polygon"<< endl;
			exit(1);
		}
		pointsOfPolygon=new Point2D[size];
		for(int i=0;i<size;++i)
			pointsOfPolygon[i]=object.pointsOfPolygon[i]; //copying.
				
	}
	Polygon::Polygon(Rectangle rectangle) //Conversion constuctor from rectangle.
		:size(4)
	{
		pointsOfPolygon=new Point2D[size]; 

		if(rectangle.getbigColor()=='r'){  //If container rectangle.
			color='r'; //initilizing container color.

			//Assigning rectangle points in dynamic array.
			pointsOfPolygon[0]=Point2D(rectangle.getPos_x(),rectangle.getPos_y());
			pointsOfPolygon[1]=Point2D(rectangle.getPos_x(),rectangle.getPos_y()+rectangle.getHeight());
			pointsOfPolygon[2]=Point2D(rectangle.getPos_x()+rectangle.getWidth(),rectangle.getPos_y()+rectangle.getHeight());
			pointsOfPolygon[3]=Point2D(rectangle.getPos_x()+rectangle.getWidth(),rectangle.getPos_y());
			
		}
		if(rectangle.getsmallColor()=='g'){ //If inner rectangle.
			color='g'; //initilizing small color.

			//Assigning rectangle points in dynamic array.
			pointsOfPolygon[0]=Point2D(rectangle.getSmallPos_x(),rectangle.getSmallPos_y());
			pointsOfPolygon[1]=Point2D(rectangle.getSmallPos_x(),rectangle.getSmallPos_y()+rectangle.getSmallHeight());
			pointsOfPolygon[2]=Point2D(rectangle.getSmallPos_x()+rectangle.getSmallWidth(),rectangle.getSmallPos_y()+rectangle.getSmallHeight());
			pointsOfPolygon[3]=Point2D(rectangle.getSmallPos_x()+rectangle.getSmallWidth(),rectangle.getSmallPos_y());
			
		}
	}
	
	Polygon::Polygon(Circle circle) //Conversion constuctor from circle.
		:size(100)
	{
		pointsOfPolygon=new Point2D[size];
		if(circle.getbigColor()=='r' && circle.getDegree()==0 ){ //If container circle.
			double radius=circle.getRadius();
			color='r'; //initilizing container color.
			degree=0; //initilizing container degree.
			int i=0;
			double j=0; 

			//Assigning circle points in dynamic array.
			while(j <=360){
				pointsOfPolygon[i]=Point2D((findPosX(radius,j)),(findPosY(radius,j))); //finding coordinates of 100 points of container circle and assigning dynamic array.
				++i;
				j=j+3.60;
			}
		}
		else if(circle.getsmallColor()=='g' && circle.getDegree()==0 ){  //If inner circle and does not rotating.
			color='g'; //initilizing inner color.
			degree=0; //initilizing inner degree.
			double j=0;
			int i=0;

			//Assigning circle points in dynamic array.
			while(j<=360){
				//finding coordinates of 100 points of small circle and assigning dynamic array.
				pointsOfPolygon[i]=Point2D(circle.getSmallPosx()+(findPosX(circle.getSmallRadius(),j)),(circle.getSmallPosy()+findPosY(circle.getSmallRadius(),j)));
				++i;
				j=j+3.60;
			}
		}
		else if(circle.getsmallColor()=='g' && circle.getDegree()!=0 ){ //If inner circle and rotating.
			color='g';
			rotateX=circle.getRotateX(); //initilizing rotating x coorcinate.
			rotateY=circle.getRotateY(); //initilizing rotating y coordinate.
			degree=circle.getDegree(); //initilizing rotating degree.
			double j=0;
			int i=0;

			//Assigning circle points in dynamic array.
			while(j<=360){
				//finding coordinates of 100 points of small rotating circle and assigning dynamic array.
				pointsOfPolygon[i]=Point2D((circle.getSmallPosx()+findPosX(circle.getSmallRadius(),j)),(circle.getSmallPosy()+findPosY(circle.getSmallRadius(),j)));
				++i;
				j=j+3.60;
			}
		}
	}
			
	Polygon::Polygon(Triangle triangle) //Conversion from triangle.
		:size(3)
	{
		pointsOfPolygon=new Point2D[size];
		if(triangle.getbigColor()=='r' && triangle.getDegree()==0 ){ //If container triangle.
			color='r'; //initilizing container color.
			degree=0;//initilizing container degree.

			//Assigning triangle points in dynamic array.
			pointsOfPolygon[0]=Point2D(triangle.getBig_a1(),triangle.getBig_a2());
			pointsOfPolygon[1]=Point2D(triangle.getBig_b1(),triangle.getBig_b2());
			pointsOfPolygon[2]=Point2D(triangle.getBig_c1(),triangle.getBig_c2());
		}
		if(triangle.getsmallColor()=='g' && triangle.getDegree()==0){ //If small triangle.
			color='g'; //initilizing small color.
			degree=0; //initlilizing small degree.

			//Assigning triangle points in dynamic array.
			pointsOfPolygon[0]=Point2D(triangle.getPos_a1(),triangle.getPos_a2());
			pointsOfPolygon[1]=Point2D(triangle.getPos_b1(),triangle.getPos_b2());
			pointsOfPolygon[2]=Point2D(triangle.getPos_c1(),triangle.getPos_c2());
			
		
			
		}
		if(triangle.getsmallColor()=='g' && triangle.getDegree()!=0){ //If small rotating triangle.
			rotateX=triangle.getRotateX(); //initilizing rotating x coordinate.
			rotateY=triangle.getRotateY(); //initilizing rotating y coordinate.
			color='g'; 
			degree=triangle.getDegree(); //initilizing rotate degree.

			//Assigning triangle points in dynamic array.
			pointsOfPolygon[0]=Point2D(triangle.getPos_a1(),triangle.getPos_a2());
			pointsOfPolygon[1]=Point2D(triangle.getPos_b1(),triangle.getPos_b2());
			pointsOfPolygon[2]=Point2D(triangle.getPos_c1(),triangle.getPos_c2());
			
			
		}
	}
			
	Polygon::~Polygon(){ //Destructor.
		delete [] pointsOfPolygon;
	}
	//Overloaded assignment operator.
	Polygon& Polygon::operator = (const Polygon& second){
		if(size !=second.size){
			delete [] pointsOfPolygon;
			pointsOfPolygon=new Point2D[second.size]; //creating new dynamic array.
		}
		size=second.size;
		//Assignment
		for(int i=0;i<size;i++)
			pointsOfPolygon[i]=second.pointsOfPolygon[i];
			
		return *this;
	}
	//Overloaded [] operator.	
	Polygon::Point2D& Polygon::operator [](const int index) const {
		if(index<0){ 
			cout << "Illegal index! "<< endl; //testing index.
			exit(1);
		}
		
		return pointsOfPolygon[index]; //returning index.
	}
	//Overloaded == operator.
	bool Polygon :: operator == (const Polygon& secondPolygon) const{
		if(size!=secondPolygon.size)
			return false;
		for(int i=0;i<size;++i){
			if(pointsOfPolygon[i].get_x() != secondPolygon.pointsOfPolygon[i].get_x() || pointsOfPolygon[i].get_y() != secondPolygon.pointsOfPolygon[i].get_y())
				return false;
		}
		return true;
	}
	//Overloaded != operator.
	bool Polygon :: operator != (const Polygon& secondPolygon) const{
		if(size!=secondPolygon.size)
			return true;
		for(int i=0;i<size;++i){
			if(pointsOfPolygon[i].get_x() != secondPolygon.pointsOfPolygon[i].get_x() || pointsOfPolygon[i].get_y() != secondPolygon.pointsOfPolygon[i].get_y())
				return true;
		}
		return false;
	}
	//Overloaded + operator.
	const Polygon Polygon:: operator + (const Polygon& secondPolygon) const{
		vector <Point2D> newVect; //creating new vector.
		int border=secondPolygon.size;
		for(int i=0;i<size;i++){
			newVect.push_back(pointsOfPolygon[i]); //Copying points of first polygon in new vector.
		}
		for(int j=0;j<border;j++){
			newVect.push_back(secondPolygon.pointsOfPolygon[j]);  //Copying point of second polygon in new vector.
		}
		return Polygon(newVect); //returning new polygon object.
	}
	//Overloaded << operator to drawing.
	ostream& operator <<(ostream& SvgFile,const Polygon& object){
		
		if(object.color=='r' || object.color !='g'){ //drawing container shape.
			SvgFile << "<svg version=\"1.1\" baseProfile=\"full\" width=\"100%\" height=\"100%\" xmlns=\"http://www.w3.org/2000/svg\"> "
				<< "<polygon  points=\"";
			int i=0;
			//This loop provides printing coordinates of all dynamic array elements in svg.
			while(i < object.size){
				SvgFile  << object.pointsOfPolygon[i].get_x() << " " << object.pointsOfPolygon[i].get_y() << endl;			
				++i;
			}
			SvgFile<< "\" fill=\"red\"/> "<< endl;
			
		}
		else if(object.color=='g'){ //drawing small shape .
			if(object.degree!=0 && object.size !=4){ //drawing small shape that is rotating.
				SvgFile <<"<polygon transform=\"rotate(" << object.degree << " " <<  object.rotateX << " "  << object.rotateY
				<< ")\" points=\"";
				int i=0;
				//This loop provides printing coordinates of all dynamic array elements in svg.
				while(i< object.size){ 
					SvgFile  << object.pointsOfPolygon[i].get_x() << " " << object.pointsOfPolygon[i].get_y() << " "  ;			
					++i;
				}
				SvgFile<< "\" fill=\"green\"/> "<< endl;
					
		
			}
			else{ //drawing small shape that is not rotating.
				SvgFile<< "<polygon  points=\"";
				int i=0;
				//This loop provides printing coordinates of all dynamic array elements in svg.
				while(i<object.size){
					SvgFile  << object.pointsOfPolygon[i].get_x() << " " << object.pointsOfPolygon[i].get_y() << endl;			
					++i;
				}
				SvgFile<< "\" fill=\"green\"/> "<< endl;
			}

			
		}
		return SvgFile;
	}
	//Prints coordinates of an element of dynamic array.
	void Polygon::printArray() const {
		for(int i=0;i<size;++i){
			cout << "x coordinate:" << pointsOfPolygon[i].get_x() 
				<< " , y coordinate:"<< pointsOfPolygon[i].get_y() << endl;
		}
	}
	//Returning private members.
	int Polygon::getSize() const {
		return size;
	}
	int Polygon::getDegree() const { return degree; }
	char Polygon::getColor() const { return color; }
	double Polygon::getrotateX() const { return rotateX; }
	double Polygon::getrotateY () const { return rotateY; }
	
} 


	





















































































