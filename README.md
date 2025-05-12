This is a simple C++ tokenizer that scans a mathematical expression and breaks it down into tokens such as numbers, 
operators ("+", "-", "*","x", "/", "x"), and parentheses("("")").

## Features
Recognizes:
- Integers (positive and negative)
- Operators: "+", "-", "*", "x", "/"
- Parentheses: "(", ")"
- Unknown characters
- Ignores whitespace
- Outputs the type and value of each token

## Files
- main.cp – Contains the main() function to interact with the user
- scanner.cpp – Implements the tokenizer logic (getToken()).
- scanner.h – Declares the TokenType enum and Token structure.


## How to Compile and Run
g++ main.cpp scanner.cpp -o program
./program
