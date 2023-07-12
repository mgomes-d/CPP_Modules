/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 08:02:58 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/07/12 12:04:07 by mgomes-d         ###   ########.fr       */
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
        easyfind(numbers, 3); // Recherche le nombre 3 dans le vecteur
        easyfind(numbers, 6); // Recherche le nombre 6 dans le vecteur (qui n'existe pas)
    }
    catch (const ExceptionNumNotFound& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
	
}