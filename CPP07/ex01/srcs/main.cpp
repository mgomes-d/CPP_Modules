/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 11:21:01 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/07/27 11:07:07 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
    // Tableau d'entiers
    int intArray[] = {1, 2, 3, 4, 5};
    std::size_t intArraySize = sizeof(intArray) / sizeof(int);

    std::cout << "Int Array: ";
    iter(intArray, intArraySize, printmsg);
    std::cout << std::endl;

    // Tableau de caractères
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    std::size_t charArraySize = sizeof(charArray) / sizeof(char);

    std::cout << "Char Array: ";
    iter(charArray, charArraySize, printmsg);
    std::cout << std::endl;

    return 0;
}
