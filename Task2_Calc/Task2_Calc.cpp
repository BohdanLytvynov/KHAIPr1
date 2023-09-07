//Create calc

#include <iostream>
#include "InputFunctions.h"




using namespace std;

#pragma region Enums

 /// <summary>
 /// Operation types enum
 /// </summary>
 enum struct Operation {

	add = 1, subtract, multiply, divide, unknown
};

#pragma region Operators

/// <summary>
/// Overriding of operator <<
/// </summary>
/// <param name="out">reference to ostream(output stream) object</param>
/// <param name="operation">reference to operation</param>
/// <returns>Reference to ostream(output stream)</returns>
ostream& operator <<(ostream &out, Operation &operation)
{
	switch (operation)
	{
		case Operation::add:
			out << "+";
			break;

		case Operation::subtract:
			out << "-";
			break;

		case Operation::multiply:
			out << "+";
			break;

		case Operation::divide:
			out << "/";
			break;

		case Operation::unknown:
			out << "Unknown Operation";
			break;

			return out;

	}
}

/// <summary>
/// Overriding of the operator >>
/// </summary>
/// <param name="in">Ref to inputstream object</param>
/// <param name="operation">ref to operation</param>
/// <returns>ref to inputstream</returns>
istream& operator >>(istream &in, Operation &operation)
{
	string str;

	operation = Operation::unknown;

	in >> str;

	if (str == "+")
		operation = Operation::add;
	if (str == "-")
		operation = Operation::subtract;
	if (str == "*")
		operation = Operation::multiply;
	if (str == "/")
		operation = Operation::divide;
	

	return in;
}

#pragma endregion


#pragma endregion


#pragma region Fields
//Message that asks wether to continue the app working
string contMessage = "Type 1 if you want to use calc again, and 2 if you want to exit this App.";

Operation oper;//Operation type

double num1;//1 number declare and defind with 0

double num2;//2 number declare and defind with 0


#pragma endregion

#pragma region Defines
//function that prints msg to console
#define printMsg(string) cout<<string<<endl;

#pragma endregion



#pragma region Methods


/// <summary>
/// Input type of the operation
/// </summary>
/// <param name="msg">Msg shown to user</param>
/// <param name="caseUnknown">Message when oper type is unknown</param>
/// <returns>Operation type enum</returns>
Operation InputOperationType(string msg, string caseUnknown)
{
	Operation result;

	do
	{
		printMsg(msg);

		cin >> result;

		if (result == Operation::unknown)
		{
			printMsg(caseUnknown);			
		}
			

	} while (result == Operation::unknown);

	return result;
}

#pragma endregion

/// <summary>
/// Entry point
/// </summary>
/// <returns>Code to OS wether programm executed correctly or not</returns>
int main()
{
	do
	{
		system("CLS");
		
		//Choose operaion
		oper = InputOperationType("Input Operation: + - * /", "Incorrect Input!");

		//Input first number
		num1 = InputNumber("Input first Number:", "Incorrect Input type!!!");

		//Input second number
		num2 = InputNumber("Input second Number:", "Incorrect Input type!!!");

		//Decide what oper should be performed
		switch (oper)
		{
		case Operation::add:

			cout << "Summ result:" << num1 + num2 << endl;

			break;
		case Operation::subtract:

			cout << "Subtract result:" << num1 - num2 << endl;

			break;
		case Operation::multiply:

			cout << "Multiplication result:" << num1 * num2 << endl;

			break;
		case Operation::divide:
			if(num2 != 0)//Case of 0 division!
			cout << "Division result:" << num1 / num2 << endl;
			else
			{
				cout << "Operation is Imposible! Division by 0! Result is undefined!" << endl;
			}

			break;				
		}

	} while (InputCommand(contMessage, "Incorrect input!", "Incorrect range! Type 1 or 2",1, 2) == 1);

	return 0;
}

