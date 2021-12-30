#include <iostream>
#include <algorithm>
#include <stdexcept>
#include "span.hpp"

void print(int i)
{
	std::cout << i << " ";
}

int main(void)
{
	{
		std::cout << "<--- Declare Span --->\n";
		Span sp = Span(5);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Inputted numbers for span of size 5: \n";
		std::for_each(sp.getBegin(), sp.getEnd(), print);
		std::cout << "\n";

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span : " << sp.longestSpan() << std::endl;

		std::cout << "\n<--- Copy using range for span (addRange) --->\n";
		Span test = Span(5);
		test.addRange(sp.getBegin(), sp.getEnd());
		std::for_each(test.getBegin(), test.getEnd(), print);
		std::cout << "\n";

		std::cout << "\n<--- Exceptions testing --->\n";
		std::cout << "*** Too many inputs (above space allocated) \n";
		try
		{
			sp.addNumber(132);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << "\n";
		}

		Span nosize;
		std::cout << "\n*** Calculating min and max span for Span Class with no size \n";
		try
		{
			nosize.shortestSpan();
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << "\n";
		}
		try
		{
			nosize.longestSpan();
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << "\n";
		}

		Span onesize(1);
		onesize.addNumber(123);
		std::cout << "\n*** Calculating min and max span for Span Class with one size \n";
		try
		{
			onesize.shortestSpan();
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << "\n";
		}
		try
		{
			onesize.longestSpan();
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << "\n";
		}

		Span twosize(2);
		twosize.addNumber(100);
		twosize.addNumber(200);
		std::cout << "\n*** Calculating min and max span for Span Class with two size \n";
		try
		{
			twosize.shortestSpan();
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << "\n";
		}
		try
		{
			twosize.longestSpan();
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << "\n";
		}
		std::cout << "[No errors noted! :))]\n";
	}
}
