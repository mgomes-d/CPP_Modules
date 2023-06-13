/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:10:27 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/13 11:24:39 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap{

public:
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &rhs);
	ClapTrap &operator=(const ClapTrap &rhs);
	~ClapTrap(void);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

protected:
	std::string  _Name;
	unsigned int _HitPoints;
	unsigned int _EnergyPoints;
	unsigned int _AttackDamage;
	bool		_haveEnergy(void);
	bool		_haveHP(void);
};

#endif