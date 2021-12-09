Err
- copy constructor may not have a parameter of type
- https://stackoverflow.com/questions/9066052/copy-constructor-parameters


Ex00
1. [Orthodox class](https://flylib.com/books/en/2.937.1.244/1/)
- specifies four required functions
- default constructor, the copy constructor, the copy assignment operator, and the destructor. 

Ex01
- roundf - floor makes negative numbers round up
- // We can call other private variables of classes in another class's member functions


Pre and postfix operator overloading
https://www.programiz.com/cpp-programming/increment-decrement-operator-overloading
https://docs.microsoft.com/en-us/cpp/cpp/increment-and-decrement-operator-overloading-cpp?view=msvc-170
- the postfix form accepts an extra argument of type int.

- Point& operator++();       // Prefix increment operator.
    - return & because no need to create another variable
    - update current variable and return
- Point operator++(int);     // Postfix increment operator.
    - need to return new variable which is not incremented
    - because only increment after
   // Declare prefix and postfix decrement operators.
- Point& operator--();       // Prefix decrement operator.
- Point operator--(int);     // Postfix decrement operator.

- smallest representable  such as 1 +  > 1.
    - equals the smallest value a deciaml can be represented, i.e. increment the bits value of 8 length

STATIC MEMBER CANNOT BE CREATED WITH CONST QUALIFIER -> NO THIS.
https://stackoverflow.com/questions/7035356/c-why-static-member-function-cant-be-created-with-const-qualifier


const' qualifier may not be applied to a reference


Bitwise operator for float
- https://stackoverflow.com/questions/1723575/how-to-perform-a-bitwise-operation-on-floating-point-numbers


Ex02
```
    static Fixed &min(Fixed &a, Fixed &b);
    // don't really understand the const requirement
    //  i.e. why need const?  static Fixed &const min(Fixed &const a, Fixed &const b); -> why couldn't i do this?
    const static Fixed &min(Fixed const &a, Fixed const &b);
    static Fixed &max(Fixed &a, Fixed &b);
    const static Fixed &max(Fixed const &a, Fixed const &b);
```
- Impossible to store `inf` for float
    - the number HAS to be stored in the form of an int
```
Fixed Fixed::operator/(Fixed const &rhs) const
{
    Fixed tmp;
    tmp._fpval = this->_fpval / rhs.toFloat();
    std::cout << tmp._fpval << std::endl;
    return (tmp);
}
```


Ex03
Triangle Area (dependent on precision of decimals)
- https://www.geeksforgeeks.org/check-whether-a-given-point-lies-inside-a-triangle-or-not/   
- https://www.youtube.com/watch?v=qObJQesvZUU
Binary Space partitioning
- https://www.youtube.com/watch?v=yTRzfKh4Tg0