#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>

Base *generate(void)
{
	int i;

	srand(time(NULL));
	i = rand() % 3;
	if (i == 0)
	{   
		std::cout << "Generated A\n" << std::endl;
		return (new A);
	}
	else if (i == 1)
	{   
		std::cout << "Generated B\n" << std::endl;
		return (new B);
	}
	else
	{   
		std::cout << "Generated C\n" << std::endl;
		return (new C);
	}

}

void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A: Identify(Base* p) Success" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B: Identify(Base* p) Success" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C: Identify(Base* p) Success" << std::endl;
	else
		std::cout << "Error: unknown type" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		std::cout << "A: Identify(Base& p) Success" << std::endl;
		(void)a;
	}
	catch(const std::exception& e)
	{
		try
		{
			B &b = dynamic_cast<B &>(p);
			std::cout << "B: Identify(Base& p) Success" << std::endl;
			(void)b;
		}
		catch(const std::exception& e)
		{
			try
			{
				C &c = dynamic_cast<C &>(p);
				std::cout << "C: Identify(Base& p) Success" << std::endl;
				(void)c;
			}
			catch(const std::exception& e)
			{
				std::cerr << "Error: " << e.what() << std::endl;
			}
		}
	}
}

int main(void)
{
	Base *ptr = generate();
	//Base *ptr = new Base;
	std::cout << "<POINTER>" << std::endl;
	identify(ptr);
	std::cout << "<REFERENCE>" << std::endl;
	identify(*ptr);

	delete ptr;
}
