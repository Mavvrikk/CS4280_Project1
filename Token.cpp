#include <iostream>
#include <string>
#include <algorithm>
#include <ctype.h>
#include "Token.h"

using namespace std;

const int NUM_KEYWORDS = 13;

struct keywords {
	string Name;
	TokenType type;
};

// CREATE AN ARRAY OF KEYWORD STRUCTURES TO HOLD ALL KW DATA AND CORRESPONDING STRINGS
keywords kw[NUM_KEYWORDS] = {
	{"START", KW_START},
	{"STOP", KW_STOP},
	{"LOOP", KW_LOOP},
	{"VOID", KW_VOID},
	{"VAR", KW_VAR},
	{"END", KW_END},
	{"SCAN", KW_SCAN},
	{"PRINT", KW_PRINT},
	{"MAIN", KW_MAIN},
	{"COND", KW_COND},
	{"THEN", KW_THEN},
	{"LET", KW_LET},
	{"FUNC", KW_FUNC}
};


// FUNCTION TO CHECK IF A STRING IS A KEYWORD	
TokenType checkKW(string letters)
{
	transform(letters.begin(), letters.end(), letters.begin(), ::toupper); // change string from file to uppercase for comparison
	for (int i = 0; i < NUM_KEYWORDS; i++)
	{
		if (letters == kw[i].Name) // if Name matches the string found
			return kw[i].type;
	}
	return TK_IDENT; // If it doesnt match a keyword, it must be an identifier (string)
}
Token* createToken(TokenType TT, int lineNum)
{
	Token* TK = new Token;
	TK->tokenType = TT;
	TK->lineNum = lineNum;
	return TK;
}