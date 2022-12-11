/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snair <snair@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:15:19 by snair             #+#    #+#             */
/*   Updated: 2022/12/11 16:15:20 by snair            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//default constructor for Bureaucrat Class
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{

}
	

//parameterized constructor for Bureaucrat Class
Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade = grade;		
}

//copy constructor for Bureaucrat Class
Bureaucrat::Bureaucrat(const Bureaucrat &member) : _name(member._name)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = member;
	
}


//destructor fo Bureaucrat class
Bureaucrat::~Bureaucrat()
{
		
}

//copy assignmentn operator of Bureaucrat class 
Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &member)
{
	if (this == &member)
		return *this;
	this->_grade = member._grade;
	return (*this);
}

//gets name value of bureaucrat
const std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

//increases the grade of the Bureaucrat (eg: 2 to 1/ 145 to 144)
void	Bureaucrat::increaseGrade()
{
	std::cout << "Bureaucrat " << this->_name << " grade is trying to be increased" 
				<< std::endl;
	try
	{
		if (this->_grade <= 1)
			throw Bureaucrat::GradeTooHighException();
		this->_grade -= 1;
		std::cout << "Bureaucrat " << this->_name << " has a grade increase and is now grade " 
				<< this->_grade << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

//decreases the grade of the Bureaucrat (eg: 2 to 3/ 145 to 146)
void	Bureaucrat::decreaseGrade()
{
	std::cout << "Bureaucrat " << this->_name << " grade is trying to be decreased" 
				<< std::endl;
	try
	{
		if (this->_grade >= 150)
			throw Bureaucrat::GradeTooLowException();
		this->_grade += 1;
		std::cout << "Bureaucrat " << this->_name << " has a grade decrease and is now grade " 
				<< this->_grade << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

//execption message for when grade is too high
const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high was called for Bureaucrat");
}

//execption message for when grade is too low 
const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low was called for Bureaucrat");
}

//gets grade value of bureaucrat
int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

// ostream overload
std::ostream	&operator<<(std::ostream &out, Bureaucrat *member)
{
	out << "Bureaucrat: " << member->getName() << " grade: " << member->getGrade() << std::endl;
	return (out);
}

// ostream overload
std::ostream	&operator<<(std::ostream &out, Bureaucrat &member)
{
	out << "Bureaucrat: " << member.getName() << " grade: " << member.getGrade() << std::endl;
	return (out);
}

//signes form if grade is high enough
void	Bureaucrat::signForm(AForm &form)
{
	form.beSigned(*this);
}

//executes the form if grade is high enough throws an exception otherwise
void	Bureaucrat::executeForm(const AForm &form) const
{
	try
	{
		std::cout << this->_name << " is trying to executed Form: " << form.getName() << std::endl;
		form.execute(*this);
		std::cout << this->_name << " executed Form: " << form.getName() << " successfully." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->_name << " was not able to execute Form: " << form.getName()
		<< " because: "<< e.what() << std::endl;
	}
	
}