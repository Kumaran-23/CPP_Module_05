/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snair <snair@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:21:31 by snair             #+#    #+#             */
/*   Updated: 2022/12/11 16:21:33 by snair            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"
#include <iostream>
#include <string>

class PresidentialPardonForm : public AForm
{
	public:
		    PresidentialPardonForm();
            PresidentialPardonForm(const std::string target);
		    PresidentialPardonForm(const PresidentialPardonForm &form);
		    ~PresidentialPardonForm();
		    PresidentialPardonForm	&operator=(const PresidentialPardonForm &form);
            std::string	getTarget() const;
            void    exForm() const;
	private:
		    std::string _target;
};

std::ostream				&operator<<(std::ostream &output , PresidentialPardonForm &form);

#endif