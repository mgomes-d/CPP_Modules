/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 09:12:20 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/12 10:41:55 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPoint(0)
{
	return ;
}

Fixed::Fixed(const int value)
{
	this->_fixedPoint = (value << Fixed::_bits);
	return ;
}

Fixed::Fixed(const float value)
{
	this->_fixedPoint = roundf(value * (1 << Fixed::_bits));
	return ;
}

Fixed::Fixed(const Fixed &rhs)
{
	*this = rhs;
}

Fixed &Fixed::operator=(const Fixed	&rhs)
{
	if (this != &rhs){
		this->_fixedPoint = rhs.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed(void)
{
	return ;
}

bool Fixed::operator>(const Fixed &rhs) const
{
	return (this->_fixedPoint > rhs.getRawBits());
}

bool Fixed::operator>=(const Fixed &rhs) const
{
	return (this->_fixedPoint >= rhs.getRawBits());
}

bool Fixed::operator<(const Fixed &rhs) const
{
	return (this->_fixedPoint < rhs.getRawBits());
}

bool Fixed::operator<=(const Fixed &rhs) const
{
	return (this->_fixedPoint <= rhs.getRawBits());
}

bool Fixed::operator==(const Fixed &rhs) const
{
	return (this->_fixedPoint == rhs.getRawBits());
}

bool Fixed::operator!=(const Fixed &rhs) const
{
	return (this->_fixedPoint != rhs.getRawBits());
}

Fixed Fixed::operator+(const Fixed &rhs) const
{
	return (this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
	return (this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
	return (this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
	return (this->toFloat() / rhs.toFloat());
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
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

Fixed &Fixed::operator++(void)
{
	++this->_fixedPoint;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	operator++();
	return (temp);
}

Fixed &Fixed::operator--(void)
{
	--this->_fixedPoint;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	operator--();
	return (temp);
}

std::ostream &operator<<(std::ostream &o, const Fixed &rhs)
{
	o << rhs.toFloat();
	return (o);
}