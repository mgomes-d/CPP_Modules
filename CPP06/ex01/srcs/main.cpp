/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 08:25:37 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/07/06 11:05:18 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
    // Création d'un objet Data
    Data data("John Doe", 25);

	std::cout << "Data value: " << data << std::endl;
    // Sérialisation de l'adresse de l'objet Data
    uintptr_t serialized = Serializer::serialize(&data);

    // Désérialisation de la valeur sérialisée
    Data* deserialized = Serializer::deserialize(serialized);

	std::cout << "Deserialized value: " << *deserialized << std::endl;
    // Vérification que le pointeur désérialisé est égal au pointeur d'origine
	std::cout << std::endl;
    if (deserialized == &data)
    {
        std::cout << "Serialization and deserialization successful!" << std::endl;
    }
    else
    {
        std::cout << "Serialization and deserialization failed!" << std::endl;
    }
    return 0;
}
