#ifndef BLUE_PARSER_H
#define BLUE_PARSER_H

#include "../include/core.hpp"
#include "Lexer.hpp"
#include "AST.hpp"

class Parser {
public:
    int GetNextToken();
    std::unique_ptr<ExprAST> ParseExpression();
    std::unique_ptr<ExprAST> ParseNumberExpr();
    std::unique_ptr<ExprAST> ParseParenExpr();
    std::unique_ptr<ExprAST> ParseIdentifierExpr();
    std::unique_ptr<ExprAST> LogError(const char *str);
    std::unique_ptr<PrototypeAST> LogErrorP(const char *str);

private:
    Lexer::Token curTok;
};


#endif //BLUE_PARSER_H
