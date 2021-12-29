#include <iostream>
#include <list>
#include "mutantstack.hpp"

void print(std::string str)
{
	std::cout << str << "\n";
}

int main(void)
{
	print("<--- Declaring stack --->");
	MutantStack<int> mstack;
	mstack.push(5);
	std::cout << "** mstack.push(5); mstack.top();-- \n"
			  << mstack.top() << "\n";
	mstack.push(17);
	std::cout << "\n** mstack.push(17); mstack.top();-- \n"
			  << mstack.top() << "\n";

	mstack.pop();
	std::cout << "\n** mstack.pop(); mstack.top();-- \n"
			  << mstack.top() << "\n";

	std::cout << "\n** push 3 5 737 0-- \n";
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	print("\n<---- Iterating using standard iterator (and modifying value subsequently after printing)---->");
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	while (it != ite)
	{
		std::cout << *it << "\n";
		(*it)++;
		++it;
	}

	print("\n<---- Iterating using const iterator ---->");
	MutantStack<int>::const_iterator cit = mstack.cbegin();
	MutantStack<int>::const_iterator cite = mstack.cend();
	while (cit != cite)
	{
		std::cout << *cit << "\n";
		++cit;
	}

	print("\n<---- Iterating using standard reverse iterator (and modifying value subsequently after printing)---->");
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();
	while (rit != rite)
	{
		std::cout << *rit << "\n";
		(*rit)++;
		++rit;
	}

	print("\n<---- Iterating using const reverse iterator ---->");
	MutantStack<int>::const_reverse_iterator crit = mstack.crbegin();
	MutantStack<int>::const_reverse_iterator crite = mstack.crend();
	while (crit != crite)
	{
		std::cout << *crit << "\n";
		++crit;
	}

	print("\n<---- Copy constructor ---->");
	MutantStack<int> copy(mstack);
	MutantStack<int>::iterator a;
	for (a = copy.begin(); a != copy.end(); ++a)
		std::cout << *a << "\n";

	print("\n<---- Assignment ---->");
	MutantStack<int> assign;
	assign = mstack;
	MutantStack<int>::iterator b;
	for (b = assign.begin(); b != assign.end(); ++b)
		std::cout << *b << "\n";
	return (0);
}
