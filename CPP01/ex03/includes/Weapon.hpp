/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:31:57 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/07 08:59:29 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

#include "HumanA.hpp"
#include "HumanB.hpp"

class Weapon
{
	public:
		Weapon(std::string type);
		~Weapon();

		const std::string &getType(void) const;
		void	setType(std::string type);

	private:
	std::string _	
};

#endif