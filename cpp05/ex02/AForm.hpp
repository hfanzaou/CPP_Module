#ifndef AForm_HPP
#define AForm_HPP
#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm {
	private :
		std::string const 	_name;
		bool 				_signed;
		int const			_s_grade;
		int const			_e_grade;
	public :
		AForm();
		AForm(const std::string& name, const int& s_grade, const int& e_grade);
		AForm(const AForm& Obj);
		AForm& operator=(const AForm& obj);
		virtual ~AForm();
		std::string  getName() const;
		int			 getSign() const;
		int 		 getSGrade() const;
		int			 getEGrade() const;
		void		 beSigned(const Bureaucrat& obj);
		virtual void		 execute(const Bureaucrat& executer) const = 0;
};

std::ostream& operator<<(std::ostream& out, const AForm& obj);

#endif