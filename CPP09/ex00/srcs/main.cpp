/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:21:00 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/07/18 10:30:00 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>

int main(int ac, char **av)
{
	if (ac != 2){
		std::cout << ERROR_MSG_OFILE << std::endl;
		return (1);
	}
	std::cout << av[1] << std::endl;
}