/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 20:46:41 by jkhong            #+#    #+#             */
/*   Updated: 2021/11/28 22:14:22 by jkhong           ###   ########.fr       */
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
	void complain(std::string level);
	// don't necessarily need constructor or destructor
	// Karen();
	// ~Karen();

private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
};

#endif