#include <iostream>
#include <vector>
#include "scanner.h"
using namespace std;

int main() {
    string input;
    cout << "Enter a math expression: ";
    getline(cin, input);

    size_t pos = 0;
    vector<Token> tokenList;

    //tokenize the input
    while (true){
        Token tok=getToken(input, pos);
        if (tok.type==END_OF_INPUT) break;
        tokenList.push_back(tok);
    }

    //print the tokens
    cout <<"\nTokens Found\n";
    for (const Token& t : tokenList) {
        cout<<"(Type: ";
        switch (t.type) {
            case NUMBER: cout<<"NUMBER"; break;
            case ADDITION: cout<< "ADDITION"; break;
            case SUBTRACTION: cout<<"SUBTRACTION"; break;
            case MULTIPLICATION:cout<< "MULTIPLICATION"; break;
            case DIVISION:cout<<"DIVISION"; break;
            case LEFT_PARENTHESIS: cout<<"LEFT_PAREN"; break;
            case RIGHT_PARENTHESIS:cout<<"RIGHT_PAREN"; break;
            case UNKNOWN:cout<<"UNKNOWN"; break;
            default: cout<< "Not found"; break;
        }
        cout << ", Value: \"" << t.val << "\")\n";
    }

    return 0;
}
