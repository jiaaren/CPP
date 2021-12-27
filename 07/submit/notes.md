Array.hpp:110:27: error: passing ‘const Array<int>’ as ‘this’ argument discards qualifiers [-fpermissive]
  110 |             _elem[i] = rhs[i];
      |                        ~~~^
Array.hpp:121:4: note:   in call to ‘T& Array<T>::operator[](int) [with T = int]’
  121 | T &Array<T>::operator[](int index)
      |    ^~~~~~~~

- https://stackoverflow.com/questions/5973427/error-passing-xxx-as-this-argument-of-xxx-discards-qualifiers
- Fixed by declaring const behind function


/*
    Still don't understand fully how full and partial specialization work
    - especially with <>
*/
