#ifndef SCANNER_H
#define SCANNER_H

#include <string>
using namespace std;

//all tokens to recognize
enum TokenType {
    NUMBER, //any number (1,2,3,4,5,6,7,8,9)
    ADDITION, // + 
    SUBTRACTION, // - 
    MULTIPLICATION,// * or x
    DIVISION, // / 
    LEFT_PARENTHESIS, // (
    RIGHT_PARENTHESIS,// )
    UNKNOWN, //anything unrecognizable
    END_OF_INPUT //end of input
};

//holds type and the actual string
struct Token {
    TokenType type;
    string val;

    Token(TokenType t, const string& v); //constructor
};

//function to extract the next token
Token getToken(const string& input, size_t& pos);

#endif
