/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 10:27:34 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/23 09:45:01 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"


Character::Character(void) : _Name("Default"), _floorIndex(0)
{
	for (int i = 0; i < 4; i++){
		this->_inventory[i] = NULL;
	}
	for (int i = 0; i < MAX_FLOOR_SIZE; i++){
		this->_floor[i] = NULL;
	}
}

Character::Character(const std::string &name) : _Name(name), _floorIndex(0)
{
	for (int i = 0; i < 4; i++){
		this->_inventory[i] = NULL;
	}
	for (int i = 0; i < MAX_FLOOR_SIZE; i++){
		this->_floor[i] = NULL;
	}
}

Character::Character(const Character &rhs)
{
	*this = rhs;
}

Character &Character::operator=(const Character &rhs)
{
	if (this != &rhs){
		this->_Name = rhs._Name;
		this->_floorIndex = rhs._floorIndex;
		for (int i = 0; i < 4; i++){
			if (rhs._inventory[i]){
				this->_inventory[i] = rhs._inventory[i]->clone();
			}
			else{
				this->_inventory[i] = NULL;
			}
		}
		for (int i = 0; i < MAX_FLOOR_SIZE; i++){
			if (rhs._floor[i]){
				this->_floor[i] = rhs._floor[i]->clone();
			}
			else{
				this->_floor[i] = NULL;
			}
		}
	}
	return (*this);
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++){
		if (this->_inventory[i] != NULL){
			delete this->_inventory[i];
		}
	}
    for (int i = 0; i < this->_floorIndex; i++) {
        if (this->_floor[i] != NULL) {
            delete this->_floor[i];
            this->_floor[i] = NULL;
        }
    }
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
		std::cout << "inventory is full!" << std::endl;
		return ;
	}
	this->_inventory[i] = m;
}

void Character::unequip(int idx)
{
	if (idx > 3 || idx < 0 || !this->_inventory[idx]){
		std::cout << "Nothing to unequip!" << std::endl;
		return ;
	}
	if (this->_floorIndex == MAX_FLOOR_SIZE){
		for (int i = 0; i < MAX_FLOOR_SIZE; i++){
			if (this->_floor[i]){
				delete (this->_floor[i]);
			}
		}
		this->_floorIndex = 0;
	}
	this->_floor[this->_floorIndex] = this->_inventory[idx];
	this->_floorIndex++;
	std::cout << "The Character " << this->_Name << " unequip " << this->_inventory[idx]->getType() << std::endl;
	this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx <= 3 && idx >= 0 && this->_inventory[idx]){
		this->_inventory[idx]->use(target);
	}
	else{
		std::cout << "Nothing to use!" << std::endl;
	}
}