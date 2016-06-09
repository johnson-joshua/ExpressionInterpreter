#include <iostream>
#include <sstream>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "plus.h"
#include "minus.h"
#include "times.h"
#include "divide.h"
#include "or.h"
#include "and.h"
#include "equality.h"
#include "greaterThan.h"
#include "lessThan.h"
#include "ternary.h"
#include "negation.h"

SubExpression::SubExpression(Expression* left, Expression* right)
{
	this->left = left;
	this->right = right;
}

Expression* SubExpression::parse(stringstream& in)
{
	Expression* left;
	Expression* right;
	Expression* condition;
	char operation, paren;

	/* This is where the program determines which of the three tupes of <exp> needs to be built. When we get here
	* we should have burnt a paren char and the next chars in has to be an operand */

	left = Operand::parse(in);

	// At this point the next thing in could be an <op>, or ':' or '!'
	// Use a switch statement to call the correct operation

	in >> operation;

	if (operation == '!') {// Negation Expression
		in >> paren;
		return new Negation(left, NULL); //Passing a NULL as the second argument as the negation opeation really only functions on one operand

	}
	else if (operation == ':') {//Ternary Expression
		right = Operand::parse(in);
		in >> paren;// this char should acutaly be a '?'
		condition = Operand::parse(in);
		in >> paren;
		return new Ternary(left, right, condition);

	}
	else {//Every other Expression

		  //These two operations need to be performed for every case that follows
		right = Operand::parse(in);
		in >> paren;

		switch (operation)
		{
		case '+': return new Plus(left, right);
		case '-': return new Minus(left, right);
		case '*': return new Times(left, right);
		case '/': return new Divide(left, right);
		case '|': return new Or(left, right);
		case '&': return new And(left, right);
		case '=': return new Equality(left, right);
		case '>': return new GreaterThan(left, right);
		case '<': return new LessThan(left, right);
		}
	}
	return 0;
}
