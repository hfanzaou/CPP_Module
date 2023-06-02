#include "Form.hpp"

Form::Form()
	: _name("Form"), _signed(false), _s_grade(150), _e_grade(150)
{
	std::cout << "Default Form Constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form Destructor called" << std::endl;
}

Form::Form(const std::string& name, const int& s_grade, const int& e_grade)
	: _name(name), _signed(false), _s_grade(s_grade), _e_grade(e_grade)
{
	std::cout << "Form Constrcutor called" << std::endl;
	if (s_grade < 1 || e_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (s_grade > 150 || e_grade > 150)
		throw Bureaucrat::GradeTooLowException();	
}

Form::Form(const Form& obj) 
	: _name(obj.getName()), _signed(false), _s_grade(obj.getSGrade()), _e_grade(obj.getEGrade()) 
{
	std::cout << "Form Copy Constructor called" << std::endl;
}

Form& Form::operator=(const Form& obj)
{
	if (this != &obj)
	{
		this->_signed = obj.getSign();
	}
	return (*this);
}

std::string Form::getName() const {return (this->_name);}

int			Form::getSign() const {return (this->_signed);}

int 		Form::getSGrade() const {return (this->_s_grade);}

int			Form::getEGrade() const {return (this->_e_grade);}

void		Form::beSigned(const Bureaucrat& obj)
{
	if (this->_signed)
		throw Bureaucrat::AlreadySignedException();
	else if (obj.getGrade() <= getSGrade())
		this->_signed = true;
	else
		throw Bureaucrat::GradeTooLowException();	
}

std::ostream& operator<<(std::ostream& out, const Form& obj)
{
	out << obj.getName() << " Form ";
	if (obj.getSign())
		out << ": signed";
	else
		out << ": not signed";
	out << ", sign grade " << obj.getSGrade() << ", execute grade " << obj.getEGrade();
	return (out);		
}	



