/*
Preston Derrig
C++ Fall 2020
Due: November 16th 2020
Lab #6 Binary To Decimal Conversion
A Program to pull binary numbers from a file and convert the binary to it correct decimal value
*/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// a function to print the binary and decimal values to the console neatly
// the decimal value and the string that has the whole binary input are passed in so they can be printed
void PrintToScreen(int DecVal, string BinaryInput); 


int main()
{
	char BinaryDigit;  // intializing variable and the input file used in the program
	string InputBinary;
	int DecimalValue = 0;
	int afterone=0;

	ifstream infile;
	infile.open("BinaryIn.dat");

	cout << "  Binary Value \t\t\t Decimal Equivalent\n";


	infile.get(BinaryDigit); // the first charater to be checked is put into the BinaryDigit variable
	while (infile) 
	{
		if (BinaryDigit == '1') // if a one is detected it change tthe decimal value correctly and it also 
		{						// set up a flag to say that the first No. 1 has been seen and binary input has begun
			InputBinary = InputBinary + BinaryDigit;
			DecimalValue = DecimalValue * 2;
			DecimalValue++;
			afterone++;
		}

		else if (BinaryDigit == '0' && afterone >= 1) // if a 0 is detect after the first No.1 it changes the decimal value
		{
			InputBinary = InputBinary + BinaryDigit;
			DecimalValue = DecimalValue * 2;
		}
		else if (BinaryDigit == '\n' && afterone >= 1) // if a new line character is found the print to screen function is called
		{											   // and it then resets all the value to be ready for the next binary number
			PrintToScreen(DecimalValue, InputBinary);
			InputBinary.erase();
			DecimalValue = 0;
			afterone = 0;
		}

		else if (BinaryDigit != '1' && BinaryDigit != '0' && afterone >= 1)  // if a non binary charater is detected after the 
		{																     // first No.1 the user is told and then all variables 
			cout << "Bad Digit in Input" << endl;							 // are cleared to prepare for the next Binary number
			InputBinary.erase();
			DecimalValue = 0;
			afterone = 0;
			infile.ignore(1000, '\n');
		}

		else if (BinaryDigit != '1' && BinaryDigit != '0' && BinaryDigit != (int)32 && afterone == 0)
		{			
			cout << "Bad Digit in Input" << endl;						// if a non binary charater that isn't a space is detected
			InputBinary.erase();										// before the first No.1 the user is told and all variables are
			DecimalValue = 0;											// cleared to prepare for the next line of input
			afterone = 0;	
			infile.ignore(1000, '\n');

		}

		infile.get(BinaryDigit); // the next charcter is read in to run the while loop again
	
	}


	infile.close(); // the infile is closed at the of the program to prevent errors
return 0; 
}


void PrintToScreen(int DecVal, string BinaryInput)
{
	int len = BinaryInput.length();
	
switch(len)
{
case 1: cout << setw(9) << BinaryInput << setw(32) << DecVal << endl;
	break;
case 2: cout << setw(10) << BinaryInput << setw(31) << DecVal << endl;
	break;
case 3: cout << setw(10) << BinaryInput << setw(31) << DecVal << endl;
	break;
case 4: cout << setw(11) << BinaryInput << setw(31) << DecVal << endl;
	break;
case 5: cout << setw(11) << BinaryInput << setw(31) << DecVal << endl;
	break;
case 6: cout << setw(12) << BinaryInput << setw(30) << DecVal << endl;
	break;
case 7: cout << setw(12) << BinaryInput << setw(30) << DecVal << endl;
	break;
case 8: cout << setw(13) << BinaryInput << setw(29) << DecVal << endl;
	break;
case 9: cout << setw(13) << BinaryInput << setw(29) << DecVal << endl;
	break;
case 10: cout << setw(14) << BinaryInput << setw(28) << DecVal << endl;
	break;
case 11: cout << setw(14) << BinaryInput << setw(29) << DecVal << endl;
	break;
case 12: cout << setw(15) << BinaryInput << setw(28) << DecVal << endl;
	break;
case 13: cout << setw(15) << BinaryInput << setw(28) << DecVal << endl;
	break;
case 14: cout << setw(16) << BinaryInput << setw(27) << DecVal << endl;
	break;
case 15: cout << setw(16) << BinaryInput << setw(27) << DecVal << endl;
	break;
case 16: cout << setw(17) << BinaryInput << setw(26) << DecVal << endl;
	break;
default: cout << "broken";
	break;
	}
}
	
