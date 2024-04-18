#ifndef BLUE_LEXER_H
#define BLUE_LEXER_H

#include "../include/core.hpp"

class Lexer {
public:
    enum Token {
        END = -1,

        // Commands
        DEF = -2,
        EXTERN = -3,

        // Primary
        ID = -4,
        NUM = -5,
        ERR = -6
    };
    static Token GetToken();
    static std::string identifierString; // If Token::ID
    static double numVal; // If Token::NUM
};


#endif //BLUE_LEXER_H
