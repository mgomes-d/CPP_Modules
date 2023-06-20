/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:51:06 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/20 09:36:35 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	this->_type = "Dog";
	this->_bigbrain = new Brain();
	std::cout << "Default Dog Constructor" << std::endl;
}

Dog::Dog(const Dog &rhs)
{
	std::cout << "Copy Dog constructor" << std::endl;
	*this = rhs;
}

Dog &Dog::operator=(const Dog &rhs)
{
	std::cout << "Copy Dog constructor" << std::endl;
	if (this != &rhs)
	{
		this->_bigbrain = rhs._bigbrain;
		this->_type = rhs._type;
	}
	return (*this);
}

Dog::~Dog(void)
{
	delete this->_bigbrain;
	std::cout << "Dog destructor" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Wof, bark" << std::endl;
}