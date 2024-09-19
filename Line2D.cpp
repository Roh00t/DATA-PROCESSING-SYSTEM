#include <cmath>
#include "Line2D.h"

Line2D::Line2D()
{

    pt1 = Point2D();
    pt2 = Point2D();

    setLength();

} // end of Line2D::Line2D()



Line2D::Line2D(Point2D pt1, Point2D pt2)
{

    this->pt1 = pt1;
    this->pt2 = pt2;

    setLength(); // call setLength() to calculate the length of the line

} // end of Line2D::Line2D(Point2D pt1, Point2D pt2)



void Line2D::setLength()
{

    length = sqrt(pow(pt2.getX() - pt1.getX(), 2) + pow(pt2.getY() - pt1.getY(), 2));

} // end of void Line2D::setLength()



Point2D Line2D::getPt1()
{

    return pt1;

} // end of Point2D Line2D::getPt1()



Point2D Line2D::getPt2()
{

    return pt2;

} // end of Point2D Line2D::getPt2()



double Line2D::getScalarValue()
{

    return length;

} // end of double Line2D::getScalarValue()



void Line2D::setPt1(Point2D pt1)
{

    this->pt1 = pt1;

    setLength(); // call setLength() to calculate the length of the line

} // end of void Line2D::setPt1(Point2D pt1)



void Line2D::setPt2(Point2D pt2)
{

    this->pt2 = pt2;

    setLength(); // call setLength() to calculate the length of the line

} // end of void Line2D::setPt2(Point2D pt2)


// the operator== is a specific function name reserved for overloading the equality operator (==). 
// This operator overloading allows you to define how two objects of a user-defined type 
// (like Line2D or Line3D) should be compared for equality using the == operator.
bool Line2D::operator==(Line2D l)
{

    // Compare the two points of the lines:
    return (pt1 == l.pt1 && pt2 == l.pt2);

} // end of bool Line2D::Comparison(Line2D l)
