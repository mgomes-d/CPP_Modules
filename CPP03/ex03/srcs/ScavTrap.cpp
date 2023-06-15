/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:13:25 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/15 10:57:29 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "ScavTrap Default has been created" << std::endl;
	this->_HitPoints = 100;
	this->_EnergyPoints = 50;
	this->_AttackDamage = 20;
	return ;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	this->_HitPoints = 100;
	this->_EnergyPoints = 50;
	this->_AttackDamage = 20;
	std::cout << "ScavTrap " << name << " has been created" << std::endl;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap &rhs)
{
	std::cout << "ScavTrap " << rhs._Name << " has been copied" << std::endl;
	*this = rhs;
	return ;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
	std::cout << "ScavTrap " << rhs._Name << " has been copied" << std::endl;
	if (this != &rhs){
		this->_Name = rhs._Name;
		this->_AttackDamage = rhs._AttackDamage;
		this->_EnergyPoints = rhs._EnergyPoints;
		this->_HitPoints = rhs._HitPoints;
	}
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->_Name << " has been destroyed" << std::endl;
	return ;
}

void ScavTrap::guardGate(void)
{
	if (this->_haveHP())
		std::cout << "ScavTrap " << this->_Name << " is now in Gate keeper mode!" << std::endl;
	else{
		std::cout << "ScavTrap " << this->_Name << " is dead!" << std::endl;
	}
	return ;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_haveEnergy() && this->_haveHP()){
		std::cout << "ScavTrap " << this->_Name << " attacks " << target << ", causing " << this->_AttackDamage << " points of damage!" << std::endl;
		this->_EnergyPoints--;
	}
	else{
		std::cout << "ScavTrap " << this->_Name << " cannot attack!" << std::endl;
	}
	return ;
}