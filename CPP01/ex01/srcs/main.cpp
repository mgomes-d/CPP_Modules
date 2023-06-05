/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 07:49:27 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/05 10:05:21 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zhorde = zombieHorde(10, "fluchten");
	
	for (int i = 0; i < 10; i++)
	{
		zhorde[i].announce();
	}
	delete [] zhorde;
	return (0);
}