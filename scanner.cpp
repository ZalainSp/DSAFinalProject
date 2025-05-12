#include "scanner.h"
#include <cctype>

//token constructor
Token::Token(TokenType t, const string& v) {
    type = t;
    val = v;
}

//getss the next token from input
Token getToken(const string& input, size_t& pos) {
    //skip whitespaces
    while (pos < input.length() && isspace(input[pos])) {
        pos++;
    }

    //return end of input if we are at the end
    if (pos >= input.length()) {
        return { END_OF_INPUT, "" };
    }

    //handles negative numbers
    char current = input[pos];
    //handle negative and positive numbers
    if (current == '-' || current == '+') {
        if (pos + 1 < input.length() && isdigit(input[pos + 1])) {
            string number(1, current); 
            pos++;
            while (pos < input.length() && isdigit(input[pos])) {
                number += input[pos++];
            }
            return { NUMBER, number };
        } else {
            TokenType type = (current == '+') ? ADDITION : SUBTRACTION;
            pos++;
            return { type, string(1, current) };
        }
    }

    //handle regular numbers
    if (isdigit(input[pos])) {
        string number;
        while (pos < input.length() && isdigit(input[pos])) {
            number += input[pos++];
        }
        return { NUMBER, number };
    }

    //symbols and operators
    switch (input[pos]) {
        case '+': pos++; 
        return { ADDITION, "+" }; //accept + as addition
        case '*':pos++;
        case 'x': pos++; 
        return { MULTIPLICATION, "x" }; //accept x and * as multiply
        case '/': pos++; 
        return { DIVISION, "/" }; //accept / as division
        case '(': pos++; 
        return { LEFT_PARENTHESIS, "(" };//accept ( as left parenthesis
        case ')': pos++; 
        return { RIGHT_PARENTHESIS, ")" };//accept ) as right parenthesis
        default:

            return { UNKNOWN, string(1, input[pos++]) }; //accept anything else as unknown
    }
}
