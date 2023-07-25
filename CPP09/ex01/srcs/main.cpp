/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:58:48 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/07/25 09:31:31 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char **av)
{
	if (ac != 2){
		std::cout << "Error" << std::endl;
		return (1);
	}
	RPN rpn(static_cast<std::string>(av[1]));

	if (rpn.calculation())
		return (1);
	return (0);
}