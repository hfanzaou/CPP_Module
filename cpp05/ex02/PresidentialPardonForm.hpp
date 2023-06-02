#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private :
		const std::string _target;
	public :
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& target);	
		PresidentialPardonForm(const PresidentialPardonForm& obj);
		~PresidentialPardonForm();
		PresidentialPardonForm& operator=(const PresidentialPardonForm& obj);
		void		 execute(const Bureaucrat& executer) const;
};
