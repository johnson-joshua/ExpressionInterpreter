#include <cctype>
#include <iostream>
#include <sstream>
#include <list>
#include <string>

using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "variable.h"
#include "literal.h"
#include "parse.h"
#include "or.h"
#include "and.h"
#include "equality.h"
#include "greaterThan.h"
#include "lessThan.h"
#include "ternary.h"
#include "negation.h"

Expression* Operand::parse(stringstream& in)
{
	char paren;
	int value;

	in >> ws;
	if (isdigit(in.peek()))
	{
		in >> value;
		Expression* literal = new Literal(value);
		return literal;
	}
	if (in.peek() == '(')
	{
		in >> paren;
		return SubExpression::parse(in);
	}
	else
		return new Variable(parseName(in));
	return 0;
}