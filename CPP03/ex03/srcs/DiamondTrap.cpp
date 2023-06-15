/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 07:32:14 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/15 11:26:43 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("_clap_name"), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap Default has been created" << std::endl;
    this->_HitPoints = FragTrap::_HitPoints;
    this->_EnergyPoints = ScavTrap::_EnergyPoints;
    this->_AttackDamage = FragTrap::_AttackDamage;
	return ;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), _Name(name)
{
	std::cout << "FragTrap " << name << " has been created" << std::endl;
	this->_HitPoints = FragTrap::_HitPoints;
    this->_EnergyPoints = ScavTrap::_EnergyPoints;
    this->_AttackDamage = FragTrap::_AttackDamage;
	return ;
}

DiamondTrap::DiamondTrap(const DiamondTrap &rhs) : ClapTrap(rhs), ScavTrap(rhs), FragTrap(rhs)
{
	std::cout << "DiamondTrap " << rhs._Name << " has been copied" << std::endl;
	*this = rhs;
	return ;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs)
{
	std::cout << "DiamondTrap " << rhs._Name << " has been copied" << std::endl;
	if (this != &rhs)
	{
		this->_Name = rhs._Name;
		this->_AttackDamage = rhs._AttackDamage;
		this->_EnergyPoints = rhs._EnergyPoints;
		this->_HitPoints = rhs._HitPoints;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << this->_Name << " has been destroyed" << std::endl;
	return ;
}

void	DiamondTrap::whoAmI(void)
{
	if (this->_haveHP()){
		std::cout << "I am " << this->_Name <<" and my ClapTrap name is " << ClapTrap::_Name << std::endl;	
	}
	else{
		std::cout << "DiamondTrap " << this->_Name << " is dead!" << std::endl;
	}
}