/*
UOW Student Name: Rohit Panda
UOW Student ID: 8943060
MAJ40164 - Digital Systems Security
CSCI251 - Advanced Programming
*/

// Comparation between two OS system. Program will choose how to pause or clear the program.
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

// Default Preprocessor Directives:
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<iomanip>
#include<sstream>
#include<cmath>
#include "algorithms.h"
using namespace std;



//Pause Program function can run on both window and unix:
void PauseProgram(int amount)
{
#ifdef WIN32
    Sleep(amount * 1000);
#define window
#else
    sleep(amount);
#define unix
#endif
}
// Wait for user to press enter:
void UserPressEnter()
{
    string state = "1";
    cout << "Press <Enter> button to go back to the main menu..." << endl;
    cin.ignore();
    do
    {
        getline(cin, state);
    } while (state.length() != 0);
}

/* Clear screen function can run on both window and unix */
void ClearScreen()
{
#ifdef WIN32
    system("cls");
#define window
#else
    system("clear");
#define unix
#endif
}
