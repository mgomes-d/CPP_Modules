/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:27:22 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/22 10:43:54 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++){
		this->_materias[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &rhs)
{
	*this = rhs;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs)
{
	if (this != &rhs){
		
	}
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	int i = 0;
	while (this->_materias[i]){
		delete this->_materias[i];
		i++;
	}
}

void MateriaSource::learnMateria(AMateria *materia)
{
	int i = 0;
	while (this->_materias[i]){
		i++;
	}
	if (i <= 3){
		this->_materias[i] = materia;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	int i = 0;
	while (this->_materias[i]){
		if (type.compare(this->_materias[i]->getType()) == 0)
			break ;
		i++;
	}
	if (i == 4 || !this->_materias[i] || type.compare(this->_materias[i]->getType()) != 0){
		return (0);
	}
	return (this->_materias[i]->clone());
}