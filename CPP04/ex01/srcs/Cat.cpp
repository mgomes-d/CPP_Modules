/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:51:15 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/20 09:38:06 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	this->_type = "Cat";
	this->_bigbrain = new Brain();
	std::cout << "Default Cat Constructor" << std::endl;
}

Cat::Cat(const Cat &rhs)
{
	std::cout << "Copy Cat constructor" << std::endl;
	*this = rhs;
}

Cat &Cat::operator=(const Cat &rhs)
{
	std::cout << "Copy Cat constructor" << std::endl;
	if (this != &rhs)
	{
		this->_bigbrain = rhs._bigbrain;
		this->_type = rhs._type;
	}
	return (*this);
}

Cat::~Cat(void)
{
	delete this->_bigbrain;
	std::cout << "Cat destructor" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Mew, Meowww" << std::endl;
}