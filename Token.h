#pragma once

using namespace std;

enum TokenType {
	//TOKENS
	TK_CHAR, TK_IDENT, TK_NUM, TK_EOF, 
	
	//KEYWORDS
	KW_START, KW_STOP, KW_LOOP, KW_VOID, KW_VAR, KW_END, KW_SCAN, 
	KW_PRINT, KW_MAIN, KW_COND, KW_THEN, KW_LET, KW_FUNC,
	
	//OPERATORS
	SB_EQ, SB_LEQ, SB_GEQ, SB_LT, SB_GT, SB_TILD, SB_COLON, SB_PLUS,
	SB_MINUS, SB_AST, SB_SLASH, SB_MOD, SB_PERIOD, SB_LPAR, SB_RPAR,
	SB_COMMA, SB_LCURLY, SB_RCURLY, SB_SEMICOLON, SB_RBRACK, SB_LBRACK
};

struct Token
{
	TokenType tokenType;
	string value;
	int lineNum;
};

TokenType checkKW(string letters);

Token* createToken(TokenType type, int lineNum);