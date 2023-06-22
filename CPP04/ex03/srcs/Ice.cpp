/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 08:57:42 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/22 09:00:54 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void)
{
	this->_type = "ice";
}

Ice::Ice(const Ice &rhs)
{
	*this = rhs;
}

Ice &Ice::operator=(const Ice &rhs)
{
	if (this != &rhs){
		this->_type = rhs._type;
	}
	return (*this);
}

Ice::~Ice(void)
{
}

AMateria *Ice::clone(void) const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}