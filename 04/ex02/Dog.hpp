/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:24:18 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/13 01:34:22 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
private:
    Brain *_brain;

public:
    Dog(void);
    Dog(Dog const &c);
    ~Dog(void);
    Dog &operator=(Dog const &rhs);
    virtual void makeSound(void) const;
    virtual void beDeep(void) const;
    // getter
    Brain *getBrain(void) const;
};

#endif