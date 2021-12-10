/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 02:01:02 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/10 15:12:02 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
private:
    static std::string _quotes[100];
    std::string _ideas[100];

public:
    Brain(void);
    ~Brain(void);
    static void fillQuotes(void);
    void fillBrain(void);
    std::string getIdea(void) const;
};

#endif