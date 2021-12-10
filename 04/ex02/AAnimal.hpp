/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:12:11 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/10 16:57:55 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>

class AAnimal
{
protected:
    std::string _type;

public:
    AAnimal(void);
    AAnimal(std::string const type);
    AAnimal(AAnimal const &a);
    // virtual destructor
    virtual ~AAnimal(void) = 0;
    AAnimal &operator=(AAnimal &rhs);
    std::string getType(void) const;
    void setType(std::string const type);
    virtual void makeSound(void) const = 0;
    virtual void beDeep(void) const = 0;
};

#endif
