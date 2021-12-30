/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 02:01:02 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/12 12:28:19 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

#define NUM_IDEAS 100

class Brain
{
private:
    static std::string _quotes[NUM_IDEAS];
    std::string _ideas[NUM_IDEAS];

public:
    Brain(void);
    Brain(Brain const &b);
    ~Brain(void);
    Brain &operator=(Brain const &rhs);
    static void fillQuotes(void);
    void fillBrain(void);
    std::string getRandIdea(void) const;
    std::string getIndexIdea(unsigned int i) const;
};

#endif
