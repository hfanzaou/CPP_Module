#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>

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
		Bureaucrat();
		Bureaucrat(const std::string& name, const int& grade);
		Bureaucrat(const Bureaucrat& obj);
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat& obj);
		std::string 	getName() const;
		int				getGrade() const;
		void			increment();
		void			decrement();
};

std::ostream&	operator<<(std::ostream &out, const Bureaucrat &obj);

#endif
