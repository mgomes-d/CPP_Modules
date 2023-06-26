/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:46:51 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/22 11:56:37 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat : public WrongAnimal{

public:
	WrongCat(void);
	WrongCat(const WrongCat &rhs);
	WrongCat &operator=(const WrongCat &rhs);
	~WrongCat(void);

	void makeSound(void) const;
};

#endif