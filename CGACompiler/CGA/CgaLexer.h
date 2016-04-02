#pragma once
#include "CgaIncludes.h"

enum class CgaTokenType {
	Identifier,
	Number,				
	String,				
	ArgNumber,			// Number ('r')?;
	True,				// 'true'
	False,				// 'false'
	Var,				// 'var'
	ParenOpen,			// '('
	ParenClose,			// ')'
	CurlOpen,			// '{'
	CurlClose,			// '}'
	Comma,				// ','
	Semicolon,			// ';'
	Assign,				// '='
	Arrow,				// '->'
	Pipe,				// '|'
	Colon,				// ':'
	Epsillon,			// '~'
	BinaryOp,
	Eof,
	Unknown,
};


struct CgaToken {
	CgaToken(CgaTokenType Type, const CGAString& ValueIdentifier, int LineNumber, int ColumnNumber)
		: Type(Type), ValueIdentifier(ValueIdentifier), LineNumber(LineNumber), ColumnNumber(ColumnNumber) {}

	CgaToken(CgaTokenType Type, float ValueNumber, int LineNumber, int ColumnNumber)
		: Type(Type), ValueNumber(ValueNumber), LineNumber(LineNumber), ColumnNumber(ColumnNumber) {}

	CgaToken(CgaTokenType Type, const CGAString& ValueIdentifier, float ValueNumber, int LineNumber, int ColumnNumber)
		: Type(Type), ValueIdentifier(ValueIdentifier), ValueNumber(ValueNumber), LineNumber(LineNumber), ColumnNumber(ColumnNumber) {}

	CgaToken() : Type(CgaTokenType::Unknown), ValueIdentifier(""), ValueNumber(0), LineNumber(0), ColumnNumber(0) {}

	CgaTokenType Type;

	CGAString ValueIdentifier;
	float ValueNumber;

	int LineNumber;
	int ColumnNumber;
};

CGAString CgaTokenType_ToString(CgaTokenType type);
CGAString CgaToken_ToString(CgaToken token);

class CgaLexer
{
public:
	CgaLexer(const CGAString& source);
	CgaToken GetToken();

private:
	char MoveNext();

	bool IsAlphaNumeric(char c);
	bool IsAlpha(char c);
	bool IsDigit(char c);
	bool IsWhiteSpace(char ch);
	CgaToken CreateToken(CgaTokenType Type, float ValueNumber);
	CgaToken CreateToken(CgaTokenType Type, const CGAString& ValueIdentifier);
	CgaToken CreateToken(CgaTokenType Type, const CGAString& ValueIdentifier, float ValueNumber);

private:
	char c;
	std::stringstream stream;
	int LineNumber;
	int ColumnNumber;
};

typedef std::shared_ptr<CgaLexer> CgaLexerPtr;

