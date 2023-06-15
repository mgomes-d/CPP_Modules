/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 07:12:27 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/15 08:19:28 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap cortiz("Cortiz");
    ClapTrap fluchten("Fluchten");
    ClapTrap marwane("Marwane");

    std::cout << std::endl;
    std::cout << "\033[1;36m" << "[ ATTACK ]" << "\033[0m" << std::endl;
    for (int i = 1; i <= 12; i++) {
        std::cout << "[" << i << "] ";
        cortiz.attack("Fluchten");
    }
    std::cout << std::endl;

    std::cout << "\033[1;31m" << "[ TAKE DAMAGE ]" << "\033[0m" << std::endl;
    fluchten.takeDamage(7);
    fluchten.takeDamage(5);
    fluchten.takeDamage(1);
    fluchten.takeDamage(2);
    marwane.takeDamage(4);
    std::cout << std::endl;

    std::cout << "\033[1;32m" << "[ BE REPAIRED ]" << "\033[0m" << std::endl;
    cortiz.beRepaired(3);
    fluchten.beRepaired(8);
    marwane.beRepaired(2);
    marwane.beRepaired(5);
    std::cout << std::endl;

    return (0);
}