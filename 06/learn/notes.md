### Casts
- Casts and notions

### Types
1. Implicit
2. Explicit

### (C) `Conversions` and hierarchy between types
- conversions between `ints` and `doubles`
    - `ints` are represented by bits
    - `doubles` represented by sign, mantissa and exponent (scientific notation)
- `doubles` are higher in hierarchy compared to `ints`
    - int -> doubles (promotion) - 
        - implicit casting - **generally ok**
        - explicit casting - ok
    - doubles -> int (demotion)
        - implicit casting - **hazardous**
        - explicit casting - ok

- Implicit usually ok for single instance
    - If called in loops, may not be the best as previous values will be used for current calculations
    - **error margins will become bigger and bigger**
    - precision may be a problem because of information loss

- Currently there are compilation flags to inform implicit casting

- [Reference](https://stackoverflow.com/questions/27998696/is-implicit-casting-considered-to-be-a-bad-concept)


### (C) Type `Reinterpretation`
- compared to conversions above (i.e. rearranging bits e.g. floats to ints and vice versa), another cast is called an **identify cast**
  - which keeps the same number of bits in order
  - so no actual conversion during the cast
  - Also termed **reinterpretation**
- Basically use **pointers** to reinterpret/cast

- Follow rules of implicit/explicit castings
  - Hierarchy also exist,
    - Generic pointers are higher hierarchy, i.e. `void *` highest
    - casting from `void *` to specific is generally bad

- Important notes:
  - reinterpretation doesn't `cast`, floats will not be read properly as an int
  - not common to reinterpret cast but sometimes necessary


### (C) `Type Qualifier` cast
- type qualifiers are keywords
  - e.g. `const`, `volatile`
- Mainly using examples of converting non const and const variables
- Const is higher in hierarchy
  - Demoting from const to non-const is **bad**


### C++ `Upcast and Downcast` (for Classes)
- Classes reinterpretation basically same rules as above
- Hierarchy -> `Parent` would be higher than `Child`
  - **Implicit** upcasts no problem, but downcasts do have issues

- Considerations during **runtime**
  - Sometimes compilation would have no issues, but during runtime, errors may be detected which shows that Class casted is inappropriate


### C++ cast syntax
- avoids issues noted above, where errors are not detected during compilation but only during runtime.

#### 1. Static cast
- made during **compilation**
  - sometimes it works sometimes it doesn't
- `static_cast<cast_to>(cast_var)`
- Can be used for:
  - Conversions (int to floats and vice versa)
  - Reinterpretations
  - Upcast and downcasts
- But basically used to ensure no reinterpretation between classes which are **not in the same class hierarchy**

#### 2. Dynamic cast
##### Purpose
- e.g. making sure that plugins work for different browsers... without the app crashing

- happens at **run time** (i.e. execution of code)
- can only be used in the case of a pointer or reference cast,
  - **Pointer** - if `NULL`, then == failed
  - **References** - since references need to store a value, a `NULL` cannot be returned to it...
    - so failed dynamic casts to references will be detected using `try/catch` with `std::bad_cast`
- Code may compile but may fail during run time
- only works for polymorphic instances, i.e. sub-type polymorphism (run time polymorphism)
  - For a base class to be polymorphic, it has to have **at least one virtual function (preferrably the destructor)**
  - If items are polymorphic, [**run-time type information**](https://www.geeksforgeeks.org/g-fact-33/) will be made available for dynamic cast to be successful

##### Random
- [Compilation Error : Source type is not polymorphic](https://stackoverflow.com/questions/15114093/getting-source-type-is-not-polymorphic-when-trying-to-use-dynamic-cast)
  - [Another reference](https://stackoverflow.com/questions/8469900/cant-downcast-because-class-is-not-polymorphic)
  - resolved by adding a virtual destructor in the parent

#### 3. Reinterpret cast
- Nothing special for this
  - **Do i need this if i can just use static cast?**
    - [Static vs interpret](https://stackoverflow.com/questions/4476182/which-cast-to-use-static-cast-or-reinterpret-cast)
    - what's the purpse of reinterpreting references?
- happens during **compile time**
- need to know what we are doing with this

##### Purpose
- basically reinterpret random bytes to information, e.g. to a string
- interpret raw data into useful data
- use with extreme caution

#### 4. Const cast
- cast between type qualifiers
- basically replaces C const cast

##### Important
- Usually using const cast is indication of bad design...
- If we need to use it alot in our program, better to revisit design and flow of code

#### [Summary](https://stackoverflow.com/questions/332030/when-should-static-cast-dynamic-cast-const-cast-and-reinterpret-cast-be-used)

### C++ Type cast operators
- for creating **implicit casts** using operator overloading in classes
- can use classes to initialise `ints` or `floats`
- not so commonly used, but can be used to improve expressivity of our classes

### [Implicit and explicit class construction](https://dev.to/aboss123/c-programming-implicit-and-explicit-constructors-27be)
- classes can be constructed via implicit construction
  - e.g. `std::string my_string = "Wow, this is cool!";`
    - this is not an assignment from a static string
    - it's essentially `std::string my_string("Wow, this is cool!");`
    - The compiler implicit casted the string `"Wow, this is cool!"` to a `std::string`

- including `explicit` into constructor prevents implicit construction from happening
