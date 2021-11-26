#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name)
{
	this->name = name;
	return;
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie " << this->name << " is now dead!" << std::endl;
	return;
}

void Zombie::announce(void)
{
	std::cout << this->name << " BraiiiiiiinnnzzzZ..." << std::endl;
	return;
}