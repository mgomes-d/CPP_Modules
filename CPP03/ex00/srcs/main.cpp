/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 07:12:27 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/13 09:49:33 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap clapTrap1("Cortiz");
    ClapTrap clapTrap2("Fluchten");

    clapTrap1.attack("Mf");
	clapTrap1.attack("lr");
	clapTrap1.attack("ro");
	clapTrap2.attack("ll");

    clapTrap1.takeDamage(5);
    clapTrap2.takeDamage(10);

    clapTrap1.beRepaired(3);
    clapTrap2.beRepaired(2);

    return (0);
}