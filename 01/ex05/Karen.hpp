/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 20:46:41 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/06 23:22:44 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_H
#define KAREN_H

#include <string>

enum e_level
{
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    NOT_FOUND
};

class Karen
{
public:
    Karen(void);
    ~Karen(void);
    void complain(std::string level);

private:
    void _debug(void);
    void _info(void);
    void _warning(void);
    void _error(void);
};

#endif
