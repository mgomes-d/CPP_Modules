/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 09:26:39 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/14 11:14:25 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	std::cout << "FragTrap Default has been created" << std::endl;
	this->_HitPoints = 100;
	this->_EnergyPoints = 100;
	this->_AttackDamage = 30;
	return ;
}

FragTrap::FragTrap(std::string name)
{
	std::cout << "FragTrap " << name << " has been created" << std::endl;
	this->_Name = name;
	this->_HitPoints = 100;
	this->_EnergyPoints = 100;
	this->_AttackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &rhs)
{
	*this = rhs;
	return ;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
	if (this != &rhs){
		this->_Name = rhs._Name;
		this->_AttackDamage = rhs._AttackDamage;
		this->_EnergyPoints = rhs._EnergyPoints;
		this->_HitPoints = rhs._HitPoints;
	}
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << this->_Name << " has been destroyed" << std::endl;
	return ;
}

void FragTrap::highFivesGuys(void)
{
	if (this->_haveHP()){
		std::cout << "FragTrap " << this->_Name << " asks for high five!" << std::endl;
	}
}