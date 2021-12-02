### Namespace
- Purpose?
- No conflicts when compiling
- For longer namespaces
  - can assign to namespaces as Aliases
  - Aliases are **not** copies, modifying one will modify another (no matter original or alias)

### Scope resolution operator (`::`)
- Used for:
  - accessing variables or functions in a namespace


### [Stdio streams](https://www.cplusplus.com/reference/iostream/)

1. Output something - `std:cout << "string"`
2. Append newline - `"string" << std:endl`
   1. Why need std:endl?
3. Input something - `std:cin >> buffer`

#### Double arrows
- When to use `<<` and `>>`
- Example of chaining directions
  - `"[" << buff << "]" << std::endl;`

#### Replaces
- open and write
- no need to manage new lines
- no need to nul terminate strings?

### Classes
- Picture Classes as **moulds**
#### File Syntax
- has `.class` pre-extension
- ends with `.hpp` (header)
  - can use `.h` too but text editor may interpret .h as C headers
- e.g. `Sample.class.hpp`

#### Code syntax
- `public` to be explained next time
- need to declare a **constructor** and **destructor**
  - C++ reads the name of the Class as the constructor, e.g. `Sample::Sample`
  - destructor is `Sample::~Sample`
- Writing **constructors** and **destructors** do not require type
  - by default they return `Void`
  - no need to write `return`
    - good practice to write to signify end of code
- **Destructor** called after program ends
    - notice in program where 2 instances of a Class is declared, constructor is called twice first,
    - destructor is called when program ends

#### Contrast with `malloc` and `free`
- constructor and destructor

### Class member attributes and functions
#### Steps
1. Declare attribute (similar as C variable) and functions in `Class` header
2. For functions -> need to write function (basically same as constructor or destructor, just need type)
3. Attributes -> assign attributes in main or functions
4. Functions -> call functions

### Class this
- Whenever class functions are called, a hidden `this` paramter is passed in which refers to the instance of the class
- can use this to assign member variables/attributes or calling member functions within Class functions

### Class initialisation
- `Sample1::Sample1(char b1, int b2, float b3) : a1(b1), a2(b2), a3(b3)`

### Const
- Why const?
  - Prevent program from blowing up
  - Robust code
  - prevent time spent for debugging
  - extension for **functional programming**
- Uses of const
    1. Constant variables
        - [const int vs int const](https://stackoverflow.com/questions/3247285/const-int-int-const)
          - declaring int both **same**
          - for pointers
            - Declares a pointer whose data cannot be changed through the pointer:
              - `const int *p = &someInt;`
            - Declares a pointer who cannot be changed to point to something else:
              - `int * const p = &someInt;`
    2. Constant class member attributes
        - need to use class initialisation during constructor
    4. Constant class member functions
        - **good practice to use this if class member function doesn't change state of class**
        - ensures state of class doesn't change 
        - will prompt error if attempt assigning
        - e.g. `this->var = 42` will prompt **read-only object** compilation error

### Visilibity (private/public)
- Public -> accessible anywhere
- Private -> only accessible within class functions
- **good practive to differentiate user accessible functions and non accessible**

#### Public
- must place constructor and destructor within public
  - however, sometimes make sense to place constructor in private

#### Private
- conventionally variables declared starting with `_` prefix before or after, e.g. _privateFoo

### Structs
- Extended structs in **C++**
- **Same** syntax as Classes
- can accept private and public keywords

#### Difference vs classes
- structs -> public by default
- classes -> private by default
- **best practice just use classes**, unless everything is public

### Accessors
- basically **normal functions**
- convention to use getters and setters to access update private variables
- naming convention -> `getFoo`/ `setFoo`

#### Getters
- since only returning data, make sure its **const**
- can be used to aggregate data or convert data after doing math (e.g. currency exchange)
- have control to what is returned to user
- good to **overuse** getters

#### Setters
- e.g. of limiting changes to data, e.g. only allowing non negative integers
- Improvements 
    - return type to boolean -> to inform user if successful set/update operation
    - print or log error message

### Comparisons
- physical equality vs structural equality
  - Usually cannot just compare class to another class instance (i.e. physical equality)
- instead we need to compare to find out structural equality
  - do this by creating a `.comapre` function accepting a pointer to another class

### Non member attributes & non member functions
- aka **instance** attributes and functions
- variables exist at Class level rather than member level

#### Syntax
- use **static** keyword
- for both variables or functions
  - Variables
    - Declare `int Sample::_nbInst = 0;` 
    - Access using `Sample::_nbInst`
  - Function
    - Calling function using `Sample::getNbInst()`

### Pointers to members & member functions
- TO LEARN
- very useful

#### Considerations
- cannot use this
  - not passed into instance
- need to use **const**
- use initialisations for constructor

### Vectors and templating
- Declaring vectors `std::vector<int>` -> < > are represented by the standard templating library
- main methods
  - `vector.pushback` -> to add items towards the end
  - `vector[]` -> for indexing
  - `vector.size()` -> to return size
    - size - 1 represents last position

### Pair
- https://en.cppreference.com/w/cpp/utility/pair
  - has member attributes `first` and `second`

### Classes (cont'd)
- https://www.tutorialspoint.com/cplusplus/cpp_static_members.html
- all **Static variables** are shared by all classes

- need to initialise static members in class
- https://stackoverflow.com/questions/9110487/undefined-reference-to-a-static-member

### C++ 98 vs 11
- 98 is simpler for introductions into C++
- https://stackoverflow.com/questions/12606713/enforcing-the-c98-standard-in-gcc


### Compilation
- g++ <filename.cpp>