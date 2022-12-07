#include "Bureaucrat.hpp"

int main()
{
    {
		std::cout << "Test for try and catch direct from function" << std::endl;
		Bureaucrat *a = new Bureaucrat();
        Bureaucrat *b = new Bureaucrat("bob", 2);
		std::cout << a;
        std::cout << b;
		a->increaseGrade();
		a->decreaseGrade();
		a->decreaseGrade();
		std::cout << a;
        b->increaseGrade();
        b->increaseGrade();
        std::cout << b;
		delete a;
        delete b;
		std::cout << std::endl;
	}
	/*std::cout << "Test with try and catch in main" << std::endl;
	{
		Bureaucrat *a = new Bureaucrat("joe", 1);
		std::cout << a;
		try
		{
		a->decreaseGrade();
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << a;
		try
		{
		a->increaseGrade();
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << a;
		try
		{
		a->increaseGrade();
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
            std::cerr << e.what() << std::endl;
		}

		std::cout << a;
		delete a;
        std::cout << std::endl;
	}*/
	std::cout << "initialize with too high a grade and too low a grade" << std::endl;
	{
		Bureaucrat *a = NULL;

		try
		{
			a = new Bureaucrat("bob",0);
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
            std::cerr << e.what() << std::endl;
		}
		if (a != NULL)
		{
			delete a;
		}
	}
	{
		Bureaucrat *a = NULL;
		try
		{
			a = new Bureaucrat("me",170);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << e.what() << std::endl;
		}

		if (a != NULL)
		{
			delete a;
		}
		std::cout << std::endl;
	}
	std::cout << "Testing copy constructor" << std::endl;
	{
		Bureaucrat *a = new Bureaucrat("Mob", 150);
		std::cout << a;
		a->increaseGrade();
        a->increaseGrade();
		std::cout << a;
		Bureaucrat *b = new Bureaucrat(*a);
        std::cout << b;
		b->decreaseGrade();
        b->decreaseGrade();
        b->decreaseGrade();
		std::cout << b;
        std::cout << a;
        delete a;
		delete b;
		std::cout << std::endl;
	}
}