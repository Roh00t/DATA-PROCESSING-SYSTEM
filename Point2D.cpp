#include <cmath>
#include "Point2D.h"


Point2D::Point2D()
{

    x = 0;
    y = 0;

    setDistFrOrigin(); // setDistFrOrigin() to set the distance from the origin

}


Point2D::Point2D(int x, int y)
{

    this->x = x;
    this->y = y;

    setDistFrOrigin(); // setDistFrOrigin() to set the distance from the origin

}


void Point2D::setDistFrOrigin()
{

    distFrOrigin = sqrt(pow(x, 2) + pow(y, 2));

}


int Point2D::getX()
{

    return x;

}


int Point2D::getY()
{

    return y;

}


double Point2D::getScalarValue()
{

    return distFrOrigin;

}


void Point2D::setX(int x)
{

    this->x = x;
    setDistFrOrigin(); // Call setDistFrOrigin() to set the distance from the origin

}


void Point2D::setY(int y)
{

    this->y = y;
    setDistFrOrigin(); // Call setDistFrOrigin() to set the distance from the origin

}


// Operator overloading
// the operator== is a specific function name reserved for overloading the equality operator (==). 
// This operator overloading allows you to define how two objects of a user-defined type 
// (like Point2D or Point3D) should be compared for equality using the == operator.
bool Point2D::operator==(Point2D p)
{

    // Compare the x and y coordinates of the two points
    return (x == p.x && y == p.y);

}



