/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 08:02:58 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/07/13 09:48:34 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <array>
#include <list>
#include <vector>

int	main(void)
{    
	std::vector<int> numbers;
	numbers.push_back(5);
    numbers.push_back(3);
	numbers.push_back(1);
	numbers.push_back(45);
    try
    {
        easyfind(numbers, 3);
        easyfind(numbers, 6);
    }
    catch (const ExceptionNumNotFound& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl;
    
    std::list<int> nbrs;
	nbrs.push_back(5);
    nbrs.push_back(3);
	nbrs.push_back(1);
	nbrs.push_back(45);
    try
    {
        easyfind(nbrs, 45);
        easyfind(nbrs, 6);
    }
    catch (const ExceptionNumNotFound& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << std::endl;

    std::array<int, 4> nbs;
	nbs[0] = 5;
    nbs[1] = 3;
	nbs[2] = 1;
	nbs[3] = 5;
    try
    {
        easyfind(nbs, 3);
        easyfind(nbs, 6);
    }
    catch (const ExceptionNumNotFound& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
	
}