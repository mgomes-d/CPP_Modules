/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 09:21:39 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/15 10:43:30 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap{

public:
	FragTrap(void);
	FragTrap(const FragTrap &rhs);
	FragTrap(const std::string &name);
	FragTrap &operator=(const FragTrap &rhs);
	~FragTrap(void);
	void highFivesGuys(void);

};

#endif