/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 08:19:31 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/22 09:00:29 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void)
{
	this->_type = "cure";
}

Cure::Cure(const Cure &rhs)
{
	*this = rhs;
}

Cure &Cure::operator=(const Cure &rhs)
{
	if (this != &rhs){
		this->_type = rhs._type;
	}
	return (*this);
}

Cure::~Cure(void)
{
}

AMateria *Cure::clone(void) const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
