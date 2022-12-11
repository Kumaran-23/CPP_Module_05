/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snair <snair@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:14:03 by snair             #+#    #+#             */
/*   Updated: 2022/12/11 16:14:04 by snair            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

class AForm;

class Bureaucrat
{
	public:
		    Bureaucrat();
		    Bureaucrat(const std::string name, int grade);
		    Bureaucrat(const Bureaucrat &member);
		    ~Bureaucrat();
		    Bureaucrat  &operator=(const Bureaucrat &member);
            int					getGrade() const;
		    void				increaseGrade();
		    void				decreaseGrade();
		    const std::string	getName() const;
			void				signForm(AForm &form);
			void				executeForm(const AForm &form) const;

        //execption classes for grade to high and grade to low    
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
	private:
		const std::string	_name;
		int		_grade;
};

//ostream overload
std::ostream	&operator<<(std::ostream &out, Bureaucrat *a);
std::ostream	&operator<<(std::ostream &out, Bureaucrat &a);


#endif