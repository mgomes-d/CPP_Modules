/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:42:31 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/05/10 08:08:49 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact(void) : _first_name(""), _last_name(""), _nickname(""), _phone_number(""), _darkest_secret("")
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void	Contact::Add_New_element(std::string element, int index)
{
	if (index == 0)
		this->_first_name = element;
	else if (index == 1)
		this->_last_name = element;
	else if (index == 2)
		this->_nickname = element;
	else if (index == 3)
		this->_phone_number = element;
	else if (index == 4)
		this->_darkest_secret = element;
}

std::string TruncateString(std::string str, int width) {
    if (str.length() > static_cast<std::string::size_type>(width)) {
        str = str.substr(0, width - 1) + ".";
    }
    return str;
}

void	Contact::_ShowInfo(Contact contact_info)
{
    if (contact_info._first_name.empty() ||
    contact_info._last_name.empty() ||
    contact_info._nickname.empty() ||
    contact_info._phone_number.empty() ||
    contact_info._darkest_secret.empty()) 
    {
        std::cout << "Invalid index, please try again." << std::endl;
        return ;
    }
    std::cout << "First name: " << contact_info._first_name << std::endl;
    std::cout << "Last name: " << contact_info._last_name << std::endl;
    std::cout << "Nickname: " << contact_info._nickname << std::endl;
    std::cout << "Phone number: " << contact_info._phone_number << std::endl;
    std::cout << "Darkest secret: " << contact_info._darkest_secret << std::endl;
    return ;
}

void    Contact::Search(Contact Contacts[8])
{
    std::cout << "     index|first name| last name|  nickname|\n";
    std::cout << "----------|----------|----------|----------|\n";
    for (int i = 0; i < 8; i++) {
        if (Contacts[i]._first_name.empty() || Contacts[i]._last_name.empty() ||Contacts[i]._nickname.empty())
        {
            break ;
        }
        std::cout << std::setw(10) << std::right << i << "|";
        std::cout << std::setw(10) << std::right << TruncateString(Contacts[i]._first_name, 10) << "|";
        std::cout << std::setw(10) << std::right << TruncateString(Contacts[i]._last_name, 10) << "|";
        std::cout << std::setw(10) << std::right << TruncateString(Contacts[i]._nickname, 10) << "|\n";
    }
	int i = 0;
	std::string input;
	input.clear();
    while (input.empty() || !std::all_of(input.begin(), input.end(), ::isdigit)) {
        std::cout << "Enter the index of the contact you want to display: ";
        if (!std::getline(std::cin, input))
            exit(0);
    }
    i = std::stoi(input);
    if (i < 0 || i >= 8){
        std::cout << "Invalid index, please try again." << std::endl;
	}
	else{
		this->_ShowInfo(Contacts[i]);
	}
	}

