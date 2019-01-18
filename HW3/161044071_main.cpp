/*
 * 161044071_main.cpp
 *
 *  Created on: 7,11, 2018
 *      Author: Nevra
 */
#include "ComposedShape.h"
using namespace std;
int main(){

	
	ofstream SvgFile;//Rectangle,Circle,Triangle  classes objects as array.
	Rectangle rect[4]={{},{120,300,0,0},{560,345,0,0},{}};
	Triangle tri[4]={{},{290},{256},{}};
	Circle circ[4]={{},{200},{300},{}};
	
	//Test functions of Rectangle class objects.
	cout << endl << "----- RECTANGLE OBJECTS -----" << endl; 
	rect[0].setSmall(180,76);   //to initilaze small rectangle.
	cout << "Height of first rectangle : " << rect[0].getSmallHeight() << endl
             << "Width of first rectangle : " << rect[0].getSmallWidth() << endl;
	cout << "Perimeter lenght of first rectangle: " << rect[0].smallPerimeter() << endl; //Perimeter lenght of small rectangle.
	cout << "Area of first rectangle:" << rect[0].smallArea() << endl ;  //Area of small rectangle.
	rect[0].setSmallColor(); //to determine small rectangle color as green.
	cout << "Color of first rectangle: " << rect[0].getsmallColor() << " ==>'g'means that green." << endl << endl;

	cout << "Height of second rectangle  : " << rect[1].getHeight() << endl
             << "Width of second rectangle : " << rect[1].getWidth() << endl
	     << "Position on x coordinate: " << rect[1].getPos_x() << endl  // x position of container rectangle. 
       	     << "Position on y coordinate: " << rect[1].getPos_y()<< endl //y position of container rectangle.
	     << "Perimeter lenght of second rectangle :" << rect[1].bigPerimeter() << endl  //Perimeter lenght of container rectangle.
	     << "Area of second rectangle :" << rect[1].bigArea() << endl ;  //Area of container rectangle.
        rect[1].setBigColor(); //to determine big rectangle color as red.
	cout << "Color: " << rect[1].getbigColor() << " ==>'r'means that red." << endl ;

	cout << "RECTANGLE IS DRAWİNG SVG FILE BY OVERLOAD << OPERATOR" <<endl  << endl;  
	SvgFile.open("overloaded.svg");
	SvgFile << rect[1];    //Conainer rectangle is drawing svg file by overloading << operator.
	SvgFile << " </svg> " << endl;
	SvgFile.close(); 
	
	
	cout << "Height of third rectangle : " << rect[2].getHeight() << endl
             << "Width of third rectangle : " << rect[2].getWidth() << endl
	     << "Position on x coordinate: " << rect[2].getPos_x() << endl
       	     << "Position on y coordinate: " << rect[2].getPos_y()<< endl;
	cout << "Perimeter lenght of third rectangle: " << rect[2].bigPerimeter() << endl; //Perimeter lenght of container rectangle.
	cout << "Area of  third rectangle:" << rect[2].bigArea() << endl ; //Area of container rectangle.
        rect[2].setBigColor(); //to determine big rectangle color as red.
	cout << "Color: " << rect[2].getbigColor() << " ==>'r'means that red." << endl;
	cout << "RECTANGLE IS DRAWİNG SVG FILE BY OVERLOAD << OPERATOR" <<endl ;
	SvgFile.open("overloaded2.svg");
	SvgFile << rect[2];   //Conainer rectangle is drawing svg file by overloading << operator.
	SvgFile << " </svg> " << endl ;
	SvgFile.close();
	cout << endl; 
	
	Rectangle newRect = rect[2] - 10.75; //New rectangle that created by using an rectangle object and double by overloading + operator.
	cout << "AFTER THIRD RECTANGLE  OVERLOADED - OPEATOR TO CREATE NEW RECTANGLE : " << endl ;
	newRect.output();

	
	Rectangle newRect2 = rect[2] + 200.175; //New rectangle that created by using an rectangle object and double by overloading - operator.
	cout << "AFTER THIRD RECTANGLE  OVERLOADED + OPEATOR TO CREATE NEW RECTANGLE : " << endl;
	newRect2.output();
	cout << endl << endl;

	rect[3].setSmall(20,15); //to initilaze small rectangle.
	cout << "Height of fourth rectangle : " << rect[3].getSmallHeight() << endl
             << "Width of fourth rectangle : " << rect[3].getSmallWidth() << endl;
	cout << "Perimeter lenght of fourth rectangle: " << rect[3].smallPerimeter() << endl; //Perimeter lenght of small rectangle.
	cout << "Area of  fourth rectangle:" << rect[3].smallArea() << endl ; //Area of small rectangle.
	   
	rect[3].setSmallColor(); //to determine small rectangle color as green.
	cout << "color: " << rect[3].getsmallColor() << " ==>'g'means that green." << endl << endl;

	
	cout << endl;

 	cout << "TO TESTING POSITIONS OF SMALL AND BİG RECTANGLES THAT INCEREASED AND DECREASED BY 1.0 :" << endl;
	Rectangle z(50.9,30.5,10.5,12.4); ++z; //Small and container Rectangle positions after pre incrementing to testing member fuction. 
	cout << "NEW POSITIONS OF SMALL AND BIG RECTANGLES AFTER PRE INCREMENTING TO POSITIONS(50.9,30.5,10.5,12.4):"  << endl;
	z.outputUploaded() ; cout << endl;
	Rectangle r(50.9,30.5,10.5,12.4); --r; //Small and container Rectangle positions after pre decrementing to testing member fuction.
	cout << "NEW POSITIONS OF SMALL AND BIG RECTANGLES AFTER PRE DECREMENTING TO POSITIONS(50.9,30.5,10.5,12.4):"  << endl;
	r.outputUploaded() ; cout << endl;


	//comparision two rectangle by overloading operators.
	if(rect[2] == rect[3]) 
		cout << "Area of third and fourth rectangle is equal." << endl;
	else if(rect[2] != rect [3])
		cout << "Area of third and fourth rectangle is not equal." << endl;
	if(rect[2] < rect [3])
		cout << "Area of third rectangle smaller than fourth rectangle. " << endl;
	else if(rect[2] > rect [3])
		cout << "Area of third rectangle bigger than fourth rectangle." << endl << endl;

	cout << "TOTAL AREA OF RECTANGLES IN RECTANGLE ARRAY: " << Circle :: totalArea() << endl; //Total area of all rectangles in array by using static member function.
 	
	//Test functions of Triangle class objects.

   	cout << endl << "----- TRIANGLE OBJECTS -----" << endl;
	tri[0].set_smallTriangle(15);//to initilaze small triangle.
	cout << "Side of first triangle : " << tri[0].getSmallSide() << endl
	     << "Perimeter lenght of first triangle:" << tri[0].smallPerimeter() << endl //Perimeter of small triangle.
	     << "Area of first triangle:" << tri[0].smallArea() << endl ; //Area of small triangle.
	tri[0].setSmallColor();  //to determine small triangle color as green.
	cout << "Color: " << tri[0].getsmallColor() << " ==>'g'means that green." << endl << endl;

	cout << "Side of secondtriangle : " << tri[1].getSide() << endl
	     << "Perimeter lenght of second triangle:" << tri[1].bigPerimeter() << endl //perimeter lenght of container triangle.
	     << "Area of second triangle:" << tri[1].bigArea() << endl ; //area of container triangle.
	tri[1].setBigColor(); //to determine big triangle color as red.
	cout << "Color: " << tri[1].getbigColor() << " ==>'r'means that red." << endl ;
	cout << "TRIANGLE IS DRAWING SVG FILE BY OVERLOAD << OPERATOR" <<endl  << endl;
	SvgFile.open("overloaded3.svg");
	SvgFile << tri[1]; //container triangle drawing svg file by overloading << operator.
	SvgFile << " </svg> " << endl;
	SvgFile.close(); 
	
	
	cout << "Side of third triangle : " << tri[2].getSide() << endl
	      << "Perimeter lenght of third triangle:" << tri[2].bigPerimeter() << endl //perimeter lenght of container triangle.
	      << "Area of third triangle:" << tri[2].bigArea() << endl ; //area of container triangle.
        tri[2].setBigColor(); //to determine big triangle color as red.
	cout << "Color: " << tri[2].getbigColor() << " ==>'r'means that red." << endl ;

	cout << "TRIANGLE IS DRAWING SVG FILE BY OVERLOAD << OPERATOR" <<endl  << endl; 
	SvgFile.open("overloaded4.svg");
	SvgFile << tri[2]; //container triangle drawing svg file by overloading << operator.
	SvgFile << " </svg> " << endl;
	SvgFile.close(); 

	Triangle newTri = tri[2] - 5.7; //New triangle object that created by using an triangle object and double number by overloading - operator.
	cout << "AFTER THIRD TRIANGLE  OVERLOADED - OPEATOR TO CREATE NEW TRIANGLE : " << endl ;
	cout << "Side of new triangle is: " << newTri.getSide() << endl;

	
	Triangle newTri2 = tri[2] + 100.45; //New triangle object that created by using an triangle object and double number by overloading - operator.
	cout << "AFTER THIRD TRIANGLE  OVERLOADED + OPEATOR TO CREATE NEW TRIANGLE : " << endl;
	cout << "Side of new triangle is: " << newTri2.getSide() << endl;
	cout << endl << endl;

	tri[3].set_smallTriangle(10);//to initilaze small triangle.
		cout <<  "Side of fourth triangle : " << tri[3].getSmallSide() << endl 
		     << "Perimeter lenght of fourth triangle:" << tri[3].smallPerimeter() << endl //perimeter lenght of small triangle.
	             << "Area of fourth triangle:" << tri[3].smallArea() << endl ; //area of small triangle.
		tri[3].setSmallColor(); //to determine small triangle color as green.
	        cout  << "Color: " << tri[3].getsmallColor() << " ==>'g'means that green." << endl << endl;
	cout << endl;
	//comparision two triangle by overloading operators.
	if(tri[2] == tri[3])
		cout << "Area of third and fourth triangle is equal." << endl;
	else if(tri[2] != tri [3])
		cout << "Area of third and fourth triangle is not equal." << endl;
	if(tri[2] < tri [3])
		cout << "Area of third triangle smaller than fourth triangle. " << endl;
	else if(tri[2] > tri [3])
		cout << "Area of third triangle bigger than fourth triangle." << endl << endl;

	cout << "TO TESTING POSITIONS OF SMALL AND BİG TRIANGLES THAT INCEREASED AND DECREASED BY 1.0 :" << endl;
	Triangle y(5,100.0,0,0,300.4,200,300.4,12.0,0,5.0,14.0,15.0,14.0); ++y; //pre ıncreasing positions to testing member function.
	cout << "NEW POSITIONS OF SMALL AND BIG TRIANGLES AFTER PRE INCREMENTING TO POSITIONS(100.0,0,0,300.4,200,300.4,12.0,0,5.0,14.0,15.0,14.0):"  << endl;
	y.outputUploaded() ; cout << endl;
	Triangle m(5,100.0,0,0,300.4,200,300.4,12.0,0,5.0,14.0,15.0,14.0); --m; //pre decreasing positions to testing member function.
	cout << "NEW POSITIONS OF SMALL AND BIG TRIANGLES AFTER PRE DECREMENTING TO POSITIONS(100.0,0,0,300.4,200,300.4,12.0,0,5.0,14.0,15.0,14.0):"  << endl;
	m.outputUploaded() ; cout << endl;


	cout << "TOTAL AREA OF TRIANGLES IN TRIANGLE ARRAY: " << Circle :: totalArea() << endl; //Total area of all triangles in array by using static member function.

	//Test functions of Circle class objects.
	
	cout << endl << "---- CIRCLE OBJECTS -----" << endl;
	circ[0].set_smallRadius(10); //to initilaze small circle.
	cout << "Radius of first circle : " << circ[0].getSmallRadius() << endl
	     << "Perimeter lenght of first circle: " << circ[0].perimeterSmall() << endl  //perimeter lenght of small circle.
	     << "Area of first circle: " << circ[0].areaSmall() << endl ; //area of small circle.
	circ[0].setSmallColor(); //to determine small circle color as green.
	cout << "Color: " << circ[0].getsmallColor() << " ==>'g'means that green." << endl << endl;
	

	cout << "Radius of second circle : " <<  circ[1].getRadius() << endl
             << "Perimeter lenght of second circle: " << circ[1].perimeterBig() << endl //perimeter lenght of container circle.
	     << "Area of second circle: " << circ[1].areaBig() << endl ; //area o container circle.
	circ[1].setBigColor(); //to determine big circle color as red.
	cout << "Color: " << circ[1].getbigColor() << " ==>'r'means that red." << endl;
	cout << "CIRCLE IS DRAWING SVG FILE BY OVERLOAD << OPERATOR" <<endl << endl; 
	SvgFile.open("overloaded5.svg");
	SvgFile << circ[1]; //drawing container circle in svg file by overloading << operator. 
	SvgFile << " </svg> " << endl;
	SvgFile.close();  
	
	
	
	cout << "Radius of third circle : " << circ[2].getRadius() << endl
	     << "Perimeter lenght of third circle: " << circ[2].perimeterBig() << endl //perimeter lenght of container circle.
	     << "Area of third circle: " << circ[2].areaBig() << endl ; //Area of container circle.
        circ[2].setBigColor(); //to determine big circle color as red.
	cout << "Color: " << circ[2].getbigColor() << " ==>'r'means that red." << endl;
	cout << "CIRCLE IS DRAWING SVG FILE BY OVERLOAD << OPERATOR" <<endl  << endl;
	SvgFile.open("overloaded6.svg");
	SvgFile << circ[2]; //drawing container circle in svg file by overloading << operator.
	SvgFile << " </svg> " ; cout << endl;
	SvgFile.close(); 
	Circle newCircle = circ[2] - 6.7; //new circle object that created by using circle object and double number by overloading - operator.
	cout << "AFTER THIRD CIRCLE  OVERLOADED - OPEATOR TO CREATE NEW CIRCLE : " << endl ;
	cout << "Radius of new circle is: " << newCircle.getRadius() << endl;

	
	Circle newCircle2 = circ[2] + 50.45;//new circle object that created by using circle object and double number by overloading + operator.
	cout << "AFTER THIRD CIRCLE  OVERLOADED + OPEATOR TO CREATE NEW CIRCLE : " << endl;
	cout << "Radius of new circle is: " << newCircle2.getRadius() << endl;
	
	cout << endl << endl;
          
	circ[3].set_smallRadius(12); //to initilaze small circle.
		cout <<  "Radius of fourth circle : " << circ[3].getSmallRadius() << endl
		     << "Perimeter lenght of fourth circle: " << circ[3].perimeterSmall() << endl //perimeter lenght of small circle.
	             << "Area of fourth circle: " << circ[3].areaSmall() << endl ; //area of small circle.
		circ[3].setSmallColor(); //to determine small circle color as green.
	        cout  << "Color: " << circ[3].getsmallColor() << " ==>'g'means that green." << endl;
	cout << endl;
	
	cout << "TO TESTING POSITIONS OF SMALL AND BİG CIRCLES ARE INCEREASED BY 1.0 :" << endl;
	
	Circle x(20.5,20.5,10.6,10.6); ++x; //uploaded positions after pre incrementing by overloading ++ operator.
	cout << "NEW POSITIONS OF SMALL AND BIG CIRCLES AFTER PRE INCREMENTING TO POSITIONS(20.5,20,5,10.6,10.6):"  << endl;
	x.outputUploaded(); cout << endl;
	Circle l(20.5,20.5,10.6,10.6); 
	Circle p = l++; //returned positions after post incrementing by using overloading ++ operator.
	cout << "RETURNED POSITIONS OF SMALL AND BIG CIRCLES AFTER POST INCREMENTING TO POSITIONS(20.5,20,5,10.6,10.6):"  << endl;
	p.outputUploaded(); cout << endl;
	Circle t(20.5,20.5,10.6,10.6); --t; //returned positions after pre decrementing by using overloading -- operator.
	cout << "NEW POSITIONS OF SMALL AND BIG CIRCLES AFTER PRE DECREMENTING TO POSITIONS(20.5,20,5,10.6,10.6):"  << endl;
	t.outputUploaded(); cout << endl;
	Circle s(20.5,20.5,10.6,10.6);
	Circle e = s -- ; //returned positions after post decrementing by using overloading -- operator.
	cout << "RETURNED POSITIONS OF SMALL AND BIG CIRCLES AFTER POST DECREMENTING TO POSITIONS(20.5,20,5,10.6,10.6):"  << endl;
	e.outputUploaded(); cout << endl;
	
	//comparision two circle by overloading operators.
	if(circ[2] == circ[3])
		cout << "Area of third and fourth circle is equal." << endl;
	else if(circ[2] != circ [3])
		cout << "Area of third and fourth circle is not equal." << endl;
	if(circ[2] < circ [3])
		cout << "Area of third circle smaller than fourth circle. " << endl;
	else if(circ[2] > circ [3])
		cout << "Area of third circle bigger than fourth circle." << endl << endl;
	
	cout << "TOTAL AREA OF CIRCLES IN CIRCLE ARRAY: " << Circle :: totalArea() << endl << endl;

	
	

	
	//ComposedShape class objects as array.

	ComposedShape compose[10] = { { rect[2],rect[0] },{ rect[1],circ[0] },{ rect[1],tri[0] },
				     { circ[1],circ[0] },{ circ[1],rect[3] },{ circ[1],tri[3] },
				     { tri[1],rect[3] }, { tri[2],circ[3] }, { tri[2],tri[0] } };

	cout << endl;

	//Calculating and drawing svg file  operations to max number of small shape.

	cout << "--------SHAPE OPERATIONS ----------" << endl;
	cout << "Max rectangle number in container rectangle is: " << compose[0].OptimalFit(rect[2],rect[0]) << endl << endl;
	compose[0].draw(SvgFile,rect[2],rect[0]);

	cout << "Max circle number in container rectangle is: " << compose[1].OptimalFit(rect[1],circ[0]) << endl << endl;
	compose[1].draw(SvgFile,rect[1],circ[0]);

	cout << "Max triangle number in container rectangle is: " << compose[2].OptimalFit(rect[1],tri[0]) << endl << endl;
	compose[2].draw(SvgFile,rect[1],tri[0]);

	cout << "Max circle number in container circle is: " << compose[3].OptimalFit(circ[1],circ[0]) << endl << endl;
	compose[3].draw(SvgFile,circ[1],circ[0]);

	cout << "Max rectangle number in container circle is: " << compose[4].OptimalFit(circ[1],rect[3]) << endl << endl;
	compose[4].draw(SvgFile,circ[1],rect[3]);

	cout << "Max triangle number in container circle is: " << compose[5].OptimalFit(circ[1],tri[3]) << endl << endl;
	compose[5].draw(SvgFile,circ[1],tri[3]);

	cout << "Max rectangle number in container triangle is: " << compose[6].OptimalFit(tri[1],rect[3]) << endl << endl;
	compose[6].draw(SvgFile,tri[1],rect[3]);

	cout << "Max circle number in container triangle is: " << compose[7].OptimalFit(tri[2],circ[3]) << endl << endl;
	compose[7].draw(SvgFile,tri[2],circ[3]);

	cout << "Max triangle number in container triangle is: " << compose[8].OptimalFit(tri[2],tri[0]) << endl << endl;
	compose[8].draw(SvgFile,tri[2],tri[0]);

	//Testing to ShapeElem class.

	cout << "----------TESTING OPERATIONS TO SHAPEELEM CLASS----------" << endl;
	Rectangle value(200,100);	
	value.setBigColor();
	ComposedShape::ShapeElem ex(value); //initilizes ShapeElem object as rectangle.
	cout << "Area of rectangle that is sizes(200,100):" << ex.area(rectangle,&value) << endl; //area of rectangle.
	cout << "Perimeter lenght of rectangle that is sizes(200,100):" << ex.perimeter(rectangle,&value) << endl; //perimeter lenght of rectangle.
	  

	Triangle triang(10);
	ComposedShape::ShapeElem ex2(triang); //initilizes ShapeElem object as triangle.
	cout << "Area of triangle that is side lenght(10):" << ex2.area(triangle,&triang) << endl; //area of triangle.
	cout << "Perimeter lenght of triangle that is side lenght(10):" << ex2.perimeter(triangle,&triang) << endl; //perimeter lenght of triangle.

	Circle cr(20);
	ComposedShape::ShapeElem ex3(cr); //initilizes ShapeElem object as triangle.
	cout << "Area of circle that is radius(20):" << ex3.area(circle,&cr) << endl; //area of triangle.
	cout << "Perimeter lenght of circle that is radius(20):" << ex3.perimeter(circle,&cr) << endl; //perimeter lenght of triangle.*/
	cout << endl << endl;

	return 0;
 

}	



























