/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:45:19 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/23 10:16:32 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void)
{
	
}

AMateria::AMateria(std::string const &type)
{
	this->_type = type;
}

AMateria::AMateria(const AMateria &rhs)
{
	*this = rhs;
}

AMateria &AMateria::operator=(const AMateria &rhs)
{
	(void)rhs;
	return (*this);
}

AMateria::~AMateria(void)
{
}

std::string const &AMateria::getType(void) const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* " << this->_type << " used on " << target.getName() << " *" << std::endl;
}