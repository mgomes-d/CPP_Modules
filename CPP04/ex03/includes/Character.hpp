/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 09:51:20 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/21 11:53:35 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter{
	
private:
	AMateria *_inventory[4];
	std::string _Name;
	AMateria **_floor;
	int		_floorIndex;

public:
	Character(void);
	Character(const std::string &name);
	Character(const Character &rhs);
	Character &operator=(const Character &rhs);
	~Character(void);

	virtual std::string const & getName() const;
	virtual void	equip(AMateria *m);
	virtual void	unequip(int idx);
	virtual void	use(int idx, ICharacter& target);
};

#endif