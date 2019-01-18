/*
 * ComposedShape.cpp
 *
 *  Created on: 24,10,2018
 *      Author: Nevra Gürses
 */
#include "ComposedShape.h"
using namespace std;

// Fits small rectangles in container rectangle and returns number of max rectangle by vectorsize.
int ComposedShape::OptimalFit(Rectangle big,Rectangle small){
	int numberOfRectangle1,numberOfRectangle2,last_numberOfRectangle,last_numberOfRectangle1,last_numberOfRectangle2,temporal;
	int bigWidth= bigRect.getWidth();  // width of container rectangle.
	int bigHeight= bigRect.getHeight();  //height of container rectangle.
	int sWidth= smallRect.getSmallWidth();  // width of small rectangle.
	int sHeight=smallRect.getSmallHeight(); // height of small rectangle.
	
	// If user enters width smaller than height,numbers are changed with each other to make processes. 
	if(sWidth<sHeight){
		smallRect.setNewSmall(sHeight,sWidth); //commutative with each other by setNewSmall function in Rectangle class.
	}

	sWidth=smallRect.getSmallWidth();
	sHeight=smallRect.getSmallHeight();

	// This if-else statements calculates number of rectangles in container shape rectangle by horizontally.
	numberOfRectangle1=(bigWidth/sWidth)*(bigHeight/sHeight);
	if((bigWidth % sWidth) >= sHeight){
		last_numberOfRectangle1=numberOfRectangle1 + ((bigHeight/sWidth)*((bigWidth% sWidth)/sHeight));
	}
	else{
		last_numberOfRectangle1=numberOfRectangle1;
	}
	// This if-else statements calculates number of rectangles in container shape rectangle by vertically.
	numberOfRectangle2=((bigHeight/sWidth)*(bigWidth/sHeight));
	if((bigHeight % sWidth) >= sHeight){
		last_numberOfRectangle2=numberOfRectangle2 + ((bigWidth/sWidth)*((bigHeight % sWidth)/sHeight));
	}
	else{
		last_numberOfRectangle2=numberOfRectangle2;
	}
	auto i=0;
	int process1=0,process2=0;
	// If number of rectangle by horizontally much than vertically,rectangles are placed horizontally in container rectangle.
	if(last_numberOfRectangle1>=last_numberOfRectangle2){
		last_numberOfRectangle=last_numberOfRectangle1;
		// This loop provides  to put max rectangle by horizontally in container shape rectangle and determines positions of small rectangles.
		while((process1+sHeight) <= bigHeight){
			while((process2+sWidth) <= bigWidth){
				smallRect.setRectangle(sWidth,sHeight,process2,process1); // New positions of small rectangles are recorded by setRectangle function in Rectangle class.
				Rect_rect.push_back(smallRect); // Features and positions are registered in  rectangle type vector.
				process2=process2+(sWidth);
			}
			process1=process1+(sHeight);
			if((process1+sHeight) <= bigHeight){
				process2=0;
			}
		}
		//If the rectangles can fit remaining space by vertically,they are replaced there.
		if((bigWidth % sWidth) >= sHeight){
			process1=0;
			// This loop provides  to put  rectangle by vertically in container shape rectangle, if there are spaces.
			while((process1+sWidth) <= bigHeight){
				while((process2+sHeight) <= bigWidth){
					smallRect.setRectangle2(sWidth,sHeight,process2,process1); // New positions of small rectangles are recorded by setRectangle function in Rectangle class.
					Rect_rect.push_back(smallRect); // Features and positions are registered in  rectangle type vector.
					process2=process2+(sHeight);
				}
				process1=process1+(sWidth);
				process2=bigWidth-(bigWidth % sWidth);
				smallRect.setRectangle(sWidth,sHeight,process2,process1);
			}
		}
	}
	// If number of rectangle by vertically much than horizontally,rectangles are placed vertically in container rectangle.
	else if (last_numberOfRectangle1<last_numberOfRectangle2){
		last_numberOfRectangle=last_numberOfRectangle2;
		while((process1+sWidth) <= bigHeight){
			while((process2+sHeight) <= bigWidth){
				smallRect.setRectangle2(sWidth,sHeight,process2,process1); // New positions of small rectangles are recorded by setRectangle function in Rectangle class.
				Rect_rect.push_back(smallRect); // Features and positions are registered in  rectangle type vector.
				process2=process2+(sHeight);
			}
			process1=process1+(sWidth);
			process2=0;
			smallRect.setRectangle(sWidth,sHeight,process2,process1);
		}
		// If the rectangles can fit remaining space by horizontally,they are replaced there.
		if((bigHeight % sWidth) >= sHeight){
			// This loop provides  to put  rectangle by horizontally in container shape rectangle, if there are spaces.	
			while((process1+sHeight) <= bigHeight){
				while((process2+ sWidth) <= bigWidth){
					smallRect.setRectangle(sWidth,sHeight,process2,process1); // New positions of small rectangles are recorded by setRectangle function in Rectangle class.
					Rect_rect.push_back(smallRect); // Features and positions are registered in  rectangle type vector.
					process2=process2+(sWidth);
				}
				process1=process1+(sHeight);
				process2=0 ;
			 }	
		}
	}
	return Rect_rect.size(); // Returned max number of rectangle in rectangle by vectorsize.

	
}
// Fits small circles in container rectangle and returns number of max circle by vectorsize.
int ComposedShape::OptimalFit(Rectangle big,Circle small){
	int value_radius=smallCircle.getSmallRadius();  // radius of small circles.
	int temp1=value_radius,temp2=value_radius;
	int bigHeight= bigRect.getHeight();   //height of container rectangle.
	int bigWidth= bigRect.getWidth();     //width of container rectangle.
	//This loop provides to calcate max circle in container shape and determines the positions of small circles.
	while((temp1+value_radius) <= bigHeight){
		while((temp2+value_radius) <= bigWidth){
			smallCircle.setCircle(temp2,temp1); // New positions of small circles are  recorded by setCircle function in Circle class.
			Rect_circle.push_back(smallCircle); // Features and positions are registered in  circle type vector.
			temp2=temp2+(2*value_radius);
		}
		temp1=temp1+(2*value_radius);
		temp2=value_radius;
		
	}
	return Rect_circle.size(); // Returned max number of circle in rectangle by vectorsize.
	
}
// Fits small triangles in container rectangle and returns number of max triangle by vectorsize.
int ComposedShape::OptimalFit(Rectangle,Triangle){
	int bigHeight= bigRect.getHeight();  //height of container regtangle.
	int bigWidth= bigRect.getWidth();    //width of container regtangle.
	int s_Side=smallTriangle.getSmallSide();   //side value of small triangle.
	int numberOfTriangle1,numberOfTriangle2;
	double condition=s_Side/2.0;
	
	int remainder1,remainder2;
	//Number of triangles that don't fit into rectangle completely along width.
	if((bigWidth % s_Side) >= condition){
		remainder1=bigHeight/((s_Side/2.0)*sqrt(3.0));
		numberOfTriangle1=(bigWidth/s_Side)*2*remainder1;
	}
	//Number of triangles that  fit into rectangle completely along width.
	else{
		remainder1=bigHeight/((s_Side/2.0)*sqrt(3.0));
		numberOfTriangle1=((bigWidth/s_Side)+((bigWidth/s_Side)-1))*remainder1;
	}
	//Number of triangles that don't fit into rectangle completely along height.
	if((bigHeight % s_Side) >= condition){
		remainder2=bigWidth/((s_Side/2.0)*sqrt(3.0));
		numberOfTriangle2=(bigHeight/s_Side)*2*remainder2;
	}
	//Number of triangles that don't fit into rectangle completely height.
	else{
		remainder2=bigWidth/((s_Side/2.0)*sqrt(3.0));
		numberOfTriangle2=((bigHeight/s_Side)+((bigHeight/s_Side)-1))*remainder2;
	}
	int last_numberOfTriangle;
	//Number of triangles  into rectangle by horizontally much than vertically,they are placed horizontally.
	if(numberOfTriangle1>numberOfTriangle2){
		last_numberOfTriangle=numberOfTriangle1;
		double x1=s_Side/2.0;
		double y1=0;
		double x2=0;
		double y2=(s_Side/2.0)*sqrt(3.0);
		double x3=s_Side;
		double y3=(s_Side/2.0)*sqrt(3.0);
		//This loop provides  to put  triangle by horizontally and flaty in container shape and determined positions of small triangles.	
		while(y2<=bigHeight){
			while(x3 <= bigWidth){
				smallTriangle.setTriangle(x1,y1,x2,y2,x3,y3); // New positions of small triangles are recorded by setTriangle function in Triangle class.
				Rect_triangle.push_back(smallTriangle); // Features and positions are recorded in vector that is triangle type. 
				x1=x1+s_Side;
				x2=x2+s_Side;
				x3=x3+s_Side;
			}
			//New positions of triangles are determined.
			x1=s_Side/2.0;
			y1=y1+((s_Side/2.0)* sqrt(3.0));
			x2=0;
			y2=y2+((s_Side/2.0)* sqrt(3.0));
			x3=s_Side;	
			y3=y3+((s_Side/2.0)* sqrt(3.0));
		}
		double k1=s_Side/2.0;
		double z1=0;
		double k2=s_Side;
		double z2=(s_Side/2.0)* sqrt(3.0);
		double k3=s_Side+(s_Side/2.0);
		double z3=0;
		//This loop provides  to put  triangle by horizontally and inverselly in container shape rectangle.	
		while(z2 <= bigHeight){
			while(k3 <= bigWidth){
				smallTriangle.setTriangle(k1,z1,k2,z2,k3,z3);  // New positions of small triangles are recorded by setTriangle function in Triangle class.
				Rect_triangle.push_back(smallTriangle);    // Features and positions are recorded in vector that is triangle type. 
				k1=k1+s_Side;
				k2=k2+s_Side;
				k3=k3+s_Side;
			}
			//New positions of triangles is determided.
			k1=s_Side/2.0;
			z1=z1+((s_Side/2.0)* sqrt(3.0));
			k2=s_Side;
			z2=z2+((s_Side/2.0)*sqrt(3.0));
			k3=s_Side+(s_Side/2.0);	
			z3=z3+((s_Side/2.0)*sqrt(3.0));
		}
	}
	//Number of triangles  into rectangle by vertically much than horizontally,they are placed vertically in svg file.
	else{
		last_numberOfTriangle=numberOfTriangle2;
		double x1=0;
		double y1=s_Side/2.0;
		double x2=(s_Side/2.0)*sqrt(3.0);
		double y2=s_Side;
		double x3=(s_Side/2.0)*sqrt(3.0);
		double y3=0;
		//This loop provides  to put  triangle by vertically and flaty in container shape rectangle.	
		while(y2<=bigHeight){
			while(x2 <= bigWidth){
				smallTriangle.setTriangle(x1,y1,x2,y2,x3,y3);  // New positions of small triangles are recorded by setTriangle function in Triangle class.
				Rect_triangle.push_back(smallTriangle);  // Features and positions are recorded in vector that is triangle type. 
				x1=x1+((s_Side/2.0)* sqrt(3.0));
				x2=x2+((s_Side/2.0)*sqrt(3.0));
				x3=x3+((s_Side/2.0)*sqrt(3.0));
			}
			//New positions of triangles is determided.
			x1=0;
			y1=y1+s_Side;	
			x2=(s_Side/2.0)*sqrt(3.0);
			y2=y2+s_Side;
			x3=(s_Side/2.0)*sqrt(3.0);
			y3=y3+s_Side;
			
	
		}
		double k1=0;
		double z1=s_Side/2.0;
		double k2=0;
		double z2=s_Side+(s_Side/2.0);
		double k3=(s_Side/2.0)*sqrt(3.0);
		double z3=s_Side;
		//This loop provides  to put  triangle by vertically and inverselly in container shape rectangle.	
		while(z2<=bigHeight){
			while(k3<= bigWidth){
				smallTriangle.setTriangle(k1,z1,k2,z2,k3,z3);  // New positions of small triangles are recorded by setTriangle function in Triangle class.
				Rect_triangle.push_back(smallTriangle);  // Features and positions are recorded in vector that is triangle type. 
				k1=k1+((s_Side/2.0)*sqrt(3.0));
				k2=k2+((s_Side/2.0)*sqrt(3.0));
				k3=k3+((s_Side/2.0)*sqrt(3.0));
			}
			//New positions of triangles is determided.
			k1=0;
			z1=z1+s_Side;
			k2=0;
			z2=z2+s_Side;
			k3=(s_Side/2.0)*sqrt(3.0);
			z3=z3+s_Side;
		}
	}
	return Rect_triangle.size(); // Returned max number of triangle in rectangle by vectorsize.
	
}
// Fits small rectangles in container circle and returns number of max rectangle by vectorsize.
int ComposedShape::OptimalFit(Circle big,Rectangle small){
	int radius=bigCircle.getRadius();  // Radius of container circle.
	int s_height= smallRect.getSmallHeight();  // height of small rectangle.
	int s_width= smallRect.getSmallWidth();  //width of small rectangle.
	int temporal;
	// If user enters width smaller than height,numbers are changed with each other to make processes. 
	if(s_width<s_height){
		smallRect.setNewSmall(s_height,s_width);  //commutative with each other by setNewSmall function in Rectangle class.
	}
	s_width=smallRect.getSmallWidth();
	s_height=smallRect.getSmallHeight();
	
	double side=(radius)*sqrt(2.0);
	int side1 =static_cast<int>(side);
	double process1=(radius-(side/2.0)),process2=(radius-(side/2.0));

	//This loop provides  to put rectangles by horizontally  in container shape.
	while((process1+s_height) <= side+(radius-(side/2.0))){
		while((process2+s_width) <= side+(radius-(side/2.0))){
			smallRect.setRectangle(s_width,s_height,process2,process1); // New positions of small rectangles are recorded by setRectangle fuction in Rectangle class.
			Circle_rect.push_back(smallRect); // Features and positions of small rectangles are registered in rectangle type vector.
			process2=process2+(s_width);
		}
		process1=process1+(s_height);
		if((process1+s_height) <= side+(radius-(side/2.0))){
			process2=(radius-(side/2.0));
		}
	}
	//If there are empty area in,rectangles is placed vertically.
	if( side1 % (s_width) >= s_height){
		process1=(radius-(side/2.0));
		//This loop provides  to put rectangles by vertically in container shape.
		while((process1+s_width) <= side+(radius-(side/2.0))){
			while((process2+s_height) <= side+(radius-(side/2.0))){
				smallRect.setRectangle2(s_width,s_height,process2,process1); // New positions of small rectangles are recorded by setRectangle2 fuction in Rectangle class.
				Circle_rect.push_back(smallRect); // Features and positions of small rectangles are registered in rectangle type vector.
				process2=process2+(s_height);
			}
			process1=process1+(s_width);
			process2=side-(side1 % s_width)+(radius-(side/2.0));
			smallRect.setRectangle(s_width,s_height,process2,process1);
		}
	}
	return Circle_rect.size(); // Returned max number of rectangle in circle by vectorsize.
}
// Fits small triangles in container circle and returns number of max triangle by vectorsize.
int ComposedShape::OptimalFit(Circle big,Triangle small){
	int s_side =smallTriangle.getSmallSide();  //side lenght of small triangle.
	int radius=bigCircle.getRadius(); //radius of big circle.

	//starting positions.	
	double up_x=radius;
	double up_y=radius;
	double left_x=(radius)-(s_side/2.0);
	double left_y=radius +((s_side/2.0)*sqrt(3.0));
	double right_x=((radius)-(s_side/2.0))+s_side;
	double right_y=radius +((s_side/2.0)*sqrt(3.0));
	int r=1,d=1,count=1,x=1,c=1;
	//This loop provides  to put triangle by flatly in container shape.
	while(x <= radius/s_side){
		while(count<=d){
			
			smallTriangle.setTriangle(up_x,up_y,left_x,left_y,right_x,right_y); // new positions are recorded by setTriangle function that is in Triangle class.
			smallTriangle.setRotate(radius,radius);  // Rotating coordinates are determined by setRotate function that is in Triangle class.
			Circle_triangle.push_back(smallTriangle); // Features and positions are registered in triangle type vector.

			up_x=up_x+s_side;
			left_x=left_x+s_side;
			right_x=right_x+s_side;
			count ++;
		}
		//New positions are determined.
		count=1;
		up_x=(radius)-d*(s_side/2.0);
		up_y=up_y + ((s_side/2.0)*sqrt(3.0));
		left_x=left_x-((d)*s_side)-(s_side/2.0);
		left_y=left_y + ((s_side/2.0)*sqrt(3.0));
		right_x=right_x-((d)*s_side)-(s_side/2.0);
		right_y=right_y + ((s_side/2.0)*sqrt(3.0));
		d++;
		++x;
	}
	double up2_x=radius;
	double up2_y=radius+(2*(s_side/2.0)*sqrt(3.0));
	double left2_x=(radius)-(s_side/2.0);
	double left2_y=radius+((s_side/2.0)*sqrt(3.0));
	double right2_x=(s_side/2.0) + (radius);
	double right2_y=radius+((s_side/2.0)*sqrt(3.0));
	int r2=1,d2=1,count2=1,x1=1;
	c=1;
	//This loop provides  to put triangle by inversely in container circle.
	while(x1 <= ((radius/s_side)-1)){
		while(count2<=d2){
			smallTriangle.setTriangle(up2_x,up2_y,left2_x,left2_y,right2_x,right2_y); // new positions are recorded by setTriangle function that is in Triangle class.
			smallTriangle.setRotate(radius,radius); // Rotating coordinates are determined by setRotate function that is in Triangle class.
			Circle_triangle.push_back(smallTriangle); // Features and positions are registered in triangle type vector.
	
			up2_x=up2_x+s_side;
			left2_x=left2_x+s_side;
			right2_x=right2_x+s_side;
			count2 ++;
		}
		//New positions are determind.
		count2=1;
		up2_x=up2_x-((d2)*s_side)-(s_side/2.0);
		up2_y=up2_y + ((s_side/2.0)*sqrt(3.0));
		left2_x=left2_x-((d2)*s_side)-(s_side/2.0);
		left2_y=left2_y + ((s_side/2.0)*sqrt(3.0));
		right2_x=right2_x-((d2)*s_side)-(s_side/2.0);
		right2_y=right2_y + ((s_side/2.0)*sqrt(3.0));
		d2++;
		++x1;
	}
	return (Circle_triangle.size()*6); // Returned max number of triangles in circle by vectorsize.
}
// Fits small circles in container circle and returns number of max circle by vectorsize.
int ComposedShape::OptimalFit(Circle big,Circle small){
	int radius=bigCircle.getRadius(); // radius of container circle.
	int s_radius=smallCircle.getSmallRadius(); // radius of small circle. 
	int numOfCircle=0;
	int value_height=(((radius/2.0)*sqrt(3.0))-(s_radius))/(2*s_radius); 
	int i=value_height;
	
	double y=radius+(2*s_radius);
	double x=(radius);
	double remainder=(2*s_radius*sqrt(3.0))/3;
	int temporal=1;
	int c=1,j=1,restart=1;
	//This loop provides  to put circles  in container shape circle.
	while(c <= value_height){
		while(j<=restart){
			smallCircle.setCircle(x,y); // new positions are recorded by setCircle function that is in Circle class.
			smallCircle.setRotate(radius,radius); // Rotating coordinates are determined by setRotate function that is in Circle class.
			Circle_circle.push_back(smallCircle); // Features and positions are registered in circle type vector.
			
			x=x+2*(2*s_radius*sqrt(3.0))/3;
			++j;
		}
		restart++;
		j=1;
		++ temporal;
		x=(radius)-(c*remainder);
		y=y+(2*s_radius);
		++c;
	}
	return (Circle_circle.size()*6); // Returned max number of circles in circle by vectorsize.
}
// Fits small circles in container triangle and returns number of max circle by vectorsize.
int ComposedShape::OptimalFit(Triangle big,Circle small){
	int side = bigTriangle.getSide(); // side of container triangle.
	int s_radius=smallCircle.getSmallRadius(); // side of small radius.
	int numOfCircle=0;
	int value_height=(((side/2.0)*sqrt(3.0))-(s_radius))/(2*s_radius);
	double remainder2=(2*s_radius*sqrt(3.0))/3;
	int i=value_height;
	double y=((side/2.0)*sqrt(3.0))-(value_height*(2*s_radius))+s_radius;
	double x=((side/2.0)-((2*s_radius)/sqrt(3.0)))+s_radius;
	int temporal=value_height;
	int c=1,j=1;
	//This loop provides  to put circle  in container shape triangle.	
	while(c <= value_height){
		while(j<= ((side-(2*temporal*remainder2))/(2*s_radius))){
			smallCircle.setCircle(x,y); // new positions are recorded by setCircle function that is in Circle class.
			Triangle_circle.push_back(smallCircle); // Features and positions are registered in circle type vector.
			x=x+(2*s_radius);
			++j;
		}
		j=1;
		-- temporal;
		x=(((side/2.0)-((2*s_radius)/sqrt(3.0)))+s_radius)-(c*remainder2);
		y=y+(2*s_radius);
		++c;
	}
	return Triangle_circle.size(); // Returned max number of circles in triangle by vectorsize.
}
// Fits small triangles in container triangle and returns number of max triangle by vectorsize.
int ComposedShape::OptimalFit(Triangle big,Triangle small){
	int side = bigTriangle.getSide(); // side of container triangle.
	int s_side=smallTriangle.getSmallSide(); // side of small triangle.
	int numberOfTriangle=0,i;
	int temp=side/s_side;
	int num=((side/2.0)*sqrt(3.0))/((s_side/2.0)*sqrt(3.0));
	double up_x=side/2.0;
	double up_y=0;
	double left_x=(side/2.0)-(s_side/2.0);
	double left_y=(s_side/2.0)*sqrt(3.0);
	double right_x=(s_side/2.0) + (side/2.0);
	double right_y=(s_side/2.0)*sqrt(3.0);
	int r=1,d=1,count=1,keep=1;
	//This loop provides  to put  triangle by horizontally and flaty in container shape triangle.	
	while(keep<=num){
		while(count<=d){
			smallTriangle.setTriangle(up_x,up_y,left_x,left_y,right_x,right_y); // new positions are recorded by setTriangle function that is in Triangle class.
			Triangle_triangle.push_back(smallTriangle); // Features and positions are registered in triangle type vector.
			up_x=up_x+s_side;
			left_x=left_x+s_side;
			right_x=right_x+s_side;
			count ++;
		}
		//New positions of triangles is determided.
		count=1;
		up_x=(side/2.0)-d*(s_side/2.0);
		up_y=up_y + ((s_side/2.0)*sqrt(3.0));
		left_x=left_x-((d)*s_side)-(s_side/2.0);
		left_y=left_y + ((s_side/2.0)*sqrt(3.0));
		right_x=right_x-((d)*s_side)-(s_side/2.0);
		right_y=right_y + ((s_side/2.0)*sqrt(3.0));
		d++;
		++keep;
	}
	double up2_x=side/2.0;
	double up2_y=2*((s_side/2.0)*sqrt(3.0));
	double left2_x=(side/2.0)-(s_side/2.0);
	double left2_y=(s_side/2.0)*sqrt(3.0);
	double right2_x=(s_side/2.0) + (side/2.0);
	double right2_y=(s_side/2.0)*sqrt(3.0);
	int r2=1,d2=1,count2=1;
	keep=1;
	//This loop provides  to put  triangle by horizontally and inversely in container shape rectangle.	
	while(keep<num){
		while(count2<=d2){
			smallTriangle.setTriangle(up2_x,up2_y,left2_x,left2_y,right2_x,right2_y); // new positions are recorded by setTriangle function that is in Triangle class.
			Triangle_triangle.push_back(smallTriangle); // Features and positions are registered in triangle type vector.
			up2_x=up2_x+s_side;
			left2_x=left2_x+s_side;
			right2_x=right2_x+s_side;
			count2 ++;
		}
		//New positions of triangles is determided.
		count2=1;
		up2_x=up2_x-((d2)*s_side)-(s_side/2.0);
		up2_y=up2_y + ((s_side/2.0)*sqrt(3.0));
		left2_x=left2_x-((d2)*s_side)-(s_side/2.0);
		left2_y=left2_y + ((s_side/2.0)*sqrt(3.0));
		right2_x=right2_x-((d2)*s_side)-(s_side/2.0);
		right2_y=right2_y + ((s_side/2.0)*sqrt(3.0));
		d2++;
		++keep;
	}
	return Triangle_triangle.size(); // Returned max number of triangles in triangle by vectorsize.
	
}
// Fits small rectangles in container triangle and returns number of max rectangle by vectorsize.
int ComposedShape::OptimalFit(Triangle big,Rectangle small){
	int s_width= smallRect.getSmallWidth(); //width of small rectangle.
	int s_height= smallRect.getSmallHeight(); //height of small rectangle.
	int side = bigTriangle.getSide(); // side of container  triangle.
	//If user enters width smaller than height,numbers are changed with each other to make processes. 
	if(s_width<s_height){
		smallRect.setNewSmall(s_height,s_width);
	}
	s_width=smallRect.getSmallWidth();
	s_height=smallRect.getSmallHeight();
	int hide;

	int numberOfRect1=0;
	double exact1=(s_height*sqrt(3.0))/3;
	int num_height1=(((side/2.0)*sqrt(3.0))-(s_width/2.0)*sqrt(3.0))/s_height;
	int temp1=num_height1;
	//This loop finds number of rectangles in triangle by vertically.
	while(temp1>=1){
		numberOfRect1=numberOfRect1 + ((side-(2*temp1*exact1))/s_width);
		-- temp1 ;
	}
	int numberOfRect2=0;
	double exact2=(s_width*sqrt(3.0))/3;
	int num_height2=((side/2.0)*sqrt(3.0))/s_width;
	int temp2=num_height2;
	//This loop finds number of rectangles in triangle by horizontally.
	while(temp2>=1){
		numberOfRect2=numberOfRect2 + ((side-(2*temp2*exact2))/s_height);
		-- temp2 ;
	}
	int numberOfRect_last;
	int i=1,j=1,temp=num_height1; 
	double y1=((side/2.0)*sqrt(3.0))-(num_height1*(s_height));
	double y2=((side/2.0)*sqrt(3.0))-(num_height2*(s_width));
	double y_temp1=y1;
	double y_temp2=y2;
	double x1=(side/2.0)-(y_temp1/sqrt(3.0));
	double x2=(side/2.0)-(y_temp2/sqrt(3.0));
	int temporal=num_height2;
	//If number of rectangles by vertically much than by horizontally,rectangles is placed vertically.  
	if(numberOfRect1>=numberOfRect2){
		numberOfRect_last= numberOfRect1;
		//This loop provides  to put  rectangle by vertically  in container shape triangle.	
		while(i <= num_height1){
			while(j<= ((side-(2*temp*exact1))/(s_width))){
				smallRect.setRectangle(s_width,s_height,x1,y1); // new positions are recorded by setRectangle function that is in Rectangle class.
				Triangle_rect.push_back(smallRect); // Features and positions are registered in rectangle type vector.
				x1=x1+s_width;
				++j;
			}
			j=1;
			-- temp;
			x1=((side/2.0)-(y_temp1/sqrt(3.0))-(i*exact1));
			y1=y1+s_height;
			++i;
			
		}
	}
	//If number of rectangles by horizontally much than by vertically,rectangles is placed horizontally.  
	else{
		numberOfRect_last= numberOfRect2;
		//This loop provides  to put  rectangle by horizontally  in container shape triangle.	
		while(i <= num_height2){
			while(j<= ((side-(2*temporal*exact2))/(s_height))){
				smallRect.setRectangle2(s_width,s_height,x2,y2); // new positions are recorded by setRectangle2 function that is in Rectangle class.
				Triangle_rect.push_back(smallRect); // Features and positions are registered in rectangle type vector.
				x2=x2+s_height;
				++j;
			}
			j=1;
			-- temporal;
			x2=((side/2.0)-(y_temp2/sqrt(3.0))-(i*exact2));
			y2=y2+s_width;
			++i;
			smallRect.setRectangle(s_width,s_height,x2,y2);
		}
		
	}
	return Triangle_rect.size(); // Returned max number of rectangles in triangle by vectorsize.
}
//Draws rectangle in rectangle.
void ComposedShape::draw(ofstream &SvgFile,Rectangle big,Rectangle small){
	SvgFile.open("output1.svg");
	bigRect.setBigColor(); //Color of container rectangle is  determined by red by setBigColor function that is in Rectangle class. 
	bigRect.draw(SvgFile); //Draws container rectangle.
	int i=0;
	int end=Rect_rect.size();
	//This loop provides to draw small rectangles in container rectangle by rectangle type vector.
	while(i < end){
		Rect_rect[i].setSmallColor(); // Color of small rectangles is  determined by green by setSmallColor function that is in Rectangle class. 
		Rect_rect[i].draw(SvgFile); // Small rectangles are drawed.Their positions and features that is recorded optimalFit function  are used to do this.
		++i;
	}
	SvgFile << " </svg> " << endl;
	SvgFile.close(); 
		
}
//Draws circle in rectangle.
void ComposedShape::draw(ofstream &SvgFile,Rectangle big,Circle small){
	SvgFile.open("output2.svg");
	bigRect.setBigColor(); //Color of container rectangle is  determined by red by setBigColor function that is in Rectangle class. 
	bigRect.draw(SvgFile); //Draws container rectangle.
	int i=0;
	int end=Rect_circle.size();
	//This loop provides to draw small circles in container rectangle by circle type vector.
	while(i < end){
		Rect_circle[i].setSmallColor(); // Color of small circles is  determined by green by setSmallColor function that is in Circle class. 
		Rect_circle[i].draw(0,SvgFile); // Small circles are drawed.Their positions and features that is recorded optimalFit function  are used to do this.
		++i;
	}
	SvgFile << " </svg> " << endl;
	SvgFile.close(); 
}
//Draws triangle in rectangle.
void ComposedShape::draw(ofstream &SvgFile,Rectangle big,Triangle small){
	SvgFile.open("output3.svg");
	bigRect.setBigColor(); //Color of container rectangle is  determined by red by setBigColor function that is in Rectangle class. 
	bigRect.draw(SvgFile); //Draws container rectangle.
	int i=0;
	int end=Rect_triangle.size();
	//This loop provides to draw small triangles in container rectangle by triangle type vector.
	while(i < end){
		Rect_triangle[i].setSmallColor(); // Color of small triangles is  determined by green by setSmallColor function that is in Triangle class. 
		Rect_triangle[i].draw(0,SvgFile);  // Small triangles are drawed.Their positions and features that is recorded optimalFit function  are used to do this.
		++i;
	}
	SvgFile << " </svg> " << endl;
	SvgFile.close();
}
//Draws rectangle in triangle.
void ComposedShape::draw(ofstream &SvgFile,Triangle big,Rectangle small){
	SvgFile.open("output4.svg");
	bigTriangle.setBigColor(); //Color of container triangle is  determined by red by setBigColor function that is in Triangle class. 
	bigTriangle.draw(0,SvgFile); //Draws container triangle.
	int i=0;
	int end=Triangle_rect.size();
	//This loop provides to draw small rectangles in container triangle by rectangle type vector.
	while(i < end){
		Triangle_rect[i].setSmallColor(); // Color of small rectangles is  determined by green by setSmallColor function that is in Rectangle class. 
		Triangle_rect[i].draw(SvgFile); // Small rectangles are drawed.Their positions and features that is recorded optimalFit function  are used to do this.
		++i;
	}
	SvgFile << " </svg> " << endl;
	SvgFile.close();
		
}
//Draws triangle in triangle.
void ComposedShape::draw(ofstream &SvgFile,Triangle big,Triangle small){
	SvgFile.open("output5.svg");
	bigTriangle.setBigColor(); //Color of container triangle is  determined by red by setBigColor function that is in Triangle class. 
	bigTriangle.draw(0,SvgFile); //Draws container triangle.
	int i=0;
	int end=Triangle_triangle.size();
	//This loop provides to draw small triangles in container triangle by triangle type vector.
	while(i < end){
		Triangle_triangle[i].setSmallColor(); // Color of small triangles is  determined by green by setSmallColor function that is in Triangle class. 
		Triangle_triangle[i].draw(0,SvgFile); // Small triangles are drawed.Their positions and features that is recorded optimalFit function  are used to do this.
		++i;
	}
	SvgFile << " </svg> " << endl;
	SvgFile.close();
		
}
//Draws circles in triangle.
void ComposedShape::draw(ofstream &SvgFile,Triangle big,Circle small){
	SvgFile.open("output6.svg");
	bigTriangle.setBigColor();   //Color of container triangle is  determined by red by setBigColor function that is in Triangle class. 
	bigTriangle.draw(0,SvgFile);  //Draws container triangle.
	int i=0;
	int end=Triangle_circle.size();
	//This loop provides to draw small circles in container triangle by circle type vector.
	while(i < end){
		Triangle_circle[i].setSmallColor();  // Color of small circles is  determined by green by setSmallColor function that is in Circle class. 
		Triangle_circle[i].draw(0,SvgFile);  // Small circles are drawed.Their positions and features that is recorded optimalFit function  are used to do this.
		++i;
	}
	SvgFile << " </svg> " << endl;
	SvgFile.close();
		
}
//Draws circles in circle.
void ComposedShape::draw(ofstream &SvgFile,Circle big,Circle small){
	SvgFile.open("output7.svg");
	bigCircle.setBigColor(); //Color of container circle is  determined by red by setBigColor function that is in Triangle class. 
	bigCircle.draw(0,SvgFile); //Draws container circle.
	int i=0;
	int end=Circle_circle.size();
	//This loop provides to draw small circles in container circle by circle type vector.
	while(i < end){
		Circle_circle[i].setSmallColor(); // Color of small circles is  determined by green by setSmallColor function that is in Circle class.
		 // Small circles are drawed.Their positions and features that is recorded optimalFit function  are used to do this.Rotating is used.
		Circle_circle[i].draw(0,SvgFile);
		Circle_circle[i].draw(60,SvgFile);
		Circle_circle[i].draw(120,SvgFile);
		Circle_circle[i].draw(180,SvgFile);
		Circle_circle[i].draw(240,SvgFile);
		Circle_circle[i].draw(300,SvgFile);
		++i;
	}
	SvgFile << " </svg> " << endl;
	SvgFile.close();
		
}
//Draws triangles in circle.
void ComposedShape::draw(ofstream &SvgFile,Circle big,Triangle small){
	SvgFile.open("output8.svg");
	bigCircle.setBigColor(); //Color of container circle is  determined by red by setBigColor function that is in Circle class. 
	bigCircle.draw(0,SvgFile); //Draws container circle.
	int i=0;
	int end=Circle_triangle.size();
	//This loop provides to draw small triangles in container circle by triangle type vector.
	while(i < end){
		Circle_triangle[i].setSmallColor();  // Color of small triangles is  determined by green by setSmallColor function that is in Triangle class.
		// Small triangles are drawed.Their positions and features that is recorded optimalFit function  are used to do this.Rotating is used.
		Circle_triangle[i].draw(0,SvgFile);
		Circle_triangle[i].draw(60,SvgFile);
		Circle_triangle[i].draw(120,SvgFile);
		Circle_triangle[i].draw(180,SvgFile);
		Circle_triangle[i].draw(240,SvgFile);
		Circle_triangle[i].draw(300,SvgFile);
		++i;
	}
	SvgFile << " </svg> " << endl;
	SvgFile.close();
		
}
//Draws rectangles in circle.
void ComposedShape::draw(ofstream &SvgFile,Circle big,Rectangle small){
	SvgFile.open("output9.svg");
	bigCircle.setBigColor(); //Color of container circle is  determined by red by setBigColor function that is in Circle class. 
	bigCircle.draw(0,SvgFile); //Draws container circle.
	int i=0;
	int end=Circle_rect.size();
	//This loop provides to draw small rectangles in container circle by rectangle type vector.
	while(i < end){
		Circle_rect[i].setSmallColor();    // Color of small rectangles is  determined by green by setSmallColor function that is in Rectangle class.
		Circle_rect[i].draw(SvgFile); // Small rectangles are drawed.Their positions and features that is recorded optimalFit function  are used to do this.
		++i;
	}
	SvgFile << " </svg> " << endl;
	SvgFile.close();
		
}




