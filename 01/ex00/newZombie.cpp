#include <string>
#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
	// parentheses for declaration of zombie after memory allocation
	Zombie *zombie = new Zombie(name);

	return (zombie);
}