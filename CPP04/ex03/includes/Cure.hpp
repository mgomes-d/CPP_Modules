/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 08:15:52 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/22 11:56:47 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "ICharacter.hpp"
#include <iostream>

class Cure : public AMateria
{
	public:
		Cure(void);
		Cure(const Cure &rhs);
		Cure &operator=(const Cure &rhs);
		~Cure(void);

		virtual AMateria *clone(void) const;
		virtual void use(ICharacter &target);
};

#endif