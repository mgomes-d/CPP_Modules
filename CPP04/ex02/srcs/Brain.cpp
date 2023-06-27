/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 08:27:17 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/26 09:48:11 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Default Brain constructor" << std::endl;
	return ;
}

Brain::Brain(const Brain &rhs)
{
	std::cout << "Copy Brain constructor" << std::endl;
	*this = rhs;
	return ;
}

Brain	&Brain::operator=(const Brain &rhs)
{
	std::cout << "Copy Brain assignation" << std::endl;
	if (this != &rhs){
		for (int i = 0; i < 100; i++){
			this->_ideas[i] = rhs._ideas[i];
		}
	}
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor" << std::endl;
}