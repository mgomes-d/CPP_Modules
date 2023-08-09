/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:11:33 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/08/09 07:49:52 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool isAllDigits(const std::string& str) {
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (!std::isdigit(*it)) {
            return false;
        }
    }
    return true;
}

int *get_input(char **av, int len)
{
	int *array = new int[len];
	for (int i = 0; i < len; i++)
	{
		std::string str = static_cast<std::string>(av[i + 1]);
		if (!isAllDigits(str)){
			std::cout << "Error" << std::endl;
			std::exit(1);
		}
		std::istringstream iss(str);
		iss >> array[i];
		if (iss.fail()){
			std::cout << "Error" << std::endl;
			std::exit(1);
		}
	}
	return (array);
}

int	main(int ac, char **av)
{
	(void)ac;
	std::srand(static_cast<unsigned>(std::time(0)));
	int len = ac - 1;
	int	*array = get_input(av, len);
	try{
		PmergeMe test;
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