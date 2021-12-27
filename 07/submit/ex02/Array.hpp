#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T>
class Array
{
public:
    // Array<T> and Array have the same output
    Array(void);
    Array(unsigned int n);
    Array(Array const &a);
    ~Array(void);
    Array &operator=(Array const &rhs);
    T &operator[](int index) const;
    // getters
    int size(void) const;
    class invalidSize : public std::exception
    {
        virtual const char *what() const throw();
    };

private:
    T *_elem;
    unsigned int _size;
};

/*
    Need to have class definition and functions in hpp file for templates
    - https://stackoverflow.com/questions/8752837/undefined-reference-to-template-class-constructor

    Is there a better way to do this than having
    template <typename T> for all functions?
    - i don't think so?
    https://www.ibm.com/docs/en/zos/2.1.0?topic=templates-member-functions-class

    Constructor Array is member function of template Array<T>
    https://stackoverflow.com/questions/69667920/name-followed-by-must-be-a-class-or-namespace-name-error-when-making-a-te
    - need to include <T>

    Empty array - NULL pointer and size 0
*/
template <typename T>
Array<T>::Array(void) : _elem(NULL), _size(0)
{
    return;
}

/*
    new in C++ doesn't return NULL on failure
    - it did before, but subsequently replaced by exceptions
    - https://stackoverflow.com/questions/26419786/why-doesnt-new-in-c-return-null-on-failure

    Initialising allocated variables to 0 (with () notation)
    - https://stackoverflow.com/questions/2204176/how-to-initialise-memory-with-new-operator-in-c
    - https://stackoverflow.com/questions/7546620/operator-new-initializes-memory-to-zero
*/
template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
    if (n == 0)
        _elem = NULL;
    else
        _elem = new T[n]();
    return;
}

template <typename T>
Array<T>::Array(Array const &a) : _elem(NULL), _size(0)
{
    *this = a;
    return;
}

template <typename T>
Array<T>::~Array(void)
{
    if (_elem)
        delete[] _elem;
    return;
}

/*
    why do i need to wrap the first Array<T> with <>?
    - because we're returning Array of typename T

    Resizing with new and delete
    https://stackoverflow.com/questions/3482941/how-do-you-realloc-in-c
*/
template <typename T>
Array<T> &Array<T>::operator=(Array const &rhs)
{
    unsigned int rhsSize = rhs.size();
    if (_size != rhsSize)
    {
        if (_elem)
            delete[] _elem;
        if (rhsSize != 0)
            _elem = new T[rhsSize]();
    }
    if (rhsSize == 0)
        _elem = NULL;
    else
        for (int i = 0; static_cast<unsigned int>(i) < rhsSize; i++)
            _elem[i] = rhs[i];
    _size = rhsSize;
    return (*this);
}

/*
    [] operator
    https://www.geeksforgeeks.org/overloading-subscript-or-array-index-operator-in-c/
*/
template <typename T>
T &Array<T>::operator[](int index) const
{
    if (static_cast<unsigned int>(index) >= _size || index < 0)
        throw invalidSize();
    return (_elem[index]);
}

template <typename T>
int Array<T>::size(void) const
{
    return (_size);
}

template <typename T>
const char *Array<T>::invalidSize::what() const throw()
{
    return ("Index inputted is out of bounds\n");
}

#endif
