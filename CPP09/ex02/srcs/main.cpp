/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:11:33 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/08/01 07:57:50 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	int i = 0;
	std::srand(static_cast<unsigned>(std::time(0)));
	int	*array = new int[21];
	while (i < 21)
	{
		array[i] = std::rand() % 20;
		i++;
	}
	try{
		PmergeMe test(array, 21);
		test.sort();	
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
		delete [] array;
		return (1);
	}
	delete [] array;
	return (0);
}