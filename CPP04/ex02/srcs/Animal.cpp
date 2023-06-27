/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:49:06 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/26 09:48:09 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("Default Animal")
{
	std::cout << "Default Animal constructor" << std::endl;
	return ;
}

Animal::Animal(const Animal &rhs)
{
	std::cout << "Copy Animal constructor" << std::endl;
	*this = rhs;
	return ;
}

Animal &Animal::operator=(const Animal &rhs)
{
	std::cout << "Copy Animal assignation" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor" << std::endl;
}

void Animal::makeSound(void) const
{
	std::cout << "Animal Sound" << std::endl;
	return ;
}

std::string	Animal::getType(void) const
{
	return (this->_type);
}
