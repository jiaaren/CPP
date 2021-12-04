#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string const name) : _name(name), _hp(10), _ep(10), _atk(0)
{
    std::cout << "ClapTrap " << name << " initiated" << std::endl;
    return;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap " << this->_name << " destroyed" << std::endl;
    return;
}

void ClapTrap::attack(std::string const &target)
{
    std::cout << "ClapTrap " << this->_name << " attacks "
              << target << " for " << this->_atk << " damage" << std::endl;
    return;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hp <= 0)
        return;
    int damage = (unsigned int)(this->_hp) < amount ? this->_hp : amount;
    this->_hp -= damage;
    std::cout << "ClapTrap " << this->_name << " takes "
              << damage << " amount(s) of damage. "
              << "Now with " << this->_hp << " health" << std::endl;
    return;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    this->_hp += amount;
    std::cout << "ClapTrap " << this->_name << " gets repaired for " << amount << ". "
              << "Now with " << this->_hp << " health" << std::endl;
    return;
}
