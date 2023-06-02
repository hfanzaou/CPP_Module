#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Bureaucrat"), _grade(150)
{
	std::cout << "Default Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, const int &grade) : _name(name), _grade(grade)
{
	std::cout << "Constructor called" << std::endl;
	if (_grade < 1)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = obj;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &obj) 
		this->_grade = obj._grade;
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const 
{
	return (this->_grade);
}

void	Bureaucrat::increment()
{
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;	
}

void	Bureaucrat::decrement()
{
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;	
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

std::ostream&	operator<<(std::ostream &out, const Bureaucrat &obj)
{
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return (out);
}