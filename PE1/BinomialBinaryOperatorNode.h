#pragma once
#include "BinomialNode.h"

class BinomialBinaryOperatorNode : public BinomialNode
{
	int _operationType;
	BinomialNode* _operand1;
	BinomialNode* _operand2;

public: 
	BinomialBinaryOperatorNode(StringParser& str, Subset set1, Subset set2) : BinomialNode(str, set1) {
		_operand1 = CreateNode(str, set1);
		_operand2 = CreateNode(str, set2);

		switch (str.GetString()[set1.GetEnd()]) {
			case '+':
				_operationType = 0;
				break;
			case '-':
				_operationType = 1;
				break;
			case '*':
				_operationType = 2;
				break;
			case '/':
				_operationType = 3;
				break;
			case '^':
				_operationType = 4;
				break;
			default:
				_operationType = 5;
				break;
		}
	}

	float Extract(const float& x) override;
};
