/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snair <snair@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:13:45 by snair             #+#    #+#             */
/*   Updated: 2022/12/11 16:13:46 by snair            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	{
		std::cout << "Test 1" << std::endl;
		Bureaucrat a;
		Form b;
		std::cout << a;
		std::cout << b;

		try
		{
			b.beSigned(a);
		}
		catch(const std::exception& e)
		{
			std::cerr << a.getName() << " was not able to sign " << b.getName() << " because: " << e.what() << std::endl;
		}
		std::cout << b;
		std::cout << std::endl;
	}
	std::cout << "Test 2" << std::endl;
	{
		Bureaucrat a("Bob", 135);
		Bureaucrat b("Billiam", 1);
		Form c("Stall leasing", 100, 130);
		std::cout << std::endl;
		std::cout << a;
		std::cout << b;
		std::cout << c;
		try
		{
			a.signForm(c);
		}
		catch(const std::exception& e)
		{
			std::cerr << a.getName() << " was not able to sign the Form " 
			<< c.getName() << " because: " << e.what() << std::endl;
		}
		std::cout << c;
		//billiam signs the Form
		try
		{
			c.beSigned(b);
		}
		catch(const std::exception& e)
		{
			std::cerr << b.getName() << " was not able to sign the Form " 
			<< c.getName() << " becaue: " << e.what() << std::endl;
		}
		std::cout << c;
		//billiam tries to sign the from again
		try
		{
			b.signForm(c);
		}
		catch(const std::exception& e)
		{
			std::cerr << b.getName() << " was not able to sign the Form " 
			<< c.getName() << " because: " << e.what() << std::endl;
		}
		try
		{
			Form d(c);
			std::cout << d;
		}
		catch(const std::exception& e)
		{
			std::cerr << b.getName() << " was not able to sign the Form " 
			<< c.getName() << " because: " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	std::cout << "Test 3" << std::endl;
	{
		std::cout << std::endl;
		//execution grade to0 low
		try
		{
			Form a("lemonade stand", 160, 145);
		}
		catch (const std::exception& e)
		{
			std::cerr << "Form could not be made becauese: " << e.what() << std::endl;
		}
		//sign grade too low
		try
		{
			Form a("limeade stand",145, 160);
		}
		catch (const std::exception& e)
		{
			std::cerr << "Form could not be made becauese: " << e.what() << std::endl;
		}
		//sign grade too high
		try
		{
			Form a("higness", 1, -1);
		}
		catch (const std::exception& e)
		{
			std::cerr << "Form could not be made becauese: " << e.what() << std::endl;
		}
		//execution grade too hgh
		try
		{
			Form a("2", 0, 12);
		}
		catch (const std::exception& e)
		{
			std::cerr << "Form could not be made becauese: " << e.what() << std::endl;
		}
	}
	return (0);
}