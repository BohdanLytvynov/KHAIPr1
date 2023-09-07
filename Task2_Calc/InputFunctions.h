#include <iostream>
#include <string>

using namespace std;
#ifndef INPUTFUNCTIONS_H

#define INPUTFUNCTIONS_H

#define printMsg(string) cout<<string<<endl;

//Declare functions
#pragma region Prototypes

/// <summary>
/// Write the number using cin, controls user input
/// </summary>
/// <param name="msg">Mesage for user</param>
/// <param name="ErrorMsg">Mesage when incorrect type was print to console</param>
/// <returns>Number of type double</returns>
double InputNumber(string msg, string ErrorMsg);


/// <summary>
/// Gives a possibility to input a command like a number.
/// </summary>
/// <param name="msg">Message showed to user</param>
/// <param name="incorrectTypeMsg">Message when type of input is not int</param>
/// <param name="incorrectCommandRange">message when Range of command is incorrect</param>
/// <param name="start">start of range</param>
/// <param name="end">end of range</param>
/// <returns>Integer</returns>
int InputCommand(string msg, string incorrectTypeMsg, string incorrectCommandRange, int start, int end);


#pragma endregion


#endif // !
