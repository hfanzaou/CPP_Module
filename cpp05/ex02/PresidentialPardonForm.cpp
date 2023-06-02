#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : 
	AForm("Presidential Pardon", 25, 5), _target("None")
{
	std::cout << "PresidentialPardonForm Default Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
	AForm("Presidential Pardon", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj)
{
	std::cout << "PresidentialPardonForm copy Constructor called" << std::endl;
	*this = obj;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj)
{
	std::cout << "PresidentialPardonForm copy assignement Constructor called" << std::endl;
	(void)obj;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Destructor called" << std::endl;
}

void	PresidentialPardonForm::execute(const Bureaucrat& executer) const
{
	if (!this->getSign())
		throw Bureaucrat::NotSignedException();
	if (this->getEGrade() < executer.getGrade())
		throw Bureaucrat::GradeTooLowException();
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;	
}