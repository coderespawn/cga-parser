
#include "CGA/CgaIncludes.h"
#include "CGA/CgaLexer.h"

#include <iostream>
#include "CGA/CgaParser.h"
using namespace std;

int main()
{
	CGAString source =
		"sidewing -> S(1r, 1r, Scope.sz * rand(0.4,1.0)) facades : 0.5"
		"\n		-> S(1r, Scope.sy * rand(0.2,0.9), Scope.sz * rand(0.4,1.0)) facades : 0.3"
		"\n		-> ~ : 0.2;"
		"\n facades->Comp(\"sidefaces\") { facade }; "
		;

	CgaLexerPtr lexer = std::make_shared<CgaLexer>(source);
	CgaParserPtr parser = std::make_shared<CgaParser>(lexer);
	parser->Parse();

	return 0;
}

