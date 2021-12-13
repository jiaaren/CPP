/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:06:33 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/13 01:59:10 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

class ICharacter;

class AMateria
{
protected:
    std::string _type;

public:
    AMateria(void);
    AMateria(AMateria const &m);
    AMateria(std::string const &type);
    virtual ~AMateria(void) = 0;
    AMateria &operator=(AMateria const &rhs);
    std::string const &getType(void) const;
    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter &target) = 0;
};

#endif
