/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:16:13 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/07/06 11:55:17 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

Base *generate(void)
{
	int	base;
	
	srand (time(NULL));

	base = rand() % 3;
	switch (base)
	{
		case 0:
			return static_cast<Base *>(new A());
		case 1:
			return static_cast<Base *>(new B());
		default:
			return static_cast<Base *>(new C());
	}
	
}

void identify(Base* p)
{
	
}

void identify(Base& p)
{
	
}

int	main()
{
	std::cout << "[ BASE A ]" << std::endl;
	Base *a = new A();
	identify(a);
	identify(*a);
	delete a;
	std::cout << std::endl;

	std::cout << "[ BASE B ]" << std::endl;
	Base *b = new B();
	identify(b);
	identify(*b);
	delete b;
	std::cout << std::endl;

	std::cout << "[ BASE C ]" << std::endl;
	Base *c = new C();
	identify(c);
	identify(*c);
	delete c;
	std::cout << std::endl;

	std::cout << "[ BASE RANDOM ]" << std::endl;
	Base *random = generate();
	identify(random);
	identify(*random);
	delete random;

	return (0);
}