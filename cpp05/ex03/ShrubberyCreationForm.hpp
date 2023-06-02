#pragma once
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private :
		const std::string _target;
	public :
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);	
		ShrubberyCreationForm(const ShrubberyCreationForm& obj);
		~ShrubberyCreationForm();
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& obj);
		void		 execute(const Bureaucrat& executer) const;
};