#ifndef BLUE_AST_H
#define BLUE_AST_H

#include "../include/core.hpp"

// Would typically have a type but we're just using double for everything.
class ExprAST {
public:
    virtual ~ExprAST() = default;
};

class NumberExprAST : public ExprAST {
public:
    NumberExprAST(double _val) : val(_val) {}
private:
    double val;
};

class VariableExprAST : public ExprAST {
public:
    VariableExprAST(const std::string &_name) : name(_name) {}
private:
    std::string name;
};

class BinaryExprAST : public ExprAST {
public:
    BinaryExprAST(char _op, std::unique_ptr<ExprAST> _LHS, std::unique_ptr<ExprAST> _RHS) :
        op(_op), LHS(std::move(_LHS)), RHS(std::move(_RHS)) {}
private:
    char op;
    std::unique_ptr<ExprAST> LHS, RHS; // Left and right sides of the expression.
};

class CallExprAST : public ExprAST {
public:
    CallExprAST(const std::string &_callee, std::vector<std::unique_ptr<ExprAST>> _args) :
        callee(_callee), args(std::move(_args)) {}
private:
    std::string callee;
    std::vector<std::unique_ptr<ExprAST>> args;
};

class PrototypeAST {
public:
    PrototypeAST(const std::string &_name, std::vector<std::string> _args) :
        name(_name), args(std::move(_args)) {}
    const std::string GetName() { return name; }
private:
    std::string name;
    std::vector<std::string> args;
};

class FunctionAST {
public:
    FunctionAST(std::unique_ptr<PrototypeAST> _proto, std::unique_ptr<ExprAST> _body) :
        proto(std::move(_proto)), body(std::move(_body)) {}
private:
    std::unique_ptr<PrototypeAST> proto;
    std::unique_ptr<ExprAST> body;
};

#endif //BLUE_AST_H
