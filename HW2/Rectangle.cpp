/*
 * Rectangle.cpp
 *
 *  Created on: 24,10,2018
 *      Author: Nevra Gürses
 */
#include <iostream>
#include <cstdlib>
#include <fstream>
#include "Rectangle.h"
using namespace std;
// Tests the height or width value are  negative or zero.If it is,then program is stopped.
void Rectangle::test(){
	if(height<=0 || width <=0){
		cout << "Height or width can not be negative number or zero." << endl;
		exit(1);
	}
}
// Writes width and height value of Rectangle on screen,if it is necessary.
void Rectangle::output() const{
	cout << "Height of Rectange is:" << height << endl
	     <<"Width of Rectangle is:"  << width << endl;
}

// Determines the new positions of small Rectangles in container shape.
void Rectangle::setRectangle(int widthValue,int heightValue,int uploaded_x,int uploaded_y ){
	s_width=widthValue;
	s_height=heightValue;
	s_posX=uploaded_x;
	s_posY=uploaded_y;
}
// Determines the new positions of small Rectangles in container shape if small rectangles be placed vertically in container shape.
void Rectangle::setRectangle2(int widthValue,int heightValue,int uploaded_x,int uploaded_y ){
	s_posX=uploaded_x;
	s_posY=uploaded_y;
	s_width=heightValue;
	s_height=widthValue;
}
// Draw the container and small Rectangle in Svg File.
void Rectangle::draw(ofstream &SvgFile){
	//Prints container rectangle in Svg file.Color is determinant.
	if( color == 'r'){
		SvgFile << "<svg version=\"1.1\" baseProfile=\"full\" width=\"100%\" height=\"100%\" xmlns=\"http://www.w3.org/2000/svg\"> " << endl
			<< " <rect width=\""<< width  << "\" height=\"" << height  << "\"" << " fill=\"red\" /> " << endl;
	}
	//Prints small rectangle in Svg file.Color is determinant.
	else if(s_color == 'g'){
		SvgFile << " <rect x=\"" << s_posX << "\"" << " y=\""<< s_posY
			<< "\"" << " width=\"" <<  s_width << "\"" << " height=\"" << s_height
			<< "\"" << " fill=\"green\" " << "/>" << endl;
	}
	
		
}

