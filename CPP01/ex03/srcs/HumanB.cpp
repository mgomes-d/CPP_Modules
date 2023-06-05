/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:34:31 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/05 11:59:53 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
	std::cout << "contructor" << std::endl;
	return ;
}

HumanB::HumanB(std::string name, Weapon *weapon):_name(name), _weapon(weapon)
{
	std::cout << "constructor" << std::endl;
	return ;
}

HumanB::~HumanB()
{
	std::cout << "destructor" << std::endl;
	return ;
}

void	HumanB::attack(void)
{
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	return ;
}

void	HumanB::setWeapon(Weapon weapon)
{
	this->_weapon = &weapon;
	return ;
}