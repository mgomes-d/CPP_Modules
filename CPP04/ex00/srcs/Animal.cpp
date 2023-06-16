/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:49:06 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/16 12:04:59 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Default Animal constructor" << std::endl;
	return ;
}

Animal::Animal(const std::string &type) : _type(type)
{
	std::cout << "Naming Animal constructor" << std::endl;
	return ;
}

Animal::Animal(const Animal &rhs)
{
	*this = rhs;
	return ;
}

Animal &Animal::operator=(const Animal &rhs)
{
	if (this != &rhs)
	{
		this->_type = ths._type;
	}
	return (*this);
}

void	Animal::makeSound(void)
{
	if (this->_type == "")
}