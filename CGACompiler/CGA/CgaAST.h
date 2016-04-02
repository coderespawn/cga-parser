#pragma once
#include "CgaIncludes.h"

class ExprAST {

};
typedef std::shared_ptr<ExprAST> ExprASTPtr;
typedef std::vector<ExprASTPtr> ExprASTList;

class NumberExprAST : public ExprAST {
public:
	NumberExprAST(float Value) : Value(Value) {}

private:
	float Value;
};
typedef std::shared_ptr<NumberExprAST> NumberExprASTPtr;


class IdentifierExprAST : public ExprAST {
public:
	IdentifierExprAST(const CGAString& Name, float Value) : Name(Name), Value(Value) {}

private:
	CGAString Name;
	float Value;
};
typedef std::shared_ptr<IdentifierExprAST> IdentifierExprASTPtr;

class BinaryExprAST : public ExprAST {
public:
	BinaryExprAST(const CGAString& Operator, ExprASTPtr lhs, ExprASTPtr rhs) : Operator(Operator), lhs(lhs), rhs(rhs) {}

private:
	CGAString Operator;
	ExprASTPtr lhs;
	ExprASTPtr rhs;
};

////////////////// Function Arguments //////////////
enum class FuncArgASTType {
	String, 
	RelativeNumber,
	Expression
};
class FuncArgAST  {
public:
	FuncArgAST(FuncArgASTType ArgType) : ArgType(ArgType) {}
	FuncArgASTType GetType() const { return ArgType; }
private:
	FuncArgASTType ArgType;
};
typedef std::shared_ptr<FuncArgAST> FuncArgASTPtr;
typedef std::vector<FuncArgASTPtr> FuncArgASTList;

class StringFuncArgAST : public FuncArgAST {
public:
	StringFuncArgAST(const CGAString& StringValue) : FuncArgAST(FuncArgASTType::String), StringValue(StringValue) {}

private:
	CGAString StringValue;
};

class RelativeNumFuncArgAST : public FuncArgAST {
public:
	RelativeNumFuncArgAST(float Value) : FuncArgAST(FuncArgASTType::RelativeNumber), Value(Value) {}

private:
	float Value;
};

class ExprFuncArgAST : public FuncArgAST {
public:
	ExprFuncArgAST(ExprASTPtr Expr) : FuncArgAST(FuncArgASTType::Expression), Expr(Expr) {}

private:
	ExprASTPtr Expr;
};

////////////////////////////////////////////////////////

class CallExprAST : public ExprAST {
public:
	CallExprAST(const CGAString& Callee, FuncArgASTList args) : Callee(Callee), args(args) {}

private:
	CGAString Callee;
	FuncArgASTList args;
};

