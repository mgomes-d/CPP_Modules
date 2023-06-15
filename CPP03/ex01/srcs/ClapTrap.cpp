/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:10:40 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/15 11:20:09 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _Name("Default"), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
	std::cout << "ClapTrap Default has been created" << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name) : _Name(name), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
	std::cout << "ClapTrap " << name << " has been created" << std::endl;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap &rhs)
{
	std::cout << "ClapTrap " << rhs._Name << " has been copied" << std::endl;
	*this = rhs;
	return ;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
	std::cout << "ClapTrap " << rhs._Name << " has been copied" << std::endl;
	if (this != &rhs)
	{
		this->_Name = rhs._Name;
		this->_AttackDamage = rhs._AttackDamage;
		this->_EnergyPoints = rhs._EnergyPoints;
		this->_HitPoints = rhs._HitPoints;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << this->_Name << " has been destroyed" << std::endl;
	return ;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_haveEnergy() && this->_haveHP()){
		std::cout << "ClapTrap " << this->_Name << " attacks " << target << ", causing " << this->_AttackDamage << " points of damage!" << std::endl;
		this->_EnergyPoints--;
	}
	else{
		std::cout << "ClapTrap " << this->_Name << " cannot attack!" << std::endl;
	}
	return ;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_haveHP()){
		std::cout << "ClapTrap " << this->_Name << " has taken " << amount << " points of damage!" << std::endl;
		if (amount < this->_HitPoints){
			this->_HitPoints -= amount;
		}
		else{
			this->_HitPoints = 0;
		}
	}
	else{
			std::cout << "ClapTrap " << this->_Name << " is death!" << std::endl;
	}
	return ;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_haveEnergy() && this->_haveHP()){
		std::cout << "ClapTrap " << this->_Name << " repairs itself " << amount << " HitPoints!" << std::endl;
		this->_HitPoints += amount;
		this->_EnergyPoints--;
	}
	else{
		std::cout << "ClapTrap " << this->_Name << " cannot repairs itself!" << std::endl;
	}
	return ;
}

bool ClapTrap::_haveHP(void) const
{
	if (this->_HitPoints > 0){
		return (true);
	}
	else{
		return (false);
	}
}

bool ClapTrap::_haveEnergy(void) const
{
	if (this->_EnergyPoints > 0){
		return (true);
	}
	else{
		return (false);
	}
}