#ifndef	BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	public:
		    Bureaucrat();
		    Bureaucrat(const std::string name, int grade);
		    Bureaucrat(const Bureaucrat &member);
		    ~Bureaucrat();
		    Bureaucrat  &operator=(const Bureaucrat &member);
            int					getGrade();
		    void				increaseGrade();
		    void				decreaseGrade();
		    const std::string	getName() const;
			void				signForm(Form &form);

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