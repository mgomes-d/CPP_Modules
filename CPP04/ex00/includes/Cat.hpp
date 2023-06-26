/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:50:55 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/22 11:57:32 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include <iostream>

class Cat : public Animal{

public:
	Cat(void);
	Cat(const Cat &rhs);
	Cat &operator=(const Cat &rhs);
	~Cat(void);

	virtual void makeSound(void) const;
private:
	
};

#endif