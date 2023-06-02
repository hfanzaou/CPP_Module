#include "AForm.hpp"

AForm::AForm() : _name("AForm"), _signed(false), _s_grade(150), _e_grade(150)
{
	std::cout << "Default AForm Constructor called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm Destructor called" << std::endl;
}

AForm::AForm(const std::string& name, const int& s_grade, const int& e_grade) :
_name(name), _signed(false), _s_grade(s_grade), _e_grade(e_grade)
{
	std::cout << "AForm Constrcutor called" << std::endl;
	if (s_grade < 1 || e_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (s_grade > 150 || e_grade > 150)
		throw Bureaucrat::GradeTooLowException();	
}

AForm::AForm(const AForm& obj) : _name(obj.getName()), _signed(false), _s_grade(obj.getSGrade()), _e_grade(obj.getEGrade())
{
	std::cout << "AForm Copy Constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& obj)
{
	if (this != &obj)
	{
		this->_signed = obj.getSign();
	}
	return (*this);
}

std::string AForm::getName() const {return (this->_name);}

int			AForm::getSign() const {return (this->_signed);}

int 		AForm::getSGrade() const {return (this->_s_grade);}

int			AForm::getEGrade() const {return (this->_e_grade);}

void		AForm::beSigned(const Bureaucrat& obj)
{
	if (this->_signed)
		throw Bureaucrat::AlreadySignedException();
	else if (obj.getGrade() <= getSGrade())
		this->_signed = true;
	else
		throw Bureaucrat::GradeTooLowException();	
}

std::ostream& operator<<(std::ostream& out, const AForm& obj)
{
	out << obj.getName() << " AForm ";
	if (obj.getSign())
		out << ": signed";
	else
		out << ": not signed";
	out << ", sign grade " << obj.getSGrade() << ", execute grade " << obj.getEGrade();
	return (out);		
}	



