/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snair <snair@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:21:16 by snair             #+#    #+#             */
/*   Updated: 2022/12/19 21:13:35 by snair            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
	std::cout << "Test 1" << std::endl;
	{
		Bureaucrat	a("Director", 3);
		Intern		intern;
		AForm		*b;
		try
		{
			b = intern.makeForm("PresidentialPardonForm", "Jibby");
			a.signForm(*b);
			a.executeForm(*b);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << a;
		std::cout << b;
		delete b;
		std::cout << std::endl;
	}
	std::cout << "Test 2" << std::endl;
	{
		Bureaucrat	a("Director", 3);
		Intern		intern;
		AForm		*b;
		try
		{
			b = intern.makeForm("RobotomyRequestForm", "Cop");
			a.signForm(*b);
			a.executeForm(*b);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << a;
		std::cout << "Cop" << b;
		delete b;
		std::cout << std::endl;
	}
	std::cout << "Test 3" << std::endl;
	{
		Bureaucrat	a("Director", 3);
		Bureaucrat	c("Newhire", 150);
		Bureaucrat	e("Employee", 100);
		Intern		intern;
		AForm		*b;
		AForm		*d;
		try
		{
			b = intern.makeForm("ShrubberyCreationForm", "Park");
			a.signForm(*b);
			a.executeForm(*b);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			d = intern.makeForm("ShrubberyCreationForm", "City");
			c.signForm(*d);
			e.executeForm(*d);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << a;
		std::cout << "Park " << b;
		std::cout << c;
		std::cout << e;
		std::cout << "City " << d;
		delete b;
		delete d;
		std::cout << std::endl;
	}
	std::cout << "Test 4" << std::endl;
	{
		Bureaucrat	a("Director", 3);
		Intern		intern;
		AForm		*b;
		try
		{
			b = intern.makeForm("MagicalGatheringForm", "Mashel");
			a.signForm(*b);
			a.executeForm(*b);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		delete b;
		std::cout << std::endl;
	}
	return (0);
}