#include <iostream>
#include <string>
#include <fstream>
#include "Token.h"
#include "Scanner.h"

using namespace std;
Token* token;

int main(int  argc, char** argv)
{

    if (argc == 1) //NO FILE WAS GIVEN AS ARGUMENT
    {
        int x;
        while ((cin >> x) && x != EOF)
        {

        }
    }
    else if (argc == 2) // FILE WAS GIVEN
    {
        fstream dataFile;
        dataFile.open(argv[1], ios::in);
        if (!dataFile)
        {
            cout << "THERE WAS AN ERROR OPENING THE FILE." << endl;
            exit(1);
        }
        else
        {
            while (dataFile)
            { 
                token = nextTK(dataFile);
                cout << "tokenID: " << token->tokenType << " tokenInstance: " << token->value << " on Line: " << token->lineNum << endl;
               
            }
        }
        dataFile.close();
    }
}
