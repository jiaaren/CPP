#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap bot("Clappy");
    bot.attack("bucket");
    bot.takeDamage(5);
    bot.beRepaired(5);
    bot.takeDamage(20);
    bot.beRepaired(5);
    return (1);
}