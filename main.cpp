/*
UOW Student Name: Rohit Panda
UOW Student ID: 8943060
MAJ40164 - Digital Systems Security
CSCI251 - Advanced Programming
*/


// Preprocessors Directives:
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <vector>
#include <stdio.h>


// Header Files:
#include "Point2D.h"
#include "Point3D.h"
#include "Line2D.h"
#include "Line3D.h"
#include "algorithms.h"
#include "ReadFileData.h"
#include "GraphicRepresentation.h"
#include "PrintFileData.h"
using namespace std;


//======================================================================================================================================================
// g++ -std=c++11 main.cpp Line2D.cpp Line3D.cpp Point2D.cpp Point3D.cpp PrintFileData.cpp ReadFileData.cpp algorithms.cpp -o csci251_a3.app           =
//      (for macbook: -o csci251_a3.run)                                                                                                               =
// ./csci251_a3.app                                                                                                                                    =
//      (for macbook: ./csci251_a3.run)                                                                                                                =
//                                                                                                                                                     =
//  OR... run the cmd below... after editing the Makefile accordingly...if using macbook                                                               =
//                                                                                                                                                     =
//  make                                                                                                                                               =
//                                                                                                                                                     =
//  make clean                                                                                                                                         =
//======================================================================================================================================================


// Declare Variables:
string studentID = "Student ID\t: 8943060";
string studentName = "Student Name\t: Rohit Panda";
string border = "------------------------------";

vector <Point2D> p2d_list;
vector <Point3D> p3d_list;
vector <Line2D> l2d_list;
vector <Line3D> l3d_list;


int main()
{

    // Variables to store user input and control the program flow:
    int userChoice;
    char userChoiceMenu;
    bool escape;

    // Default filter and sort criteria:
    string filter = "Point2D";
    string sort_criteria = "x-ordinate";
    string sort_order = "ASC";

    // Menu Dispalyed for user:
    while (userChoice != 8) // Continue the loop until the user chooses to quit
    {
        ClearScreen();
        cout << border << endl;
        cout << studentID << endl;
        cout << studentName << endl;
        cout << border << endl;

        cout << "Welcome to Assn3 program!" << endl;
        cout << endl;
        cout << "1)\tRead in data" << endl;
        cout << "2)\tSpecify filtering criteria (current : " << filter << ")" << endl;
        cout << "3)\tSpecify sorting criteria (current : " << sort_criteria << ")" << endl;
        cout << "4)\tSpecify sorting order (current : " << sort_order << ")" << endl;
        cout << "5)\tView data" << endl;
        cout << "6)\tStore data" << endl;
        cout << "7)\tGraphic Representation" << endl;
        cout << "8)\tQuit" << endl;


        // The line of code above is outputting:

        /*
            +--------------------------------------+
            |           Welcome to Assn3           |
            +--------------------------------------+
            | 1) Read in data                      |
            | 2) Specify filtering criteria        |
            |    (current : Point2D)               |
            | 3) Specify sorting criteria          |
            |    (current : x-ordinate)            |
            | 4) Specify sorting order             |
            |    (current : ASC)                   |
            | 5) View data                         |
            | 6) Store data                        |
            | 7) Quit                              |
            +--------------------------------------+
            Please enter your choice [1-8]: _
        */

        cout << endl;
        cout << "Please enter your choice [1-8]: ";

        // Validate user input
        while (true)
        {

            cin >> userChoice;

            if (cin.fail()) // If input is not integer
            {

                cout << "Invalid input. Please enter your choice [1-8]: ";

                // Clear error state:
                cin.clear();
                
                // Ignore invalid input:
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

            }
            else
            {

                // If the choice is not within the valid range:
                if (userChoice < 1 || userChoice > 8)
                {

                    cout << "Invalid input. Please enter your choice [1-8]: ";

                }
                else
                {
                    // If the choice is within the valid range:
                    break;

                }

            }

        }

        cout << endl;


        // Handle user choice using a switch statement:
        switch (userChoice)
        {
        case 1:
            // Read data from the file:
            ReadFileData(p2d_list, p3d_list, l2d_list, l3d_list);
            break;
        case 2:
            // Allow user to specify filtering criteria:
            cout << "[ Specifying filtering criteria (current : " << filter << ") ]" << endl;
            cout << endl;

            escape = false;
            // Loop until a valid filtering criteria is set:
            while (!escape)
            {

                cout << endl;
                cout << "    a)\tPoint2D records" << endl;
                cout << "    b)\tPoint3D records" << endl;
                cout << "    c)\tLine2D records" << endl;
                cout << "    d)\tLine3D records" << endl;
                cout << endl;
                cout << "    Please enter your criteria (a - d) : ";

        // The line of codes above is outputting:
            /*
            +--------------------------------------+
            | Specify filtering criteria (current) |
            +--------------------------------------+
            | a) Point2D records                   |
            | b) Point3D records                   |
            | c) Line2D records                    |
            | d) Line3D records                    |
            +--------------------------------------+
            Please enter your criteria (a - d): _
                    
            */

                cin >> userChoiceMenu;
                switch (userChoiceMenu)
                {
                case 'a':
                   // Set filter to Point2D and default sort criteria to x-ordinate:
                    // Set the filter to Point2D:
                    filter = "Point2D";
                    // Set the sort criteria to default (x-ordinate):
                    sort_criteria = "x-ordinate";
                    escape = true;
                    break;
                case 'b':
                    // Set the filter to Point3D:
                    filter = "Point3D";
                    // Set the sort criteria to default (x-ordinate):
                    sort_criteria = "x-ordinate";
                    escape = true;
                    break;
                case 'c':
                    // Set the filter to Line2D:
                    filter = "Line2D";
                    // Set the sort criteria to default (Pt. 1):
                    sort_criteria = "Pt. 1";
                    escape = true;
                    break;
                case 'd':
                    // Set the filter to Line3D:
                    filter = "Line3D";
                    // Set the sort criteria to default (Pt. 1):
                    sort_criteria = "Pt. 1";
                    escape = true;
                    break;
                default: 
                // If the input is not a, b, c, or d:
                    cout << "    Invalid choice" << endl;
                    break;

                }

            }

            cout << "    Filter criteria successfully set to '" << filter << "'!" << endl;

            PauseProgram(1);
            ClearScreen();

            break;
        case 3:
            // Allow user to specify sorting criteria:
            cout << "[ Specifying sorting criteria (current : " << sort_criteria << ") ]" << endl;
            cout << endl;

             // If the current filter is Point2D:
            if (filter == "Point2D")
            {

                escape = false;

                while (!escape)
                {

                    cout << endl;
                    cout << "    a)\tX ordinate value" << endl;
                    cout << "    b)\tY ordinate value" << endl;
                    cout << "    c)\tDist. Fr Origin value" << endl;
                    cout << endl;
                    cout << "    Please enter your criteria (a - c) : ";
        // The line of codes above is outputting:
            /*
            +--------------------------------------+
            | Specify sorting order (current : ASC)|
            +--------------------------------------+
            | a) ASC (Ascending order)             |
            | b) DSC (Descending order)            |
            +--------------------------------------+
            Please enter your criteria (a - b): _
                    
            */


                    cin >> userChoiceMenu;
                    switch (userChoiceMenu)
                    {
                    case 'a':
                        sort_criteria = "x-ordinate";
                        escape = true;
                        break;
                    case 'b':
                        sort_criteria = "y-ordinate";
                        escape = true;
                        break;
                    case 'c':
                        sort_criteria = "Dist. Fr Origin";
                        escape = true;
                        break;
                    default: // If the input is not a, b, or c
                        cout << "    Invalid choice" << endl;
                        break;

                    }

                }

            }
            // If the current filter is Point3D:
            else if (filter == "Point3D")
            {

                escape = false;
                while (!escape)
                {

                    cout << endl;
                    cout << "    a)\tX ordinate value" << endl;
                    cout << "    b)\tY ordinate value" << endl;
                    cout << "    c)\tZ ordinate value" << endl;
                    cout << "    d)\tDist. Fr Origin value" << endl;
                    cout << endl;
                    cout << "    Please enter your criteria (a - d) : ";
                    cin >> userChoiceMenu;
                    switch (userChoiceMenu)
                    {
                    case 'a':
                        sort_criteria = "x-ordinate";
                        escape = true;
                        break;
                    case 'b':
                        sort_criteria = "y-ordinate";
                        escape = true;
                        break;
                    case 'c':
                        sort_criteria = "z-ordinate";
                        escape = true;
                        break;
                    case 'd':
                        sort_criteria = "Dist. Fr Origin";
                        escape = true;
                        break;
                    default: // If the input is not a, b, c, or d
                        cout << "    Invalid choice" << endl;
                        break;

                    }

                }

            }
             // If the current filter is Line2D or Line3D:
            else if (filter == "Line2D" || filter == "Line3D")
            {

                escape = false;
                while (!escape)
                {

                    cout << endl;
                    cout << "    a)\tX and Y coordinate values of Pt. 1" << endl;
                    cout << "    b)\tX and Y coordinate values of Pt. 2" << endl;
                    cout << "    c)\tLength value" << endl;
                    cout << endl;
                    cout << "    Please enter your criteria (a - c) : ";

                    cin >> userChoiceMenu;
                    switch (userChoiceMenu)
                    {
                    case 'a':
                        sort_criteria = "Pt. 1";
                        escape = true;
                        break;
                    case 'b':
                        sort_criteria = "Pt. 2";
                        escape = true;
                        break;
                    case 'c':
                        sort_criteria = "Length";
                        escape = true;
                        break;
                    default: // If the input is not a, b, or c
                        cout << "    Invalid choice" << endl;
                        break;

                    }

                }

            }

            cout << "    Sorting criteria successfully set to '" << sort_criteria << "'!" << endl;
            cout << "    Going back to main menu" << endl;

            PauseProgram(1);
            ClearScreen();

            break;
        case 4:
            cout << "[ Specifying sorting order (current : " << sort_order << ") ]" << endl;
            escape = false;

            while (!escape)
            {

                cout << endl;
                cout << "    a)\tASC (Ascending order)" << endl;
                cout << "    b)\tDSC (Descending order)" << endl;
                cout << endl;
                cout << "    Please enter your criteria (a - b) : ";
                cin >> userChoiceMenu;

                switch (userChoiceMenu)
                {
                case 'a':
                    sort_order = "ASC";
                    escape = true;
                    break;
                case 'b':
                    sort_order = "DSC";
                    escape = true;
                    break;
                 // If the input is not a, b, c, or d:
                default:
                    cout << "    Invalid choice" << endl;
                    break;

                }

            }

            cout << "    Sorting order successfully set to '" << sort_order << "'!" << endl;
            break;
        case 5:
            cout << "[ View data... ]" << endl;

            // Show the current filter and sort criteria:
            cout << "Filtering criteria : " << filter << endl;
            cout << "Sorting criteria : " << sort_criteria << endl;
            cout << "Sorting order : " << sort_order << endl;
            cout << endl;

        // The line of codes BELOW is outputting:
            /*
            +--------------------------------------+
            |           Viewing Data               |
            +--------------------------------------+
            | Filtering criteria : Point2D         |
            | Sorting criteria : x-ordinate        |
            | Sorting order : ASC                  |
            +--------------------------------------+
            | Data:                                |
            | X: 1.0, Y: 2.0, Dist. Fr Origin: 2.24|
            | X: 3.0, Y: 4.0, Dist. Fr Origin: 5.0 |
            +--------------------------------------+
            Press any key to go back to main menu...

            */

            // Print the data based on the filter and sort criteria:
            if (filter == "Point2D")
            {

                cout << PrintFileData(p2d_list, sort_criteria, sort_order) << endl;

            }
            else if (filter == "Point3D")
            {

                cout << PrintFileData(p3d_list, sort_criteria, sort_order) << endl;

            }
            else if (filter == "Line2D")
            {

                cout << PrintFileData(l2d_list, sort_criteria, sort_order) << endl;

            }
            else if (filter == "Line3D")
            {

                cout << PrintFileData(l3d_list, sort_criteria, sort_order) << endl;

            }

            cout << "Press any key to go back to main menu ...";
             // Clear the input buffer:
            cin.ignore();

            while (true)
            {

                // Get a character without the need to press enter:
                system("stty raw");
                 // If any key is pressed:
                if (getchar())
                {

                    // Reset the terminal to the default mode:
                    system("stty cooked");
                    break;

                }

            }
            cout << endl;
            ClearScreen();
            break;
        case 6:
        {

        // The line of codes BELOW is outputting:
            /*
            +--------------------------------------+
            |          Storing Data to File        |
            +--------------------------------------+
            Please enter filename: data.txt
            File 'data.txt' already exists. Overwrite? (Y/N): _

            */

            // Store the data to the file:
            cout << "Please enter filename : ";
            string filename;
            cin >> filename;
            cout << endl;
            ifstream f(filename);

             // If the file already exists:
            if (f.good())
            {

                // Ask the user if they want to overwrite the file:
                cout << "File " << filename << " already exists. Are you sure to overwrite it? (Y/N) : ";
                string option;
                cin >> option;

                if (option == "y" || option == "Y" || option == "yes" || option == "YES")
                {

                    cout << endl;

                }
                else if (option == "n" || option == "N" || option == "no" || option == "NO")
                {

                    cout << endl;
                    cout << "Returning to main menu..." << endl;
                    PauseProgram(1);
                    ClearScreen();
                    break;

                }
                else
                {

                    cout << endl;
                    cout << "Unexpected input. Returning to main menu..." << endl;
                    PauseProgram(1);
                    ClearScreen();
                    break;

                }

                f.close(); // Close the file

            }
            // Open the file to write the data
            ofstream file;
            file.open(filename);
            if (file.is_open())
            {

                string result = "";
                int size = 0;

                if (filter == "Point2D")
                {

                    result = PrintFileData(p2d_list, sort_criteria, sort_order);
                    size = p2d_list.size();

                }
                else if (filter == "Point3D")
                {

                    result = PrintFileData(p3d_list, sort_criteria, sort_order);
                    size = p3d_list.size();

                }
                else if (filter == "Line2D")
                {

                    result = PrintFileData(l2d_list, sort_criteria, sort_order);
                    size = l2d_list.size();

                }
                else if (filter == "Line3D")
                {

                    result = PrintFileData(l3d_list, sort_criteria, sort_order);
                    size = l3d_list.size();

                }

                file.write(result.c_str(), result.size()); // Write the data to the file
                file.close();                              // Close the file
                cout << size << " records output successfully!" << endl;

            }
            else
            {

                cout << "Error: Unable to open file" << endl;

            }
            cout << endl;
            cout << "Going back to main menu ..." << endl;

            PauseProgram(1);
            ClearScreen();

        }
        break;
        case 7:
        ClearScreen();
        if(filter == "Point2D") {
            for(int i=0; i<p2d_list.size(); i++) {
                GenerateP2D(p2d_list[i]);
            }
        } else if(filter == "Point3D") {
            for(int i=0; i<p3d_list.size(); i++) {
                GenerateP3D(p3d_list[i]);
            }
        } else if(filter == "Line2D") {
            for(int i=0; i<l2d_list.size(); i++) {
                GenerateL2D(l2d_list[i]);
            }
        } else {
            for(int i=0; i<l3d_list.size(); i++) {
                GenerateL3D(l3d_list[i]);
            }
        }
        UserPressEnter();
        ClearScreen();
        break;
        case 8:
            cout << "[ Quitting... ]" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;

        }

        cout << endl;

    } // end of while (userChoice != 7) loop

    return 0;
}