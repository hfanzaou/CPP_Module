#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
int main()
{
	// try {
	// 	Bureaucrat b("gg", 1);
	// }
	// catch (std::exception& e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }
	// try
	// {
	// 	Bureaucrat a("hello", 150);
	// 	a.decrement();
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }

	Intern    h;
	AForm *b;
	Bureaucrat ceo("ceo", 1);
	b = h.makeForm("", "lol");
	b = h.makeForm("Robotomy Request", "Target");
	if (b)
	{
		ceo.executeForm(*b);
		ceo.signForm(*b);
		ceo.executeForm(*b);
		ceo.executeForm(*b);
	}
	delete b;

	AForm		*robotomy = new RobotomyRequestForm("there");
	Bureaucrat	mike("mike", 1);

	mike.executeForm(*robotomy);
	mike.signForm(*robotomy);
	mike.executeForm(*robotomy);
	delete robotomy;
	
	AForm		*presidential = new PresidentialPardonForm("there");
	Bureaucrat	lucie("Lucie", 6);

	lucie.executeForm(*presidential);
	lucie.signForm(*presidential);
	lucie.executeForm(*presidential);
	lucie.increment();
	lucie.executeForm(*presidential);
	delete presidential;

	return (0);
}