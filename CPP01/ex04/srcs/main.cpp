/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 07:48:22 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/06 10:57:42 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

int	main(int ac, char **av)
{
	if (ac != 4){
		std::cout << "Error: Number of arguments" << std::endl;
		return (1);
	}
	
	File file(av[1], av[2], av[3]);

	if (file.getContent()){
		return (1);
	}
	file.remplace();
	return (0);
}