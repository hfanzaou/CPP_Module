#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : 
	AForm("Shrubbery Creation", 145, 137), _target("None")
{
	std::cout << "ShrubberyCreationForm Default Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
	AForm("Shrubbery Creation", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj)
{
	std::cout << "ShrubberyCreationForm copy Constructor called" << std::endl;
	*this = obj;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
{
	std::cout << "ShrubberyCreationForm copy assignement Constructor called" << std::endl;
	(void)obj;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executer) const
{
	std::ofstream file;

	if (!this->getSign())
		throw Bureaucrat::NotSignedException();
	if (this->getEGrade() < executer.getGrade())
		throw Bureaucrat::GradeTooLowException();

	file.open((_target + "_shrubbery").c_str());
	file << "              ,@@@@@@@," << std::endl;
	file << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
	file << "    ,&%%&%&&%,@@@@@/@@@@@@,888888/8o" << std::endl;
	file << "   ,%&%&&%&&%,@@@@@@/@@@8888888/88'" << std::endl;
	file << "   %&&%&%&/%&&%@@@@/ /@@@8888888888'" << std::endl;
	file << "   %&&%/ %&%%&&@@ V /@@' `888 `/88'" << std::endl;
	file << "  `&% ` /%&'    |.|         '|8'" << std::endl;
	file << "       |o|        | |         | |" << std::endl;
	file << "       |.|        | |         | |" << std::endl;
	file << "    \\/ ._//_/__/  ,_//__\\/.  _//__/_" << std::endl;
}