/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:42:36 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/05/10 08:06:27 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void) : index(0)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::AddNewContact(void)
{
    std::string input;
    int j = 0;

	input.clear();
    while (input.empty()) {
        std::cout << "first name: ";
        if (!std::getline(std::cin, input))
            exit(0);
    }
    this->_Contacts[this->index].Add_New_element(input, j);
    j++;

    input.clear();
    while (input.empty()) {
        std::cout << "last name: ";
        if (!std::getline(std::cin, input))
            exit(0);
    }
    this->_Contacts[this->index].Add_New_element(input, j);
    j++;

    input.clear();
    while (input.empty()) {
        std::cout << "nickname: ";
        if (!std::getline(std::cin, input))
            exit(0);
    }
    this->_Contacts[this->index].Add_New_element(input, j);
    j++;

    input.clear();
    while (input.empty()) {
        std::cout << "phone number: ";
        if (!std::getline(std::cin, input))
            exit(0);
    }
    this->_Contacts[this->index].Add_New_element(input, j);
    j++;

    input.clear();
    while (input.empty()) {
        std::cout << "darkest secret: ";
        if (!std::getline(std::cin, input))
            exit(0);
    }
    this->_Contacts[this->index].Add_New_element(input, j);
}

void    PhoneBook::Search(void)
{
    _Contacts->Search(this->_Contacts);
}