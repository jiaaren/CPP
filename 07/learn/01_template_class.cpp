#include <iostream>

/*
    Same way of initialising templates
    - However, referring to the classname itself, would need ClassName<T>

    Take note that we have not set up a Class here, just a class 'template'
*/
template <typename T>
class List
{
public:
    List<T>(void);
    List<T>(T const &content);
    List<T>(List<T> const &lst);
    ~List<T>(void);

private:
    // can basically change content from a pointer to a T variable
    T *_content;
    List<T> *_next;
};

int main(void)
{
    // int list
    List<int> a(42);
    // float list
    List<float> b(42.42f);
    // list of lists - pretty weird
    // or list of list of list... etc
    List<List<int>> c(a);
    return (0);
}
