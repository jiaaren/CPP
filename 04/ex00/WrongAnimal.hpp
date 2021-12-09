/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:12:11 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/09 18:36:46 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal
{
protected:
    std::string _type;

public:
    WrongAnimal(void);
    WrongAnimal(std::string const type);
    WrongAnimal(WrongAnimal const &a);
    ~WrongAnimal(void);
    WrongAnimal &operator=(WrongAnimal &rhs);
    std::string getType(void) const;
    void setType(std::string const type);
    void makeSound(void) const;
};

#endif
