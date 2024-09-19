#ifndef LINE3D_H
#define LINE3D_H
#include "Point3D.h"
#include "Line2D.h"

class Line3D : public Line2D
{
private:
    Point3D pt1;
    Point3D pt2;

protected:
    void setLength(); // defines the length of line

public:

    // Default Constructor:
    Line3D();
    // Methods:
    Line3D(Point3D pt1, Point3D pt2);

    // Getters:
    Point3D getPt1();
    Point3D getPt2();

    // Setters
    void setPt1(Point3D pt1);
    void setPt2(Point3D pt2);

    
// the operator== is a specific function name reserved for overloading the equality operator (==). 
// This operator overloading allows you to define how two objects of a user-defined type 
// (like Point2D or Point3D) should be compared for equality using the == operator.
    bool operator==(Line3D l);
};
#endif