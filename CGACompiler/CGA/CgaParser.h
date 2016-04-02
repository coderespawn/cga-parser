#pragma once
#include "CgaLexer.h"

class CgaParser
{
public:
	CgaParser(CgaLexerPtr lexer);

	void Parse();

private:


private:
	CgaLexerPtr lexer;
};

typedef std::shared_ptr<CgaParser> CgaParserPtr;

