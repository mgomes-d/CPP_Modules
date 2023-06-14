/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 07:13:23 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/14 09:13:04 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

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

    ScavTrap scavtrap1("fluchten");
    for (int i = 0; i < 25; i++){
        scavtrap1.attack("mgomes");
    }
    scavtrap1.takeDamage(150);
    scavtrap1.attack("fe");
    scavtrap1.guardGate();

    return (0);
}