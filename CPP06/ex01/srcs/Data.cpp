/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 08:25:59 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/07/06 10:52:42 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void) : _name("Jibileu"), _age(15)
{
	
}

Data::Data(const std::string &name, int age) : _name(name), _age(age)
{
	return ;
}

Data::Data(const Data &rhs)
{
	*this = rhs;
}

Data	&Data::operator=(const Data &rhs)
{
	this->_name = rhs._name;
	this->_age = rhs._age;
	return (*this);
}

Data::~Data(void)
{
	
}

std::string Data::getName(void) const
{
	return (this->_name);
}

int Data::getAge(void) const
{
	return (this->_age);
}

std::ostream	&operator<<(std::ostream &out, const Data &data)
{
	out << "Name: " << data.getName() << ", Age: " << data.getAge();

	return (out);
}