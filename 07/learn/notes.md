## Templates
- can be used to write very expressive programs
- To write code templates, have compiler code for us and by filling the blanks

### Subjects
1. Parametric macros
2. Templates
3. Default Types
4. Specialization


### Parametric macros (from C)
- C pre-processor goes through our source files 

#### Problems
- Edge effects for functions (passing functions into macros)
- Linked lists
  - Can create specific linked lists but going to be too detailed
    - Alot of repetitive
  - Can create generic linked lists with `void *`, but
    - will have problems since we need to constantly dereference (which will slow down)
    - alot of casts and recasting (which we can accidentally make mistakes over)
  - basically there are issues over **repetitiveness** and **constant dereferencing (genericity)**

### C++ Templates
- define function templates, class templates or struct templates
- type variables in templates will be instantiated by **compiler**, not during runtime

- Can instantiate implicitly or explicitly
  - preferrably explicitly
- Addresses problems noted using functions in macros such as the **C** way above

- Class templates
  - Same way of initialising templates
    - However, referring to the classname itself, would need `ClassName<T>`

- Multiple typenames
  - e.g. declare with `<typename T, typename U>`

- Standard template library (STL)
  - library of template functions/classes/data structures written by more competent programmers
    - E.g. Array, List, Stack, Queue templates...

### Default values to type variables in templates
- use `.tpp` for template files

### Specialisation
- Template to accept parameter
- Types:
  - Generic templates **(above)**
  - Partial template specialization
  - Full template specialization
- Function templates -> only partial
- Class templates -> partial and full

- Need to write a few variants of our code

### Random
- putting **void constructor in private**
    - force users to use constructors with parameters
- **Each instance** of a class or function needs its own **template** keyword


### Question
- do i need `ClassName<T>` or just `ClassName` in our classes?