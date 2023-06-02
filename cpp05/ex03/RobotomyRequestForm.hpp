#pragma once
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private :
		const std::string _target;
	public :
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& target);	
		RobotomyRequestForm(const RobotomyRequestForm& obj);
		~RobotomyRequestForm();
		RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);
		void		 execute(const Bureaucrat& executer) const;
};
