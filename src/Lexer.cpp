#include "Lexer.hpp"

Lexer::Token Lexer::GetToken() {
    int lastChar = ' ';
    while (isspace(lastChar)) {
        lastChar = getchar();
    }
    if (isalpha(lastChar)) {
        identifierString = lastChar;
        while (isalnum(lastChar = getchar())) {
            identifierString += lastChar;
        }
        if (identifierString == "def") {
            return Token::DEF;
        }
        if (identifierString == "extern") {
            return Token::EXTERN;
        }
        return Token::ID;
    }

    if (isdigit(lastChar) || lastChar == '.') {
        std::string numStr;
        do {
            numStr += lastChar;
            lastChar = getchar();
        } while (isdigit(lastChar) || lastChar == '.');

        numVal = strtod(numStr.c_str(), 0);
        return Token::NUM;
    }

    if (lastChar == '#') {
        do {
            lastChar = getchar();
        } while (lastChar != EOF && lastChar != '\n' && lastChar != '\r');

        if (lastChar != EOF) {
            return GetToken();
        }
    }

    if (lastChar == EOF) {
        return Token::END;
    }

    // May be better to return the ascii value.
    return Token::ERR;
}
