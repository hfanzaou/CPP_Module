#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include "Form.hpp"

class Form;
class Bureaucrat {
	private :
		const std::string	_name;
		int 				_grade;
	public :
		class GradeTooHighException : public std::exception {
			public :
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public :
				const char *what() const throw();
		};
		class AlreadySignedException : public std::exception {
			public :
				const char *what() const throw();
		};
		Bureaucrat();
		Bureaucrat(const std::string& name, const int& grade);
		Bureaucrat(const Bureaucrat& obj);
		~Bureaucrat();
		Bureaucrat&  operator=(const Bureaucrat& obj);
		std::string  getName() const;
		int			 getGrade() const;
		void		 increment();
		void		 decrement();
		void		 signForm(Form& obj);
};


std::ostream&	operator<<(std::ostream &out, const Bureaucrat &obj);

#endif
