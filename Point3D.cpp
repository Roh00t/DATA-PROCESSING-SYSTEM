#include <cmath>
#include "Point3D.h"

Point3D::Point3D() : Point2D()
{
    // Set variable z to 0;
    z = 0;
    setDistFrOrigin(); // setDistFrOrigin() to set the distance from origin

} // end of Point3D::Point3D() : Point2D()


Point3D::Point3D(int x, int y, int z) : Point2D(x, y)
{

    this->z = z;
    setDistFrOrigin(); // Call setDistFrOrigin() to set the distance from the origin

} // end of  Point3D::Point3D(int x, int y, int z) : Point2D(x, y)


void Point3D::setDistFrOrigin()
{

    this->distFrOrigin = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));

} // end of  void Point3D::setDistFrOrigin()


int Point3D::getZ() const
{

    return z;

} // end of  int Point3D::getZ() const


void Point3D::setZ(int z)
{

    this->z = z;
    setDistFrOrigin(); // setDistFrOrigin() to set the distance from the origin

} // end of  void Point3D::setZ(int z)



// the operator== is a specific function name reserved for overloading the equality operator (==). 
// This operator overloading allows you to define how two objects of a user-defined type 
// (like Point2D or Point3D) should be compared for equality using the == operator.
bool Point3D::operator==(Point3D p)
{

    // Compare the x, y, and z coordinates of the two points
    return (x == p.x && y == p.y && z == p.z);

}// end of bool Point3D::Comparison(Point3D p)