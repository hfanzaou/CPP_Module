#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
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

		AForm		*form = new ShrubberyCreationForm("there");
	Bureaucrat	corr("Corrr", 1);
	Bureaucrat	a("Lucie", 140);

	corr.executeForm(*form);
	corr.signForm(*form);
	// std::cout << *form << std::endl;
	// std::cout << corr << std::endl;
	corr.executeForm(*form);
	a.executeForm(*form);
	delete form;

	AForm		*robotomy = new RobotomyRequestForm("there");
	Bureaucrat	mike("mike", 1);

	mike.executeForm(*robotomy);
	mike.signForm(*robotomy);
	mike.executeForm(*robotomy);
	mike.executeForm(*robotomy);
	mike.executeForm(*robotomy);
	mike.executeForm(*robotomy);
	mike.executeForm(*robotomy);
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