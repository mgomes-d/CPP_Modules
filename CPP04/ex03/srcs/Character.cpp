/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 10:27:34 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/21 12:23:57 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"


Character::Character(void) : _Name("Default")
{
	std::cout << "Default Character constructor" << std::endl;
	for (int i = 0; i < 4; i++){
		this->_inventory[i] = NULL;
	}
	this->_floor[0] = NULL;
	this->_floorIndex = 0;
}

Character::Character(const std::string &name) : _Name(name)
{
	std::cout << "Naming Character constructor" << std::endl;
	for (int i = 0; i < 4; i++){
		this->_inventory[i] = NULL;
	}
	this->_floor[0] = NULL;
	this->_floorIndex = 0;
}

Character::Character(const Character &rhs)
{
	std::cout << "Copy Character constructor" << std::endl;
	*this = rhs;
}

Character &Character::operator=(const Character &rhs)
{
	std::cout << " Copy assignement Character" << std::endl;
	if (this != &rhs){
		this->_Name = rhs._Name;
	}
	return (*this);
}

Character::~Character(void)
{
	std::cout << "Default Character destructor" << std::endl;
    for (int i = 0; i < this->_floorIndex; i++) {
        if (this->_floor[i] != NULL) {
            delete this->_floor[i];
            this->_floor[i] = NULL;
        }
    }
    delete[] this->_floor;
    this->_floor = NULL;
}

std::string const &Character::getName(void) const
{
	return (this->_Name);
}

void Character::equip(AMateria *m)
{
	int i = 0;

	while (this->_inventory[i] && i < 4){
		i++;
	}
	if (i == 4){
		std::cout << "inventory is full" << std::endl;
	}
	this->_inventory[i] = m;
	std::cout << m->getType() << " has been equiped at " << i << "slot" << std::endl;
}

void Character::unequip(int idx)
{
	if (!this->_inventory[idx]){
		std::cout << "There noting for unequip" << std::endl;
	}
	this->_floor[_floorIndex++] = this->_inventory[idx];
	this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 4 || idx < 0){
		return ;
	}
	this->_inventory[idx]->use(target);
}