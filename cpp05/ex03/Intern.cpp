#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern Destructor called" << std::endl;
}

Intern::Intern(const Intern& obj)
{
	std::cout << "Intern copy contrcutor called" << std::endl;
	*this = obj;
}

Intern& Intern::operator=(const Intern& obj)
{
	std::cout << "Intern copy assignement called" << std::endl;
	(void)obj;
	return (*this);
}

AForm* Shrubbery(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Robotomy(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}

AForm* Presidential(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::makeForm(const std::string& name, const std::string& target)
{
	AForm *(*ret[3])(const std::string& target) = {&Shrubbery, &Robotomy, &Presidential};
	std::string Forms[3] = {"Shrubbery Creation", "Robotomy Request", "Presidential Pardon"};
	for (int i = 0; i < 3; i++)
	{
		if (name == Forms[i])
		{
			std::cout << "Intern creates " << Forms[i] << " Form" << std::endl; 
			return (*ret[i])(target);
		}
	}
	std::cout << "Intern failed to create a " << name << " Form" << std::endl;
	return (NULL);

}