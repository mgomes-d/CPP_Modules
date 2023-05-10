/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:41:37 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/05/10 07:57:00 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

int	main(int ac, char **av)
{
	std::string input;
	PhoneBook	PhoneBook;

	(void)ac;
	(void)av;
	while (true)
	{
		std::cout << "PhoneBook: ";
		if (!std::getline(std::cin, input)) {
       		break;
		}
		if (input == "ADD")
		{
			PhoneBook.AddNewContact();
			PhoneBook.index++;
			if (PhoneBook.index > 7)
			{
				PhoneBook.index = 0;
			}
		}
		else if (input == "SEARCH")
		{
			PhoneBook.Search();
		}
		else if (input == "EXIT")
		{
			break;
		}
	}
	return (0);
}