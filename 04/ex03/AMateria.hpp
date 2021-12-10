/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:06:33 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/10 23:28:36 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

class ICharacter;

class AMateria
{
protected:
    std::string const _type;
    //...
public:
    AMateria(std::string const &type);
    virtual ~AMateria(void);
    std::string const &getType(void) const;
    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter &target);
};

#endif