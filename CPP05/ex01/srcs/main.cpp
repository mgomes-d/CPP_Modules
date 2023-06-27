/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 08:09:18 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/27 11:10:58 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try {
		Bureaucrat b1("John", 100);
		std::cout << b1 << std::endl;

		b1.addGrade();
		std::cout << b1 << std::endl;

		b1.removeGrade();
		std::cout << b1 << std::endl;

		Bureaucrat b2("Alice", 1);
		std::cout << b2 << std::endl;

		b2.removeGrade(); // Throws GradeTooHighException
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try {
		Bureaucrat b3("Bob", 150);
		std::cout << b3 << std::endl;

		b3.removeGrade();
		std::cout << b3 << std::endl;

		b3.addGrade();
		b3.addGrade(); // Throws GradeTooLowException
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	try {
		Bureaucrat fluchten("fluchten", 250);
		std::cout << fluchten << std::endl;
	}
	catch (std::exception &e){
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
