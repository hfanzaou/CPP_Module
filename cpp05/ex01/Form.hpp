#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form {
	private :
		const std::string 	_name;
		bool 				_signed;
		const int 			_s_grade;
		const int 			_e_grade;
	public :
		Form();
		Form(const std::string& name, const int& s_grade, const int& e_grade);
		Form(const Form& Obj);
		Form& operator=(const Form& obj);
		~Form();
		std::string  getName() const;
		int			 getSign() const;
		int 		 getSGrade() const;
		int			 getEGrade() const;
		void		 beSigned(const Bureaucrat& obj);
};

std::ostream& operator<<(std::ostream& out, const Form& obj);

#endif