#include "RPN.hpp"

int	operate(char op, int t, int e)
{
	switch(op)
	{
		case '*':
			return(e * t);
		case '-':
			return (e - t);
		case '+':
			return(e + t);
		case '/':
			if (t == 0)
				throw std::runtime_error("Error");
			return(e / t);
	}
	throw std::runtime_error("Error");
}
void	calculate(std::string& exp)
{
	std::string::iterator it;
	std::stack<int> RPN;
	int t;
	int e;

	for (it = exp.begin(); it != exp.end(); ++it)
	{
		if (std::isdigit(*it))
			RPN.push((static_cast<int>(*it) - 48));
		else if (!(std::isspace(*it)))
		{
			if (RPN.size() < 2)
				throw std::runtime_error("Error");
			t = RPN.top();
			RPN.pop();
			e = RPN.top();
			RPN.pop();
			RPN.push(operate(*it, t, e));
		}
	}
	while (RPN.size() != 1)
		throw std::runtime_error("Error");
	std::cout << RPN.top() << std::endl;	
}


