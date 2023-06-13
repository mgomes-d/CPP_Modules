/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 10:09:54 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/12 07:54:43 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPoint(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPoint = (value << Fixed::_bits);
	return ;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPoint = roundf(value * (1 << Fixed::_bits));
	return ;
}

Fixed::Fixed(const Fixed &rhs)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed& rhs)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &rhs){
		this->_fixedPoint = rhs.getRawBits();
	}
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	return (this->_fixedPoint);
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPoint = raw;
	return ;
}

float Fixed::toFloat(void) const
{
	return ((float)this->_fixedPoint / (1 << Fixed::_bits));
}

int	Fixed::toInt(void) const
{
	return (this->_fixedPoint >> Fixed::_bits);
}

std::ostream &operator<<(std::ostream &o, const Fixed &rhs)
{
	o << rhs.toFloat();
	return (o);
}
