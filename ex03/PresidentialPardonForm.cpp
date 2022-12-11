/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snair <snair@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:21:24 by snair             #+#    #+#             */
/*   Updated: 2022/12/11 16:21:25 by snair            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

//default constructor for PresidentialPardonForm Class
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 5, 25)
{
	this->_target = "Default";
}

//parameterized constructor for PresidentialPardonForm Class
PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 5, 25)
{
	this->_target = target;
}

//copy constructor for PresidentialPardonForm Class
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &form) : AForm(form)
{
	*this = form;
}

//destructor for PresidentialPardonForm class
PresidentialPardonForm::~PresidentialPardonForm()
{
	
}

//copy assignmentn operator of PresidentialPardonForm class
PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &form)
{
	if (this == &form)
		return *this;
	this->_target = form._target;
	return (*this);
}

std::string   PresidentialPardonForm::getTarget() const
{
    return (this->_target);
}

//executes the  form pardoning the target by Zaphod Beeblebrox 
//function gets called in excute from AForm class 
void	PresidentialPardonForm::exForm() const
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::ostream	&operator<<(std::ostream &out, PresidentialPardonForm &form)
{
	out << "Form: " << form.getName() << "| Execution grade: " << form.getGradeExecution()
	<< "| Sign grade: " << form.getSignGrade() << "| Signed: " << form.getSigned() 
    << "| Target: " << form.getTarget() << std::endl;
	return (out);
}
