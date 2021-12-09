/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:12:11 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/09 18:16:50 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
protected:
    std::string type;

public:
    Animal(void);
    Animal(Animal const &a);
    ~Animal(void);
    Animal &operator=(Animal &rhs);
    std::string getType(void) const;
    void setType(std::string const type);
}

#endif