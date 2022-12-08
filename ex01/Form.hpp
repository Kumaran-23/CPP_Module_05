#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
			Form();
			Form(const Form &form);
			Form(const std::string name, int signGrade, int executeGrade);
			~Form();
			Form    &operator=(const Form &form);
			void				beSigned(Bureaucrat &member);
			int					getGradeExecution() const;
			int					getSignGrade() const;
			const std::string	getName() const;
			bool				getSigned() const;

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
			const int			_gradeExecution;
			const int			_signGrade;
			bool				_signed;
};

std::ostream				&operator<<(std::ostream &output , Form *form);
std::ostream				&operator<<(std::ostream &output , Form &form);

#endif