/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:23:59 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/05/05 12:36:18 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char** argv)
{
	if (argc <= 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}

	for (int i = 1; i < argc; i++)
	{
		std::string arg = argv[i];
		int j = 0;
		while (arg[j])
		{
			if (std::islower(arg[j]))
				arg[j] = std::toupper(arg[j]);
			j++;
		}
		std::cout << arg;
	}
	std::cout << std::endl;

	return 0;
}
