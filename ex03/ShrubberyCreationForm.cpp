/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snair <snair@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:21:50 by snair             #+#    #+#             */
/*   Updated: 2022/12/11 16:21:51 by snair            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

//default constructor for ShrubberyCreationForm Class
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 137, 145)
{
	this->_target = "Default";
}

//parameterized constructor for ShrubberyCreationForm Class
ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 137, 145)
{
	this->_target = target;
}

//copy constructor for ShrubberyCreationForm Class
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &form) : AForm(form)
{
	*this = form;
}

//destructor for ShrubberyCreationForm class
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	
}

//copy assignmentn operator of ShrubberyCreationForm class
ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &form)
{
	if (this == &form)
		return *this;
	this->_target = form._target;
	return (*this);
}

std::string   ShrubberyCreationForm::getTarget() const
{
    return (this->_target);
}

//executes the  form, creates a file with ASCII tree art
//function gets called in excute from AForm class 
void	ShrubberyCreationForm::exForm() const
{
    std::ofstream output(this->getTarget().append("_shrubbery").c_str());
    for(int i = 0; i < 4; i++)
    {
        output <<
			"         -" << std::endl <<
			"        - -" << std::endl <<
			"     //~~  ~~\\" << std::endl <<
			"   //~~      ~~\\" << std::endl <<
			" //              \\" << std::endl <<
			" \\  _-     -_   //" << std::endl <<
			"  \\   \\  //   //" << std::endl <<
			"    ~~~ \\//~~~~" << std::endl <<
			"        |  |" << std::endl <<
			"        |  |" << std::endl <<
			"        |  |" << std::endl <<
			"    //$$$$$$$\\" << std::endl <<
			"  .//$$$$$$$$$\\." << std::endl <<
			". //$$i$$$$$$$$\\." << std::endl <<
		std::endl;
    }
	output.close();
}

std::ostream	&operator<<(std::ostream &out, ShrubberyCreationForm &form)
{
	out << "Form: " << form.getName() << "| Execution grade: " << form.getGradeExecution()
	<< "| Sign grade: " << form.getSignGrade() << "| Signed: " << form.getSigned() 
    << "| Target: " << form.getTarget() << std::endl;
	return (out);
}