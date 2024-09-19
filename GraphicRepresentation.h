#ifndef GRAPHICREPRESENTATION_H
#define GRAPHICREPRESENTATION_H


// is designed to provide functionality related to generating and manipulating graphical representations of 2D and 3D points and lines:
// Preprocessors Directives:
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>


// Header Files:
#include "Point2D.h"
#include "Point3D.h"
#include "Line2D.h"
#include "Line3D.h"
#include "algorithms.h"
#include "GraphicRepresentation.h"


void GenerateP2D(Point2D p); // generates a graphical representation or output of a 2D point.
void GenerateP3D(Point3D p); // generates a graphical representation or output of a 3D point.
void GenerateL2D(Line2D l); //  generates a graphical representation or output of a 2D line.
void GenerateL3D(Line3D l); // generates a graphical representation or output of a 3D line.
Point2D Normalize(Point3D p); // normalizes a 3D point to a 2D point, possibly for easier graphical representation or other calculations.
#endif