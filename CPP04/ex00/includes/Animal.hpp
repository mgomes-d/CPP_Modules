/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:17:09 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/16 11:57:50 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

class Animal{

public:
	Animal(void);
	Animal(const std::string &type);
	Animal(const Animal &rhs);
	Animal &operator=(const Animal &rhs);

	void makeSound(void);

protected:
	std::string _type;

};

#endif