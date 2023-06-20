/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 11:33:26 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/20 07:54:12 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include "iostream"

class WrongAnimal{

public:
	WrongAnimal(void);
	WrongAnimal(const WrongAnimal &rhs);
	WrongAnimal &operator=(const WrongAnimal &rhs);
	virtual ~WrongAnimal(void);
	
	void makeSound(void) const;
	std::string getType(void) const;

protected:
	std::string	_type;

};

#endif