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

### Compilation
- g++ <filename.cpp>