/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 08:09:18 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/07/11 09:37:34 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
	try
	{
		std::cout << "\033[1;32m" << "~~~ TEST 1 ~~~" << "\033[0m" << std::endl;
		
		Bureaucrat fluchten("Fluchten", 25);
		Bureaucrat cortiz("Cortiz", 75);

		Form minishell("minishell", 70, 70);
		Form webserv("webserv", 20, 20);

		std::cout << fluchten << std::endl << webserv << std::endl << cortiz << std::endl << minishell << std::endl;

		fluchten.signForm(minishell);
		fluchten.signForm(webserv);
		for (int i = 0; i < 6; i++){
			fluchten.addGrade();
		}
		std::cout << fluchten << std::endl;
		fluchten.signForm(webserv);
		
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "\033[1;35m" << "~~~ TEST 2 ~~~" << "\033[0m" << std::endl;
		
		Bureaucrat fluchten("Fluchten", 25);
		Bureaucrat cortiz("Cortiz", 75);

		Form minishell("minishell", 10, 70);
		Form webserv("webserv", 20, 210);

		std::cout << fluchten << std::endl << webserv << std::endl << cortiz << std::endl << minishell << std::endl;

		fluchten.signForm(minishell);
		fluchten.signForm(webserv);
		for (int i = 0; i < 6; i++){
			fluchten.addGrade();
		}
		fluchten.signForm(webserv);
		
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
