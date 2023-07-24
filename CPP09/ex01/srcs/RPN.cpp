/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:58:56 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/07/24 12:23:06 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void)
{
	
}

RPN::RPN(const std::string &args)
{
	this->_args = args;
}

RPN::RPM(const RPN &other)
{
	*this = other;
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other){
		this->_args = other._args;
		this->_values = other._values
	}
	return (*this);
}

RPN::~RPN(void)
{
	
}

int	RPN::calculation(void)
{
	r
	
	return (0);
}
