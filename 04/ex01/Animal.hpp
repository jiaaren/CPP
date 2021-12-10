/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:12:11 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/10 15:23:15 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
protected:
    std::string _type;

public:
    Animal(void);
    Animal(std::string const type);
    Animal(Animal const &a);
    // virtual destructor
    virtual ~Animal(void);
    Animal &operator=(Animal &rhs);
    std::string getType(void) const;
    void setType(std::string const type);
    virtual void makeSound(void) const;
    virtual void beDeep(void) const;
};

#endif
