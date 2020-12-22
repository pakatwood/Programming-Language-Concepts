// CS4303 Programming Language Concepts
// Lab exercise - Parser
//
// Name Haider Qazi 
// ID 1453851
// A simple parser for C/C++-style variable declarations.
// THe grammar is as follows:
//
// <declaration> 	::= 	<type>  <var> ';' | <type> <var> '=' <number> ';'
// <type> 		::= 	int | float
// <var> 		::= 	A | B | C | D | E
// <number> 	::= 	<integer> | <float>
// <integer> 	::= 	<integer> <digit> | <digit>
// <digit> 		::= 	0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
// <float> 		::= 	<integer> '.' <integer>
// 
// Input is entered at the keyboard.
// If the input is correct, the program should print
// "no error found", otherwise, it should print the type
// of error and terminate its execution. There are four
// possible errors:
// 
// "unrecognizable type"
// "illegal variable name"
// "unexpected number"
// "; expected"
//
// Error message is printed out by calling function 
// "error". An error code ranging from 0 to 4 can be
// passed as an argument to the function indicating what
// message is to be printed. The mapping from the error
// code to the message can be found by looking at the
// definition of function "error".
//
// The following are some sample input and the response
// from the program:
//
// Please enter a declaration in format <type> <variable> [= number] ;
// int A;
// no error found
//
// Please enter a declaration in format <type> <variable> [= number] ;
// int a;
// illegal variable name
//
// Please enter a declaration in format <type> <variable> [= number] ;
// short B;
// unrecognizable type
// 
// Please enter a declaration in format <type> <variable> [= number] ;
// float C = 0.5;
// no error found
// 
// Please enter a declaration in format <type> <variable> [= number] ;
// int A = 10,
// ; expected
//
// float C = ;
// unexpected number
//
// float D = 2;
// no errors found
//
// int E = 2.2;
// no errors found
//
// float B 40.5;
// ; expected
//
// Other sample input:
//		float B;
//		float C=0.2;
//		short D;
//		float F;
//
// The last two sample inputs should generate errors because "short" and "F" are
// not acceptable tokens.

#include <iostream>
#include <string>

using namespace std;

string GetToken();
void error(int);


string GetToken() {

	string token;
	bool goToken = true;
	char ch;

	while (goToken == true)
	{
		cin.get(ch);

		while (ch == ' ')
		{
			cin.get(ch);
		}
		if (isdigit(ch))
		{
			while (isdigit(ch))
			{
				token = token + ch;
				cin.get(ch);
				if (ch == '.')
				{
					token = token + ch;
					cin.get(ch);
				}
				if (ch == ';')
				{
					token = token + '\n' + ch;
					cin.get(ch);
				}
				if (ch == '#')
				{
					//token = token + '\n' + ch + ':' + " Error: Unrecognizable token";
				}
			}
			goToken = false;
		}
		else
		{
			token = token + ch;
			if (token == "i")
			{
				goToken = true;
			}
			else if (token == "in")
			{
				goToken = true;
			}
			else if (token == "int")
			{
				goToken = false;
			}
			else if (token == "f")
			{
				goToken = true;
			}
			else if (token == "fl")
			{
				goToken = true;
			}
			else if (token == "flo")
			{
				goToken = true;
			}
			else if (token == "floa")
			{
				goToken = true;
			}
			else if (token == "float")
			{
				goToken = false;
			}
			else if (token == "A" || token == "B" || token == "C" || token == "D" || token == "E")
			{
				goToken = false;
			}
			else if (token == "=")
			{
				goToken = false;
			}
			else if (token == ";")
			{

				goToken = false;
			}
			else if (token == "\n")
			{
				token = "";
				goToken = false;
			}
			else
			{
				//token = token + ':' + " Error: Unrecognizable token";
				goToken = false;
			}
		}

	}
	return token;
}

void error(int code) {
	switch (code) {
	case 0: cout << "no errors found" << endl; break;
	case 1: cout << "unrecognizable type" << endl; break;
	case 2: cout << "illegal variable name" << endl; break;
	case 3: cout << "unexpected number" << endl; break;
	case 4: cout << "; expected" << endl;
	}
	return;
}


int main() {
	string token;

	cout << "Please enter a declaration in format "
		<< "<type> <variable> [= number] ;" << endl;

	int a = 0, b = 0, i = 0, c = 0, f = 0, k = 0;
	string tokenString = "";
	bool dataType = false;
	token = GetToken();
	if (token == "int" || token == "float") {
		if (token == "float")
			dataType = true;
	}
	else {
		error(1);
		a = 1;
	}


	if (a == 0)
	{
		token = GetToken();
		if (!(token == "A" || token == "B" || token == "C" || token == "D" || token == "E")) {
			error(2);
		}
		if (token == "A" || token == "B" || token == "C" || token == "D" || token == "E") {
			token = GetToken();
			if (isdigit(token[0]))
			{
				error(4);
			}
			b = 1;
			if (token == ";") {
				error(0);
			}
			else if (token == "=") {
				token = GetToken();
				if (dataType == true) {
					while (i < token.length()) {
						if (token[0] == ';') {
							error(3);
							c = 1;
							break;
						}
						else if (token[i] >= '0' && token[i] <= '9' || token[i] == '.') {
							tokenString += token[i];
						}
						else {
							error(4);
							break;
						}
						if (token[token.length() - 1] == ';') {
							error(0);
							break;
						}

						i++;
					}
				}
				else if (dataType == false) {
					while (i < token.length()) {
						if (token[0] == ';') {
							error(3);
							//f = 1;
							c = 1;
							break;
						}
						else if (token[i] >= '0' && token[i] <= '9' || token[i] == '.') {
							tokenString += token[i];
							if (token[i] == '.') {
								error(3);
								k = 1;
								break;
							}
						}
						else {
							b = 1;
							break;
						}
						i++;

					}
					if (k == 0) {
						if (b == 1) {
							error(4);
						}
					}
					for (int i = 0; i < token.length(); i++) {
						if (k == 0 && token[token.length() - 1] == ';')
							error(0);
						break;
					}
				}
			}
		}
		
	}
	
	system("PAUSE");
	return 0;
}






