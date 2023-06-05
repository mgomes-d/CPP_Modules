/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 07:49:37 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/05 09:45:54 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie{

public:
	Zombie();
	Zombie(std::string name);
	~Zombie();

	void	naming(std::string name);
	void	announce(void);

private:
	std::string _name;
};

Zombie* zombieHorde(int N, std::string name);

#endif