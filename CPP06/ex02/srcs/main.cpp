/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:16:13 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/07/07 08:17:35 by mgomes-d         ###   ########.fr       */
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
	if (dynamic_cast<A *>(p)){
		std::cout << "A" << std::endl;
	}
	else if (dynamic_cast<B *>(p)){
		std::cout << "B" << std::endl;
	}
	else if (dynamic_cast<C *>(p)){
		std::cout << "C" << std::endl;
	}
	else{
		std::cout << "unknown" << std::endl;
	}
}

void identify(Base& p)
{
	try{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (const std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try{
		B &b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "B" << std::endl;
	}
	catch (const std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try{
		C &c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "C" << std::endl;
	}
	catch (const std::exception &e){
		std::cout << e.what() << std::endl;
	}
}

int	main()
{
	Base	*base = generate();
	identify(base);
	identify(*base);

	return (0);
}