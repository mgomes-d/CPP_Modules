/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 07:13:23 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/21 07:47:17 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap cortiz("Cortiz");
	DiamondTrap fluchten("fluchten");
	DiamondTrap marwane("Marwane");

	std::cout << std::endl;
    std::cout << "\033[1;30m" << " Test 1 ~ ATTACK ~ " << "\033[0m" << std::endl;
	cortiz.attack("fluchten");
	cortiz.attack("Marwane");
	std::cout << std::endl;

    std::cout << "\033[1;31m" << " Test 2 ~ TAKE DAMAGE ~ " << "\033[0m" << std::endl;
	fluchten.takeDamage(85);
	fluchten.takeDamage(15);
	fluchten.takeDamage(1);
	fluchten.takeDamage(2);
	fluchten.takeDamage(3);
	marwane.takeDamage(25);
	std::cout << std::endl;

    std::cout << "\033[1;32m" << "Test 3 ~ BE REPAIRED ~ " << "\033[0m" << std::endl;
	cortiz.beRepaired(3);
	fluchten.beRepaired(8);
	marwane.beRepaired(2);
	marwane.beRepaired(5);
	std::cout << std::endl;

    std::cout << "\033[1;34m" << "Test 4 ~ GUARD GATE ~ " << "\033[0m" << std::endl;
	cortiz.guardGate();
	fluchten.guardGate();
	marwane.guardGate();
	std::cout << std::endl;

    std::cout << "\033[1;33m" << "Test 5 ~ HIGH FIVES GUYS ~ " << "\033[0m" << std::endl;
	cortiz.highFivesGuys();
	fluchten.highFivesGuys();
	marwane.highFivesGuys();
	std::cout << std::endl;

    std::cout << "\033[1;36m" << "Test 6 ~ WHO I AM ~ " << "\033[0m" << std::endl;
	cortiz.whoAmI();
	fluchten.whoAmI();
	marwane.whoAmI();
	std::cout << std::endl;
    return (0);
}