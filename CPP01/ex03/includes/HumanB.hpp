/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:31:54 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/07 08:59:36 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class Weapon;

class HumanB
{
	public:
		HumanB(std::string name);
		HumanB(std::string name, Weapon *weapon);
		~HumanB();
		void attack(void);
		void setWeapon(Weapon &weapon);

	private:
		std::string _name;
		Weapon	*_weapon;
};

#endif