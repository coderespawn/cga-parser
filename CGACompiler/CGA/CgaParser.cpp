
#include "CgaParser.h"
#include "CgaIncludes.h"
#include <iostream>

CgaParser::CgaParser(CgaLexerPtr lexer) : lexer(lexer)
{
}

void CgaParser::Parse()
{
	CgaToken token;
	do {
		token = lexer->GetToken();
		std::cout << CgaToken_ToString(token) << " ";
	} while (token.Type != CgaTokenType::Eof);
}
