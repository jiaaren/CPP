/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:24:18 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/12 11:51:25 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
    Brain *_brain;

public:
    Cat(void);
    Cat(Cat const &c);
    ~Cat(void);
    Cat &operator=(Cat const &rhs);
    virtual void makeSound(void) const;
    virtual void beDeep(void) const;
    // getter
    Brain *getBrain(void) const;
};

#endif
