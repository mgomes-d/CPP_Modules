/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:13:36 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/13 11:24:59 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{

public:
	ScavTrap(void);
	ScavTrap(const ScavTrap &rhs);
	ScavTrap &operator=(const ScavTrap &rhs);
	~ScavTrap(void);
	void guardGate(void);
	void attack(const std::string& target);

private:

};

#endif