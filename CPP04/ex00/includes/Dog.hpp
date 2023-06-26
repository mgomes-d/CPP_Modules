/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:50:59 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/22 11:57:37 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include <iostream>

class Dog : public Animal{
	
public:
	Dog(void);
	Dog(const Dog &rhs);
	Dog &operator=(const Dog &rhs);
	~Dog(void);

	virtual void makeSound(void) const;
private:

};

#endif