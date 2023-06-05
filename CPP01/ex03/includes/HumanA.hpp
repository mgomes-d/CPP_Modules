/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:31:18 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/05 11:58:44 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class Weapon;

class HumanA
{
	public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void attack(void);

	private:
	std::string _name;
	Weapon	&_weapon;
};

#endif