/******************************************************************************
 * Bellevue Class: PROG 113
 *           Term: Spring 2015
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

// Function Prototype
void checkPassword(string);

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
*     Name							       Description
* ------------		 --------------------------------------------------------------
* checkPassword		  Validates password, reprompt until valid entry is received
*
*******************************************************************************
*/
 int main()          
{
	 // Constant "const" Value Declarations
	 const int NO_ERRORS = 0;

	 //Declare string to hold user password
	 string password;

	 //Prompt for password entry
	 cout << "Please enter a password. Password must contain:" << endl << endl;

	 //Password Requirements
	 cout << "- At least six characters" << endl;
	 cout << "- At least one uppercase and one lowercase letter" << endl;
	 cout << "- At least one digit" << endl << endl;

	 //Input form
	 cout << "Password: ";
	 getline(cin, password);
	 cout << endl;

	 //Call password validation method
	 checkPassword(password);

	// This prevents the Console Window from closing during debug mode using
	// the Visual Studio IDE.
	// Note: Generally, you should not remove this code
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nPress only the 'Enter' key to exit program: ";
	cin.get();

	return NO_ERRORS;
}

 /******************************************************************************
 * Method: checkPassword()
 *
 * Method Description
 * ------------------
 * Accepts user entered password as argument. Uses a series of bool variables as
 * flags to check for the presence of the various program requirements. Displays
 * "Valid Password!" if the user password meets the requirements. Otherwise, the
 * method displays which requirement or requirements is/are missing and prompts
 * user to enter a new password.
 *
 * Pre-Conditions
 * --------------
 * Valid string argument needs to be passed to the method
 *
 * Method Arguments
 * ----------------
 *   Type        Name                        Description
 * --------  -------------  ----------------------------------------------------
 * string	 password		User entered password
 *
 * Return Value
 * ------------
 *   None
 *
 * Invoked Methods
 * ---------------
 *  None
 *
 *******************************************************************************
 */
 void checkPassword(string password)
 {
	 // Minimum password length in charecters
	 const int MIN_PASS = 6;

	 // Declare and initialize variable to store password length
	 int pLength = NULL;

	 // Declare and initialize flags for password requirements
	 bool upper = false,
		 lower = false,
		 digit = false,
		 length = false;

	 // Overarching loop to reprompt if password is invalid
	 while ((!upper) || (!lower) || (!digit) || (pLength < MIN_PASS))
	 {
		 //Reset flags after each invalid password
		 upper = lower = digit = length = false;
		 pLength = NULL;

		 //Get password length
		 pLength = password.length();

		 //Check each character in string for presence of requirements
		 for (int count = 0; count < pLength; count++)
		 {
			 // Is there an uppercase letter?
			 if (isupper(password[count]))
				 upper = true;
			 // Is there a lower case letter?
			 if (islower(password[count]))
				 lower = true;
			 // Is there a digit?
			 if (isdigit(password[count]))
				 digit = true;
			 // Does the password meet the length requirement?
			 if (pLength >= MIN_PASS)
				 length = true;
		 }

		 // If password does not meet all of the requirements display an error
		 if ((!upper) || (!lower) || (!digit) || (pLength < MIN_PASS))
			 cout << "Error: ";

		 //Specify missing criteria
		 if (!upper)
			 cout << "Password does not contain an upper case letter." << endl;
		 if (!lower)
			 cout << "Password does not contain a lower case letter." << endl;
		 if (!digit)
			 cout << "Password does not contain a digit." << endl;
		 if (pLength < MIN_PASS)
			 cout << "Password is not at least six characters long." << endl;

		 // If password is not valid, prompt for a new entry
		 if ((!upper) || (!lower) || (!digit) || (pLength < MIN_PASS))
		 {
			 cout << endl << "Please enter another password: ";
			 getline(cin, password);
			 cout << endl;
		 }
	 }

	 // Display confirmation message
	 cout << "Valid Password!" << endl;
 }