Err
- copy constructor may not have a parameter of type
- https://stackoverflow.com/questions/9066052/copy-constructor-parameters


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

