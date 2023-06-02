#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : 
	AForm("Robotomy Request", 72, 45), _target("None")
{
	std::cout << "RobotomyRequestForm Default Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
	AForm("Robotomy Request", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj)
{
	std::cout << "RobotomyRequestForm copy Constructor called" << std::endl;
	*this = obj;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
	std::cout << "RobotomyRequestForm copy assignement Constructor called" << std::endl;
	(void)obj;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

void	RobotomyRequestForm::execute(const Bureaucrat& executer) const
{
	int i;

	if (!this->getSign())
		throw Bureaucrat::NotSignedException();
	if (this->getEGrade() < executer.getGrade())
		throw Bureaucrat::GradeTooLowException();
	std::cout << "kzZzzzZZZzz!!!" << std::endl; 	
	i = rand() % 2;
	if (i)
		std::cout << this->_target << " has been successfully robotomized" << std::endl;
	else
		std::cout << "failed to robotimize" << this->_target << std::endl;	 	

}