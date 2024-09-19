#ifndef PRINTFILEDATA_H
#define PRINTFILEDATA_H

#include "Point2D.h"
#include "Point3D.h"
#include "Line2D.h"
#include "Line3D.h"

using namespace std;

string PrintFileData(vector<Point2D> p2d_list, string sort_criteria, string sort_order);
string PrintFileData(vector<Point3D> p3d_list, string sort_criteria, string sort_order);
string PrintFileData(vector<Line2D> l2d_list, string sort_criteria, string sort_order);
string PrintFileData(vector<Line3D> l3d_list, string sort_criteria, string sort_order);
#endif