#include "Parser.hpp"

int Parser::GetNextToken() {
    return curTok = Lexer::GetToken();
}

std::unique_ptr<ExprAST> Parser::LogError(const char *str) {
    std::cerr << "Error: " << str << "\n";
    return nullptr;
}

std::unique_ptr<PrototypeAST> Parser::LogErrorP(const char *str) {
    LogError(str);
    return nullptr;
}

std::unique_ptr<ExprAST> Parser::ParseNumberExpr() {
    auto result = std::make_unique<NumberExprAST>(Lexer::numVal);
    GetNextToken();
    return std::move(result);
}

std::unique_ptr<ExprAST> Parser::ParseParenExpr() {
    GetNextToken();
    auto v = ParseExpression();
    if (!v) {
        return nullptr;
    }
    if (curTok != ')') {
        return LogError("Expected ')'");
    }
    GetNextToken();
    return v;
}

std::unique_ptr<ExprAST> Parser::ParseIdentifierExpr() {
    std::string idName = Lexer::identifierString;
    GetNextToken();
    if (curTok != '(') {
        return std::make_unique<VariableExprAST>(idName);
    }

    GetNextToken();
    std::vector<std::unique_ptr<ExprAST>> args;
    if (curTok != ')') {
        while (true) {
            if (auto arg = ParseExpression()) {
                args.push_back(std::move(arg));
            }
            else {
                return nullptr;
            }
            if (curTok == ')') {
                break;
            }
            if (curTok != ',') {
                return LogError("Expected ')' or ',' in args list");
            }
            GetNextToken();
        }
    }
    GetNextToken();
    return std::make_unique<CallExprAST>(idName, std::move(args));
}
