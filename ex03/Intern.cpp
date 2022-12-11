/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snair <snair@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:20:52 by snair             #+#    #+#             */
/*   Updated: 2022/12/11 16:20:53 by snair            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	
}

Intern::Intern(const Intern &intern)
{
	*this = intern;
}

Intern::~Intern()
{

}

Intern	&Intern::operator=(const Intern &intern)
{
	if (this == &intern)
		return(*this);
	return (*this);
}

//execption for invalid form 
const char	*Intern::FormInvalidException::what() const throw()
{
	return ("Form Invalid was called for Intern");
}

static AForm *makePresident(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static AForm *makeRobot(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm *makeShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}


//makes the appropriate form that is passed as a parameter
//checks if form matches any valid form, if yes calls the correct function
AForm	*Intern::makeForm(const std::string form, const std::string target)
{
	AForm	*validForms[3] = {makePresident(target), makeRobot(target), makeShrubbery(target)};
	const std::string forms[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	AForm	*formToMake;
	formToMake = NULL;
	for (int i = 0; i < 3; i++)
	{
		if (form == forms[i])
		{
			std::cout << "Intern creates " << form << std::endl;
			formToMake = validForms[i];
		}
		else
			delete validForms[i];
	}
	if (formToMake == NULL)
		throw  Intern::FormInvalidException();
	return (formToMake);
}
