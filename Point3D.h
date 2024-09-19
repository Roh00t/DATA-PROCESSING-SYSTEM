#ifndef POINT3D_H
#define POINT3D_H
#include "Point2D.h"

class Point3D : public Point2D
{

protected:
    int z;
    void setDistFrOrigin(); // returns the distance from origin (Different formula from Point2D)

public:
    //Default Contructors:
    Point3D();

    // Methods:
    Point3D(int x, int y, int z);

    //Getters:
    int getZ() const;

    //Setters:
    void setZ(int z);

// the operator== is a specific function name reserved for overloading the equality operator (==). 
// This operator overloading allows you to define how two objects of a user-defined type 
// (like Point2D or Point3D) should be compared for equality using the == operator.
    bool operator==(Point3D p);

};

#endif
