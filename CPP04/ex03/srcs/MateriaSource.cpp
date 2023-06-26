/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:27:22 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/23 10:13:18 by mgomes-d         ###   ########.fr       */
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
		for (int i = 0; i < 4; i++){
			if (this->_materias[i]){
				delete (this->_materias[i]);
			}
			if (rhs._materias[i]){
				this->_materias[i] = rhs._materias[i]->clone();
			}
			else{
				this->_materias[i] = NULL;
			}
		}
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
	if (i <= 3 && !this->_materias[i]){
		this->_materias[i] = materia;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++){
		if (this->_materias[i] && this->_materias[i]->getType().compare(type) == 0){
			return this->_materias[i]->clone();
		}
	}
	return (0);
}