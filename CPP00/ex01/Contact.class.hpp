/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:34:06 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/05/10 08:06:14 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>

class Contact{

public:
	Contact();
	~Contact();
	void	Add_New_element(std::string element, int index);
	void    Search(Contact Contacts[8]);

private:
	std::string _first_name;
	std::string _last_name;
	std::string	_nickname;
	std::string _phone_number;
	std::string _darkest_secret;	
	void	_ShowInfo(Contact contact_info);
};

#endif