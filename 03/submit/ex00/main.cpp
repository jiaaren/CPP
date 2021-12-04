#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap bot("Clappy");
    bot.attack("bucket");
    bot.takeDamage(5);
    bot.beRepaired(10);
    bot.takeDamage(20);
    bot.beRepaired(1);
    return (1);
}