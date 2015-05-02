/******************************************************************************
 * Bellevue Class: PROG 113
 *           Term: Speing 2015
 *     Instructor: Robert Main
 *
 * Solution/Project Name: BrintonProject4
 *             File Name: Password.cpp
 *
 * This file defines the entry point method, main(), for a C++ Console
 * application. When the executable file is selected for execution, the OS
 * will transfer execution to the first line of code in method main(). Other
 * methods called from main() may be defined here as well.
 *
 * Programmer: Colin Brinton
 *
 * Assigned Project Number: 4
 *
 *
 * Revision     Date                        Release Comment
 * --------  ----------  ------------------------------------------------------
 *   1.0     05/02/2015  Initial Release
 *
 *
 * Program Inputs
 * --------------
 *  Device                              Description
 * --------  ------------------------------------------------------------------
 * Keyboard  User enters password to be verified
 *
 *
 * Program Outputs
 * ---------------
 *  Device                            Description
 * --------  ------------------------------------------------------------------
 * Monitor   Prompt user to enter password
 *			 Display password requirements
 *			 Display form to enter password
 *
 *
 * File Methods
 * ------------
 *     Name								 Description
 * ------------		 --------------------------------------------------------------
 * main				 Program entry point method
 * checkPassword	 Validates password, reprompt until valid entry is received
 *
 ******************************************************************************
 */
// External Definition files
// The first inclusion file MUST always be declared and MUST be first in the list
#include "stdafx.h"  // Defines IDE required external definition files
#include <iostream>  // Defines objects and classes used for stream I/O
#include <string>    // Needed to use string class

// Namespaces utilized in this program
using namespace std; // Announces to the compiler that members of the namespace
                     // "std" are utilized in this program

/******************************************************************************
* Method: main()
* 
* Method Description
* ------------------
* Method provides the initial prompt for user to enter a password. The password
* requirements are displayed. 
*
* Pre-Conditions
* --------------
* None
*
* Method Arguments
* ----------------
*   Type        Name                        Description
* --------  -------------  ----------------------------------------------------
*                        *** No Arguments supplied ***
*
* Return Value
* ------------
*   Type                              Description
* --------  -------------------------------------------------------------------
* int       Program execution status: 0 - No errors
*
*
* Invoked Methods
* ---------------
*     Name                             Description
* ------------  --------------------------------------------------------------
*
*******************************************************************************
*/

// Function Prototype
void checkPassword(string);

 int main()          
{
	 // Constant "const" Vlaue Declarations
	 const int NO_ERRORS = 0;

	 string password;

	 cout << "Please enter a password. Password must contain:" << endl << endl;

	 cout << "- At least six charecters" << endl;
	 cout << "- At least one uppercase and one lowercase letter" << endl;
	 cout << "- At least one digit" << endl << endl;

	 cout << "Password: ";
	 getline(cin, password);
	 cout << endl;

	 checkPassword(password);

	// This prevents the Console Window from closing during debug mode using
	// the Visual Studio IDE.
	// Note: Generally, you should not remove this code
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nPress only the 'Enter' key to exit program: ";
	cin.get();

	return NO_ERRORS;
}

 void checkPassword(string password)
 {
	 const int MIN_PASS = 6;

	 int pLength = NULL;

	 bool upper = false,
		 lower = false,
		 digit = false,
		 length = false;

	 while ((!upper) || (!lower) || (!digit) || (!digit))
	 {
		 upper = lower = digit = length = false;

		 pLength = password.length();

		 for (int count = 0; count < pLength; count++)
		 {
			 if (isupper(password[count]))
				 upper = true;
			 if (islower(password[count]))
				 lower = true;
			 if (isdigit(password[count]))
				 digit = true;
			 if (pLength >= MIN_PASS)
				 length = true;
		 }

		 if ((!upper) || (!lower) || (!digit) || (!digit))
			 cout << "Error: ";
		 if (!upper)
			 cout << "Password does not contain an upper case letter." << endl;
		 if (!lower)
			 cout << "Password does not contain a lower case letter." << endl;
		 if (!digit)
			 cout << "Passowrd does not contain a digit." << endl;
		 if (!length)
			 cout << "Password is not at least six charecters long." << endl;

		 if ((!upper) || (!lower) || (!digit) || (!digit))
		 {
			 cout << endl << "Please enter another password: ";
			 getline(cin, password);
			 cout << endl;
		 }
	 }

	 cout << "Valid Passord!" << endl;
 }