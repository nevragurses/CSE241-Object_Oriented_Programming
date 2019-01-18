/*
 * Polyline.cpp
 *
 *  Created on: 19,11,2018
 *      Author: Nevra Gürses
 */
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <cmath>
#include "Polyline.h"
using std::istream;
using std::ostream;
using std::cout;
using std::endl;
using std::cin;

namespace PolylineOfGurses{
	
	Polyline::Polyline() //No parameter constructor.
		: object() 
	{ } 
	Polyline::Polyline(vector<Polygon::Point2D>PolylinePoints) //constructor that takes vector and represent polygon points by using polygon object.
		:object(PolylinePoints)
	{   }
	//Conversion constructors that are using Polygon class to do conversion by polygon class object.
	Polyline::Polyline(Rectangle rectangle)
		:object(rectangle)
	{   }
	Polyline::Polyline(Circle circle)
		:object(circle)
	{   }
	Polyline::Polyline(Triangle triangle)
		:object(triangle)
	{   }
	Polygon::Point2D& Polyline::operator [](const int index) const { //overloaded [] operator that returns index of array.
		if(index<0){
			cout << "Illegal index!"<< endl;
			exit(1);
		}

		return object[index];
	}
	//Overloaded == operator
	bool Polyline :: operator == (const Polyline& second) const{
		if(object.getSize()!=second.object.getSize())
			return false;
		for(int i=0;i< object.getSize();++i){
			if(object[i].get_x() != second.object[i].get_x() || object[i].get_y() != second.object[i].get_y())
				return false;
		}
		return true;
	}
	//Overloaded != operator.
	bool Polyline :: operator != (const Polyline& second) const{
		if(object.getSize()!=second.object.getSize())
			return true;
		for(int i=0;i<object.getSize();++i){
			if(object[i].get_x() != second.object[i].get_x() || object[i].get_y() != second.object[i].get_y())
				return true;
		}
		return false;
	}
	//Overloaded + operator to create new polyline object.
	const Polyline Polyline:: operator + (const Polyline& second) const{
		vector <Polygon::Point2D> newVect; //new vector.
		int border=second.object.getSize();
		for(int i=0;i<object.getSize();i++){
			newVect.push_back(object[i]); //elements of first poline are copying new polyline vector.
		}
		for(int j=0;j<border;j++){
			newVect.push_back(second.object[j]); //elements of second poline are copying new polyline vector.
		}
		return Polyline(newVect);
	}
	//overloaded << operator to drawing polyline.
	ostream& operator <<(ostream& SvgFile,const Polyline& element){
		if(element.object.getColor()=='r' && element.object.getColor()!='g'){ //Drawing container polyline.
			SvgFile << "<svg version=\"1.1\" baseProfile=\"full\" width=\"100%\" height=\"100%\" xmlns=\"http://www.w3.org/2000/svg\"> "
				<< "<polyline  points=\"";
			int i=0;
			while(i < element.object.getSize()){
				SvgFile  << element.object[i].get_x() << " " << element.object[i].get_y() << endl;
				++i; 
			}
			SvgFile<< "\" fill=\"none\" stroke=\"red\"/> "<< endl;

		}
		else if(element.object.getColor()=='g'){ //Drawing small polyline.
			if(element.object.getDegree()!=0 && element.object.getSize() !=4){ //drawing rotating polyline.
				SvgFile <<"<polyline transform=\"rotate(" << element.object.getDegree() << " " <<  element.object.getrotateX() << " "  << element.object.getrotateY()
				<< ")\" points=\"";
				int i=0;
				while(i< element.object.getSize()){
					SvgFile  << element.object[i].get_x() << " " << element.object[i].get_y() << endl;
					++i;
				}
				SvgFile<< "\" fill=\"none\" stroke=\"red\"/> "<< endl;


			}
			else{ //drawing small and not rotating polyline.
				SvgFile<< "<polyline  points=\"";
				int i=0;
				while(i<element.object.getSize()){
					SvgFile  << element.object[i].get_x() << " " << element.object[i].get_y() << endl;
					++i;
				}
				SvgFile<< "\" fill=\"none\" stroke=\"red\"/> "<< endl;
			}


		}
		return SvgFile;
	}
	//Prints coordinates of polyline points.
	void Polyline::print() const {
		for(int i=0;i<object.getSize();++i){
			cout << "x coordinate:" << object[i].get_x()
				<< " , y coordinate:"<< object[i].get_y() << endl;
		}
	}
}
