Polymorphism

1. Why need virtual destructor?
- https://stackoverflow.com/questions/12994920/how-to-delete-an-object-of-a-polymorphic-class-type-that-has-no-virtual-destruct
- i.e. `virtual ~AMateria(void);`, what's the purpose


1. What's a virtual method really
     - virtual function vs concrete function

2. Interfaces and abstract classes
    - https://www.tutorialspoint.com/cplusplus/cpp_interfaces.htm
    - created essentially the same way, i.e. having at lesat 1 virtual function (method)
    - Convention to write as **A**ClassName or **I**ClassName
    - Interfaces
      - **Only** virtual methods (no attributes)
        - attributes cannot be virtual
        - Imagine using Interfaces for **behaviors**
        - Good uses to work collaboratively
    - Abstract
      - **At least 1** virtual method


### Others
1. Explicitly calling destructor is **wrong** - [Link](https://stackoverflow.com/questions/14187006/is-calling-destructor-manually-always-a-sign-of-bad-design)
    - both for static and dynamically allocated memory
    - destructors will be called twice if explicitly called because it will be defaultly called by end of program
    - one exception is for variables allocated with `new`
```
{
  Class c;
  c.~Class();
}
```

2. Random
```

// why need this, also silenced Werror flags
void AMateria::use(ICharacter &target)
{
    return;
}
```

3. Do i really need cononical form for interfaces and abstracts?
   1. Interfaces/abstracts
      1. [cannot have virtual constructors](https://stackoverflow.com/questions/8513408/c-abstract-base-class-constructors-destructors-general-correctness)

    2. [Best way to declare interfaces](https://stackoverflow.com/questions/14323595/best-way-to-declare-an-interface-in-c11)

4. Do i write interface functions within my other class .cpp?

5. UNdefined reference to destructor
    - need body - `{}`
    - [Link](https://stackoverflow.com/questions/18302617/undefined-reference-to-destructor-error-in-c?rq=1)

6. Upcasting
    -     *this = (Character)c;         (will not work)
-         *this = *(Character *)&c;     (will work)

-   imagine a `short` which we want to upcast to access bits subsequently
-   we wouldn't be able to use `(int)short` because the subsequent bits will be lost

7. Why need to add this one specifically?
```
    // assignment added in so it can be overriden in Character.hpp
    virtual ICharacter &operator=(ICharacter const &rhs) = 0;
```