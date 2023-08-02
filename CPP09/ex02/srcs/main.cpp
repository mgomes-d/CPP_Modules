/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:11:33 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/08/02 08:20:21 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	(void)ac;
	int i = 0;
	std::srand(static_cast<unsigned>(std::time(0)));
	int len = ac - 1;
	int	*array = new int[len];
	while (i < len)
	{
		array[i] = atoi(av[i]);
		i++;
	}
	try{
		PmergeMe test(array, len);
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