/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:34:31 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/06 07:45:05 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
	return ;
}

HumanB::HumanB(std::string name, Weapon *weapon):_name(name), _weapon(weapon)
{
	return ;
}

HumanB::~HumanB()
{
	return ;
}

void	HumanB::attack(void)
{
	if (this->_weapon->getType() != ""){
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	}
	else{
		std::cout << this->_name << " attacks with their feet" << std::endl;
	}
	return ;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
	return ;
}