#include "InputFunctions.h"

/// <summary>
/// Write the number using cin, controls user input
/// </summary>
/// <param name="msg">Mesage for user</param>
/// <param name="ErrorMsg">Mesage when incorrect type was print to console</param>
/// <returns>Number of type double</returns>
double InputNumber(string msg, string ErrorMsg)
{
	double r;

	do
	{
		printMsg(msg);

		cin >> r;//Write value to r variable

		if (cin.fail())//if writing to r fails cause of incorrect type
		{
			printMsg(ErrorMsg);

			cin.clear();//Clear cin's error flag so we can use it again

			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');//clear input buffer

			continue;//restart while cycle iteration
		}
		else//Correct input type
		{
			break;//Stop while cycle
		}
	} while (true);

	return r;
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

	do
	{
		printMsg(msg);

		cin >> result;

		if (cin.fail())
		{
			printMsg(incorrectTypeMsg);

			cin.clear();

			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');

			continue;
		}
		else if (result < start || result > end)
		{
			printMsg(incorrectCommandRange);

			continue;
		}
		else
		{
			break;
		}

	} while (true);

	return result;
}