/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:35:55 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/05/09 10:17:03 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include <iostream>
#include <string>
#include "Contact.class.hpp"

class PhoneBook{
	
public:
	PhoneBook();
	~PhoneBook();
	int		index;
	void	AddNewContact(void);
	void    Search(void);
	
private:
	Contact	_Contacts[8];
};


#endif