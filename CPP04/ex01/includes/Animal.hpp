/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:17:09 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/19 11:27:52 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal{

public:
	Animal(void);
	Animal(const Animal &rhs);
	Animal &operator=(const Animal &rhs);
	virtual ~Animal(void);

	virtual void makeSound(void) const;
	std::string getType(void) const;

protected:
	std::string _type;
};

#endif