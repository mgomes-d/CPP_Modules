/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 09:50:11 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/07/14 12:36:20 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <list>
#include <cstdlib>

Span::Span(void) : _N(0)
{

}

Span::Span(unsigned int N) : _N(N)
{
	
}

Span::Span(const Span &rhs) : _N(rhs._N)
{
	*this = rhs;
}

Span &Span::operator=(const Span &rhs)
{
	this->_list = rhs._list;
	return (*this);
}

Span::~Span(void)
{

}

void	Span::addNumber(int nb)
{
	if (this->_list.size() >= this->_N)
		throw Span::MaxOfElementsStore();
	this->_list.push_back(nb);
}

void	Span::addNumbers(std::list<int>::const_iterator it,std::list<int>::const_iterator ite)
{
	if (this->_list.size() >= this->_N)
		throw Span::MaxOfElementsStore();
	this->_list.insert(this->_list.end(), it, ite);

}

unsigned int Span::shortestSpan(void) const
{
	std::size_t size = this->_list.size();
	if (size <= 1) {
		if (size == 1)
			throw Span::OnlyOneNumberStore();
		else
			throw Span::NoNumberStore();
	}
	unsigned int smallestRange = std::numeric_limits<int>::max();
	std::list<int>::const_iterator it = this->_list.begin();
	std::list<int>::const_iterator ite = this->_list.end();
	while (it != ite)
	{
		std::list<int>::const_iterator it2 = it;
		while (++it2 != ite)
		{
			if (abs(*it - *it2) < static_cast<int>(smallestRange))
			{
				smallestRange = abs(*it - *it2);
			}
		}
		it++;
	}
	return (smallestRange);
}

unsigned int Span::longestSpan(void) const
{
	std::size_t size = this->_list.size();
	if (size <= 1) {
		if (size == 1)
			throw Span::OnlyOneNumberStore();
		else
			throw Span::NoNumberStore();
	}
	unsigned int longestRange = 0;
	std::list<int>::const_iterator it = this->_list.begin();
	std::list<int>::const_iterator ite = this->_list.end();
	while (it != ite)
	{
		std::list<int>::const_iterator it2 = it;
		while (++it2 != ite)
		{
			if (abs(*it - *it2) > static_cast<int>(longestRange))
			{
				longestRange = abs(*it - *it2);
			}
		}
		it++;
	}
	return (longestRange);
}

const std::list<int> &Span::getList(void) const
{
	return (this->_list);
}

std::ostream &operator<<(std::ostream &out, const Span &rhs)
{
	const std::list<int> list = rhs.getList();
	std::list<int>::const_iterator it = list.begin();
	std::list<int>::const_iterator ite = list.end();
	out << "list: ";
	while (it != ite){
		out << "[";
		out << *it;
		out << "] ";
		it++;
	}
	return (out);
}