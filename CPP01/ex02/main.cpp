/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:12:20 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/05 10:26:02 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string brain = "HI THIS IS BRAIN";
	std::string *stringPTR = &brain;
	std::string	&stringREF = brain;

	std::cout << "string memory address " << &brain << std::endl;
	std::cout << "stringPTR memory address " << stringPTR << std::endl;
	std::cout << "stringREF memory address " << &stringREF << std::endl;

	std::cout << std::endl;
	
	std::cout << "string value " << brain << std::endl;
	std::cout << "stringPTR value " << *stringPTR << std::endl;
	std::cout << "stringREF value " << stringREF << std::endl;
	return (0);
}