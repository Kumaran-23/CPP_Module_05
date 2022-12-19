/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snair <snair@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:14:10 by snair             #+#    #+#             */
/*   Updated: 2022/12/19 21:02:37 by snair            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

//default constructor for AForm Class
AForm::AForm() : _name("Default"), _gradeExecution(150),
			_signGrade(150), _signed(false), _executed(false)
{

}
	

//parameterized constructor for AForm Class
AForm::AForm(const std::string name, int gradeExecute, int signGrade) : _name(name),
			_gradeExecution(gradeExecute), _signGrade(signGrade)
{
	try
	{
		if (this->_gradeExecution > 150 || this->_signGrade > 150)
			throw AForm::GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Form could not be made becauese: " << e.what() << std::endl;
	}
	try
	{
		if (this->_gradeExecution < 1 || this->_signGrade < 1)
			throw AForm::GradeTooHighException();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Form could not be made becauese: " << e.what() << std::endl;
	}
	this->_signed = false;
	this->_executed = false;
}

//copy constructor for AForm Class
AForm::AForm(const AForm &AForm) : _name(AForm._name), _gradeExecution(AForm._gradeExecution),
							_signGrade(AForm._signGrade)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = AForm;
	
}


//destructor fo AForm class
AForm::~AForm()
{
		
}

//copy assignmentn operator of AForm class 
AForm	&AForm::operator=(const AForm &form)
{
	if (this == &form)
		return *this;
	this->_signed = form._signed;
	return (*this);
}

/*checks if bureaucrat is high enough grade to sign AForm, if not throw execption 
if AForm not signed yet, sign AForm, else display message showing AForm already signed*/
void	AForm::beSigned(Bureaucrat &member)
{
	try
	{
		if (member.getGrade() > this->getSignGrade())
			throw AForm::GradeTooLowException();
		if (this->_signed == false)
		{
			this->_signed = true;
			std::cout << member.getName() << " has signed Form: " << this->getName() << std::endl;
		}
		else 
			std::cout << this->getName() << " Form is already signed" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << member.getName() << " was not able to sign " << this->getName() 
		<< " because: " << e.what() << std::endl;
	}
}

//gets the grade required for execution of a AForm
int	AForm::getGradeExecution() const
{
	return (this->_gradeExecution);
}

//gets the grade required to sign a AForm
int AForm::getSignGrade() const
{
	return (this->_signGrade);
}

//gets name value of AForm
const std::string	AForm::getName() const
{
	return (this->_name);
}

//gets the boolean value for if a AForm is signed or not
bool	AForm::getSigned() const
{
	return (this->_signed);
}

//execption message for when grade is too high
const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high was called for Form");
}

//execption message for when grade is too low 
const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low was called for Form");
}

// ostream overload
std::ostream	&operator<<(std::ostream &out, AForm *form)
{
	out << "Form: " << form->getName() << "| Execution grade: " << form->getGradeExecution()
	<< "| Sign grade: " << form->getSignGrade() << "| Signed: " << form->getSigned() << std::endl;
	return (out);
}

std::ostream	&operator<<(std::ostream &out, AForm &form)
{
	out << "Form: " << form.getName() << "| Execution grade: " << form.getGradeExecution()
	<< "| Sign grade: " << form.getSignGrade() << "| Signed: " << form.getSigned() 
	<< "| Executed: " << std::endl;
	return (out);
}

//checks if grade of bureaucrat is high enough to excutes the Form
//checks if Form has already been signed 
//executes the Forms of the concrete classes
//function called by executeForm in Bureaucrat Class try-catch done over there
void	AForm::execute(const Bureaucrat &member) const
{
	if (member.getGrade() > this->_gradeExecution)
		throw AForm::GradeTooLowException();
	if (this->_signed == false)
		throw AForm::FormNotSigned();
	exForm();

}

//execption message for when grade is too high
const char	*AForm::FormNotSigned::what() const throw()
{
	return ("Form not signed has been called for AForm");
}