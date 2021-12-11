/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 11:41:39 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/11 12:28:20 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "ClapTrap.hpp"

// added virtual keyword
class FragTrap : virtual public ClapTrap
{
public:
    FragTrap(std::string const name);
    ~FragTrap(void);

    void attack(std::string const &target);
    void highFivesGuys(void);
};
