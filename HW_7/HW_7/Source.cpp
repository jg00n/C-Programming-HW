/*
*   Write a Circle class that has the following member variables:
*   double radius
*   double pi = 3.1415927
*    
*   it should have the following member functions :
*    
*   default contructor that sets radius to 0.0
*   constructor that accepts the radius of the circle as an argument.
*   setradius : a mutator that accepts the value for radiusand changes it
*   getradius : an accessor that returns the value of radius
*   getarea that returns the area of the circle(area = pi * radius * radius)
*   getcircumference that returns the circumference of the circle(circumference = 2 * pi * radius)
*    
*   write a program that remonstrates the circle class by :
*    
*       asking for the circle's radius
*       creating a circle object with that value
*       reporting the object's area
*       reporting the object's circumference
*	
*	Jonathan Goon
*	3/21/2021
* 
* 	Honor Code : "I have neither given nor received unauthorized aid in completing this work,
*	nor have I presented someone else's work as my own."
* 
*/


#include <iostream>
#include "Circle.h"
#include "IO_text.h"

int main() {
    //variable needed to store user input
    double rad;
    //variable used to handle additional input output.
    IO_text message;

    //prompt user to enter the circle radius, assigns rad.
    message.Prompt(rad, "Enter the radius of your circle: ", 0.0, 20);

    //IO_Text verifies the information before assigning rad to circle class.
    Circle circ1(rad);
    message.Prompt("A circle was created!");

    //Report the information of the circle.
    std::cout.precision(2);
    message.Prompt("\nCircle information\n");
    std::cout << "Radius: "          << std::fixed << circ1.getRadius();
    std::cout << "\nArea: "          << std::fixed << circ1.getArea();
    std::cout << "\nCircumference: " << std::fixed << circ1.getCircumfrence() << "\n";
    //End of script.
    system("pause");
    return 0;
}