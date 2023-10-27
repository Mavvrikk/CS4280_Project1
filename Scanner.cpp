#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <vector>
#include "Token.h"
#include "Scanner.h"

using namespace std;

char currentChar;
int* linePos;
int lineNum = 1;
const int MAX_TK = 8;
Token* TK;

Token* nextTK(fstream &dataFile) 
{
	dataFile.get(currentChar); // grab one character 
	while (isspace(currentChar)) // skip any ws, \t, \n
	{
		if (currentChar == '\n') //if we hit a new line 
		{
			lineNum++; // increase line number
		}
		dataFile.get(currentChar); // grab one character 
	}
	testInput(currentChar, dataFile);
	return TK;
}

Token* testInput(char currentChar, fstream &dataFile)
{
	if (isdigit(currentChar))
	{ // if current character is a number, we need to grab all proceeding characters that are numbers 
		int loops = 0;
		string input;
		while (isdigit(currentChar) && !dataFile.eof()) 
		{
			input.append(1, currentChar);
			dataFile.get(currentChar);
			if (dataFile.eof())
				break;
				loops++;
				if (loops >= 8) // token is too large, error
				{
					cout << "ERROR, TOKEN TO LARGE" << endl;
					exit(0);
				}
		}

		// now that we have a complete number token, create it. 
		TK = createToken(TK_NUM, lineNum);
		TK->value = input; //give it the int value
		
		//currentChar now points to last digit of num and ready to grab next char
		
		return TK;
	}
	else if (isalpha(currentChar) && !dataFile.eof())
	{
		int loops = 0;
		string input;
		while (isalpha(currentChar))
		{
			//NEED TO APPEND STRING WITH CHAR(S)
			input.append(1, currentChar);  // ***********check this line***************
			dataFile.get(currentChar);
			if (dataFile.eof())
				break;
			loops++;
			if (loops >= 8) // token is too large, error
			{
				cout << "ERROR, TOKEN TO LARGE " << input << endl;
				exit(0);
			}
		}
		
		if (input.size() == 1) // its a char, not ident
			TK = createToken(TK_CHAR, lineNum);
		else
			TK = createToken(checkKW(input), lineNum);
		
		TK->value = input;
		return TK;
	}
	else if (ispunct(currentChar))
	{
		switch (currentChar)
		{ 
			//DO NOT FORGET TO ADD SB_LEQ, SB_GEQ
		case '=':
			TK = createToken(SB_EQ, lineNum);
			TK->value = currentChar;
			return TK;
		case '>': 
			TK = createToken(SB_GT, lineNum);
			TK->value = currentChar;
			return TK;
		case '<':
			TK = createToken(SB_LT, lineNum);
			TK->value = currentChar;
			return TK;
		case '~':
			TK = createToken(SB_TILD, lineNum);
			TK->value = currentChar;
			return TK;
		case ':':
			TK = createToken(SB_COLON, lineNum);
			TK->value = currentChar;
			return TK;
		case '+':
			TK = createToken(SB_PLUS, lineNum);
			TK->value = currentChar;
			return TK;
		case '-':
			TK = createToken(SB_MINUS, lineNum);
			TK->value = currentChar;
			return TK;
		case '*':
			TK = createToken(SB_AST, lineNum);
			TK->value = currentChar;
			return TK;
		case '/':
			TK = createToken(SB_SLASH, lineNum);
			TK->value = currentChar;
			return TK;
		case '%':
			TK = createToken(SB_MOD, lineNum);
			TK->value = currentChar;
			return TK;
		case '.':
			TK = createToken(SB_PERIOD, lineNum);
			TK->value = currentChar;
			return TK;
		case '(':
			TK = createToken(SB_LPAR, lineNum);
			TK->value = currentChar;
			return TK;
		case ')':
			TK = createToken(SB_RPAR, lineNum);
			TK->value = currentChar;
			return TK;
		case ',':
			TK = createToken(SB_COMMA, lineNum);
			TK->value = currentChar;
			return TK;
		case '{':
			TK = createToken(SB_LCURLY, lineNum);
			TK->value = currentChar;
			return TK;
		case '}':
			TK = createToken(SB_RCURLY, lineNum);
			TK->value = currentChar;
			return TK;
		case ';':
			TK = createToken(SB_SEMICOLON, lineNum);
			TK->value = currentChar;
			return TK;
		case '[':
			TK = createToken(SB_LBRACK, lineNum);
			TK->value = currentChar;
			return TK;
		case ']':
			TK = createToken(SB_RBRACK, lineNum);
			TK->value = currentChar;
			return TK;
		case '#':
			//skipComment();
		default:
			cout << "ERROR: UNEXPECTED INPUT: " << currentChar << endl;
			exit(0);
		}
	}
}
