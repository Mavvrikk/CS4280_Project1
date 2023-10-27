#pragma once

extern char currentChar;
extern int lineNum;

Token* nextTK(fstream &);
Token* testInput(char currnet, fstream &);