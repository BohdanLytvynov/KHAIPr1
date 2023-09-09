#include"InputFunctions.h"//Add all code form InputFunctions.h using preprocessing
#include <iostream>
#include<string>

#pragma region Defines

#define printMsg(string) cout<<string<<endl;

#pragma endregion

#pragma region Methods
/// <summary>
/// Checks wether the string str is digit or not
/// </summary>
/// <param name="str">String for check</param>
/// <returns>True - if str is digit</returns>
bool isNumber(string str)
{
	for (char s : str) //Iterate string [array of chars]
		if (!isdigit(s))//check if every char is digit, but we need to invert this condition
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

	for (; ;)//Infinity looping cycle, can be break from inside
	{
		printMsg(msg);

		cin >> str;//Write string into str from the input stream of the console

		if (str.empty())//Check wether string is empty
		{
			printMsg("You have input an empty value!");

			continue;//Run new iteration
		}		
		else if (!isNumber(str))//Check wether str is a number if not restart the loop of input
		{
			printMsg("Wrong input! It is not a number!");

			continue;
		}
		else		//All correct, break the infinity looping
			break;			
	}					

	return stod(str);//Convert input to double
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

	for (; ;)//Infinity looping cycle, can be break from inside
	{
		printMsg(msg);

		cin >> str;//Write string into str from the input stream of the console

		if (str.empty())//Check wether string is empty
		{
			printMsg("Empty input!");
			continue; //Run new iteration
		}
		else if(!isNumber(str))//Check wether str is a number if not restart the loop of input
		{
			printMsg(incorrectTypeMsg);
			continue;
		}
		else 
		{
			result = stoi(str);//Convert input to int

			if (result < start || result > end) // Check range start <= result <= end
			{
				printMsg(incorrectCommandRange);

				continue;
			}				
			break;//Success break the for loop and return the result
		}
	}
	
	return result;
}

#pragma endregion
