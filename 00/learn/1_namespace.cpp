#include <stdio.h>

int gl_var = 1;
int f(void)
{
	return (2);
}

namespace Foo
{
	int gl_var = 2;
	int f(void)
	{
		return (3);
	}
}

namespace Bar
{
	int gl_var = 3;
	int gl_var2 = 10;
	int f(void)
	{
		return (4);
	}
}

namespace Huf = Bar;

int main(void)
{
	// Both of these are the same
	printf("Global: gl_var: %i, f(): %i\n", gl_var, f());
	printf("Global: gl_var: %i, f(): %i\n", ::gl_var, ::f());

	printf("Foo: gl_var: %i, f(): %i\n", Foo::gl_var, Foo::f());

	Bar::gl_var = 100;
	Huf::gl_var2 = 400;
	printf("Bar: gl_var: %i, gl_var2: %i, f(): %i\n", Bar::gl_var, Bar::gl_var2, Bar::f());
	// Alias for Bar namespace
	printf("Huf: gl_var: %i, gl_var2: %i, f(): %i\n", Huf::gl_var, Huf::gl_var2, Huf::f());
	return (0);
}