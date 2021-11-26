#include "Zombie.hpp"

int main(void)
{
	Zombie *heap_zombo = newZombie("Heap Zombo");
	heap_zombo->announce();
	randomChump("Stack zombo");
	delete heap_zombo;
	return (0);
}