/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snair <snair@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:14:46 by snair             #+#    #+#             */
/*   Updated: 2022/12/11 16:14:47 by snair            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

//default constructor for RobotomyRequestForm Class
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 45, 72)
{
	this->_target = "Default";
}

//parameterized constructor for RobotomyRequestForm Class
RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 45, 72)
{
	this->_target = target;
}

//copy constructor for RobotomyRequestForm Class
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &form) : AForm(form)
{
	*this = form;
}

//destructor for RobotomyRequestForm class
RobotomyRequestForm::~RobotomyRequestForm()
{
	
}

//copy assignmentn operator of RobotomyRequestForm class
RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &form)
{
	if (this == &form)
		return *this;
	this->_target = form._target;
	return (*this);
}

std::string   RobotomyRequestForm::getTarget() const
{
    return (this->_target);
}

//executes the  form to robotomize target, works only 50% of the time
//function gets called in excute from AForm class 
void	RobotomyRequestForm::exForm() const
{
    srand(time(NULL));
	if (rand() % 2 == 0)
		std::cout << "DddRrRrriIIiIiLlLlL" << this->getTarget() << " was robotomized" << std::endl;
	else
		std::cout << "Robotomization of " << this->getTarget() << " has failed" << std::endl;
}

std::ostream	&operator<<(std::ostream &out, RobotomyRequestForm &form)
{
	out << "Form: " << form.getName() << "| Execution grade: " << form.getGradeExecution()
	<< "| Sign grade: " << form.getSignGrade() << "| Signed: " << form.getSigned() 
    << "| Target: " << form.getTarget() << std::endl;
	return (out);
}