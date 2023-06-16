/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 07:13:23 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/16 07:46:12 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	FragTrap cortiz("Cortiz");
	FragTrap francois("francois");
	FragTrap marwane("Marwane");

	std::cout << std::endl;
	std::cout << "\033[1;36m" << "[ ATTACK ]" << "\033[0m" << std::endl;
	cortiz.attack("francois");
	cortiz.attack("Marwane");
	std::cout << std::endl;

	std::cout << "\033[1;31m" << "[ TAKE DAMAGE ]" << "\033[0m" << std::endl;
	francois.takeDamage(85);
	francois.takeDamage(15);
	francois.takeDamage(1);
	francois.takeDamage(2);
	francois.takeDamage(3);
	marwane.takeDamage(25);
	std::cout << std::endl;

	std::cout << "\033[1;32m" << "[ BE REPAIRED ]" << "\033[0m" << std::endl;
	cortiz.beRepaired(3);
	francois.beRepaired(8);
	marwane.beRepaired(2);
	marwane.beRepaired(5);
	std::cout << std::endl;

	std::cout << "\033[1;34m" << "[ HIGH FIVES GUYS ]" << "\033[0m" << std::endl;
	cortiz.highFivesGuys();
	francois.highFivesGuys();
	marwane.highFivesGuys();
	std::cout << std::endl;

    return (0);
}