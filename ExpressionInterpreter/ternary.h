#pragma once
class Ternary : public SubExpression
{
public:
	Ternary(Expression* left, Expression* right, Expression* condition) : SubExpression(left, right)
	{
		this->condition = condition;
	}
	int evaluate()
	{
		return condition->evaluate() ? left->evaluate() : right->evaluate();
	}

private:
	Expression* condition;
};