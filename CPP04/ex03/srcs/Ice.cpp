/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 08:57:42 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/21 12:21:38 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
	std::cout << "Default Ice constructor" << std::endl;
}

Ice::Ice(const Ice &rhs)
{
	std::cout << "Copy Ice constructor" << std::endl;
	*this = rhs;
}

Ice &Ice::operator=(const Ice &rhs)
{
	std::cout << "Copy Ice assignement" << std::endl;	
	if (this != &rhs){
		this->_type = rhs._type;
	}
	return (*this);
}

Ice::~Ice(void)
{
	std::cout << "Ice destructor" << std::endl;
}

AMateria *Ice::clone(void) const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}