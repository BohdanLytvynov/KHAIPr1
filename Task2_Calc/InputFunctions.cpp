#include"InputFunctions.h"
#include <iostream>
#include<string>

#pragma region Defines

#define printMsg(string) cout<<string<<endl;

#pragma endregion

#pragma region Methods

bool isNumber(string str)
{
	for (char s : str)
		if (!isdigit(s))
			return false;

	return true;
}

#pragma endregion


#pragma region Prototype definition

/// <summary>
/// Write the number using cin, controls user input
/// </summary>
/// <param name="msg">Mesage for user</param>
/// <param name="ErrorMsg">Mesage when incorrect type was print to console</param>
/// <returns>Number of type double</returns>
double InputNumber(string msg, string ErrorMsg)
{
	double r;

	string str("");

	for (; ;)
	{
		printMsg(msg);

		cin >> str;

		if (str.empty())
		{
			printMsg("You have input an empty value!");

			continue;
		}		
		else if (!isNumber(str))
		{
			printMsg("Wrong input! It is not a number!");

			continue;
		}
		else		
			break;			
	}					

	return stod(str);
}

/// <summary>
/// Gives a possibility to input a command like a number.
/// </summary>
/// <param name="msg">Message showed to user</param>
/// <param name="incorrectTypeMsg">Message when type of input is not int</param>
/// <param name="incorrectCommandRange">message when Range of command is incorrect</param>
/// <param name="start">start of range</param>
/// <param name="end">end of range</param>
/// <returns>Integer</returns>
int InputCommand(string msg, string incorrectTypeMsg, string incorrectCommandRange, int start, int end)
{
	int result;

	string str("");

	for (; ;)
	{
		printMsg(msg);

		cin >> str;

		if (str.empty())
		{
			printMsg("Empty input!");
			continue;
		}
		else if(!isNumber(str))
		{
			printMsg(incorrectTypeMsg);
			continue;
		}
		else 
		{
			result = stoi(str);

			if (result < start || result > end) // start <= result <= end - invert this
			{
				printMsg(incorrectCommandRange);

				continue;
			}
				

			break;
		}
	}
	
	return result;
}

#pragma endregion
