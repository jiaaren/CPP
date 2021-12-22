#ifndef ITER_HPP
#define ITER_HPP

/*
    Passing arrays to C++
    https://stackoverflow.com/questions/31346940/passing-array-as-function-parameter-in-c
    int a[] is same as int *a

    https://stackoverflow.com/questions/1174169/function-passed-as-template-argument
    - Ben Supnik
*/
template <typename T, typename F>
void iter(T *arr, int len, F f)
{
    for (int i = 0; i < len; i++)
        f(arr[i]);
    return;
}

#endif
