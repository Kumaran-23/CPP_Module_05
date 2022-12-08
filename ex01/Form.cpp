#include "Form.hpp"

//default constructor for Form Class
Form::Form() : _name("Default"), _gradeExecution(150),
			_signGrade(150), _signed(false)
{

}
	

//parameterized constructor for Form Class
Form::Form(const std::string name, int gradeExecute, int signGrade) : _name(name),
			_gradeExecution(gradeExecute), _signGrade(signGrade)
{
	
	if (this->_gradeExecution < 1 || this->_signGrade < 1)
		throw Form::GradeTooLowException();
	if (this->_gradeExecution > 150 || this->_signGrade > 150)
		throw Form::GradeTooHighException();
	this->_signed = false;		
}

//copy constructor for Form Class
Form::Form(const Form &form) : _name(form._name), _gradeExecution(form._gradeExecution),
							_signGrade(form._signGrade)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = form;
	
}


//destructor fo Form class
Form::~Form()
{
		
}

//copy assignmentn operator of Form class 
Form	&Form::operator=(const Form &form)
{
	if (this == &form)
		return *this;
	this->_signed = form._signed;
	return (*this);
}

/*checks if bureaucrat is high enough grade to sign form, if not throw execption 
if form not signed yet, sign form, else display message showing form already signed*/
void	Form::beSigned(Bureaucrat &member)
{
	if (member.getGrade() > this->getSignGrade())
		throw Form::GradeTooLowException();
	if (this->_signed == false)
	{
		this->_signed = true;
		std::cout << member.getName() << " has signed Form: " << this->getName() << std::endl;
	}
	else 
		std::cout << this->getName() << " Form is already signed" << std::endl;
}

//gets the grade required for execution of a form
int	Form::getGradeExecution() const
{
	return (this->_gradeExecution);
}

//gets the grade required to sign a form
int Form::getSignGrade() const
{
	return (this->_signGrade);
}

//gets name value of Form
const std::string	Form::getName() const
{
	return (this->_name);
}

//gets the boolean value for if a form is signed or not
bool	Form::getSigned() const
{
	return (this->_signed);
}


//execption message for when grade is too high
const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high was called for Form");
}

//execption message for when grade is too low 
const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low was called for Form");
}

// ostream overload
std::ostream	&operator<<(std::ostream &out, Form *form)
{
	out << "Form: " << form->getName() << "| Execution grade: " << form->getGradeExecution()
	<< "| Sign grade: " << form->getSignGrade() << "| Signed: " << form->getSigned() << std::endl;
	return (out);
}

std::ostream	&operator<<(std::ostream &out, Form &form)
{
	out << "Form: " << form.getName() << "| Execution grade: " << form.getGradeExecution()
	<< "| Sign grade: " << form.getSignGrade() << "| Signed: " << form.getSigned() << std::endl;
	return (out);
}