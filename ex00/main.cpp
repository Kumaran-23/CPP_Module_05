#include "Bureaucrat.hpp"

int main()
{
    {
		std::cout << "Test 1" << std::endl;
		Bureaucrat a;
        Bureaucrat b("bob", 2);
		std::cout << a;
        std::cout << b;
		try
		{
			a.decreaseGrade();
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			a.decreaseGrade();
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << a;
		try
		{
			 b.increaseGrade();
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			  b.increaseGrade();
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
        std::cout << b;
		std::cout << std::endl;
	}
	std::cout << "Test with try and catch in main" << std::endl;
	{
		Bureaucrat a ("joe", 1);
		std::cout << a;
		try
		{
			a.decreaseGrade();
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << a;
		try
		{
			a.increaseGrade();
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << a;
		try
		{
			a.increaseGrade();
		}
		catch(std::exception& e)
		{
            std::cerr << e.what() << std::endl;
		}

		std::cout << a;
        std::cout << std::endl;
	}
	std::cout << "initialize with too high a grade and too low a grade" << std::endl;
	{
		try
		{
			Bureaucrat a("bob",0);
		}
		catch(std::exception& e)
		{
            std::cerr << e.what() << std::endl;
		}
	}
	{
		try
		{
			Bureaucrat a("me",170);
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	std::cout << "Testing copy constructor" << std::endl;
	{
		Bureaucrat a("Mob", 150);
		std::cout << a;
		try
		{
			a.increaseGrade();
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}	
		try
		{
			a.increaseGrade();
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		Bureaucrat b(a);
        std::cout << b;
		std::cout << a;
		try
		{
			b.decreaseGrade();
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			  b.decreaseGrade();
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			 b.decreaseGrade();
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << b;
        std::cout << a;
		Bureaucrat c;
		c = a;
		std::cout << c;
        std::cout << a;
		try
		{
			c.increaseGrade();
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}	
		try
		{
			c.increaseGrade();
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << c;
		std::cout << b;
        std::cout << a;
		std::cout << std::endl;
	}
}