/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:45:19 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/20 11:52:59 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void)
{
	std::cout << "Default AMateria constructor" << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
	std::cout << "Type AMateria constructor" << std::endl;
}

AMateria::AMateria(const AMateria &rhs)
{
	std::cout << "Copy AMateria" << std::endl;
	*this = rhs;
}

AMateria &AMateria::operator=(const AMateria &rhs)
{
	std::cout << "Copy AMateria" << std::endl;
	if (this != &rhs){
		this->_type = rhs._type;
	}
	return (*this);
}

AMateria::~AMateria(void)
{
	std::cout << "Default AMateria Destructor" << std::endl;
}