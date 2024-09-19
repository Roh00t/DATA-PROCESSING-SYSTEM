#ifndef LINE2D_H
#define LINE2D_H
#include "Point2D.h"

class Line2D
{
private:
    Point2D pt1;
    Point2D pt2;

protected:
    double length;
    void setLength();// defines the length of line

public:

    // Default Constructors:
    Line2D();
    // Methods:
    Line2D(Point2D pt1, Point2D pt2);
    
    
    // Getters:
    Point2D getPt1();
    Point2D getPt2();
    double getScalarValue(); // sets the length of the line

    
    // Setters:
    void setPt1(Point2D pt1);
    void setPt2(Point2D pt2);

    
// the operator== is a specific function name reserved for overloading the equality operator (==). 
// This operator overloading allows you to define how two objects of a user-defined type 
// (like Point2D or Point3D) should be compared for equality using the == operator.
    bool operator==(Line2D l);
};
#endif
