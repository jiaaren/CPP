### Containers
- Templated containers

#### Types
- Lists
- Maps -> dictionaries/hash tables
- Vector - arrays

#### Iterators
- Iterators - stl component of pointers
  - not really like pointers but work the same way
  - all STL classes would use iterators
- can use reverse iterators to do things backwards along with **algorithms**

### Algorithms
- collection of functions/algorithms

### Templates (cont'd)
- Typename and Class is sort of interchangable in the context of templates
  - https://stackoverflow.com/questions/2023977/difference-of-keywords-typename-and-class-in-templates
- Template functions or classes do not exist
  - Only exist when the function or class is called/initialised
  - So wrong syntax in the template may still result in code being compiled, during compile time.
    - Some compilers may highlight errors some may not
- Don't need to specify type, e.g. `<int>`, `<std::string>`, if compiler can detect what's inside the brackets `()`
- Templates basically copy and paste a new instance of a function/class and replace the type specified by `typename`

#### Not only limited by typename
- Use types in templates - refer **cherno_templates.cpp**
  - E.g. C++ doesn't allow variable length arrays (VLAs), so instead, we can use tempaltes with `<int N>` to intiialise our arrays
    - This works because templates are evaluated at compile time, this bypassing VLAs

#### Where to / not to use templates
- templates are fragile, can be messy and difficult to debug


### TODO
- to understand how iterators work

```
int Span::longestSpan(void) const
{
    if (_filled <= 1)
        throw(SearchFailed());
    int smallest = std::numeric_limits<int>::max();
    int largest = std::numeric_limits<int>::min();
    std::vector<int>::const_iterator it;
    std::cout << largest << " " << smallest << "\n";
    for (it = _v.begin(); it != _v.end(); ++it)
    {
        if (*it > largest)
            largest = *it;
        if (*it < smallest)
            smallest = *it;
        // std::cout << largest << " " << smallest << "\n";
        std::cout << *it << "\n";
    }
    return (largest - smallest);
}
```