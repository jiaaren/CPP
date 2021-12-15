Nested classes
- define class within class
- can intitialise nested class with 
  - `Parent::Derived c`
  - just like - `Parent c`


Exceptions
- e.g. unclosed brackets, bad memory allocation
- **Exceptions should handle exceptional behavior (i.e. last resort...), useless to optimise exceptions**
- imagine replacing functions returning -1, -2 in functions
- 2 ways of implemeting it
  - sending exceptions and receiving it in same function
  - separate function for sending and receiving
- 2 parts
  - Throw exceptions
  - catch exception and read using `e.what()`
    - picture catch as a **'function' (but not really)** which receives e as a parameter
- receive:
  - specific exception -> inherit from `std::exception` class to create a new exception class
  - process all exceptions using `std::exception`

Question
- What does `throw()` towards end of `what()` mean in std::exception class?
  - [good explanation over throw](https://stackoverflow.com/questions/13258786/writing-custom-exceptions-in-c)
- what does throwing an **int** mean (or float etc)?
  - [better to throw std::exception than int](https://stackoverflow.com/questions/6976489/c-exceptions-int-or-stdexception)


Stackoverflow
- [Good explanation over exceptions](https://stackoverflow.com/questions/3763457/c-exception-throw-annotations-on-virtual-functions)
- using **noexcept** - [avoid program from terminating](https://stackoverflow.com/questions/54011523/terminate-called-after-throwing-an-instance-of-an-exception-core-dumped) - 


Issues noted
- including `public` solved the issue
  - `class GradeTooHighException : public std::exception`


What's virtual for inheritance for?
- don't understand what's the best practice...


Pure virtual class
- pure virtual for destructor -> not good practice
- https://stackoverflow.com/questions/24316700/c-abstract-class-destructor/24317407