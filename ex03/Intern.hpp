/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snair <snair@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:21:09 by snair             #+#    #+#             */
/*   Updated: 2022/12/11 16:21:10 by snair            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class   Intern
{
	public:
			Intern();
			Intern(const Intern &intern);
			~Intern();
			Intern	&operator=(const Intern &intern);
			AForm	*makeForm(const std::string form, const std::string target);
		class FormInvalidException : public std::exception
		{
			public:
					virtual const char	*what() const throw();
		};
};

#endif