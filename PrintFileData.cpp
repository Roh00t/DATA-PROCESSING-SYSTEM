// Preproccessor Directives:
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>

// include header files:
#include "PrintFileData.h"
#include "MyTemplates.h"
using namespace std;


string PrintFileData(vector<Point2D> p2d_list, string sort_criteria, string sort_order)
{
    ostringstream oss; // Create an output string stream
    string results = "";

    if (sort_criteria == "x-ordinate")
    {
        if (sort_order == "ASC")
        {
            sort(p2d_list.begin(), p2d_list.end(), CompareX<Point2D, true>);
        }
        else
        {
            sort(p2d_list.begin(), p2d_list.end(), CompareX<Point2D, false>);
        }
    }
    else if (sort_criteria == "y-ordinate")
    {
        if (sort_order == "ASC")
        {
            sort(p2d_list.begin(), p2d_list.end(), CompareY<Point2D, true>);
        }
        else
        {
            sort(p2d_list.begin(), p2d_list.end(), CompareY<Point2D, false>);
        }
    }
    else if (sort_criteria == "Dist. Fr Origin")
    {
        if (sort_order == "ASC")
        {
            sort(p2d_list.begin(), p2d_list.end(), CompareScalar<Point2D, true>);
        }
        else
        {
            sort(p2d_list.begin(), p2d_list.end(), CompareScalar<Point2D, false>);
        }
    }

    // Output the data to the output string stream
    oss << setw(5) << "X" << setw(6) << "Y" << setw(4) << " "
        << "Dist. Fr Origin" << endl;
    oss << "- - - - - - - - - - - - - - - - - - -" << endl;
    for (auto p : p2d_list)
    {
        oss << "[" << setw(4) << p.getX() << ", " << setw(4) << p.getY() << "]" << setw(3) << " " << fixed << setprecision(3) << p.getScalarValue() << endl;
    }
    // Get the string from the output string stream
    results = oss.str();
    // Return the string
    return results;
}

string PrintFileData(vector<Point3D> p3d_list, string sort_criteria, string sort_order)
{
    ostringstream oss; // Create an output string stream
    string results = "";

    if (sort_criteria == "x-ordinate")
    {
        if (sort_order == "ASC")
        {
            sort(p3d_list.begin(), p3d_list.end(), CompareX<Point3D, true>);
        }
        else
        {
            sort(p3d_list.begin(), p3d_list.end(), CompareX<Point3D, false>);
        }
    }
    else if (sort_criteria == "y-ordinate")
    {
        if (sort_order == "ASC")
        {
            sort(p3d_list.begin(), p3d_list.end(), CompareY<Point3D, true>);
        }
        else
        {
            sort(p3d_list.begin(), p3d_list.end(), CompareY<Point3D, false>);
        }
    }
    else if (sort_criteria == "z-ordinate")
    {
        if (sort_order == "ASC")
        {
            sort(p3d_list.begin(), p3d_list.end(), CompareZ<Point3D, true>);
        }
        else
        {
            sort(p3d_list.begin(), p3d_list.end(), CompareZ<Point3D, false>);
        }
    }
    else if (sort_criteria == "Dist. Fr Origin")
    {
        if (sort_order == "ASC")
        {
            sort(p3d_list.begin(), p3d_list.end(), CompareScalar<Point3D, true>);
        }
        else
        {
            sort(p3d_list.begin(), p3d_list.end(), CompareScalar<Point3D, false>);
        }
    }

    // Output the data to the output string stream
    oss << setw(5) << "X" << setw(6) << "Y" << setw(6) << "Z" << setw(4) << " "
        << "Dist. Fr Origin" << endl;
    oss << "- - - - - - - - - - - - - - - - - - -" << endl;
    for (auto p : p3d_list)
    {
        oss << "[" << setw(4) << p.getX() << ", " << setw(4) << p.getY() << ", " << setw(4) << p.getZ() << "]" << setw(3) << " " << fixed << setprecision(3) << p.getScalarValue() << endl;
    }
    // Get the string from the output string stream
    results = oss.str();
    // Return the string
    return results;
}

string PrintFileData(vector<Line2D> l2d_list, string sort_criteria, string sort_order)
{
    ostringstream oss; // Create an output string stream
    string results = "";

    if (sort_criteria == "Pt. 1")
    {
        if (sort_order == "ASC")
        {
            sort(l2d_list.begin(), l2d_list.end(), CompareXandY<Line2D, true, 1>);
        }
        else
        {
            sort(l2d_list.begin(), l2d_list.end(), CompareXandY<Line2D, false, 1>);
        }
    }
    else if (sort_criteria == "Pt. 2")
    {
        if (sort_order == "ASC")
        {
            sort(l2d_list.begin(), l2d_list.end(), CompareXandY<Line2D, true, 2>);
        }
        else
        {
            sort(l2d_list.begin(), l2d_list.end(), CompareXandY<Line2D, false, 2>);
        }
    }

    else if (sort_criteria == "Length")
    {
        if (sort_order == "ASC")
        {
            sort(l2d_list.begin(), l2d_list.end(), CompareScalar<Line2D, true>);
        }
        else
        {
            sort(l2d_list.begin(), l2d_list.end(), CompareScalar<Line2D, false>);
        }
    }

    // Output the data to the output string stream
    oss << setw(5) << "P1-X" << setw(6) << "P1-Y" << setw(4) << " " << setw(5) << "P2-X" << setw(6) << "P2-Y" << setw(4) << " "
        << "Length" << endl;
    oss << "- - - - - - - - - - - - - - - - - - -" << endl;
    for (auto l : l2d_list)
    {
        oss << "[" << setw(4) << l.getPt1().getX() << ", " << setw(4) << l.getPt1().getY() << "]" << setw(3) << " "
            << "[" << setw(4) << l.getPt2().getX() << ", " << setw(4) << l.getPt2().getY() << "]" << setw(3) << " " << fixed << setprecision(3) << l.getScalarValue() << endl;
    }
    // Get the string from the output string stream
    results = oss.str();
    // Return the string
    return results;
}

string PrintFileData(vector<Line3D> l3d_list, string sort_criteria, string sort_order)
{
    ostringstream oss; // Create an output string stream
    string results = "";

    if (sort_criteria == "Pt. 1")
    {
        if (sort_order == "ASC")
        {
            sort(l3d_list.begin(), l3d_list.end(), CompareXandY<Line3D, true, 1>);
        }
        else
        {
            sort(l3d_list.begin(), l3d_list.end(), CompareXandY<Line3D, false, 1>);
        }
    }
    else if (sort_criteria == "Pt. 2")
    {
        if (sort_order == "ASC")
        {
            sort(l3d_list.begin(), l3d_list.end(), CompareXandY<Line3D, true, 2>);
        }
        else
        {
            sort(l3d_list.begin(), l3d_list.end(), CompareXandY<Line3D, false, 2>);
        }
    }

    else if (sort_criteria == "Length")
    {
        if (sort_order == "ASC")
        {
            sort(l3d_list.begin(), l3d_list.end(), CompareScalar<Line3D, true>);
        }
        else
        {
            sort(l3d_list.begin(), l3d_list.end(), CompareScalar<Line3D, false>);
        }
    }

    // Output the data to the output string stream
    oss << setw(5) << "P1-X" << setw(6) << "P1-Y" << setw(6) << "P1-Z" << setw(4) << " " << setw(5) << "P2-X" << setw(6) << "P2-Y" << setw(6) << "P2-Z" << setw(4) << " "
        << "Length" << endl;
    oss << "- - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    for (auto l : l3d_list)
    {
        oss << "[" << setw(4) << l.getPt1().getX() << ", " << setw(4) << l.getPt1().getY() << ", " << setw(4) << l.getPt1().getZ() << "]" << setw(3) << " "
            << "[" << setw(4) << l.getPt2().getX() << ", " << setw(4) << l.getPt2().getY() << ", " << setw(4) << l.getPt2().getZ() << "]" << setw(3) << " " << fixed << setprecision(3) << l.getScalarValue() << endl;
    }
    // Get the string from the output string stream
    results = oss.str();
    // Return the string
    return results;
}