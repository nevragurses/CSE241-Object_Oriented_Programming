/*
 * hw1_svg.cpp
 *
 *  Created on: Oct 18, 2018
 *      Author: Nevra
 */
#include <iostream>
#include <fstream>
#include "hw1_svg.h"
using namespace std;

//User selects container shape and small shape by this function and other functions are called for making SVG file and calculations.
void SelectShape(ShapeFeatures& Selection){
	char ans,ans2;
	cout << "Please enter the main container shape (R, C, T):";
	cin >> ans ;
	SelectionAns(Selection,ans); 
	//User selects container and small shapes by this condition statements.
	if (Selection.container == Shape::Rectangle){
		cout << "Please enter the width:";
		cin >> Selection.width;
		cout << "Please enter the height:";
		cin >> Selection.height;
		cout << "Please enter the small shape (R,C,T):";
		cin >> ans2;
		SelectionAns(Selection,ans2); //Enum class member are selected for determining shape by calling this function.
		if(Selection.s_shape == Shape::Rectangle){
			Small_rectangle(Selection); //Function calling to take lenghts for small shapes.
			Rectangle_rectangle(Selection); //Function is calling to make calculations and SVG file for rectangle in rectangle.
		}
		else if(Selection.s_shape == Shape::Circle){
			Small_circle(Selection);
			Rectangle_circle(Selection); //Function is calling to make calculations and SVG file for circle in rectangle.
		}
		else if(Selection.s_shape == Shape::Triangle){
			Small_triangle(Selection);
			Rectangle_triangle(Selection); //Function is calling to make calculations and SVG file for triangle in rectangle.
		}
	}
	else if (Selection.container == Shape::Circle){
		cout << "Please enter the radius:";
		cin >> Selection.radius;
		cout << "Please enter the small shape (R,C,T):";
		cin >> ans2;
		SelectionAns(Selection,ans2); 
		if(Selection.s_shape == Shape::Rectangle){
			Small_rectangle(Selection);
			Circle_rectangle(Selection); //Function is calling to make calculations and SVG file for rectangle in  circle.
		}
		else if(Selection.s_shape == Shape::Circle){
			Small_circle(Selection);	
			Circle_circle(Selection); //Function is calling to make calculations and SVG file for circle in circle.
		}
		else if(Selection.s_shape == Shape::Triangle){
			Small_triangle(Selection);
			Circle_triangle (Selection); //Function is calling to make calculations and SVG file for triangle in circle.
		}
	}
	else if (Selection.container == Shape::Triangle){
		cout << "Please enter the side lenght:";
		cin >> Selection.sideLenght;
		cout << "Please enter the small shape (R,C,T):";
		cin >> ans2;
		SelectionAns(Selection,ans2); 
		if(Selection.s_shape == Shape::Rectangle){
			Small_rectangle(Selection);
			Triangle_rectangle(Selection); //Function is calling to make calculations and SVG file for rectangle in triangle.
		}
		else if(Selection.s_shape == Shape::Circle){
			Small_circle(Selection);	
			Triangle_circle(Selection); //Function is calling to make calculations and SVG file for circle in triangle.
		}
		else if(Selection.s_shape == Shape::Triangle){
			Small_triangle(Selection);
			Triangle_triangle (Selection); //Function is calling to make calculations and SVG file for triangle in triangle.
		}
	}
}
//This function determines enum class member by char answer that is entered user.
void SelectionAns(ShapeFeatures& Selection,char ans){
	switch(ans){
		case 'R': Selection.container=Shape::Rectangle;
			  Selection.s_shape=Shape::Rectangle;
			 break;
		case 'C': Selection.container=Shape::Circle; 
			  Selection.s_shape=Shape::Circle;
			 break;
		case 'T': Selection.container=Shape::Triangle;
			  Selection.s_shape=Shape::Triangle;  
			break;
		default:
			cout << "You entered false character!:" << endl;
	}
}
//This function takes width and height  from user for small rectangle in container shape.
void Small_rectangle(ShapeFeatures& Selection){
	cout << "Please enter the width:";
	cin >> Selection.s_width;
	cout << "Please enter the height:";
	cin >> Selection.s_height;
}
//This function takes radius  from user for small circle in container shape.
void Small_circle(ShapeFeatures& Selection){
	cout << "Please enter the radius:";
	cin >> Selection.s_radius;
}
//This function takes sidelenght  from user for small triangle in container shape.
void Small_triangle(ShapeFeatures& Selection){
	cout << "Please enter the side lenght:";
	cin >> Selection.s_sideLenght;

}
//This function calculates the number of  max circle and finds empty area in container rectangle and produces  SVG file.
void Rectangle_circle(ShapeFeatures& Selection){
	ofstream SvgFile;
	SvgFile.open("output.svg");  //Svg file is opening to write calculations and produce shape.
	SvgFile << "<svg version=\"1.1\" baseProfile=\"full\" width=\"100%\" height=\"100%\" xmlns=\"http://www.w3.org/2000/svg\"> " << endl
		<< " <rect width=\""<< Selection.width  << "\" height=\"" << Selection.height  << "\"" << " fill=\"red\" /> " << endl;
	int temp1=Selection.s_radius;
	int temp2=Selection.s_radius;
	//This loop provides to put max circle in container shape rectangle in svg file.
	while((temp1+Selection.s_radius) <= Selection.height){
		while((temp2+Selection.s_radius) <= Selection.width){
			//The new location of circle in rectangle is determines and writes in svg file.
			SvgFile << " <circle cx=\"" <<  temp2 << "\"" << " cy=\"" << temp1 
				<< "\"" <<" r=\"" << Selection.s_radius << "\" "<< "fill=\"green\" /> " << endl; 
			temp2=temp2+(2*Selection.s_radius);
		}
		temp1=temp1+(2*Selection.s_radius);
		temp2=Selection.s_radius;
		
	}
	SvgFile << " </svg> " << endl; 
	
	int numberOfCircle;
	double area; 
	numberOfCircle=(Selection.width/(2*Selection.s_radius))*(Selection.height/(2*Selection.s_radius)); //Number of max circle in container shape rectangle.
	area=((Selection.width)*(Selection.height))-(PI*(Selection.s_radius)*(Selection.s_radius)*(numberOfCircle)); //Empty area.
	cout << "I can fit at most" <<  "  " << numberOfCircle
		<<  " " <<  "small shapes into the main container." 
		<< "The empty area (red) in container is" << " " << area << endl;
	SvgFile.close(); //Svg file closing.
}
//This function calculates the number of  max rectangle and finds empty area in container rectangle and produces  SVG file.
void Rectangle_rectangle(ShapeFeatures& Selection){
	int numberOfRectangle1,numberOfRectangle2,last_numberOfRectangle,last_numberOfRectangle1,last_numberOfRectangle2,temporal;
	ofstream SvgFile;
	SvgFile.open("output.svg"); //Svg file is opening to write calculations and produce shape.
	SvgFile << "<svg version=\"1.1\" baseProfile=\"full\" width=\"100%\" height=\"100%\" xmlns=\"http://www.w3.org/2000/svg\"> " << endl
		<< " <rect width=\""<< Selection.width  << "\" height=\"" << Selection.height  << "\"" << " fill=\"red\" /> " << endl;
	
	int process1=0,process2=0;
	//If user enters width smaller than height,numbers are changed with each other to make processes. 
	if(Selection.s_width<Selection.s_height){
		temporal=Selection.s_width;
		Selection.s_width=Selection.s_height;
		Selection.s_height=temporal;
	}
	//This if-else statements calculates number of rectangles in container shape rectangle by horizontally.
	numberOfRectangle1=((Selection.width/Selection.s_width)*(Selection.height/Selection.s_height));
	if((Selection.width % Selection.s_width) >= Selection.s_height){
		last_numberOfRectangle1=numberOfRectangle1 + ((Selection.height/Selection.s_width)*((Selection.width % Selection.s_width)/Selection.s_height));
	}
	else{
		last_numberOfRectangle1=numberOfRectangle1;
	}
	//This if-else statements calculates number of rectangles in container shape rectangle by vertically.
	numberOfRectangle2=((Selection.height/Selection.s_width)*(Selection.width/Selection.s_height));
	if((Selection.height % Selection.s_width) >= Selection.s_height){
		last_numberOfRectangle2=numberOfRectangle2 + ((Selection.width/Selection.s_width)*((Selection.height % Selection.s_width)/Selection.s_height));
	}
	else{
		last_numberOfRectangle2=numberOfRectangle2;
	}
	//If number of rectangle by horizontally much than vertically,rectangles are placed horizontally in container rectangle.
	if(last_numberOfRectangle1>=last_numberOfRectangle2){
		last_numberOfRectangle=last_numberOfRectangle1;
		//This loop provides  to put max rectangle by horizontally in container shape rectangle in svg file.
		while((process1+Selection.s_height) <= Selection.height){
			while((process2+Selection.s_width) <= Selection.width){
				SvgFile << " <rect x=\"" << process2 << "\"" << " y=\""<< process1 
					<< "\"" << " width=\"" <<  Selection.s_width << "\"" << " height=\"" << Selection.s_height
					<< "\"" << " fill=\"green\" " << "/>" << endl;
				process2=process2+(Selection.s_width);
			}
			process1=process1+(Selection.s_height);
			if((process1+Selection.s_height) <=Selection.height){
				process2=0;
			}
		}
		//If the rectangles can fit remaining space by vertically,they are replaced there.
		if((Selection.width % Selection.s_width) >= Selection.s_height){
			process1=0;
			//This loop provides  to put  rectangle by vertically in container shape rectangle in svg file, if there are spaces.
			while((process1+Selection.s_width) <= Selection.height){
				while((process2+Selection.s_height) <= Selection.width){
					SvgFile << " <rect x=\"" << process2 << "\"" << " y=\""<< process1 
						<< "\"" << " width=\"" <<  Selection.s_height << "\"" << " height=\"" << Selection.s_width
						<< "\"" << " fill=\"green\" " << "/>" << endl;
					process2=process2+(Selection.s_height);
				}
				process1=process1+(Selection.s_width);
				process2=Selection.width-(Selection.width % Selection.s_width);
		
			}
		}
	}
	//If number of rectanle by vertically much than horizontally,rectangles are placed vertically in container rectangle.
	else{
		last_numberOfRectangle=last_numberOfRectangle2;
		while((process1+Selection.s_width) <= Selection.height){
			while((process2+Selection.s_height) <= Selection.width){
				SvgFile << " <rect x=\"" << process2 << "\"" << " y=\""<< process1
					<< "\"" << " width=\"" <<  Selection.s_height << "\"" << " height=\"" << Selection.s_width
					<< "\""  << " fill=\"green\" " << "/>" << endl;
				process2=process2+(Selection.s_height);
			}
			process1=process1+(Selection.s_width);
			process2=0;
		}
		//If the rectangles can fit remaining space by horizontally,they are replaced there.
		if((Selection.height % Selection.s_width) >= Selection.s_height){
			//This loop provides  to put  rectangle by horizontally in container shape rectangle in svg file, if there are spaces.	
			while((process1+Selection.s_height) <= Selection.height){
				while((process2+Selection.s_width) <= Selection.width){
					SvgFile << " <rect x=\"" << process2 << "\"" << " y=\""<< process1
						<< "\"" << " width=\"" <<  Selection.s_width << "\"" << " height=\"" << Selection.s_height
						<< "\"" << " fill=\"green\" " << "/>" << endl;
					process2=process2+(Selection.s_width);
				}
				process1=process1+(Selection.s_height);
				process2=0 ;
			 }	
		}
	}
	SvgFile << " </svg> " << endl;
	SvgFile.close(); //Svg file closing.
	double area=(Selection.width*Selection.height)-(Selection.s_height*Selection.s_width*last_numberOfRectangle); // Empty area.
	cout << "I can fit at most" <<  "  " << last_numberOfRectangle
		<<  " " <<  "small shapes into the main container." 
		<< "The empty area (red) in container is" << " " << area << endl;
	
}
//This function find  root of a number by using Babil metod (I use this function to dont use c math library)
double findRoot(double number){
	double temp=1;
	int i;
	for(i=0;i<100;i++){
 		temp=0.5*(temp+(number/temp));
	}
	return (temp);
}
//This function calculates the number of  max triangle and finds empty area in container rectangle and produces  SVG file.
void Rectangle_triangle(ShapeFeatures& Selection){
	int numberOfTriangle1,numberOfTriangle2;
	double condition=Selection.s_sideLenght/2.0;
	
	ofstream SvgFile;
	SvgFile.open("output.svg"); //Svg file is opening to write calculations and produce shape.
	SvgFile << "<svg version=\"1.1\" baseProfile=\"full\" width=\"100%\" height=\"100%\" xmlns=\"http://www.w3.org/2000/svg\"> " << endl
		<< " <rect width=\""<< Selection.width  << "\" height=\"" << Selection.height  << "\"" << " fill=\"red\" /> " << endl;
	
	int remainder1,remainder2;
	//Number of triangles that don't fit into rectangle completely along width.
	if((Selection.width % Selection.s_sideLenght) >= condition){
		remainder1=Selection.height/((Selection.s_sideLenght/2.0)*findRoot(3.0));
		numberOfTriangle1=(Selection.width/Selection.s_sideLenght)*2*remainder1;
	}
	else{
		remainder1=Selection.height/((Selection.s_sideLenght/2.0)*findRoot(3.0));
		numberOfTriangle1=((Selection.width/Selection.s_sideLenght)+((Selection.width/Selection.s_sideLenght)-1))*remainder1;
	}
	//Number of triangles that don't fit into rectangle completely along height.
	if((Selection.height % Selection.s_sideLenght) >= condition){
		remainder2=Selection.width/((Selection.s_sideLenght/2.0)*findRoot(3.0));
		numberOfTriangle2=(Selection.height/Selection.s_sideLenght)*2*remainder2;
	}
	else{
		remainder2=Selection.width/((Selection.s_sideLenght/2.0)*findRoot(3.0));
		numberOfTriangle2=((Selection.height/Selection.s_sideLenght)+((Selection.height/Selection.s_sideLenght)-1))*remainder2;
	}
	int last_numberOfTriangle;
	//Number of triangles  into rectangle by horizontally much than vertically,they are placed horizontally in svg file.
	if(numberOfTriangle1>numberOfTriangle2){
		last_numberOfTriangle=numberOfTriangle1;
		double x1=Selection.s_sideLenght/2.0;
		double y1=0;
		double x2=0;
		double y2=(Selection.s_sideLenght/2.0)*findRoot(3.0);
		double x3=Selection.s_sideLenght;
		double y3=(Selection.s_sideLenght/2.0)*findRoot(3.0);
		//This loop provides  to put  triangle by horizontally and flaty in container shape rectangle in svg file.	
		while(y2<=Selection.height){
			while(x3 <= Selection.width){
				SvgFile << "<polygon  points=\"" << x1 << " " << y1 << " " << x2 << " "
					<< y2 << " "<< x3 <<" "<< y3  << "\" fill=\"green\"/> "<< endl;
				x1=x1+Selection.s_sideLenght;
				x2=x2+Selection.s_sideLenght;
				x3=x3+Selection.s_sideLenght;
			}
			//New positions of triangles are determined.
			x1=Selection.s_sideLenght/2.0;
			y1=y1+((Selection.s_sideLenght/2.0)* findRoot(3.0));
			x2=0;
			y2=y2+((Selection.s_sideLenght/2.0)*findRoot(3.0));
			x3=Selection.s_sideLenght;	
			y3=y3+((Selection.s_sideLenght/2.0)*findRoot(3.0));
		}
		double k1=Selection.s_sideLenght/2.0;
		double z1=0;
		double k2=Selection.s_sideLenght;
		double z2=(Selection.s_sideLenght/2.0)*findRoot(3.0);
		double k3=Selection.s_sideLenght+(Selection.s_sideLenght/2.0);
		double z3=0;
		//This loop provides  to put  triangle by horizontally and inverselly in container shape rectangle in svg file.	
		while(z2<=Selection.height){
			while(k3 <= Selection.width){
				SvgFile << "<polygon  points=\"" << k1 << " " << z1 << " " << k2 << " " 
					<< z2 << " "<< k3 <<" "<< z3  << "\" fill=\"green\"/> "<< endl;
				k1=k1+Selection.s_sideLenght;
				k2=k2+Selection.s_sideLenght;
				k3=k3+Selection.s_sideLenght;
			}
			//New positions of triangles is determided.
			k1=Selection.s_sideLenght/2.0;
			z1=z1+((Selection.s_sideLenght/2.0)* findRoot(3.0));
			k2=Selection.s_sideLenght;
			z2=z2+((Selection.s_sideLenght/2.0)*findRoot(3.0));
			k3=Selection.s_sideLenght+(Selection.s_sideLenght/2.0);	
			z3=z3+((Selection.s_sideLenght/2.0)*findRoot(3.0));
		}
	}
	//Number of triangles  into rectangle by vertically much than horizontally,they are placed vertically in svg file.
	else{
		last_numberOfTriangle=numberOfTriangle2;
		double x1=0;
		double y1=Selection.s_sideLenght/2.0;
		double x2=(Selection.s_sideLenght/2.0)*findRoot(3.0);
		double y2=Selection.s_sideLenght;
		double x3=(Selection.s_sideLenght/2.0)*findRoot(3.0);
		double y3=0;
		//This loop provides  to put  triangle by vertically and flaty in container shape rectangle in svg file.	
		while(y2<=Selection.height){
			while(x2 <= Selection.width){
				SvgFile << "<polygon  points=\"" << x1 << " " << y1 << " " << x2 << " " 
					<< y2 << " "<< x3 <<" "<< y3  << "\" fill=\"green\"/> "<< endl;
				x1=x1+((Selection.s_sideLenght/2.0)* findRoot(3.0));
				x2=x2+((Selection.s_sideLenght/2.0)*findRoot(3.0));
				x3=x3+((Selection.s_sideLenght/2.0)*findRoot(3.0));
			}
			//New positions of triangles is determided.
			x1=0;
			y1=y1+Selection.s_sideLenght;	
			x2=(Selection.s_sideLenght/2.0)*findRoot(3.0);
			y2=y2+Selection.s_sideLenght;
			x3=(Selection.s_sideLenght/2.0)*findRoot(3.0);
			y3=y3+Selection.s_sideLenght;
			
		}
		double k1=0;
		double z1=Selection.s_sideLenght/2.0;
		double k2=0;
		double z2=Selection.s_sideLenght+(Selection.s_sideLenght/2.0);
		double k3=(Selection.s_sideLenght/2.0)*findRoot(3.0);
		double z3=Selection.s_sideLenght;
		//This loop provides  to put  triangle by vertically and inverselly in container shape rectangle in svg file.	
		while(z2<=Selection.height){
			while(k3<= Selection.width){
				SvgFile << "<polygon  points=\"" << k1 << " " << z1 << " " << k2 << " "
					<< z2 << " "<< k3 <<" "<< z3  << "\" fill=\"green\"/> "<< endl;
				k1=k1+((Selection.s_sideLenght/2.0)*findRoot(3.0));
				k2=k2+((Selection.s_sideLenght/2.0)*findRoot(3.0));
				k3=k3+((Selection.s_sideLenght/2.0)*findRoot(3.0));
			}
			//New positions of triangles is determided.
			k1=0;
			z1=z1+Selection.s_sideLenght;
			k2=0;
			z2=z2+Selection.s_sideLenght;
			k3=(Selection.s_sideLenght/2.0)*findRoot(3.0);
			z3=z3+Selection.s_sideLenght;
		}
	}
	SvgFile << " </svg> " << endl;
	SvgFile.close(); //Svg file closing.
	double area=(Selection.height*Selection.width)-(last_numberOfTriangle*((Selection.s_sideLenght*Selection.s_sideLenght*findRoot(3.0))/4.0)); //Empty area;
	
	cout << "I can fit at most" <<  "  " << last_numberOfTriangle
		<<  " " <<  "small shapes into the main container."
		<< "The empty area (red) in container is" << " " << area << endl;
}
//This function calculates the number of  max triangle and finds empty area in container triangle and produces  SVG file.
void Triangle_triangle(ShapeFeatures& Selection){
	int numberOfTriangle=0,i;
	int temp=Selection.sideLenght/Selection.s_sideLenght;
	ofstream SvgFile;
	SvgFile.open("output.svg"); //Svg file is opening to write calculations and produce shape.
	SvgFile << "<svg version=\"1.1\" baseProfile=\"full\" width=\"100%\" height=\"100%\" xmlns=\"http://www.w3.org/2000/svg\"> " 
		<< "<polygon  points=\"" << Selection.sideLenght/2.0 << " " << 0 << " " << 0 << " " 
		<< (Selection.sideLenght/2.0)*findRoot(3.0) << " "<< Selection.sideLenght <<" "<< (Selection.sideLenght/2.0)*findRoot(3.0)  << "\" fill=\"red\"/> "<< endl;
	int selected_leng=Selection.s_sideLenght;
	double up_x=Selection.sideLenght/2.0;
	double up_y=0;
	double left_x=(Selection.sideLenght/2.0)-(Selection.s_sideLenght/2.0);
	double left_y=(Selection.s_sideLenght/2.0)*findRoot(3.0);
	double right_x=(Selection.s_sideLenght/2.0) + (Selection.sideLenght/2.0);
	double right_y=(Selection.s_sideLenght/2.0)*findRoot(3.0);
	int r=1,d=1,count=1;
	//This loop provides  to put  triangle by horizontally and flaty in container shape triangle in svg file.	
	while(left_y<=(Selection.sideLenght/2.0)*findRoot(3.0)){
		while(count<=d){
			SvgFile <<"<polygon  points=\"" << up_x << " " << up_y << " " << left_x << " " 
				<< left_y << " "<< right_x <<" "
				<< right_y << "\" fill=\"green\"/> "<< endl;
			up_x=up_x+Selection.s_sideLenght;
			left_x=left_x+Selection.s_sideLenght;
			right_x=right_x+Selection.s_sideLenght;
			count ++;
		}
		//New positions of triangles is determided.
		count=1;
		up_x=(Selection.sideLenght/2.0)-d*(Selection.s_sideLenght/2.0);
		up_y=up_y + ((Selection.s_sideLenght/2.0)*findRoot(3.0));
		left_x=left_x-((d)*Selection.s_sideLenght)-(Selection.s_sideLenght/2.0);
		left_y=left_y + ((Selection.s_sideLenght/2.0)*findRoot(3.0));
		right_x=right_x-((d)*Selection.s_sideLenght)-(Selection.s_sideLenght/2.0);
		right_y=right_y + ((Selection.s_sideLenght/2.0)*findRoot(3.0));
		d++;
	}
	double up2_x=Selection.sideLenght/2.0;
	double up2_y=2*((Selection.s_sideLenght/2.0)*findRoot(3.0));
	double left2_x=(Selection.sideLenght/2.0)-(Selection.s_sideLenght/2.0);
	double left2_y=(Selection.s_sideLenght/2.0)*findRoot(3.0);
	double right2_x=(Selection.s_sideLenght/2.0) + (Selection.sideLenght/2.0);
	double right2_y=(Selection.s_sideLenght/2.0)*findRoot(3.0);
	int r2=1,d2=1,count2=1;
	//This loop provides  to put  triangle by horizontally and inversely in container shape rectangle in svg file.	
	while(up2_y<=(Selection.sideLenght/2.0)*findRoot(3.0)){
		while(count2<=d2){
			SvgFile <<"<polygon  points=\"" << up2_x << " " << up2_y << " " << left2_x << " " 
				<< left2_y << " "<< right2_x <<" "
				<< right2_y << "\" fill=\"green\"/> "<< endl;
			up2_x=up2_x+Selection.s_sideLenght;
			left2_x=left2_x+Selection.s_sideLenght;
			right2_x=right2_x+Selection.s_sideLenght;
			count2 ++;
		}
		//New positions of triangles is determided.
		count2=1;
		up2_x=up2_x-((d2)*Selection.s_sideLenght)-(Selection.s_sideLenght/2.0);
		up2_y=up2_y + ((Selection.s_sideLenght/2.0)*findRoot(3.0));
		left2_x=left2_x-((d2)*Selection.s_sideLenght)-(Selection.s_sideLenght/2.0);
		left2_y=left2_y + ((Selection.s_sideLenght/2.0)*findRoot(3.0));
		right2_x=right2_x-((d2)*Selection.s_sideLenght)-(Selection.s_sideLenght/2.0);
		right2_y=right2_y + ((Selection.s_sideLenght/2.0)*findRoot(3.0));
		d2++;
	}
	
	SvgFile << " </svg> " << endl;
	SvgFile.close(); //Svg file closing.

	//Number of max triangle in container shape triangle
	for(i=1;i<=temp;++i){
		numberOfTriangle=numberOfTriangle+(2*i-1);
	}
	double out_area=(Selection.sideLenght*Selection.sideLenght*findRoot(3.0))/4.0;
	double area_in=numberOfTriangle*((selected_leng*selected_leng*findRoot(3.0))/4.0);
	double area=out_area-area_in;  //Empty area.
	cout << "I can fit at most" <<  "  " << numberOfTriangle
		<<  " " <<  "small shapes into the main container."
		<< "The empty area (red) in container is" << " " << area << endl;
}
//This function calculates the number of  max rectangle and finds empty area in container triangle and produces  SVG file.
void Triangle_rectangle(ShapeFeatures& Selection){
	ofstream SvgFile;
	SvgFile.open("output.svg"); //Svg file is opening to write calculations and produce shape.
	SvgFile << "<svg version=\"1.1\" baseProfile=\"full\" width=\"100%\" height=\"100%\" xmlns=\"http://www.w3.org/2000/svg\"> " 
		<< "<polygon  points=\"" << Selection.sideLenght/2.0 << " " << 0 << " " << 0 << " " 
		<< (Selection.sideLenght/2.0)*findRoot(3.0) << " "<< Selection.sideLenght <<" "<< (Selection.sideLenght/2.0)*findRoot(3.0)  << "\" fill=\"red\"/> "<< endl;
	int hide;
	//If user enters width smaller than height,numbers are changed with each other to make processes. 
	if(Selection.s_width<Selection.s_height){
		hide=Selection.s_width;
		Selection.s_width=Selection.s_height;
		Selection.s_height=hide;
	}

	int numberOfRect1=0;
	double exact1=(Selection.s_height*findRoot(3.0))/3;
	int num_height1=(((Selection.sideLenght/2.0)*findRoot(3.0))-(Selection.s_width/2.0)*findRoot(3.0))/Selection.s_height;
	int temp1=num_height1;
	//This loop finds number of rectangles in triangle by vertically.
	while(temp1>=1){
		numberOfRect1=numberOfRect1 + ((Selection.sideLenght-(2*temp1*exact1))/Selection.s_width);
		-- temp1 ;
	}
	int numberOfRect2=0;
	double exact2=(Selection.s_width*findRoot(3.0))/3;
	int num_height2=((Selection.sideLenght/2.0)*findRoot(3.0))/Selection.s_width;
	int temp2=num_height2;
	//This loop finds number of rectangles in triangle by horizontally.
	while(temp2>=1){
		numberOfRect2=numberOfRect2 + ((Selection.sideLenght-(2*temp2*exact2))/Selection.s_height);
		-- temp2 ;
	}

	int numberOfRect_last;
	int i=1,j=1,temp=num_height1; 
	double y1=((Selection.sideLenght/2.0)*findRoot(3.0))-(num_height1*(Selection.s_height));
	double y2=((Selection.sideLenght/2.0)*findRoot(3.0))-(num_height2*(Selection.s_width));
	double y_temp1=y1;
	double y_temp2=y2;
	double x1=(Selection.sideLenght/2.0)-(y_temp1/findRoot(3.0));
	double x2=(Selection.sideLenght/2.0)-(y_temp2/findRoot(3.0));
	int temporal=num_height2;
	//If number of rectangles by vertically much than by horizontally,rectangles is placed vertically.  
	if(numberOfRect1>=numberOfRect2){
		numberOfRect_last= numberOfRect1;
		//This loop provides  to put  rectangle by vertically  in container shape triangle in svg file.	
		while(i <= num_height1){
			while(j<= ((Selection.sideLenght-(2*temp*exact1))/(Selection.s_width))){
				SvgFile << " <rect x=\"" << x1 << "\"" << " y=\""<< y1
					<< "\"" << " width=\"" <<  Selection.s_width << "\"" << " height=\"" << Selection.s_height
					<< "\""  << " fill=\"green\" " << "/>" << endl;
					x1=x1+Selection.s_width;
					++j;
			}
			j=1;
			-- temp;
			x1=((Selection.sideLenght/2.0)-(y_temp1/findRoot(3.0))-(i*exact1));
			y1=y1+Selection.s_height;
			++i;
			
		}
	}
	//If number of rectangles by horizontally much than by vertically,rectangles is placed horizontally.  
	else{
		numberOfRect_last= numberOfRect2;
		//This loop provides  to put  rectangle by horizontally  in container shape triangle in svg file.	
		while(i <= num_height2){
			while(j<= ((Selection.sideLenght-(2*temporal*exact2))/(Selection.s_height))){
				SvgFile << " <rect x=\"" << x2 << "\"" << " y=\""<< y2
					<< "\"" << " width=\"" <<  Selection.s_height << "\"" << " height=\"" << Selection.s_width
					<< "\""  << " fill=\"green\" " << "/>" << endl;
					x2=x2+Selection.s_height;
					++j;
			}
			j=1;
			-- temporal;
			x2=((Selection.sideLenght/2.0)-(y_temp2/findRoot(3.0))-(i*exact2));
			y2=y2+Selection.s_width;
			++i;
		}
		
	}
	SvgFile << " </svg> " << endl;
	SvgFile.close(); //Svg file closing.
	 
	double outArea=(Selection.sideLenght*Selection.sideLenght*findRoot(3.0))/4.0;
	double inArea=numberOfRect_last*Selection.s_height*Selection.s_width;
	double area=outArea-inArea; //Empty area.
	cout << "I can fit at most" <<  "  " << numberOfRect_last
		<<  " " <<  "small shapes into the main container."
		<< "The empty area (red) in container is" << " " << area << endl;
}
//This function calculates the number of  max circle and finds empty area in container triangle and produces  SVG file.
void Triangle_circle(ShapeFeatures& Selection){
	ofstream SvgFile; 
	SvgFile.open("output.svg"); //Svg file is opening to write calculations and produce shape.
	SvgFile << "<svg version=\"1.1\" baseProfile=\"full\" width=\"100%\" height=\"100%\" xmlns=\"http://www.w3.org/2000/svg\"> " 
		<< "<polygon  points=\"" << Selection.sideLenght/2.0 << " " << 0 << " " << 0 << " " 
		<< (Selection.sideLenght/2.0)*findRoot(3.0) << " "<< Selection.sideLenght <<" "<< (Selection.sideLenght/2.0)*findRoot(3.0)  << "\" fill=\"red\"/> "<< endl;
	int numOfCircle=0;
	int value_height=(((Selection.sideLenght/2.0)*findRoot(3.0))-(Selection.s_radius))/(2*Selection.s_radius);
	double remainder2=(2*Selection.s_radius*findRoot(3.0))/3;
	int i=value_height;
	//This loop finds number of max circles in container shape triangle.
	while(i>=1){
		numOfCircle=numOfCircle+((Selection.sideLenght-(2*i*remainder2))/(2*Selection.s_radius));
		--i;
	}
	double y=((Selection.sideLenght/2.0)*findRoot(3.0))-(value_height*(2*Selection.s_radius))+Selection.s_radius;
	double x=((Selection.sideLenght/2.0)-((2*Selection.s_radius)/findRoot(3.0)))+Selection.s_radius;
	int temporal=value_height;
	int c=1,j=1;
	//This loop provides  to put circle  in container shape triangle in svg file.	
	while(c <= value_height){
		while(j<= ((Selection.sideLenght-(2*temporal*remainder2))/(2*Selection.s_radius))){
			SvgFile << " <circle cx=\"" <<  x << "\"" << " cy=\"" << y
			<< "\"" <<" r=\"" << Selection.s_radius << "\" "<< "fill=\"green\" /> " << endl;
			x=x+(2*Selection.s_radius);
			++j;
		}
		j=1;
		-- temporal;
		x=(((Selection.sideLenght/2.0)-((2*Selection.s_radius)/findRoot(3.0)))+Selection.s_radius)-(c*remainder2);
		y=y+(2*Selection.s_radius);
		++c;
	}
	double area= ((Selection.sideLenght*Selection.sideLenght*findRoot(3.0))/4.0)-(numOfCircle*PI*Selection.s_radius*Selection.s_radius); //Empty area.
	cout << "I can fit at most" <<  "  " << numOfCircle
		<<  " " <<  "small shapes into the main container."
		<< "The empty area (red) in container is" << " " << area << endl;
	
	SvgFile << " </svg> " << endl;
	SvgFile.close(); //Svg file closing.

}
//This function calculates the number of  max triangle and finds empty area in container circle and produces  SVG file.
void Circle_triangle (ShapeFeatures& Selection){
	ofstream SvgFile;
	SvgFile.open("output.svg"); //Svg file is opening to write calculations and produce shape.
	SvgFile << "<svg version=\"1.1\" baseProfile=\"full\" width=\"100%\" height=\"100%\" xmlns=\"http://www.w3.org/2000/svg\"> " 
		 << " <circle cx=\"" <<  Selection.radius<< "\"" << " cy=\"" << Selection.radius
		<< "\"" <<" r=\"" << Selection.radius << "\" "<< "fill=\"red\" /> " << endl;

	//Starting positions of triangles.	
	double up_x=Selection.radius;
	double up_y=Selection.radius;
	double left_x=(Selection.radius)-(Selection.s_sideLenght/2.0);
	double left_y=Selection.radius +((Selection.s_sideLenght/2.0)*findRoot(3.0));
	double right_x=((Selection.radius)-(Selection.s_sideLenght/2.0))+Selection.s_sideLenght;
	double right_y=Selection.radius +((Selection.s_sideLenght/2.0)*findRoot(3.0));
	int r=1,d=1,count=1,x=1;
	//This loop provides  to put triangle by flatly in container shape circle in svg file.
	while(x <= Selection.radius/Selection.s_sideLenght){
		while(count<=d){
			SvgFile <<"\n<polygon  points=\"" << up_x << " " << up_y << " " << left_x << " " 
			<< left_y << " "<< right_x <<" "
			<< right_y << "\" fill=\"green\"/> " << endl
			<<"<polygon transform=\"rotate(-60 "<< Selection.radius << " "  << Selection.radius 
			<< ")\" points=\"" << up_x << " " << up_y 
			<< " " << left_x<< " "  << left_y << " "  << right_x << " "  << right_y << "\" fill=\"green\"/> "
			<<"<polygon transform=\"rotate(-120 "<< Selection.radius << " "  << Selection.radius 
			<< ")\" points=\"" << up_x << " " << up_y 
			<< " " << left_x<< " "  << left_y << " "  << right_x << " "  << right_y << "\" fill=\"green\"/> "
			<<"<polygon transform=\"rotate(-180 "<< Selection.radius << " "  << Selection.radius 
			<< ")\" points=\"" << up_x << " " << up_y 
			<< " " << left_x<< " "  << left_y << " "  << right_x << " "  << right_y << "\" fill=\"green\"/> "
			<<"<polygon transform=\"rotate(-240 "<< Selection.radius << " "  << Selection.radius 
			<< ")\" points=\"" << up_x << " " << up_y 
			<< " " << left_x<< " "  << left_y << " "  << right_x << " "  << right_y << "\" fill=\"green\"/> "
			<<"<polygon transform=\"rotate(-300 "<< Selection.radius << " "  << Selection.radius 
			<< ")\" points=\"" << up_x << " " << up_y 
			<< " " << left_x<< " "  << left_y << " "  << right_x << " "  << right_y << "\" fill=\"green\"/> ";
			
			up_x=up_x+Selection.s_sideLenght;
			left_x=left_x+Selection.s_sideLenght;
			right_x=right_x+Selection.s_sideLenght;
			count ++;
		}
		//New positions are determined.
		count=1;
		up_x=(Selection.radius)-d*(Selection.s_sideLenght/2.0);
		up_y=up_y + ((Selection.s_sideLenght/2.0)*findRoot(3.0));
		left_x=left_x-((d)*Selection.s_sideLenght)-(Selection.s_sideLenght/2.0);
		left_y=left_y + ((Selection.s_sideLenght/2.0)*findRoot(3.0));
		right_x=right_x-((d)*Selection.s_sideLenght)-(Selection.s_sideLenght/2.0);
		right_y=right_y + ((Selection.s_sideLenght/2.0)*findRoot(3.0));
		d++;
		++x;
	}
	double up2_x=Selection.radius;
	double up2_y=Selection.radius+(2*(Selection.s_sideLenght/2.0)*findRoot(3.0));
	double left2_x=(Selection.radius)-(Selection.s_sideLenght/2.0);
	double left2_y=Selection.radius+((Selection.s_sideLenght/2.0)*findRoot(3.0));
	double right2_x=(Selection.s_sideLenght/2.0) + (Selection.radius);
	double right2_y=Selection.radius+((Selection.s_sideLenght/2.0)*findRoot(3.0));
	int r2=1,d2=1,count2=1,x1=1;
	//This loop provides  to put triangle by inversely in container shape circle in svg file.
	while(x1 <= ((Selection.radius/Selection.s_sideLenght)-1)){
		while(count2<=d2){
			SvgFile <<"<polygon  points=\"" << up2_x << " " << up2_y << " " << left2_x << " " 
				<< left2_y << " "<< right2_x <<" "
				<< right2_y << "\" fill=\"green\"/> "<< endl
				<<"<polygon transform=\"rotate(-60 "<< Selection.radius << " "  << Selection.radius
				<< ")\" points=\"" << up2_x << " " << up2_y 
				<< " " << left2_x<< " "  << left2_y << " "  << right2_x << " "  << right2_y << "\" fill=\"green\"/> "
				<<"<polygon transform=\"rotate(-120 "<< Selection.radius << " "  << Selection.radius
				<< ")\" points=\"" << up2_x << " " << up2_y 
				<< " " << left2_x<< " "  << left2_y << " "  << right2_x << " "  << right2_y << "\" fill=\"green\"/> "
				<<"<polygon transform=\"rotate(-180 "<< Selection.radius << " "  << Selection.radius
				<< ")\" points=\"" << up2_x << " " << up2_y 
				<< " " << left2_x<< " "  << left2_y << " "  << right2_x << " "  << right2_y << "\" fill=\"green\"/> "
				<<"<polygon transform=\"rotate(-240 "<< Selection.radius << " "  << Selection.radius
				<< ")\" points=\"" << up2_x << " " << up2_y 
				<< " " << left2_x<< " "  << left2_y << " "  << right2_x << " "  << right2_y << "\" fill=\"green\"/> "
				<<"<polygon transform=\"rotate(-300 "<< Selection.radius << " "  << Selection.radius
				<< ")\" points=\"" << up2_x << " " << up2_y 
				<< " " << left2_x<< " "  << left2_y << " "  << right2_x << " "  << right2_y << "\" fill=\"green\"/> ";
		
			up2_x=up2_x+Selection.s_sideLenght;
			left2_x=left2_x+Selection.s_sideLenght;
			right2_x=right2_x+Selection.s_sideLenght;
			count2 ++;
		}
		//New positions are determind.
		count2=1;
		up2_x=up2_x-((d2)*Selection.s_sideLenght)-(Selection.s_sideLenght/2.0);
		up2_y=up2_y + ((Selection.s_sideLenght/2.0)*findRoot(3.0));
		left2_x=left2_x-((d2)*Selection.s_sideLenght)-(Selection.s_sideLenght/2.0);
		left2_y=left2_y + ((Selection.s_sideLenght/2.0)*findRoot(3.0));
		right2_x=right2_x-((d2)*Selection.s_sideLenght)-(Selection.s_sideLenght/2.0);
		right2_y=right2_y + ((Selection.s_sideLenght/2.0)*findRoot(3.0));
		d2++;
		++x1;
	}
	int numberOfTriangle,i;
	int temp=Selection.radius/Selection.s_sideLenght;

	//This loop finds number of triangles in container shape circle.
	for(i=1;i<=temp;++i){
		numberOfTriangle=numberOfTriangle+(2*i-1);
	}
	int numberOfTriangle_last=6* numberOfTriangle;
	double area=(PI*Selection.radius*Selection.radius)-(numberOfTriangle*((Selection.s_sideLenght*Selection.s_sideLenght*findRoot(3.0))/4.0)); //Empty area.
	cout << "I can fit at most" <<  "  " << numberOfTriangle_last
		<<  " " <<  "small shapes into the main container."
		<< "The empty area (red) in container is" << " " << area << endl;
	SvgFile << " </svg> " << endl;
	SvgFile.close(); //Svg file closing.

}
//This function calculates the number of  max circle and finds empty area in container circle and produces  SVG file.
void Circle_circle(ShapeFeatures& Selection){
	ofstream SvgFile;
	SvgFile.open("output.svg"); //Svg file is opening to write calculations and produce shape.
	SvgFile << "<svg version=\"1.1\" baseProfile=\"full\" width=\"100%\" height=\"100%\" xmlns=\"http://www.w3.org/2000/svg\"> " 
		 << " <circle cx=\"" <<  Selection.radius<< "\"" << " cy=\"" << Selection.radius
		<< "\"" <<" r=\"" << Selection.radius << "\" "<< "fill=\"red\" /> " << endl;
	int numOfCircle=0;
	int value_height=(((Selection.radius/2.0)*findRoot(3.0))-(Selection.s_radius))/(2*Selection.s_radius);
	int i=value_height;
	//This loop finds number of circles in container shape circle.
	while(i>=1){
		numOfCircle=numOfCircle+i;
		--i;
	}
	
	numOfCircle=6*numOfCircle+1;
	
	double y=Selection.radius+(2*Selection.s_radius);
	double x=(Selection.radius);
	double remainder=(2*Selection.s_radius*findRoot(3.0))/3;
	SvgFile << " <circle cx=\"" <<  Selection.radius << "\"" << " cy=\"" << Selection.radius //Circle that is in center is writing svg file.
		<< "\"" <<" r=\"" << Selection.s_radius << "\" "<< "fill=\"green\" />" ;
	int temporal=1;
	int c=1,j=1,restart=1;
	//This loop provides  to put circles  in container shape circle in svg file.
	while(c <= value_height){
		while(j<=restart){
			SvgFile << " <circle cx=\"" <<  x << "\"" << " cy=\"" << y
				<< "\"" <<" r=\"" << Selection.s_radius << "\" "<< "fill=\"green\" " 
				<<"transform=\"rotate(60,"<< Selection.radius << ","  << Selection.radius << ")\"/> " << endl ;
			SvgFile << " <circle cx=\"" <<  x << "\"" << " cy=\"" << y
				<< "\"" <<" r=\"" << Selection.s_radius << "\" "<< "fill=\"green\" " 
				<<"transform=\"rotate(120,"<< Selection.radius << ","  << Selection.radius << ")\"/> " << endl; 
			SvgFile << " <circle cx=\"" <<  x << "\"" << " cy=\"" << y
				<< "\"" <<" r=\"" << Selection.s_radius << "\" "<< "fill=\"green\" "
				<<"transform=\"rotate(180,"<< Selection.radius << ","  << Selection.radius << ")\"/> " << endl; 
			SvgFile << " <circle cx=\"" <<  x << "\"" << " cy=\"" << y
				<< "\"" <<" r=\"" << Selection.s_radius << "\" "<< "fill=\"green\" " 
				<<"transform=\"rotate(240,"<< Selection.radius << ","  << Selection.radius << ")\"/> " << endl ;
			SvgFile << " <circle cx=\"" <<  x << "\"" << " cy=\"" << y
				<< "\"" <<" r=\"" << Selection.s_radius << "\" "<< "fill=\"green\" " 
				<<"transform=\"rotate(300,"<< Selection.radius << ","  << Selection.radius << ")\"/> " << endl ;
			SvgFile << " <circle cx=\"" <<  x << "\"" << " cy=\"" << y
				<< "\"" <<" r=\"" << Selection.s_radius << "\" "<< "fill=\"green\" " 
				<<"transform=\"rotate(360,"<< Selection.radius << ","  << Selection.radius << ")\"/> " <<  endl ;
	
	
			x=x+2*(2*Selection.s_radius*findRoot(3.0))/3;
			++j;
		}
		restart++;
		j=1;
		++ temporal;
		x=(Selection.radius)-(c*remainder);
		y=y+(2*Selection.s_radius);
		++c;
	}
	double area=(PI*Selection.radius*Selection.radius)-numOfCircle*(PI*Selection.s_radius*Selection.s_radius); //Empty area.
	cout << "I can fit at most" <<  "  " << numOfCircle
		<<  " " <<  "small shapes into the main container." 
		<< "The empty area (red) in container is" << " " << area << endl;
	SvgFile << " </svg> " << endl;
	SvgFile.close(); //Svg file closing.

}
//This function calculates the number of  max rectangle and finds empty area in container circle and produces  SVG file.
void Circle_rectangle(ShapeFeatures& Selection){
	int temporal;
	ofstream SvgFile;
	SvgFile.open("output.svg"); //Svg file is opening to write calculations and produce shape.
	SvgFile << "<svg version=\"1.1\" baseProfile=\"full\" width=\"100%\" height=\"100%\" xmlns=\"http://www.w3.org/2000/svg\"> " 
		<< " <circle cx=\"" <<  Selection.radius<< "\"" << " cy=\"" << Selection.radius
		<< "\"" <<" r=\"" << Selection.radius << "\" "<< "fill=\"red\" /> " << endl;
	//If user enters width smaller than height,numbers are changed with each other to make processes.
	if(Selection.s_width<Selection.s_height){
		temporal=Selection.s_width;
		Selection.s_width=Selection.s_height;
		Selection.s_height=temporal;
	}
	double side=(Selection.radius)*findRoot(2.0);
	int side1 =static_cast<int>(side);
	double process1=(Selection.radius-(side/2.0)),process2=(Selection.radius-(side/2.0));
	int last_numberOfRectangle1=0;
	//This conditions provides to find max number of rectangles in container shape circle.
	int numberOfRectangle1=(side1 /Selection.s_width)*( side1 /Selection.s_height);
	if( (side1) % (Selection.s_width) >= (side1 / Selection.s_height)){
		last_numberOfRectangle1=numberOfRectangle1 + ((side/Selection.s_width)*((side1 % Selection.s_width)/Selection.s_height));
	}
	else{
		last_numberOfRectangle1=numberOfRectangle1;
	}
	//This loop provides  to put rectangles by horizontally  in container shape circle in svg file.
	while((process1+Selection.s_height) <= side+(Selection.radius-(side/2.0))){
		while((process2+Selection.s_width) <= side+(Selection.radius-(side/2.0))){
			SvgFile << " <rect x=\"" << process2 << "\"" << " y=\""<< process1 
				<< "\"" << " width=\"" <<  Selection.s_width << "\"" << " height=\"" << Selection.s_height
				<< "\""  << " fill=\"green\" " << "/>" << endl;
				process2=process2+(Selection.s_width);
		}
		process1=process1+(Selection.s_height);
		if((process1+Selection.s_height) <= side+(Selection.radius-(side/2.0))){
			process2=(Selection.radius-(side/2.0));
		}
	}
	//If there are empty area in,rectangles is placed vertically.
	if( side1 % (Selection.s_width) >= Selection.s_height){
		process1=(Selection.radius-(side/2.0));
		//This loop provides  to put rectangles by vertically in container shape circle in svg file.
		while((process1+Selection.s_width) <= side+(Selection.radius-(side/2.0))){
			while((process2+Selection.s_height) <= side+(Selection.radius-(side/2.0))){
				SvgFile << " <rect x=\"" << process2 << "\"" << " y=\""<< process1 
					<< "\"" << " width=\"" <<  Selection.s_height << "\"" << " height=\"" << Selection.s_width
					<< "\""  << " fill=\"green\" " << "/>" << endl;
					process2=process2+(Selection.s_height);
			}
			process1=process1+(Selection.s_width);
			process2=side-(side1 % Selection.s_width)+(Selection.radius-(side/2.0));
		}
	}
	SvgFile << " </svg> " << endl;
	SvgFile.close(); //Svg file closing.

	double area=(PI*Selection.radius*Selection.radius)-(Selection.s_height*Selection.s_width*last_numberOfRectangle1); //Empty area.
	cout << "I can fit at most" <<  "  " << numberOfRectangle1
		<<  " " <<  "small shapes into the main container." 
		<< "The empty area (red) in container is" << " " << area << endl;
	
}

	
	


	
	
	
	























	
	


	
	
	
	






















