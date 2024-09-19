// Preprocessors Directives:
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>


// Including all Header Files:
#include "ReadFileData.h"
#include "Point2D.h"
#include "Point3D.h"
#include "Line2D.h"
#include "Line3D.h"
#include "algorithms.h"
#include "MyTemplates.h"
using namespace std;


// Fuction Prototyping:
vector<string> splitString(string line, string delimiter);
int clearDuplicates(vector<Point2D> &p2d_list, vector<Point3D> &p3d_list, vector<Line2D> &l2d_list, vector<Line3D> &l3d_list);



// Reads in File data that user provided:
void ReadFileData(vector<Point2D> & p2d_list, vector<Point3D> & p3d_list, vector<Line2D> & l2d_list, vector<Line3D> & l3d_list)
{

    cout << "Please enter filename : ";
    string filename;
    cin >> filename;

    ifstream dataFile;
    dataFile.open(filename);

    // Check if file exists:
    if (dataFile.fail())
    {

        cout << "Error: Cannot open file " << filename << endl;
        cout << "Returning to main menu " << endl;
        PauseProgram(1);
        ClearScreen();
        return;

    } // end of if statement


    int counter = 0;


    // Loop until end of file
    while (!dataFile.eof())
    {
        string line;
        getline(dataFile, line);

        if (!line.empty())
        {

            // Split the line into a vector of strings:
            vector<string> data = splitString(line, ",");

            // Check first element of vector to determine the type of data:
            // than create appropriate object:
            // than add it to appropriate list:
            if (data[0] == "Point2D")
            {

                int x = stoi(data[1].erase(0, 1));
                int y = stoi(data[2].substr(0, data[2].size() - 1));
                p2d_list.push_back(Point2D(x, y));

            }
            else if (data[0] == "Point3D")
            {

                int x = stoi(data[1].erase(0, 1));
                int y = stoi(data[2]);
                int z = stoi(data[3].substr(0, data[3].size() - 1));
                p3d_list.push_back(Point3D(x, y, z));

            }
            else if (data[0] == "Line2D")
            {

                int x1 = stoi(data[1].erase(0, 1));
                int y1 = stoi(data[2].substr(0, data[2].size() - 1));
                int x2 = stoi(data[3].erase(0, 1));
                int y2 = stoi(data[4].substr(0, data[4].size() - 1));
                l2d_list.push_back(Line2D(Point2D(x1, y1), Point2D(x2, y2)));

            }
            else if (data[0] == "Line3D")
            {

                int x1 = stoi(data[1].erase(0, 1));
                int y1 = stoi(data[2]);
                int z1 = stoi(data[3].substr(0, data[3].size() - 1));
                int x2 = stoi(data[4].erase(0, 1));
                int y2 = stoi(data[5]);
                int z2 = stoi(data[6].substr(0, data[6].size() - 1));
                l3d_list.push_back(Line3D(Point3D(x1, y1, z1), Point3D(x2, y2, z2)));

            } // end of if-else statment

            // increment the counter by 1:
            counter++;

        } // end of if (!line.empty()) statement

    } // end of while (!dataFile.eof()) statement


    // Close the file 
    dataFile.close();


    cout << endl;


    cout << counter << " records read in successfully!" << endl;

    // Clearing of duplicate lines:
    // Function returns the number of records erasedDupData:
    int erasedDupData = clearDuplicates(p2d_list, p3d_list, l2d_list, l3d_list);
    cout << erasedDupData << " duplicate records cleared." << endl;

    cout << endl;
    cout << "Going back to main menu ..." << endl;
    PauseProgram(1);
    ClearScreen();

    return;

} // end of void ReadFileData(vector<Point2D> &p2d_list, vector<Point3D> &p3d_list, vector<Line2D> &l2d_list, vector<Line3D> &l3d_list)


// This function splits string of words, based on delimiter:
vector<string> splitString(string str, string delimiter)
{

    vector<string> stringRange;
    size_t position = 0;
    string token;

    while ((position = str.find(delimiter)) != string::npos)
    {

        token = str.substr(0, position);
        stringRange.push_back(token);
        str.erase(0, position + 1);

    } // end of while loop


    if (!str.empty())
    {

        stringRange.push_back(str);

    } // end of if statment


    // Remove empty spaces:
    for (int i = 0; i < stringRange.size(); i++)
    {

        stringRange[i].erase(remove(stringRange[i].begin(), stringRange[i].end(), ' '), stringRange[i].end());

    } // end of for loop

    return stringRange;

} //end of vector<string> splitString(string str, string delimiter)


// clear duplicates lines of words inside user provided file:
int clearDuplicates(vector<Point2D> &p2d_list, vector<Point3D> &p3d_list, vector<Line2D> &l2d_list, vector<Line3D> &l3d_list)
{

    int erasedDupData = 0;
    // Loop through each list and compare each element with the other elements of file:
    // If a duplicate is found, erase it:

    for (int i = 0; i < p2d_list.size(); i++)
    {

        for (int j = i + 1; j < p2d_list.size(); j++)
        {

            if (equals<Point2D>(p2d_list[i], p2d_list[j]))
            {

                p2d_list.erase(p2d_list.begin() + j);
                erasedDupData++;

            } // end of if statment

        } // end of inner for loop

    } // end of for loop


    for (int i = 0; i < p3d_list.size(); i++)
    {

        for (int j = i + 1; j < p3d_list.size(); j++)
        {

            if (equals<Point3D>(p3d_list[i], p3d_list[j]))
            {

                p3d_list.erase(p3d_list.begin() + j);
                erasedDupData++;

            } // end of if statment

        } // end of inner for loop

    } // end of for loop


    for (int i = 0; i < l2d_list.size(); i++)
    {

        for (int j = i + 1; j < l2d_list.size(); j++)
        {

            if (equals<Line2D>(l2d_list[i], l2d_list[j]))
            {

                l2d_list.erase(l2d_list.begin() + j);
                erasedDupData++;

            } // end of if statment

        } // end of inner for loop

    } // end of for loop


    for (int i = 0; i < l3d_list.size(); i++)
    {

        for (int j = i + 1; j < l3d_list.size(); j++)
        {

            if (equals<Line3D>(l3d_list[i], l3d_list[j]))
            {

                l3d_list.erase(l3d_list.begin() + j);
                erasedDupData++;

            } // end of if statment

        } // end of inner for loop
        
    } // end of for loop

    return erasedDupData;
} // end of int clearDuplicates(vector<Point2D> &p2d_list, vector<Point3D> &p3d_list, vector<Line2D> &l2d_list, vector<Line3D> &l3d_list)