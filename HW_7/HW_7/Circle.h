#pragma once

/*
*	Jonathan Goon
*	3/21/2021
*
*	It should have the following member functions :
*
*	Default contructor that sets radius to 0.0
*	Constructor that accepts the radius of the circle as an argument.
*	setRadius : a mutator that accepts the value for radiusand changes it
*	getRadius : an accessor that returns the value of radius
*	getArea that returns the area of the circle(area = pi * radius * radius)
*	getCircumference that returns the circumference of the circle(circumference = 2 * pi * radius)
*
*	Write a program that remonstrates the Circle class by :
*
*    Asking for the circle's radius
*    Creating a Circle object with that value
*    Reporting the object's area
*    Reporting the object's circumference
* 
*	Honor Code : "I have neither given nor received unauthorized aid in completing this work,
*	nor have I presented someone else's work as my own."
*
*/
class Circle
{
private:
	//	double radius
	//	double pi = 3.1415927
	double radius;
	const double PI = 3.1415927;

	
public:
	//Constructors
	Circle() {
		//	Default contructor that sets radius to 0.0
		radius = 0.0;
	}
	Circle(double rads) {
		//	Constructor that accepts the radius of the circle as an argument.
		radius = rads;
	}
	//Accessors
	double getRadius() const{
		//	getRadius : an accessor that returns the value of radius.
		return radius;
	}
	double getArea() const{
		//	getArea that returns the area of the circle(area = pi * radius * radius)
		double x = PI * radius * radius;
		return x;
	}
	double getCircumfrence() const{
		//	getCircumference that returns the circumference of the circle(circumference = 2 * pi * radius)
		double c = 2 * PI * radius;
		return c;
	}
	//Mutators
	void setRadius(double rads) {
		//	setRadius : a mutator that accepts the value for radius and changes it
		radius = rads;
	}
};

