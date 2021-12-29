#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <list>
#include <iostream>

std::list<int>::iterator it;

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack(void);
	MutantStack(MutantStack const &ms);
	virtual ~MutantStack(void){};
	// create iterator class
	class iterator : public std::list<T>::const_iterator
	{
		// pre increment and decrement - copy from std::list iterator
		// != operator - copy from std::list iterator
	};
	// iterator method for begin and end
	iterator begin(void) const;
	iterator end(void) const;
	void push(T n);
	void pop(void);

private:
	std::list<T> _l;
	void _copyToList(void);
};

/*
- this seems unnecessary now
mutantstack.hpp:36:13: error: there are no arguments to ‘size’ that depend on a template parameter, so a declaration of ‘size’ must be available [-fpermissive]
   36 |     int s = size();
	  |             ^~~~
https://stackoverflow.com/questions/9941987/there-are-no-arguments-that-depend-on-a-template-parameter
*/
template <typename T>
void MutantStack<T>::_copyToList(void)
{
	std::stack<T> dup(static_cast<std::stack<T> >(*this));
	// execute this from base class
	int s = std::stack<T>::size();
	for (int i = 0; i < s; i++)
	{
		_l.push_back(dup.top());
		dup.pop();
	}
	return;
}

// base class constructor void no need to explicitly call
template <typename T>
MutantStack<T>::MutantStack(void) : std::stack<T>()
{
	std::cout << "executed" << std::endl;
}

// need copy constructor to run base class std::stack<T>'s copy constructor
template <typename T>
MutantStack<T>::MutantStack(MutantStack const &ms) : std::stack<T>(ms)
{
	(void)ms;
	std::cout << "executed again" << std::endl;
	_copyToList();
}

template<typename T>
void MutantStack<T>::push(T n)
{
	// need to run base class functions again
	std::stack<T>::push(n);
	_l.push_front(n);
	return;
}

template<typename T>
void MutantStack<T>::pop(void)
{
	// need to run base class functions again
	std::stack<T>::pop();
	_l.pop_front();
	return;
}

/*
mutantstack.hpp:90:1: error: need ‘typename’ before ‘MutantStack<T>::iterator’ because ‘MutantStack<T>’ is a dependent scope
   90 | MutantStack<T>::iterator &MutantStack<T>::begin(void) const
	  | ^~~~~~~~~~~~~~
	  | typename 
*/
template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void) const
{
	return (_l.begin());
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void) const
{
	return (_l.end());
}

#endif
