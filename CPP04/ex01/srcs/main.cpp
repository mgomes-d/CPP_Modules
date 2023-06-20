/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:16:55 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/20 10:33:59 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void Test(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* a = new WrongAnimal();
	const WrongAnimal* b = new WrongCat();

	std::cout << std::endl;
	std::cout << "\033[1;44m" << j->getType() << "\033[0m " << std::endl;
	std::cout << "\033[1;44m" << i->getType() << "\033[0m " << std::endl;
	std::cout << "\033[1;44m" << a->getType() << "\033[0m " << std::endl;
	std::cout << "\033[1;44m" << b->getType() << "\033[0m " << std::endl;

	std::cout << std::endl;

	j->makeSound();
	i->makeSound();
	meta->makeSound();
	a->makeSound();
	b->makeSound();

	std::cout << std::endl;

	delete i;
	delete j;
	delete meta;
	delete a;
	delete b;
}

void Test02(void)
{
	Animal *array[20];
	std::cout << "\033[1;32mConstructor \033[0m" << std::endl;
	for (int i = 0; i < 20; i++){
		if (i % 2 == 0){
			array[i] = new Dog();
		}
		else{
			array[i] = new Cat();
		}
	}
	std::cout << std::endl;
	
	std::cout << "\033[1;36m Sound Test \033[0m" << std::endl;
	for(int i = 0; i < 20; i++){
		std::cout << array[i]->getType() << ": ";
		array[i]->makeSound();
	}

	std::cout << std::endl;
	std::cout << "\033[1;33mDestructor \033[0m" << std::endl;

	for (int i = 0; i < 20; i++){
		delete array[i];
	}
}

int	main(void)
{
	std::cout << "\033[4;41m Test From ex00 \033[0m" << std::endl;
	Test();

	std::cout << std::endl;
	
	std::cout << "\033[4;41m NewTest \033[0m" << std::endl;
	Test02();

	return (0);
}
