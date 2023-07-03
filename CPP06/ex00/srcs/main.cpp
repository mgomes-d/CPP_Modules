/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 08:38:04 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/07/03 09:09:07 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2){
		std::cout << "Error: Arguments" << std::endl;
		return (0);
	}
	ScalarConverter::convert(static_cast<std::string>(av[1]));
	return (0);
}