#include <iostream>
#include <list>
#include "mutantstack.hpp"

void print(std::string str)
{
	std::cout << str << "\n";
}

int main(void)
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);

	MutantStack<int> another(mstack);
	std::cout << "another " << another.top() << std::endl;
	another.pop();
	std::cout << another.top() << std::endl;

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	print("\n<---- Iterating using standard iterator (and modifying value subsequently after printing)---->");
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		(*it)++;
		++it;
	}

	print("\n<---- Iterating using const iterator ---->");
	MutantStack<int>::const_iterator cit = mstack.cbegin();
	MutantStack<int>::const_iterator cite = mstack.cend();
	while (cit != cite)
	{
		std::cout << *cit << std::endl;
		++cit;
	}

	print("\n<---- Iterating using standard reverse iterator (and modifying value subsequently after printing)---->");
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();
	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		(*rit)++;
		++rit;
	}

	print("\n<---- Iterating using const reverse iterator ---->");
	MutantStack<int>::const_reverse_iterator crit = mstack.crbegin();
	MutantStack<int>::const_reverse_iterator crite = mstack.crend();
	while (crit != crite)
	{
		std::cout << *crit << std::endl;
		++crit;
	}
	return (0);
}
