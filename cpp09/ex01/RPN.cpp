#include "RPN.hpp"

// =========== CONSTRUCTORS AND DESTRUCTORS ===========

RPN::RPN(void)
{
	// std::cout << "Default RPN constructor called" << std::endl;
}

RPN::RPN(const RPN &copy)
{
	// std::cout << "Copy RPN constructor called" << std::endl;
	*this = copy;
}

RPN& RPN::operator=(const RPN &rhs)
{
	// std::cout << "Copy RPN assignation called" << std::endl;
	if (this != &rhs)
	{
		this->stack = rhs.getStack();
	}
	return (*this);
}

RPN::~RPN(void)
{
	// std::cout << "Destructor for RPN called" << std::endl;
}

// =========== ===========

bool isValidRPN(const std::string& input) {
	std::string::const_iterator iter = input.begin();
	char c = *iter;

	if (!isdigit(c)) {
		return false;
	}
	size_t operatorCount = 0;
	size_t digitCount = 1;
	iter++;

	while (iter != input.end()) {
		c = *iter;
		if (c != ' ')
			return false;
		iter++;

		c = *iter;
		if (!(isdigit(c) || c == '+' || c == '-' || c == '*' || c == '/')) {
			return false;
		}

		if (isdigit(c))
		{
			digitCount++;
		}
		else
		{
			operatorCount++;
		}

		if (digitCount < operatorCount + 1) {
	   	 	return false;
		}
		iter++;
	}
	return true;
}

const std::stack<double>& RPN::getStack() const {
    return this->stack;
}

double	operate(double a, double b, char op) {
	switch (op) {
		case '+':
			return (a + b);
		case '-':
			return (a - b);
		case '/':
			if (b == 0)
				throw std::runtime_error("Error");
			return (a / b);
		case '*':
			return (a * b);
		default:
            throw std::runtime_error("Error");
	}
}

double	RPN::calculate(const std::string& input) {
	std::string::const_iterator	iter = input.begin();

	while (iter < input.end()) {
		if (std::isdigit(*iter))
			stack.push(static_cast<double>(*iter - '0'));
		else {
			double b = stack.top();
			stack.pop();
			double a = stack.top();
			stack.pop();
			stack.push(operate(a, b, *iter));
		}
		iter += 2;
	}
	return (stack.top());
}