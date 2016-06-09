#pragma once
class Variable : public Operand
{
public:
	Variable(string name)
	{
		this->name = name;
	}
	int Variable::evaluate();
private:
	string name;
};