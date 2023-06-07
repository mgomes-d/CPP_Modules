/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 08:51:37 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/07 09:01:17 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{

	if (ac != 2){
		std::cout << "Wrong usage: ./harlFilter <level>" << std::endl;
		return (1);
	}
	
	Harl Harl;
	std::string level = av[1];
	Harl.complain(level);
	return (0);
}