/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 09:17:18 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/07/11 09:20:37 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename T>
void printArray(const Array<T>& array)
{
    std::cout << "Array elements: " << array << std::endl;
}

int main()
{
    // Test du constructeur par défaut
    Array<int> intArrayDefault;
    std::cout << "Default Array size: " << intArrayDefault.size() << std::endl;

    // Test du constructeur avec taille spécifiée
    Array<int> intArray(5);
    std::cout << "Array size: " << intArray.size() << std::endl;

    // Test de l'opérateur []
    for (unsigned int i = 0; i < intArray.size(); i++)
    {
        intArray[i] = i + 1;
    }
    std::cout << "Array elements: " << intArray << std::endl;

    // Test de l'exception OutOfBoundsException
    try
    {
        intArray[10] = 100; // Accès à un index hors limites
    }
    catch (const Array<int>::OutOfBoundsException& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}