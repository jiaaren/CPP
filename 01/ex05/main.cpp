/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 21:25:42 by jkhong            #+#    #+#             */
/*   Updated: 2021/11/28 22:27:36 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int main(void)
{
    Karen karen;
    karen.complain("DEBUG");
    // karen.complain("WRONG");
    karen.complain("INFO");
    // karen.complain("WARNING");
    // karen.complain("ERROR");
    return (0);
}