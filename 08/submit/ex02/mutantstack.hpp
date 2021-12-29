#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <list>
#include <iostream>
#include <iterator>

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
	iterator const &begin(void) const;
	iterator const &end(void) const;
	void push(T n);
	void pop(void);

private:
	std::list<T> _l;
	void _copyToList(void);
};

// template <typename T>
// class MutantStack : public std::stack<T>
// {
// private:
// 	std::list<T> _l;
// 	void _copyToList(void);

// public:
// 	MutantStack(void);
// 	MutantStack(MutantStack const &ms);
// 	virtual ~MutantStack(void){};
// 	// create iterator class
// 	typedef std::list<T> base_list;
// 	typedef typename base_list::iterator iterator;
// 	typedef typename base_list::const_iterator const_iterator;
// 	// iterator method for begin and end
// 	using _l::begin;
// 	using _l::end;
// 	void push(T n);
// 	void pop(void);
// };

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

./mutantstack.hpp:119:9: error: no viable conversion from returned value of type 'std::__1::list<int, std::__1::allocator<int> >::const_iterator' (aka '__list_const_iterator<int, void *>') to function return type
      'MutantStack<int>::iterator'
        return (_l.begin());

./mutantstack.hpp:17:8: note: candidate constructor (the implicit copy constructor) not viable: cannot bind base class object of type 'std::__1::list<int, std::__1::allocator<int> >::const_iterator'
      (aka '__list_const_iterator<int, void *>') to derived class reference 'const MutantStack<int>::iterator &' for 1st argument
        class iterator : public std::list<T, std::allocator<T> >::const_iterator
              ^
- added reference (&) to silence error
*/
template<typename T>
typename MutantStack<T>::iterator const &MutantStack<T>::begin(void) const
{
	return (_l.begin());
}

template<typename T>
typename MutantStack<T>::iterator const &MutantStack<T>::end(void) const
{
	return (_l.end());
}

#endif
