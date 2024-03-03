#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
	public:
		RPN(void);
		RPN(const RPN &copy);
		RPN &operator=(const RPN &rhs);
		~RPN(void);

		double	calculate(const std::string& input);
		const std::stack<double>& getStack() const;

	private:
		std::stack<double>	stack;
};

bool	isValidRPN(const std::string& input);
double		operate(double a, double b, char op);

#endif