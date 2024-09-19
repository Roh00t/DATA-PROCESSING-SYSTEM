#include <cmath>
#include "Line3D.h"

Line3D::Line3D()
{

    pt1 = Point3D();
    pt2 = Point3D();

    setLength();

} //end of Line3D::Line3D()



Line3D::Line3D(Point3D pt1, Point3D pt2) : Line2D()
{

    this->pt1 = pt1;
    this->pt2 = pt2;

    setLength(); // call setLength() to calculate the length of the line

} //end of Line3D::Line3D(Point3D pt1, Point3D pt2) : Line2D()



void Line3D::setLength()
{

    length = sqrt(pow(pt2.getX() - pt1.getX(), 2) + pow(pt2.getY() - pt1.getY(), 2) + pow(pt2.getZ() - pt1.getZ(), 2));

} //end of void Line3D::setLength()



Point3D Line3D::getPt1()
{

    return pt1;

} //end of Point3D Line3D::getPt1()



Point3D Line3D::getPt2()
{

    return pt2;

} //end of Point3D Line3D::getPt2()



void Line3D::setPt1(Point3D pt1)
{

    this->pt1 = pt1;

    setLength(); //  setLength() to calculate the length of the line

} //end of void Line3D::setPt1(Point3D pt1)



void Line3D::setPt2(Point3D pt2)
{

    this->pt2 = pt2;

    setLength(); //  setLength() to calculate the length of the line

} //end of void Line3D::setPt2(Point3D pt2)


// the operator== is a specific function name reserved for overloading the equality operator (==). 
// This operator overloading allows you to define how two objects of a user-defined type 
// (like Line2D or Line3D) should be compared for equality using the == operator.
bool Line3D::operator==(Line3D l)
{

    // Compare the two points of the lines"
    return (pt1 == l.pt1 && pt2 == l.pt2);

} //end of bool Line3D::Comparison(Line3D l)