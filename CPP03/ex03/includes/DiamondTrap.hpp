/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 07:27:13 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/15 11:12:12 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap{

public:
	DiamondTrap(void);
	DiamondTrap(const std::string &name);
	DiamondTrap(const DiamondTrap &rhs);
	DiamondTrap &operator=(const DiamondTrap &rhs);
	~DiamondTrap(void);

	void	whoAmI(void);
	using ScavTrap::attack;
	
private:
	std::string _Name;
};

#endif