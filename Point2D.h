#ifndef POINT2D_H
#define POINT2D_H

class Point2D
{

protected:
    int x;
    int y;
    double distFrOrigin;

    void setDistFrOrigin(); // returns the distance from origin (Different formula from Point2D)

public:
    // Default Constructors:
    Point2D();

    // Methods:
    Point2D(int x, int y);

    // Getters:
    int getX();
    int getY();
    double getScalarValue();

    // Setters:
    void setX(int x);
    void setY(int y);
    
// the operator== is a specific function name reserved for overloading the equality operator (==). 
// This operator overloading allows you to define how two objects of a user-defined type 
// (like Point2D or Point3D) should be compared for equality using the == operator.
    bool operator==(Point2D p);

};
#endif